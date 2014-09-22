CC=gcc
CCFLAGS=-W -Wall -pedantic -std=c99 -I.
LDFLAGS=

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

EXEC=devoir_tris

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CCFLAGS)

clean:
	@echo "Clean .o files"
	rm -rf *.o

mrproper: clean
	@echo "Remove $(EXEC) file"
	rm -rf $(EXEC)

doxygen:
	@echo "Generate Doxygen documentation !"
	rm -rf documentation/*
	doxygen config_doxygen.conf

rebuild:
	@echo " --- Cleaning --- "
	make clean
	@echo " \n\n--- Building --- "
	make all

