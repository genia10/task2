TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    ce.c \
    line_to_end.c \
    m.c \
    moving.c \
    process_forward.c \
    save.c \
    showwordbeginnings.c \
    y.c \
    y_line.c \
    append_line.c 

 
HEADERS += \
    text.h\
    _text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DISTFILES += \
    ../tests/shwb
