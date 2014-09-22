EXEC=devoir1

make:
	dmd src/utils/randomcoin.d -c
	
	dmd src/structure/node.d -c
	dmd src/structure/skiplist.d node.o -c	
	
	dmd src/main/main.d skiplist.o randomcoin.o -of$(EXEC)

clean:
	rm *.o
