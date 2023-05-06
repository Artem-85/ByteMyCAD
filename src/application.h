#ifndef BMC_APPLICATION_H
#define BMC_APPLICATION_H

#include <QApplication>
#include <QSettings>

/**
 * @brief Contains main application data
 */
class BMC_Application : public QApplication
{
    Q_OBJECT
public:
    BMC_Application(int &argc, char **argv, int flags = ApplicationFlags);
    ~BMC_Application();

    /**
     * @brief Initialize application
     */
    void init();
private:

    /**
     * @brief Stores application settings
     */
    QSettings *settings;
};

#endif // BMC_APPLICATION_H
