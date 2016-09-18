# -*- Makefile -*-

#target: dependencies
#	action
include source.mk
CC=gcc  #declaring the compilers
CFLAGS= -g -Wall -O0 -std=c99 #declaring the flags
CPROG= main.c memory.c project_1.c
HEAD= hw1.h memory.h project_1.h
OBJ= main.o memory.o project_1.o memzero.o mymemmove.o reverse.o
INCLUDE=./HEADER
PREP= main.i memory.i memzero.i mymemmove.i project_1.i reverse.i
BBB= output root@192.168.7.2:home/ESE/project

ifeq ($(arch),bbb)
CC=arm-linux-gnueabihf-gcc
else ifeq ($(arch),frdm)
CC=arm-none-eabi
else ifeq ($(arch),host)
CC=gcc
else 
CC=gcc
endif

#all: %

.PHONY: %.i
makefile.i: $(PREP)
	cpp -I $(INCLUDE) $^ > preprocessed/$@
%.i: %.c
	mkdir -p preprocessed
	$(CC) $(CFLAGS) -I $(INCLUDE) -E $^
	cpp -I $(INCLUDE) $^ > preprocessed/$@
.PHONY: makefiles.s
makefile.s: $(CPROG)
	mkdir -p asm-file
	$(CC) $(CFLAG) -I $(INCLUDE) $^ -S
	mv *.s asm-file

.PHONY: main.s
main.s: main.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^ 
.PHONY: memory.s
memory.s: memory.c 
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: mymemmove
mymemmove.s: mymemmove.c
	$(CC) $(CFLAG) -S $^
.PHONY: memzero
memzero.s: memzero.c
	$(CC) $(CFLAG) -S $^

.PHONY: reverse
reverse.s: reverse.c
	$(CC) $(CFLAG) -S $^
.PHONY: %.o
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) $^ -c

.PHONY: compile-all
compile-all: $(OBJ)
	$(CC) $(CFLAGS) -I $(INCLUDE) $^ -c

Build: $(CPROG)
	$(CC) $(CFLAGS) $^ -I $(INCLUDE) -o output
	$(CC) $(CFLAGS) -I $(INCLUDE) -M ./source/*.c > output.dep
	size -d output 
	objdump -a $(OBJ)
upload: output
	scp $(BBB)

Build-lib: $(CPROG)
	ar rU libproject1.a ./source/*.c
	ranlib libproject1.a 
	tar -cvf libproject1.tar ./source/*.c
	
clear:
	rm -rf *.i *.o *.s main compail-all Build Build-lib libproject1.a libproject1.tar Mapfile

