#include "mainmenubar.h"
#include "menu.h"

BMC_MainMenuBar::BMC_MainMenuBar(QWidget *parent)
    : QMenuBar(parent)
{

}

BMC_Menu *BMC_MainMenuBar::addMenu(const QString &title)
{
    return static_cast<BMC_Menu *>(QMenuBar::addMenu(title));
}
