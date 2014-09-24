SRC=$(wildcard src/*/*.d)
OBJ=$(SRC:.d=.o)
EXEC=devoir1

all: $(EXEC)

$(EXEC): $(OBJ)
	dmd $(notdir $^) -of$(EXEC)

%.o:%.d
		dmd $< -c

clean:
	@echo "Clean .o files"
	rm *.o

mrproper: clean
	@echo "Remove $(EXEC) file"
	rm -rf $(EXEC)

rebuild:
	@echo " --- Cleaning --- "
	make mrproper
	@echo "\n\n --- Building --- "
	make all
