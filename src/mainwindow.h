/**
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    /**
     * @brief Generate GUI objects and populate them in the main window
     *
     */
    void Populate();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
