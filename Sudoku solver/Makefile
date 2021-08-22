CC = g++

CFLAGS = -g -Wall

soduko_solver: Logic.o Matchfield.o main.o Input_Handling.o
	$(CC) $(CFLAGS) -o soduko_solver Logic.o Matchfield.o  main.o Input_Handling.o

main.o: Matchfield.h Logic.h Input_Handling.h Datastructures.h
	$(CC) $(CFLAGS) -c main.cpp

Logic.o: Logic.h

Matchfield.o: Matchfield.h

Input_Handling.o: Input_Handling.h

clean:
	-rm *.o
