.PHONY: all clean install uninstall

CFLAGS ?= -O3 -Wall -Wextra -Werror -Wconversion -std=c11
PREFIX ?= /usr/local
objs=pool.o tokens.o str.o

all: libbase.a libbase.so

libbase.a: $(objs)
	$(AR) -rcs $@ $^

libbase.so: $(objs)
	$(CC) -o $@ $^ -shared

install: libbase.a libbase.so
	mkdir -p $(PREFIX)/include/base
	cp arena.h str.h tokens.h $(PREFIX)/include/base
	mkdir -p $(PREFIX)/lib
	cp libbase.a $(PREFIX)/lib
	cp libbase.so $(PREFIX)/lib

uninstall:
	rm -rf $(PREFIX)/include/base
	rm -f $(PREFIX)/lib/libbase.a
	rm -f $(PREFIX)/lib/libbase.so

clean:
	rm -f libbase.* $(objs)
