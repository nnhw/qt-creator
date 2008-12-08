TEMPLATE = lib
TARGET = CppTools
include(../../qworkbenchplugin.pri)
include(../../plugins/quickopen/quickopen.pri)
include(cpptools_dependencies.pri)

# DEFINES += QT_NO_CAST_FROM_ASCII
DEFINES += QT_NO_CAST_TO_ASCII
unix:QMAKE_CXXFLAGS_DEBUG += -O3
INCLUDEPATH += .
DEFINES += CPPTOOLS_LIBRARY
CONFIG += help

HEADERS += cpptools_global.h \
    cppquickopenfilter.h \
    cppclassesfilter.h \
    searchsymbols.h
SOURCES += cppquickopenfilter.cpp \
    cpptoolseditorsupport.cpp \
    cppclassesfilter.cpp \
    searchsymbols.cpp

# Input
SOURCES += cpptools.cpp \
    cppmodelmanager.cpp \
    cppcodecompletion.cpp \
    cpphoverhandler.cpp
HEADERS += cpptools.h \
    cppmodelmanager.h \
    cppcodecompletion.h \
    cpphoverhandler.h \
    cppmodelmanagerinterface.h \
    cpptoolseditorsupport.h \
    cpptoolsconstants.h
RESOURCES += cpptools.qrc
