#include "player.h"
#include "spell.h"
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <dos.h>
#include <stdio.h>

Player::Player(int d, int h, int m, int df, char* n, int l, bool p, QTextEdit &M):
        damage(d),
        health(h),
        mana(m),
        defence(df),
        luck(l),
        name(n),
        bot(p),
        Memo(&M),
        Info(new QLabel()),
        restoreMana(2)

{}
char* Player::intToCh(int n){
    char *res = new char[10];
    char *ret = new char[10];
    res[0]='\0';

    bool p = false;
    if (n<0){
        n=-n;
        p=true;
    }
    while (n>=1){
        strcat(res, new char((n%10)+48));
        n/=10;
    }
    if (p){strcat(res,"-");}

    int i=0;
    for (int j=strlen(res)-1; j>=0; i++,j--){
        ret[i]=res[j];
    }
    ret[strlen(res)]='\0';
    return ret;
}
QString Player::getChars(){
    QString res = QString("");
    res.append("Здоровье: ");
    res.append(QString::number(this->health));
    res.append("\nАтака: ");
    res.append(QString::number(this->damage));
    res.append("\nЗащита: ");
    res.append(QString::number(this->defence));
    res.append("\nУдача: ");
    res.append(QString::number(this->luck));
    res.append("\nМана: ");
    res.append(QString::number(this->mana));
    return QString(res);
}
char* Player::getName(){
    return name;
}

void Player::setConnection(Player *enemy){
    connect(this,&Player::laidDamage,enemy,&Player::beAttacked);
}

void Player::attack(bool p=true){

    if (this->health<=0) return;

    QString *s=new QString("");

    int lD = this->damage;
    int ch = rand()%10;
    lD+=abs(this->luck*ch/10);

    s->append("\n");
    s->append(this->name);
    s->append(" атакует и наносит ");
    s->append(QString::number(lD));
    s->append(" урона.");
    s->append(this->Memo->toPlainText());
    this->Memo->setText(*s);

    emit laidDamage(lD,0,0,0,0);
}

