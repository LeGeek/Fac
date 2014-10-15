CC=g++
CCFLAGS=-W -Wall -pedantic -I./include -I.
LDFLAGS=

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

EXEC=avl

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CCFLAGS)

clean:
	@echo "Clean .o files"
	rm -rf */*.o

mrproper: clean
	@echo "Remove $(EXEC) file"
	rm -rf $(EXEC)

doxygen:
	@echo "Generate Doxygen documentation"
	rm -rf documentation
	doxygen config_doxygen.conf

rebuild:
	@echo " --- Cleaning --- "
	make mrproper
	@echo " \n\n--- Building --- "
	make all

