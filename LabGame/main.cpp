#include "widget.h"
#include "player.h"
#include "spell.h"
#include "spelllabel.h"
#include "spelldesc.h"
#include <QApplication>
#include <QLayout>
#include <QtWidgets>
#include <QPushButton>
#include <QPixmap>
#include <QImage>
#include <ctime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *w = new QWidget();


    //w.setStyleSheet("QWidget {background-color:#013; color: #790}");
    srand(time(NULL));
    QHBoxLayout *Left = new QHBoxLayout();

    QVBoxLayout *Me = new QVBoxLayout();
    QVBoxLayout *Center = new QVBoxLayout();
    QTextEdit *Memo = new QTextEdit("Game Statistics");
    Center->addWidget(Memo);
    Player *I = new Player(10,300,60,6,(char*)"Capt Osmant",7,false,*Memo);
    Player *Enemy = new Player(22,300,60,6,(char*)"Jack Albatraos",4,true,*Memo);

    QVBoxLayout *MeInfo= new QVBoxLayout();
    I->Info->setText(I->getChars());

    QLabel *MeNew = new QLabel("Image must be there!");
    MeNew->setAutoFillBackground(true);
    QPixmap Pix;
    Pix.load(":/img/darkMag.jpg");
    MeNew->resize(Pix.size());
    MeNew->setPixmap(Pix);
    MeNew->setStyleSheet("QLabel {border: 2px solid black}");

    QLabel *MeHeader = new QLabel(I->getName());
    MeInfo->addWidget(MeHeader);
    MeInfo->addWidget(MeNew,1,Qt::AlignLeft);

    MeInfo->addWidget(I->Info);
    Me->addLayout(MeInfo);

    QPushButton *MeAttack = new QPushButton("Атаковать");
    QPushButton *MeHeal = new QPushButton("Лечиться");


    Spell *Healing = new Spell("Исцеление","Излечивает игроку 30 единиц жизни.",16,0,30,0,0,0,0,0,0,0,0,2);
    Spell *Lightning = new Spell("Молния","Наносит по противнику 20 единиц\n урона. Подвержено ослабляю-\nщему влиянию защитой противника",12, 20,0,0,0,0,0,0,0,0,0,1);
    Spell *LifeGet = new Spell("Вытягивание жизни","Вытягивает из противника 12 \nединиц жизни и передает 8 из них \nигроку.",11,12,8,0,0,0,0,0,0,0,0,1);
    Spell *Curse = new Spell("Проклятье","Проклинает противника. Уменьшает \nего защиту на 2, удачу на 3 \nи атаку на 1.",17,0,0,-1,0,-2,0,-3,0,0,0,4);
    Spell *Firestorm = new Spell("Огненный смерч","Наносит мощнейший урон противнику - \n53 единицы урона",28,53,0,0,0,0,0,0,0,0,0,1);
    Spell *Exch = new Spell("Ритуал равновесия","Дает игроку 20 единиц маны.\nДает противнику 10 единиц жизни.",5,-10,0,0,0,0,0,0,0,0,20,2);
    Spell *DeMemorize = new Spell("Спутывание памяти","Наносит противнику 5 урона.\nУменьшает удачу противника на 2.\nУменьшает атаку противника на 5\nПротивник теряет 20 маны.",33,5,0,-5,0,0,0,-2,0,-20,0,4);
    Spell *EnergyRitual = new Spell("Ритуал энергии","Повышает атаку игрока на 1,\n защиту - на 2, удачу - на 3.",18,0,0,0,1,0,2,0,3,0,0,2);
    Spell *Destruction = new Spell("Коллапс материи","Коллапсирует на противника\n окружающий мир и наносит ему 90 урона.",41,90,0,0,0,0,0,0,0,0,0,1);
    Spell *FireRitual = new Spell("Огненный ритуал","Опасный ритуал, имеющий \nтемные корни. Наносит игроку \n40 единиц урона, повышает его атаку на 4 \nи удачу на 5",13,0,-40,0,4,0,0,0,5,0,0,2);
    Spell *Poisoning = new Spell("Отравление","Пускает облако ядовитого газа,\nкоторое наносит обоим игрокам\nпо 25 единиц урона.",15,25,-25,0,0,0,0,0,0,0,0,1);
    Spell *Stoning = new Spell("Окаменение","Повышает защиту противника на 13,\nпонижает его атаку на 15.\nНаносит противнику 20 урона.",29,20,0,-15,0,13,0,0,0,0,0,4);
    Spell *DarkBreathe = new Spell("Дыхание тьмы","Понижает удачу каждого \nигрока до нуля, понижает\nзащиту противника на 5,\nповышает атаку игрока на 6.",45,0,0,0,6,-5,0,-100,-100,0,0,4);
    Spell *Canal = new Spell("Энергетический канал","Дает игроку 15 единиц маны.",6,0,0,0,0,0,0,0,0,0,15,2);
    Spell *Envy = new Spell("Призыв ярости","Мгновенно увеличивает атаку\nигрока на 5.",24,0,0,0,5,0,0,0,0,0,0,2);
    Spell *Shield = new Spell("Энергетический щит","Создате вокруг игрока силовое\nполе, которое наносит противнику\n10 урона и повышает защиту игрока\nна 4.",22,10,0,0,0,0,4,0,0,0,0,2);
    Spell *CallToDark = new Spell("Призыв ко тьме","Наносит игроку 25 урона.\nПонижает атаку, защиту и удачу\nпротивника на 4.",26,0,-25,-4,0,-4,0,-4,0,0,0,4);
    Spell *LifeEnergy = new Spell("Энергия жизни","Излечивает игроку 130 единиц жизни.\nОтнимает всю имеющуюся у него ману.",48,0,130,0,0,0,0,0,0,0,-1000,2);
    Spell *ProtonArrow = new Spell("Протонная стрела","Наносит противнику 8 урона.\nПротивник лишается 5 маны.",4,8,0,0,0,0,0,0,0,-5,0,1);
    Spell *Burning = new Spell("Сожжение","Уменьшает защиту противника на 7.\nПротивник теряет 25 здоровья и 10 маны.",38,25,0,0,0,-6,0,0,0,-10,0,4);
    Spell *DarkTouch = new Spell("Прикосновение тьмы","Понижает атаку и защиту\nпротивника на 1",7,0,0,-1,0,-1,0,0,0,0,0,4);
    Spell *Freezing = new Spell("Заледенение","Наносит противнику 30 урона.\nЛишает противника всей его защиты.",39,30,0,0,0,-100,0,0,0,0,0,1);

    QVBoxLayout *SpellV = new QVBoxLayout();

    SpellDesc *Charm = new SpellDesc();


    SpellLabel *for1 = new SpellLabel(Healing,SpellV,I,Enemy);

    for1->setDesc(Charm);

    SpellLabel *for2 = new SpellLabel(Lightning, SpellV, I, Enemy);
    SpellLabel *for3 = new SpellLabel(LifeGet, SpellV, I, Enemy);
    SpellLabel *for4 = new SpellLabel(Curse,SpellV,I, Enemy);
    SpellLabel *for5 = new SpellLabel(Firestorm,SpellV,I,Enemy);
    SpellLabel *for6 = new SpellLabel(Exch,SpellV,I,Enemy);
    SpellLabel *for7 = new SpellLabel(DeMemorize,SpellV,I,Enemy);
    SpellLabel *for8 = new SpellLabel(EnergyRitual,SpellV,I,Enemy);

    QHBoxLayout *ShortSpells1 = new QHBoxLayout();
    QHBoxLayout *ShortSpells2 = new QHBoxLayout();
    QHBoxLayout *ShortSpells3 = new QHBoxLayout();


    ShortSpells1->addWidget(new SpellLabel(ProtonArrow,SpellV,I,Enemy),1,Qt::AlignLeft);
    ShortSpells1->addWidget(for3,1,Qt::AlignLeft);
    ShortSpells1->addWidget(for2,10,Qt::AlignLeft);
    ShortSpells1->addWidget(new SpellLabel(Poisoning,SpellV,I,Enemy),40,Qt::AlignLeft);
    ShortSpells1->addWidget(for5,80,Qt::AlignLeft);
    ShortSpells1->addWidget(new SpellLabel(Freezing,SpellV,I,Enemy),400,Qt::AlignLeft);
    ShortSpells1->addWidget(new SpellLabel(Destruction,SpellV,I,Enemy),900,Qt::AlignLeft);


    ShortSpells2->addWidget(for6,1,Qt::AlignLeft);
    ShortSpells2->addWidget(new SpellLabel(Canal,SpellV,I,Enemy),10,Qt::AlignLeft);
    ShortSpells2->addWidget(new SpellLabel(FireRitual,SpellV,I,Enemy),20,Qt::AlignLeft);
    ShortSpells2->addWidget(for1,30,Qt::AlignLeft);
    ShortSpells2->addWidget(for8,40,Qt::AlignLeft);
    ShortSpells2->addWidget(new SpellLabel(Shield,SpellV,I,Enemy),50,Qt::AlignLeft);
    ShortSpells2->addWidget(new SpellLabel(Envy,SpellV,I,Enemy),60,Qt::AlignLeft);
    ShortSpells2->addWidget(new SpellLabel(LifeEnergy,SpellV,I,Enemy),70,Qt::AlignLeft);

    ShortSpells3->addWidget(new SpellLabel(DarkTouch,SpellV,I,Enemy),1,Qt::AlignLeft);
    ShortSpells3->addWidget(for4,0,Qt::AlignLeft);
    ShortSpells3->addWidget(new SpellLabel(CallToDark,SpellV,I,Enemy),10,Qt::AlignLeft);
    ShortSpells3->addWidget(new SpellLabel(Stoning,SpellV,I,Enemy),40,Qt::AlignLeft);
    ShortSpells3->addWidget(for7,90,Qt::AlignLeft);
    ShortSpells3->addWidget(new SpellLabel(Burning,SpellV,I,Enemy),390,Qt::AlignLeft);
    ShortSpells3->addWidget(new SpellLabel(DarkBreathe,SpellV,I,Enemy),990,Qt::AlignLeft);

    SpellV->addLayout(ShortSpells1);
    SpellV->addLayout(ShortSpells2);
    SpellV->addLayout(ShortSpells3);
    SpellV->addLayout(Charm);

    Player::connect(MeAttack,&QPushButton::clicked,I,&Player::attack);
    Player::connect(MeHeal,&QPushButton::clicked,I,&Player::heal);
    I->setConnection(Enemy);
    Enemy->setConnection(I);

    QHBoxLayout *MeButtons = new QHBoxLayout;
    MeButtons->addWidget(MeAttack);
    MeButtons->addWidget(MeHeal);
    //MeButtons->addWidget(MeDefence);
    Me->addLayout(MeButtons);

    Me->addLayout(SpellV);


    QVBoxLayout *En = new QVBoxLayout();

    QVBoxLayout *EnemyInfo = new QVBoxLayout();
    QLabel *header = new QLabel(Enemy->getName());
    Enemy->Info->setText(Enemy->getChars());
    QLabel *img = new QLabel();
    QPixmap Px;
    Px.load(":/img/deathMag.jpg");
    img->setPixmap(Px);
    img->setStyleSheet("QLabel {border: 2px solid black}");
    header->setStyleSheet("QLabel {font-size:21px; color: #124;}");
    EnemyInfo->addWidget(header);
    EnemyInfo->addWidget(img,10,Qt::AlignTop);
    EnemyInfo->addWidget(Enemy->Info,1000,Qt::AlignLeft);

    En -> addLayout(EnemyInfo);




    Left->addLayout(Me);
    Left->addLayout(Center);
    Left->addLayout(En);
    //Left->setGeometry(QRect(0,100,300,500));

    w->setLayout(Left);

    Widget *Main=new Widget();

    Main->setCentralWidget(w);

    Main->show();
    QMenuBar *menu = Main->menuBar();

    QMenu *M = new QMenu("Cправка");
    M->addAction("Общая информация");
    M->addAction("Атака");
    M->addAction("Защита и лечение");
    M->addAction("Типы заклинаний");
    M->addAction("Колдовство и мана");

    QObject::connect(M,SIGNAL(triggered(QAction*)),I,SLOT(message(QAction*)));
    menu->addMenu(M);

    QMenu *generalInfo = new QMenu("Информация");
    generalInfo->addAction("О программе");
    QObject::connect(generalInfo,SIGNAL(triggered(QAction*)),I,SLOT(message(QAction*)));
    menu->addMenu(generalInfo);

    return a.exec();
}
