/**
 * @file mainwindow.h
 * @brief Declaration of BMC_MainWindow class.
 * @author Artem Plyusnin
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class BMC_MDI;
class BMC_MainMenuBar;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The main window of the application
 *
 */
class BMC_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    BMC_MainWindow(QWidget *parent = nullptr);
    ~BMC_MainWindow();

    void writeSettings();

    void readSettings();

private:
    /**
     * @brief Generate GUI objects and populate them in the main window
     *
     */
    void init();

    /**
     * @brief Create and connect signals
     */
    void createActions();

    void createMainMenu();

    void openSettingsWindow();

    /****** Events ******/
    /**
     * @brief The code called on closing the main window.
     * @param event
     */
    void closeEvent(QCloseEvent *event);
    /****** /Events ******/

    /****** GUI elements ******/
    /**
     * @brief Automatically generated UI object
     */
    Ui::MainWindow *ui;

    BMC_MDI *mdiArea;

    BMC_MainMenuBar *mainMenuBar;
    /****** /GUI elements ******/

    /****** Actions ******/
    QAction *actionQuit;
    QAction *actionSettings;
    /****** /Actions ******/
};
#endif // MAINWINDOW_H
