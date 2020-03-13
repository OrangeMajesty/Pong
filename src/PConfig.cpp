#include "PConfig.h"

PConfig::PConfig(QObject *parent) : QObject(parent)
{
}

QMap<PConfig::key, int> PConfig::getKeysControl() const
{
    return keysControl;
}

void PConfig::setKeysControl(const QMap<key, int> &value)
{
    keysControl = value;
}
