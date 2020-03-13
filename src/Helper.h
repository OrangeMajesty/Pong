#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QtOpenGL>

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = nullptr);
    void drawText(QString);

private:
    struct Character {
        GLuint     TextureID;  // ID handle of the glyph texture
        GLuint*     Size;       // Size of glyph
        GLuint*     Bearing;    // Offset from baseline to left/top of glyph
        GLuint     Advance;    // Offset to advance to next glyph
    };

    std::map<GLchar, Character> Characters;

signals:

};

#endif // HELPER_H
