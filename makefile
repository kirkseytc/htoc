htoc.o : 
	gcc ./src/htoc.c -c -Wall

htoc : htoc.o
	gcc -o htoc htoc.o -Wall

install : htoc
	cp htoc /usr/local/bin/
	make clean

clean :
	rm *.o htoc

