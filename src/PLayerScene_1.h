#ifndef PLAYERSCENE_1_H
#define PLAYERSCENE_1_H

#include <QObject>
#include "PLayer.h"

/**
 * @brief The PLayerScene_1 class.
 */
class PLayerScene_1 : public PLayer
{
    Q_OBJECT
public:
    /// Configures objects and text at the level
    PLayerScene_1(QObject *parent = nullptr);

    /// Method for rendering text at the level
    void drawTextArray(QPainter*) override;

    /// Keystroke handler
    void keyUpdate() override;

    /// Level reload method
    void layerReset() override;

public slots:
    /// Level Reload Handler
    void winLose(QVector3D);
};

#endif // PLAYERSCENE_1_H
