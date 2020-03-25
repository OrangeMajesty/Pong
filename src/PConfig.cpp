#include "PConfig.h"

/**
 * @brief PConfig::getKeysControl
 * @return array keys
 */
QMap<PConfig::key, int> PConfig::getKeysControl() const
{
    return keysControl;
}

/**
 * @brief PConfig::setKeysControl
 * @param keys
 */
void PConfig::setKeysControl(const QMap<key, int> &value)
{
    keysControl = value;
}
