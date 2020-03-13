#ifndef PCONFIG_H
#define PCONFIG_H

#include <QObject>
#include <QMap>

class PConfig : public QObject
{
    Q_OBJECT
public:
    explicit PConfig(QObject *parent = nullptr);

    enum key {
        Up,
        Down
    };

    QMap<key, int> getKeysControl() const;
    void setKeysControl(const QMap<key, int> &value);

private:
    QMap<key, int> keysControl;

signals:

};

#endif // PCONFIG_H
