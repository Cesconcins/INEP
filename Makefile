CC = g++
CFLAGS = -Wall -g

# Targets
main: main.o DBConnection.o Menus.o
	$(CC) $(CFLAGS) -o main main.o DBConnection.o Menus.o -lmysqlcppconn

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

DBConnection.o: DBConnection.cpp
	$(CC) $(CFLAGS) -c DBConnection.cpp

Menus.o: Menus.cpp
	$(CC) $(CFLAGS) -c Menus.cpp

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf *.o main

