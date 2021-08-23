CC = g++

CFLAGS = -g 
soduko_solver: Logic.o Matchfield.o main.o Input_Handling.o
	$(CC) $(CFLAGS) -o soduko_solver Logic.o Matchfield.o  main.o Input_Handling.o

main.o: ../src/libMatchfield/Matchfield.h ../src/libLogic/Logic.h ../src/libInput/Input_Handling.h ../src/libMatchfield/Datastructures.h
	$(CC) $(CFLAGS) -c ../src/app/main.cpp

Logic.o: ../src/libLogic/Logic.h ../src/libLogic/Logic.cpp
	$(CC) $(CFLAGS) -c ../src/libLogic/Logic.cpp 

Matchfield.o: ../src/libMatchfield/Datastructures.h ../src/libMatchfield/Matchfield.h ../src/libMatchfield/Matchfield.cpp
	$(CC) $(CFLAGS) -c ../src/libMatchfield/Matchfield.cpp 

Input_Handling.o: ../src/libInput/Input_Handling.h ../src/libInput/Input_Handling.cpp 
	$(CC) $(CFLAGS) -c ../src/libInput/Input_Handling.cpp

clean:
	-rm -f *.o soduko_solver
