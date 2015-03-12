#ifndef SPELLBUTTON_H
#define SPELLBUTTON_H

#include <QObject>
#include <QtWidgets>

class SpellButton:public QPushButton
{
    Q_OBJECT
public:
    QString name;
    QString description;
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
     int price;
     int type;
    SpellButton();
    SpellButton(char* val);
    ~SpellButton();
signals:

    void initiateAttack(QString, int,int,int,int,int,int,int,int,int,int,int);


public slots:
    void transferAttack(bool p);
};

#endif // SPELLBUTTON_H
