#ifndef MEMO
#define MEMO
#include <QWidget>
#include <QTextEdit>
#include "player.h"

class Memo : public QTextEdit
{
    Q_OBJECT

public:
    explicit Memo(QTextEdit *parent = 0);


private:

};

#endif // MEMO

