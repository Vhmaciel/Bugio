CCPP= g++
CC= gcc
CCFLAGS= -Wall -W -pedantic -std=c++17
LIBS= -L/usr/lib -lrt -lstdc++fs 
THREADLIB= -pthread
SRC= src/
OBJ= cell.o kernel.o

all: init bugio

bugio: main.o kernel.o
	$(CCPP) obj/main.o obj/kernel.o -o bin/Bugio

main.o: $(SRC)main.cpp $(SRC)kernel.h
	$(CCPP) $(SRC)main.cpp -o obj/main.o -c $(THREADLIB) $(CCFLAGS) $(LIBS)

kernel.o: $(SRC)kernel.cpp $(SRC)kernel.h $(SRC)cell.h
	$(CCPP) $(SRC)kernel.cpp -o obj/kernel.o -c $(CCFLAGS) $(THREADLIB) $(LIBS)

cell.o: $(SRC)cell.cpp $(SRC)cell.h
	$(CCPP) $(SRC)cell.cpp -o obj/cell.o -c $(CCFLAGS)

domino: $(SRC)domino.cpp
	$(CCPP) $(SRC)domino.cpp -o bin/domino $(CCFLAGS)

clean:
	rm -f obj/*.o $(OBJ) bin/*

init:
	mkdir -p bin obj
