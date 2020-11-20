.POSIX:

# Simple makefile to build main.cpp and produce an executable 'sales3'.

SRC = main.cpp
OBJ = main.o
BIN = sales3

#CXXFLAGS =
#LDFLAGS =

all: clean ${BIN}

${BIN}: ${OBJ}
	$(CXX) ${OBJ} -o ${BIN} ${LDFLAGS}

${OBJ}: ${SRC}
	$(CXX) -c ${SRC} ${CXXFLAGS}

clean:
	rm -f ${BIN} ${OBJ}
