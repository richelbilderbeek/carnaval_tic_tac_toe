#include "game_dialog.h"
#include "ui_game_dialog.h"
#include <QMouseEvent>

game_dialog::game_dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::game_dialog)
{
  ui->setupUi(this);

  ui->beer_bl->setVisible(false);
  ui->beer_bm->setVisible(false);
  ui->beer_br->setVisible(false);
  ui->beer_ml->setVisible(false);
  ui->beer_mm->setVisible(false);
  ui->beer_mr->setVisible(false);
  ui->beer_tl->setVisible(false);
  ui->beer_tm->setVisible(false);
  ui->beer_tr->setVisible(false);
}

game_dialog::~game_dialog()
{
  delete ui;
}

void game_dialog::mousePressEvent(QMouseEvent *event)
{
  if (event->x() < this->width() / 3)
  {
    if (event->y() < this->height() / 3)
    {
      ui->beer_tl->setVisible(true);
    }
    else if (event->y() < 2 * this->height() / 3)
    {
      ui->beer_ml->setVisible(true);
    }
    else
    {
      ui->beer_bl->setVisible(true);
    }
  }
  else if (event->x() < 2 * this->width() / 3)
  {
    if (event->y() < this->height() / 3)
    {
      ui->beer_tm->setVisible(true);
    }
    else if (event->y() < 2 * this->height() / 3)
    {
      ui->beer_mm->setVisible(true);
    }
    else
    {
      ui->beer_bm->setVisible(true);
    }
  }
  else
  {
    if (event->y() < this->height() / 3)
    {
      ui->beer_tr->setVisible(true);
    }
    else if (event->y() < 2 * this->height() / 3)
    {
      ui->beer_mr->setVisible(true);
    }
    else
    {
      ui->beer_br->setVisible(true);
    }
  }
}
