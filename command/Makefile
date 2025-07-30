flags=-O2 -Wall -std=c2x -I../osapi
ldflags=

.PHONY: clean

all: clean command.com

../osapi/ospai.o: ../osapi/osapi.c
	 $(MAKE) -C ../osapi -sk "CFAGS=$(flags)"

command.com: command.o	../osapi/osapi.o
	cc $(flags) $^ -o $@ $(ldflags)

command.o: command.c command.h
	cc $(flags) -c $<

clean:
	rm -f *.o command.com