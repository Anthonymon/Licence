QT += widgets
QT += opengl

LIBS += -lglut -lGLU

CONFIG +=link_pkgconfig

PKGCONFIG += gtkmm-3.0

SOURCES += \
	src/main.cc \
	src/complex.cc \
	src/menu.cc \
	src/ongletChoix.cc \
	src/ongletVide.cc \
	src/fractale.cc \
	src/mandelbrot.cc \
	src/juliaFatou.cc \
	src/fenetreMandelbrotGL.cc \
	src/fenetreJuliaFatouGL.cc \
	src/abstractFenetreGL.cc \
	src/enregistreurFractale.cc \
	src/dessinFractaleGL.cc \
	src/abstractDessin.cc \
	
HEADERS += \
	head/types.hh \
	head/complex.hh \
	head/menu.hh \
	head/ongletChoix.hh \
	head/ongletVide.hh \
	head/fractale.hh \
	head/mandelbrot.hh \
	head/juliaFatou.hh \
	head/fenetreMandelbrotGL.hh \
	head/fenetreJuliaFatouGL.hh \
	head/abstractFenetreGL.hh \
	head/enregistreurFractale.hh \
	head/dessinFractaleGL.hh \
	head/abstractDessin.hh \
