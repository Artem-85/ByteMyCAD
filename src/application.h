#ifndef BMC_APPLICATION_H
#define BMC_APPLICATION_H

#include <QApplication>

/**
 * @brief Contains main application data
 */
class BMC_Application : public QApplication
{
    Q_OBJECT
public:
    BMC_Application(int &argc, char **argv, int flags = ApplicationFlags);
};

#endif // BMC_APPLICATION_H
