#ifndef SPELL_H
#define SPELL_H

#include <QtWidgets>
#include "player.h"
#include "spelldesc.h"
class Spell:public QObject
{
    Q_OBJECT
private:


public:
    QString name;
    QString description;
    int price;
    int damage;
    int heal;
    int Eattack;
    int Mattack;
    int Edefence;
    int Mdefence;
    int Eluck;
    int Mluck;
    int Emana;
    int Mmana;
    int type;
    QFormLayout *Layer;
    Spell();
    Spell(QString n,QString ds,int pr, int d, int h, int ea, int ma, int ed, int md, int el, int ml, int em, int mm, int t);

    void fill(QHBoxLayout *Layer, Player *Me, Player *Enemy);
    void fillSD(SpellDesc *Layer, Player *Me, Player *Enemy);
    ~Spell();

signals:
    void launch();
};

#endif // SPELL_H
