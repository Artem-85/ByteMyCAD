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
     * @brief Initialize application.
     */
    void init();

    /**
     * @brief Get pointer to the application settings.
     * @return @ref settings.
     */
    QSettings *getSettings() { return settings; }

    void writeSettings() {};

    void readSettings() {};
private:

    void createActions();

    void cleanUp();

    /**
     * @brief Stores application settings
     */
    QSettings *settings;
};

#endif // BMC_APPLICATION_H
