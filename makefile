SHELL=/bin/bash

htoc.o :
	if [ ! -d ./obj ]; then mkdir obj; fi
	gcc ./src/htoc.c -c -o ./obj/htoc.o -Wall

htoc : htoc.o
	if [ ! -d ./bin ]; then mkdir bin; fi
	gcc -o ./bin/htoc ./obj/htoc.o -Wall

install : htoc
	cp ./bin/htoc /usr/local/bin/
	@echo ""
	@echo "htoc successfully installed."

uninstall :
	rm /usr/local/bin/htoc
	make clean
	@echo ""
	@echo "htoc successfully uninstalled."

clean :
	rm ./obj/*.o ./bin/htoc
	rmdir obj bin
