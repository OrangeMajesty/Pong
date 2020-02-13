TEMPLATE = subdirs

SUBDIRS +=  \
    src/src.pro \
    unitTest/unitTest.pro


app.subdir = src/
tests.subdir = unitTest/

app.depends = src test
