# ! [0]
HEADERS = shoppinglistform.h

# ! [0] #! [1]
FORMS = shoppinglistform.ui \
    itemFrame.ui

# ! [1]
SOURCES = shoppinglistform.cpp \
    main.cpp

TARGET = shoppinglist

QT       += core gui

unix {
  #VARIABLES
  isEmpty(PREFIX) {
    PREFIX = /usr
  }
  BINDIR = $$PREFIX/bin
  DATADIR =$$PREFIX/share

  DEFINES += DATADIR=\"$$DATADIR\" \
             PKGDATADIR=\"$$PKGDATADIR\"

  #MAKE INSTALL

  INSTALLS += target desktop service iconxpm icon26 icon48 icon64

  target.path =$$BINDIR

  desktop.path = $$DATADIR/applications/hildon
  desktop.files += ../data/$${TARGET}.desktop

  service.path = $$DATADIR/dbus-1/services
  service.files += ../data/org.indt.$${TARGET}.service

  iconxpm.path = $$DATADIR/pixmap
  iconxpm.files += ../data/$${TARGET}.xpm

  icon26.path = $$DATADIR/icons/hicolor/26x26/apps
  icon26.files += ../data/26x26/$${TARGET}.png

  icon48.path = $$DATADIR/icons/hicolor/48x48/apps
  icon48.files += ../data/48x48/$${TARGET}.png

  icon64.path = $$DATADIR/icons/hicolor/64x64/apps
  icon64.files += ../data/64x64/$${TARGET}.png
}

TEMPLATE = app

CONFIG += mobility
MOBILITY =

symbian {
    TARGET.UID3 = 0xefecf024
    # TARGET.CAPABILITY +=
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
