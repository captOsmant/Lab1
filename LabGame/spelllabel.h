#ifndef SPELLLABEL_H
#define SPELLLABEL_H

#include <QObject>
#include <QWidget>
#include "player.h"
#include "spell.h"
#include "spelldesc.h"

class SpellLabel:public QLabel
{
    Q_OBJECT

public:
    Spell *base;
    QHBoxLayout *Lay;
    QVBoxLayout *Parent;
    Player *I, *Enemy;
    SpellLabel();
    void enterEvent(QEvent *e);
    void mousePressEvent(QEvent *e);
    static SpellDesc *Desc;

    void setDesc(SpellDesc *d);
    SpellLabel(Spell *base, QVBoxLayout *Parent, Player* I, Player* Enemy);
    ~SpellLabel();
};

#endif // SPELLLABEL_H
