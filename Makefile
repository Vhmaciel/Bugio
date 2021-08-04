CCPP= g++
CC= gcc
CCFLAGS= -Wall -W
LIBS= -L/usr/lib -lrt
THREADLIB= -pthread
SRC= src/
OBJ= cell.o kernel.o

all: init main

main: $(SRC)main.cpp kernel.o
	$(CCPP) $(SRC)main.cpp obj/kernel.o -o bin/Bugio $(LIBS) $(THREADLIB) $(CCFLAGS)

kernel.o: $(SRC)kernel.cpp $(SRC)kernel.h cell.o
	$(CCPP) $(SRC)kernel.cpp obj/cell.o -o obj/kernel.o -c $(CCFLAGS) $(LIBS) $(THREADLIB)

cell.o: $(SRC)cell.cpp $(SRC)cell.h
	$(CCPP) $(SRC)cell.cpp -o obj/cell.o -c $(CCFLAGS) $(LIBS) $(THREADLIB)

clean:
	rm -f obj/*.o $(OBJ) bin/*

init:
	mkdir -p bin obj
