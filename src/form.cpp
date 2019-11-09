#include "player.h"
#include "ui_form.h"

Player::Player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);
}

Player::~Player()
{
    delete ui;
}
