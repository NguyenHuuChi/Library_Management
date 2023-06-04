CC = g++
CFLAGS = -std=c++11 -Wall

# Object files
OBJ = Main.o Library.o Student.o

# Executable file
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

Main.o: Main.cpp Library.h Student.h
	$(CC) $(CFLAGS) -c Main.cpp

Library.o: Library.cpp Library.h
	$(CC) $(CFLAGS) -c Library.cpp

Student.o: Student.cpp Library.h Student.h
	$(CC) $(CFLAGS) -c Student.cpp

clean:
	rm -f $(OBJ) $(TARGET)
