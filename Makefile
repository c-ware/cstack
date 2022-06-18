# This Makefile is the output of a template Makefile that was
# processed by the m4 macro preprocessor. It is not intended
# to be human readable.

CC=cc
PREFIX=/usr/local
# CFLAGS=-ansi -Wall -Wextra -Wshadow -Wdouble-promotion -fpic -Wno-unused-variable -Wno-unused-function -Wno-sign-compare
TESTS=tests/test_free.out tests/test_peek.out tests/test_init.out tests/test_push.out tests/test_pop.out tests/test_is_empty.out tests/test_length.out 
DOCS=./doc/cstack_length.cware ./doc/cstack_push.cware ./doc/cstack_free.cware ./doc/cstack_init_stack.cware ./doc/cstack_peek.cware ./doc/cstack_init.cware ./doc/cstack.cware ./doc/cstack_is_empty.cware ./doc/cstack_pop.cware 
MANNAMES=cstack_length.cware cstack_push.cware cstack_free.cware cstack_init_stack.cware cstack_peek.cware cstack_init.cware cstack.cware cstack_is_empty.cware cstack_pop.cware 
DEBUGGER=

.PHONY: all clean check install
.SUFFIXES: .c .out

all: $(TESTS) $(DOCS)

clean:
	rm -f $(TESTS)

check:
	./scripts/check.sh $(DEBUGGER)

install:
	install -d -m 755 $(PREFIX)/include/cware
	install -m 755 src/cstack.h $(PREFIX)/include/cware
	install -d -m 755 $(PREFIX)/share/man/mancware
	for manual in $(MANNAMES); do \
		install -m 755 doc/$$manual $(PREFIX)/share/man/mancware; \
	done


uninstall:
	rm -f $(PREFIX)/include/cware/cstack.h
	for manual in $(MANNAMES); do  \
		rm -f $(PREFIX)/share/man/mancware/$$manual; \
	done
	rmdir $(PREFIX)/share/man/mancware
	rmdir $(PREFIX)/include/cware

.c.out:
	$(CC) $< $(OBJS) $(CFLAGS) -o $@
