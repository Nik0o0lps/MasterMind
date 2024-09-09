QT += widgets

HEADERS += \
    boardpart.h \
    holereview.h \
    secrethole.h \
    board.h \
    coloritem.h \
    graphicsview.h \
    mainwindow.h \
    boardbutton.h \
    boarddesign.h \
    codinghole.h \
    boardsecret.h

SOURCES += \
    boardpart.cpp \
    codinghole.cpp \
    holereview.cpp \
    secrethole.cpp \
    board.cpp \
    coloritem.cpp \
    main.cpp \
    graphicsview.cpp \
    mainwindow.cpp \
    boardbutton.cpp \
    boarddesign.cpp \
    boardsecret.cpp

RESOURCES += \
    mastermind.qrc

DISTFILES +=

FORMS += \
    board.ui \
    boardbutton.ui \
    boarddesign.ui \
    boardpart.ui \
    boardsecret.ui \
    codinghole.ui \
    coloritem.ui \
    graphicsview.ui \
    holereview.ui \
    mainwindow.ui \
    secrethole.ui
