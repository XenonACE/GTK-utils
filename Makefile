CC = tcc

all: gtk-utils.a

gtk-utils.a: utils.o
	ar rcs $@ $^

utils.o: utils.c
	$(CC) -o $@ -c `pkg-config gtk+-3.0 --cflags` $^

install: gtk-utils.a
	mv $^ /usr/lib
	cp ./Xe-gtk-utils.h /usr/include
	cp ./Xe-Bluetooth-status.sh /usr/local/bin
	chmod +x /usr/local/bin/Xe-Bluetooth-status.sh

.PHONY: clean

clean:
	rm -f utils.o
