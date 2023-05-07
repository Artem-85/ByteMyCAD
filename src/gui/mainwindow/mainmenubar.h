#ifndef BMC_MAINMENUBAR_H
#define BMC_MAINMENUBAR_H

#include <QMenuBar>

class BMC_Menu;

class BMC_MainMenuBar : public QMenuBar
{
    Q_OBJECT
public:
    BMC_MainMenuBar(QWidget *parent);
    BMC_Menu *addMenu(const QString &title);
};

#endif // BMC_MAINMENUBAR_H