void Player::beAttacked(int damage,int Eattack, int Edefence, int Eluck, int Emana){

    this->mana+=this->restoreMana;
    int attemptDamage = damage-this->defence;
    if (attemptDamage<0) attemptDamage=0;
    if (damage<0) attemptDamage=damage;

    if (Eattack) this->damage+=Eattack;
    if (this->damage<0) this->damage=0;

    if (Edefence) this->defence+=Edefence;
    if (this->defence<0) this->defence=0;

    if (Eluck) this->luck+=Eluck;
    if (this->luck<0) this->luck=0;

    if (Emana) this->mana+=Emana;
    if (this->mana<0) this->mana=0;

    QString *s=new QString("");

    s->append("\n\n");
    s->append(this->name);
    s->append(" получает ");
    s->append(QString::number(attemptDamage));
    s->append(" урона.");
    s->append(this->Memo->toPlainText());
    this->Memo->setText(*s);

    this->health-=attemptDamage;
    this->Info->setText(this->getChars());
    if (this->health<=0) {die(); return;}

    if (bot) {
            int ch = rand()%13;


            if((this->health<=15)&&(this->mana>=16)){
                ch=8;
            }else
            if ((this->mana<=12)&&(this->mana>=5)){
                ch=4;
            }else{
                if((this->damage<=1)&&(ch==0)){
                    ch+=rand()%8+1;
                }
            }



            if (ch==2) {this->heal();
                        return;}
            else if(ch==1){
                int lD = this->damage;
                int ch = abs(rand()%10);
                 if (ch<this->luck) lD+=this->damage;
                emit laidDamage(lD,0,0,0,0);
                 return;
              }else if(ch==3){
                if(this->mana>=17){
                QString *s=new QString("");
                s->append("\n");
                s->append(this->name);
                s->append(" использует заклинание Проклятие. Заклинание уменьшает атаку противника на 1. Заклинание уменьшает защиту противника на 2. Заклинание уменьшает удачу противника на 3.");
                this->mana-=17;
                this->Info->setText(this->getChars());
                s->append(this->Memo->toPlainText());
                this->Memo->setText(*s);
                emit laidDamage(0,-1,-2,-3,0);

                return;
                }
            }else if(ch==4){
                if(this->mana>=5){
                    QString *s=new QString("");
                    s->append("\n");
                    s->append(this->name);
                    s->append(" использует заклинание Энергетический канал. Заклинание дает игроку 15 маны.");
                    this->mana-=5;
                    this->mana+=15;
                    this->Info->setText(this->getChars());
                    s->append(this->Memo->toPlainText());
                    this->Memo->setText(*s);
                    emit laidDamage(0,0,0,0,0);
                    return;
                }
            }else if(ch==5){
                if (this->mana>=12){
                    QString *s=new QString("");
                    s->append("\n");
                    s->append(this->name);
                    s->append(" использует заклинание Молния. Заклинание наносит противнику 20 урона.");
                    this->mana-=12;
                    this->Info->setText(this->getChars());
                    s->append(this->Memo->toPlainText());
                    this->Memo->setText(*s);
                    emit laidDamage(20,0,0,0,0);
                    return;
                }
            }else if(ch==6){
                 if(this->mana>=24){
                     QString *s=new QString("");
                     s->append("\n");
                     s->append(this->name);
                     s->append(" использует заклинание Призыв ярости. Заклинание повышает атаку игрока на 5.");
                     this->mana-=24;
                     this->damage+=5;
                     this->Info->setText(this->getChars());
                     s->append(this->Memo->toPlainText());
                     this->Memo->setText(*s);
                     emit laidDamage(0,0,0,0,0);
                     return;
                 }
            }else if(ch==7){
                if(this->mana>=28){
                    QString *s=new QString("");
                    s->append("\n");
                    s->append(this->name);
                    s->append(" использует заклинание Огненный смерч. Заклинание наносит 53 единицы урона.");
                    this->mana-=28;

                    this->Info->setText(this->getChars());
                    s->append(this->Memo->toPlainText());
                    this->Memo->setText(*s);
                    emit laidDamage(53,0,0,0,0);
                    return;
                }
            }else if(ch==8){
                if(this->mana>=16){
                    QString *s=new QString("");
                    s->append("\n");
                    s->append(this->name);
                    s->append(" использует заклинание Исцеление. Заклинание излечивает игроку 30 единиц жизни.");
                    this->mana-=16;
                    this->health+=30;
                    this->Info->setText(this->getChars());
                    s->append(this->Memo->toPlainText());
                    this->Memo->setText(*s);
                    emit laidDamage(0,0,0,0,0);
                    return;
                }
            }else if (ch==9){
                if(this->mana>=33){
                    QString *s=new QString("");
                    s->append("\n");
                    s->append(this->name);
                    s->append(" использует заклинание Спутывание памяти. Заклинание наносит противнику 5 единиц урона.\n Заклинание уменьшает удачу противника на 2 и атаку на 5.\nПротивник теряет 20 маны.");
                    this->mana-=33;

                    this->Info->setText(this->getChars());
                    s->append(this->Memo->toPlainText());
                    this->Memo->setText(*s);
                    emit laidDamage(5,-5,0,-2,-20);
                    return;
                }
            }else if (ch==10){
                if(this->mana>=18){
                    QString *s=new QString("");
                    s->append("\n");
                    s->append(this->name);
                    s->append(" использует заклинание Ритуал энергии. Заклинание повышает атаку игрока на 1, защиту - на 2 и удачу на 3.");
                    this->mana-=18;
                    this->damage+=1;
                    this->defence+=2;
                    this->luck+=3;
                    this->Info->setText(this->getChars());
                    s->append(this->Memo->toPlainText());
                    this->Memo->setText(*s);
                    emit laidDamage(0,0,0,0,0);
                    return;
                }
            }else if (ch==11){
                if(this->mana>=45){
                    QString *s=new QString("");
                    s->append("\n");
                    s->append(this->name);
                    s->append(" использует заклинание Дыхание тьмы. Заклинание обнуляет удачу каждого игрока, понижает защиту противника на 5, повышает атаку игрока на 6.");
                    this->mana-=45;
                    this->damage+=6;
                    this->luck-=100;
                    if(this->luck<0) this->luck=0;
                    this->Info->setText(this->getChars());
                    s->append(this->Memo->toPlainText());
                    this->Memo->setText(*s);
                    emit laidDamage(0,0,-5,-100,0);
                    return;
                }
            }
                laidDamage(this->damage,0,0,0,0);


    }
}

void Player::die(){
    QString *str = new QString(this->name);
    str->append(" повержен!");
    QMessageBox *Mes = new QMessageBox(QMessageBox::Warning,"Конец игры",*str);
    Mes->show();
}
 void Player::heal(){

    int getHealth=round(this->mana*(this->luck+1)/10);

    QString *s=new QString("");
    s->append("\n");
    s->append(this->name);
    s->append(" лечится и восстанавливает ");
    s->append(QString::number(getHealth));
    s->append(" жизни.");
    s->append(this->Memo->toPlainText());
    this->Memo->setText(*s);
    this->mana-=getHealth;
    this->health+=getHealth;
    this->Info->setText(this->getChars());

    emit laidDamage(0,0,0,0,0);
 }

