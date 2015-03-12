#include "spell.h"
Spell::Spell(){

}

Spell::Spell(QString n, QString ds, int pr, int d, int h, int ea, int ma, int ed, int md, int el, int ml, int em, int mm, int t):
    name(n),
    description(ds),
    price(pr),
    damage(d),
    heal(h),
    Eattack(ea),
    Mattack(ma),
    Edefence(ed),
    Mdefence(md),
    Eluck(el),
    Mluck(ml),
    Emana(em),
    Mmana(mm),
    type(t),
    Layer(new QFormLayout)
{}

Spell::~Spell()
{

}

void Spell::fill(QHBoxLayout *Layer, Player *I, Player *Enemy){
    Enemy;
    QLabel *Img = new QLabel();
    QString filename = QString(":/img/").append(this->name);
    filename.append(".jpg");

    QPixmap *im = new QPixmap(filename);
    Img->setPixmap(*im);
    QVBoxLayout *General = new QVBoxLayout();
    QLabel *Name = new QLabel(this->name);
    Name->setStyleSheet("QLabel {font-size: 20px; color: #115}");
    QString price = QString("Цена: ").append(QString::number(this->price));
    QLabel *Price = new QLabel(price);
    Price->setStyleSheet("QLabel {color: #103090;}");
    Img->setStyleSheet("QLabel {border: 2px solid #117}");
    General->addWidget(Name);
    General->addWidget(Img,1,Qt::AlignLeft);
    General->addWidget(Price);

    QVBoxLayout *SpellInfo = new QVBoxLayout();

    QLabel *SpellD = new QLabel(this->description);
    SpellButton *Act = new SpellButton("Колдовать");

    Act->name=this->name;
    Act->price=this->price;
    Act->damage=this->damage;
    Act->heal=this->heal;
    Act->Eattack=this->Eattack;
    Act->Mattack=this->Mattack;
    Act->Edefence=this->Edefence;
    Act->Mdefence=this->Mdefence;
    Act->Eluck=this->Eluck;
    Act->Mluck=this->Mluck;
    Act->Emana=this->Emana;
    Act->Mmana=this->Mmana;
    Act->type = this->type;
    QObject::connect(Act,SIGNAL(clicked(bool)),Act,SLOT(transferAttack(bool)));
    QObject::connect(Act,SIGNAL(initiateAttack(QString,int,int,int,int,int,int,int,int,int,int,int)),I,SLOT(spellAttack(QString,int,int,int,int,int,int,int,int,int,int,int)));
    //QObject::connect(Act,SIGNAL(spellType2(QString,int)),I,SLOT(spellHeal(QString,int)));

    SpellInfo->addWidget(SpellD);
    SpellInfo->addWidget(Act);

    Layer->addLayout(General,10);
    Layer->addLayout(SpellInfo);



}
void Spell::fillSD(SpellDesc *Layer, Player *Me, Player *Enemy){

    Layer->descr->setText(this->description);
    Layer->name->setText(this->name);
    Layer->price->setText(QString("Цена: ").append(QString::number(this->price)));
    QPixmap *im = new QPixmap(QString(":/img/").append(this->name).append(QString(".jpg")));
    Layer->img->setPixmap(*im);
    Layer->right->removeWidget((QPushButton*)Layer->btn);
    delete Layer->btn;
    Layer->btn=new SpellButton("Колдовать!");

    Layer->btn->name=this->name;
    Layer->btn->price=this->price;
    Layer->btn->damage=this->damage;
    Layer->btn->heal=this->heal;
    Layer->btn->Eattack=this->Eattack;
    Layer->btn->Mattack=this->Mattack;
    Layer->btn->Edefence=this->Edefence;
    Layer->btn->Mdefence=this->Mdefence;
    Layer->btn->Eluck=this->Eluck;
    Layer->btn->Mluck=this->Mluck;
    Layer->btn->Emana=this->Emana;
    Layer->btn->Mmana=this->Mmana;
    Layer->btn->type = this->type;
    Layer->right->addWidget(Layer->btn);
    QObject::disconnect(Layer->btn,SIGNAL(clicked(bool)),Layer->btn,NULL);
    QObject::connect(Layer->btn,SIGNAL(clicked(bool)),Layer->btn,SLOT(transferAttack(bool)));
    QObject::connect(Layer->btn,SIGNAL(initiateAttack(QString,int,int,int,int,int,int,int,int,int,int,int)),Me,SLOT(spellAttack(QString,int,int,int,int,int,int,int,int,int,int,int)));

}
