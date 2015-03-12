#ifndef PLAYER
#define PLAYER
#include <QtWidgets>

class Player: public QObject{

    Q_OBJECT

private:
    int damage;
    int health;
    int mana;
    int defence;   
    char* name;
    int luck;
    bool bot;

    QTextEdit *Memo;
    int restoreMana;

public:
    QLabel *Info;

    Player(int d,int h,int m,int df,char* n, int l, bool p,QTextEdit &M);
    QString getChars();
    char* intToCh(int n);
    char* getName();
    void setConnection(Player *obj);
    void die();

public slots:
    void attack(bool p);
    void beAttacked(int damage,int Eattack, int Edefence, int Eluck, int Emana);
    void heal();
    void message(QAction*);
    void spellAttack(QString nm, int price, int damage, int heal, int Eattack, int Mattack, int Edefence, int Mdefence, int Eluck, int Mluck, int Emana, int Mmana);
signals:
    void laidDamage(int,int,int,int,int);

};

#endif // PLAYER
