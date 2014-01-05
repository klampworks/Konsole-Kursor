TEMPLATE = app
TARGET = 
DEPENDPATH += 
INCLUDEPATH += . \
               /usr/local/include

# Input
HEADERS += 
SOURCES += qtlua_test.cpp
LIBS += -L/usr/local/lib/ -lqtlua 
QMAKE_CXXFLAGS += -fpermissive
