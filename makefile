CC=gcc
CFLAGS=-Wall -ansi  -I./header
LDFLAGS= -lMLV
OBJ=bin/main.o bin/delaunay.o bin/interactions.o bin/window.o

exec: $(OBJ)
	$(CC) -o exec $(OBJ) $(CFLAGS) $(LDFLAGS)

bin/main.o: src/main.c header/interactions.h
	$(CC) -o $@ -c src/main.c $(CFLAGS)

bin/window.o: src/window.c header/window.h
	$(CC) -o $@ -c src/window.c $(CFLAGS)	
	
bin/interactions.o: src/interactions.c header/interactions.h header/window.h header/delaunay.h
	$(CC) -o $@ -c src/interactions.c $(CFLAGS)	
	
bin/delaunay.o: src/delaunay.c header/delaunay.h
	$(CC) -o $@ -c src/delaunay.c $(CFLAGS)
	
clean:
	rm -f bin/*.o
	rm -f */~
	rm -f exec
