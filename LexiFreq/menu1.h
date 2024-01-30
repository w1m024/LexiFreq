#ifndef MENU1_H
#define MENU1_H

#include <QWidget>
#include "menu.h"

namespace Ui {
class Menu1;
}

class Menu1 : public QWidget
{
    Q_OBJECT

public:
    explicit Menu1(Menu* MENU = nullptr,QWidget *parent = 0);
    ~Menu1();

private slots:
    void on_SSearchButton_clicked();

    void on_BSearchButton_clicked();

    void on_BackButton1_clicked();

private:
    Ui::Menu1 *ui;
    Menu* MENU;
};

#endif // MENU1_H
