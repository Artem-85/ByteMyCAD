#ifndef BMC_MDI_H
#define BMC_MDI_H

#include <QMdiArea>

class BMC_MDI : public QMdiArea
{
    Q_OBJECT
public:
    /**
     * @brief Main constructor
     * @param parent
     */
    BMC_MDI(QWidget *parent);
};

#endif // BMC_MDI_H
