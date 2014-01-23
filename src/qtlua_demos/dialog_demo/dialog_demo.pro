TEMPLATE = app
TARGET = dialog_demo
DEPENDPATH += 
INCLUDEPATH += . \
               /usr/local/include

# Input
HEADERS += 
SOURCES += dialog_demo.cpp
LIBS += -L/usr/local/lib/ -lqtlua 
QMAKE_CXXFLAGS += -fpermissive
