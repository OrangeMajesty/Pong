#ifndef PCONFIG_H
#define PCONFIG_H

#include <QObject>
#include <QMap>

/**
 * @brief The PConfig class.
 *      Defines gameplay settings.
 *
 * @warning Used only for player.
 * @todo Add the ability to save and load data.
 */
class PConfig : public QObject
{
    Q_OBJECT
public:
    explicit PConfig(QObject *parent = nullptr) {};

    /// Available control keys
    enum key {
        Up,
        Down
    };

    /// Method for obtaining control keys
    QMap<key, int> getKeysControl() const;

    /// Method for setting control keys
    void setKeysControl(const QMap<key, int> &value);

private:

    /// Control keys
    QMap<key, int> keysControl;

};

#endif // PCONFIG_H
