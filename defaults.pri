QT += opengl
LIBS += -lglu32 -lopengl32
INCLUDEPATH += $$PWD/src

LIBS += -L$$PWD/src/debug -lpong

## Include SFML 2.5.1
LIBS += -LD:\ProjectsC++\library\SFML-2.5.1\lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += D:\ProjectsC++\library\SFML-2.5.1\include
DEPENDPATH += D:\ProjectsC++\library\SFML-2.5.1\include

## Include OpenGL GLUT 3.7
LIBS += -LD:\ProjectsC++\library\glut-3.7\lib

#LIBS += -lglut

INCLUDEPATH += D:\ProjectsC++\library\glut-3.7\include
DEPENDPATH += D:\ProjectsC++\library\glut-3.7\include

### Include GLEW 2.1
#LIBS += -LD:\ProjectsC++\library\glew-2.1.0\lib\Release\x64

#LIBS += -lglew32 -lglu32

#INCLUDEPATH += D:\ProjectsC++\library\glew-2.1.0\include
#DEPENDPATH += D:\ProjectsC++\library\glew-2.1.0\include

### Include GLFW 3.3.2
#LIBS += -LD:\ProjectsC++\library\glfw-3.3.2\lib-mingw-w64

#LIBS += -lglfw3 -lgdi32

#INCLUDEPATH += D:\ProjectsC++\library\glfw-3.3.2\include
#DEPENDPATH += D:\ProjectsC++\library\glfw-3.3.2\include
