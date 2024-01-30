#ifndef MENU3_H
#define MENU3_H

#include <QWidget>
#include "menu.h"

namespace Ui {
class Menu3;
}

class Menu3 : public QWidget
{
    Q_OBJECT

public:
    explicit Menu3(Menu* MENU = nullptr,QWidget *parent = 0);
    ~Menu3();

private slots:
    void on_LinearButton_clicked();

    void on_LinkedButton_clicked();

    void on_BackButton3_clicked();

private:
    Ui::Menu3 *ui;
    Menu* MENU;
};

#endif // MENU3_H
