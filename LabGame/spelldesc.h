#ifndef SPELLDESC_H
#define SPELLDESC_H

#include <QObject>
#include <QWidget>
#include "spellbutton.h"

class SpellDesc:public QVBoxLayout
{
    Q_OBJECT
public:
    SpellDesc();

    QLabel *name;
    QLabel *img;
    QLabel *price;
    QHBoxLayout *mainL;
    QVBoxLayout *left;
    QVBoxLayout *right;
    QLabel *descr;
    SpellButton *btn;

    ~SpellDesc();
};

#endif // SPELLDESC_H
