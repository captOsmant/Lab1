#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>


class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit    Widget(QMainWindow *parent = 0);
    ~Widget();

private:

};

#endif // WIDGET_H
