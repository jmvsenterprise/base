.PHONY: all clean install uninstall

CFLAGS ?= -O3 -Wall -Wextra -Werror -Wconversion -std=c11
PREFIX ?= /usr/local

all: libbase.a libbase.so

libbase.a: arena.o tokens.o str.o
	$(AR) -rcs $@ $^

libbase.so: arena.o
	$(CC) -o $@ $^ -shared

install: libbase.a libbase.so
	mkdir -p $(PREFIX)/include/base
	cp arena.h $(PREFIX)/include/base
	mkdir -p $(PREFIX)/lib
	cp libbase.a $(PREFIX)/lib
	cp libbase.so $(PREFIX)/lib

uninstall:
	rm -f $(PREFIX)/include/base/arena.h
	rm -f $(PREFIX)/lib/libbase.a
	rm -f $(PREFIX)/lib/libbase.so

clean:
	rm -f libbase.* *.o
