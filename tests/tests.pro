include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     \
    ../app/_text.h \
    ../app/text.h \
    ce_test.h \
    m_test.h \
    save_test.h \
    showwordbeginnings_test.h \
    y_test.h

SOURCES +=     main.cpp \
    ../app/save.c \
    ../app/m.c \
    ../app/y.c \
    ../app/showwordbeginnings.c \
    ../app/ce.c \
    ../app/y_line.c \
    ../app/process_forward.c \
    ../app/moving.c \
    ../app/line_to_end.c \
    ../app/append_line.c 

INCLUDEPATH += ../app

DISTFILES +=