void Player::spellAttack(QString nm, int price,int dmg, int heal, int Eattack, int Mattack, int Edefence, int Mdefence, int Eluck, int Mluck, int Emana, int Mmana){

    if(this->mana>=price){
    QString *s=new QString("");
    s->append("\n");
    s->append(this->name);
    s->append(" использует заклинание ");
    s->append(nm);
    if(dmg>0){s->append("\nЗаклинание наносит "); s->append(QString::number(dmg)); s->append(" урона.");}
    if (dmg<0){s->append("\nЗаклинание излечивает противнику ").append(QString::number(-dmg)); s->append(" жизни.");}
    if (Eattack<0){s->append("\nЗаклинание понижает атаку противника на ").append(QString::number(-Eattack)); s->append(" единиц.");}
    if (Edefence<0){s->append("\nЗаклинание понижает защиту противника на ").append(QString::number(-Edefence)); s->append(" единиц.");}
    if (Eluck<0){s->append("\nЗаклинание понижает удачу противника на ").append(QString::number(-Eluck)); s->append(" единиц.");}
    if (Emana<0){s->append("\nЗаклинание лишает противника ").append(QString::number(-Emana)); s->append(" единиц маны.");}

    if (Mattack>0){s->append("\nЗаклинание повышает атаку игрока на ").append(QString::number(Mattack)); s->append(" единиц.");}
    this->damage+=Mattack;
    if (this->damage<0) this->damage=0;

    if (Mdefence>0){s->append("\nЗаклинание повышает защиту игрока на ").append(QString::number(Mdefence)); s->append(" единиц.");}
    this->defence+=Mdefence;
    if (this->defence<0) this->defence=0;

    if (Mluck>0){s->append("\nЗаклинание повышает удачу игрока на ").append(QString::number(Mluck)); s->append(" единиц.");}
    this->luck+=Mluck;
    if (this->luck<0) this->luck=0;

    if (Mmana>0){s->append("\nЗаклинание добавляет игроку ").append(QString::number(Mmana)); s->append(" маны.");}
    this->mana+=Mmana;

    if (heal>0){s->append("\nЗаклинание излечивает "); s->append(QString::number(heal)); s->append(" жизни."); }
    if (heal<0){s->append("\nЗаклинание наносит игроку "); s->append(QString::number(heal)); s->append(" урона."); }

    this->health+=heal;

    s->append(this->Memo->toPlainText());
    this->Memo->setText(*s);
    this->mana-=price;
    this->Info->setText(this->getChars());
    emit laidDamage(dmg,Eattack,Edefence,Eluck,Emana);}
    else{
        QMessageBox *Mes = new QMessageBox(QMessageBox::Warning,"И не пытайся!","Не хватает маны!");
        Mes->show();
    }
}
void Player::message(QAction *A){
    QString str;
    if (A->text()=="Атака") str = QString("Общие принципы атаки. \n Параметр атаки игрока показывает, сколько урона будет передано противнику, если на текущем ходу игрок выберет Атаковать. Этот урон будет увеличен в зависимости от удачи игрока. Противник получит переданный ему урон минус его защита.");
    if (A->text()=="Защита и лечение") str = QString("Принципы защиты и лечения. \nПараметр защиты показывает, сколько переданного противником урона будет проигнорировано. Если показатель защиты выше, чем переданный урон, игрок не получает повреждений. При выборе Лечения игрок восстанавливает случайное число жизни за счет своей маны. Максимум игрок может восстановить 10*удача жизни(если количества маны хватает).");
    if (A->text()=="Типы заклинаний") str = QString("Типы заклинаний. \nВ игре есть три типа заклинаний. Первый тип - атакующие заклинания, предназначены для нанесения прямого урона противнику. Весь урон такими заклинаниями будет подвержен действию защиты противника. \nВторой тип заклинаний - благословления. Эти заклинания используются для повышения собственных характеристик - защиты, атаки, здоровья, удачи и количества маны. Эффект этих заклинаний пермаментный и аккумулятивный. \nТретий (наиболее полезный) тип заклинаний - проклятья. Они позволяют уменьшить характеристики противника. Разумная комбинация этих заклинаний приведет к полному разгрому противника.");
    if (A->text()=="Колдовство и мана") str = QString("Применение магии.\nВ игре лучше всегда, когда есть возможность, применять магию. Прямая атака полезна только в случае отсутствия маны или высокого показателя атаки+удачи. В игре применимы несколько стратегий, которые могут помочь победить соперника, однако о них я рассказывать не буду. Советую лишь чаще использовать заклинания, когда это возможно, не брезговать энергетическим каналом и не забывать про проклятья. ");
    if (A->text()=="Общая информация") str = QString("Информация об игре.\nВ игре есть два игрока - человек и компьютер. Игровой процесс разделен на ходы. На каждом ходу игрок может делать одно из трех действий - атаковать, лечиться или колдовать. После хода первого игрока сразу же наступает ход второго. Игрок не сможет колдовать заклинания, цена которых выше количества его маны. Цель каждого игрока - применить разумную комбинацию атак, заклинаний и лечений, чтобы понизить жизнь противника до нуля раньше, чем это сделает он. Противник умеет колдовать, атаковать и лечиться, поэтому простой задачей это не будет.");
    if (A->text()=="О программе") str = QString("LabGame v1.1\nРазработчик: Латушкин Денис Александрович, 2 курс 9 группа ММФ БГУ. На разработку потрачено 23 часа.");

    QMessageBox *Mes = new QMessageBox(QMessageBox::Information,A->text(),str);
    Mes->show();

}
