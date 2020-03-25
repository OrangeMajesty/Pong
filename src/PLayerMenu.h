#ifndef PLAYERMENU_H
#define PLAYERMENU_H

#include <QObject>
#include "PLayer.h"

/**
 * @brief The PLayerMenu class.
 */
class PLayerMenu : public PLayer
{
    Q_OBJECT
public:
    /// Configures objects and text at the level
    PLayerMenu(QObject *parent = nullptr);

    /// Method for rendering text at the level
    void drawTextArray(QPainter*) override;

    /// Keystroke handler
    void keyUpdate() override;
};

#endif // PLAYERMENU_H
