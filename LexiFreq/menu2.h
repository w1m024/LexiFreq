#ifndef MENU2_H
#define MENU2_H

#include <QWidget>
#include "menu.h"

namespace Ui {
class Menu2;
}

class Menu2 : public QWidget
{
    Q_OBJECT

public:
    explicit Menu2(Menu* MENU = nullptr,QWidget *parent = 0);
    ~Menu2();

private slots:
    void on_AddButton_clicked();

    void on_ChaButton_clicked();

    void on_BackButton2_clicked();

private:
    Ui::Menu2 *ui;
    Menu* MENU;
};

#endif // MENU2_H
