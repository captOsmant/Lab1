#include "spellbutton.h"
SpellButton::SpellButton(){}
SpellButton::SpellButton(char *val):QPushButton(val)
{

}

SpellButton::~SpellButton()
{

}

void SpellButton::transferAttack(bool p){
    emit initiateAttack(this->name,this->price,this->damage,this->heal,this->Eattack,this->Mattack,this->Edefence,this->Mdefence,this->Eluck,this->Mluck,this->Emana,this->Mmana);
}
