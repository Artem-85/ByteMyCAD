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

    /**
     * @brief Detect the application locale
     * @details Application locale is setup following these steps:
     * 1. Read latesl locale from app settings;
     * 2. Use system locale if no app settings found;
     * 3. Use en_US if no translation matching the system locale is found.
     */
    void setAppLocale();

    /**
     * @brief Get abbreviation for the app's locale.
     * @return
     */
    QString &getAppLocaleName() { return localeName; };

    void writeSettings();

    void readSettings();
private:

    void createActions();

    void cleanUp();

    /**
     * @brief Stores application settings
     */
    QSettings *settings;

    QLocale *locale;

    QTranslator *translator;

    QString localeName;
};

#endif // BMC_APPLICATION_H
