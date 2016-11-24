# Object files to either reference or create
OBJECTS = Escultor.o main.o
# The executable file that will be created at the end
EXEC = ESCULTOR
# The flags to use for compilation
FLAGS = -L/
# The code compiler to use for compilation
CC = g++

# Perform action on all object files (May or may not exist)
all: $(OBJECTS)
	$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)
