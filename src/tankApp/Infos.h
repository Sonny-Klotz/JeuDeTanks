#ifndef INFOS_H
#define INFOS_H

#include <QLabel>
#include <QString>

/*!
 * \brief Widget contenant les informations d'un tank
 */
class Infos : public QLabel
{
public:
    Infos(QWidget *parent = 0);
};

#endif // INFOS_H
