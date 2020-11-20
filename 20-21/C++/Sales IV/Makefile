.POSIX:

SRC = main.cpp
OBJ = main.o
BIN = sales4
CXXFLAGS = -Os
#LDFLAGS =

all: clean ${BIN}

${BIN}: ${OBJ}
	${CXX} -o ${BIN} ${OBJ} ${LDFLAGS}

${OBJ}: ${SRC}
	${CXX} -c ${SRC} ${CXXFLAGS}

clean:
	rm -f ${OBJ} ${BIN}
