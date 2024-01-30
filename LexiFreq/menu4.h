#ifndef MENU4_H
#define MENU4_H

#include <QWidget>
#include "menu.h"

namespace Ui {
class Menu4;
}

class Menu4 : public QWidget
{
    Q_OBJECT

public:
    explicit Menu4(Menu* MENU = nullptr,QWidget *parent = 0);
    ~Menu4();

private slots:
    void on_CountBuutton_clicked();

    void on_SearchButton_clicked();

    void on_BackButton4_clicked();

private:
    Ui::Menu4 *ui;
    Menu* MENU;
};

#endif // MENU4_H
