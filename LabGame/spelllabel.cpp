#include "spelllabel.h"
#include "spell.h"
SpellLabel::SpellLabel(Spell *base, QVBoxLayout *Parent, Player* I, Player *Enemy):
    base(base),

    Parent(Parent),
    I(I),
    Enemy(Enemy)
{
    QString filename = QString(":/img/");
    filename.append(QString(base->name));
    filename.append("-min.jpg");

    QPixmap pm = QPixmap(filename);
    this->setPixmap(pm);
    if(base->type==1)
    this->setStyleSheet("SpellLabel {border: 2px solid #FF4500;}");

    if(base->type==2){
        this->setStyleSheet("SpellLabel {border: 2px solid #00CD00;}");
    }
    if(base->type==3) this->setStyleSheet("SpellLabel {border: 2px solid #00C5CD;}");
    if (base->type==4) this->setStyleSheet("SpellLabel {border: 2px solid #9400D3;}");
    this->setAlignment(Qt::AlignTop);
    //this->setMouseTracking(true);

    QObject::connect(this,SIGNAL(clicked()),this,SLOT(sendAttack()));
    QObject::connect(this,SIGNAL(spellAtk(QString,int,int,int,int,int,int,int,int,int,int,int)),I,SLOT(spellAttack(QString,int,int,int,int,int,int,int,int,int,int,int)));
}

SpellLabel::~SpellLabel()
{

}
SpellDesc* SpellLabel::Desc;

void SpellLabel::setDesc(SpellDesc *d){
    this->Desc=d;
}

void SpellLabel::enterEvent(QEvent *e){
    this->base->fillSD(this->Desc,I,Enemy);

}

void SpellLabel::mouseReleaseEvent(QMouseEvent *e){
    emit clicked();
}
void SpellLabel::sendAttack(){
    emit spellAtk(this->base->name,this->base->price,this->base->damage,this->base->heal,this->base->Eattack,this->base->Mattack,this->base->Edefence,this->base->Mdefence,this->base->Eluck, this->base->Mluck, this->base->Emana, this->base->Mmana);
}
