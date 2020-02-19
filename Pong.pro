TEMPLATE = subdirs

SUBDIRS +=  \
    app \
    src \
    unitTest

app.depends = src
unitTest.depends = src
