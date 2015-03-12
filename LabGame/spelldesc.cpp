#include "spelldesc.h"



SpellDesc::SpellDesc()
{
    this->name = new QLabel("Имя");
    this->img = new QLabel("Картинка");
    this->price = new QLabel("Цена");
    this->left = new QVBoxLayout();
    this->img->setStyleSheet("QLabel {border: 2px solid #146;}");
    this->name->setStyleSheet("QLabel {font-size: 15px; color: #023;}");
    this->price->setStyleSheet("QLabel {color: #069}");
    this->addWidget(this->name);
    this->left->addWidget(this->img,1,Qt::AlignLeft);
    this->left->addWidget(this->price);

    this->right = new QVBoxLayout();
    this->descr = new QLabel("Описание заклинания");
    this->btn = new SpellButton("Колдовать!");
    this->right->addWidget(this->descr);
    this->right->addWidget(this->btn);
    this->mainL = new QHBoxLayout();
    this->mainL->addLayout(this->left);
    this->mainL->addLayout(this->right);
    this->addLayout(this->mainL);
}

SpellDesc::~SpellDesc()
{

}


