# -*- Makefile -*-

#target: dependencies
#	action
include source.mk
CC=gcc  #declaring the compilers
CFLAGS= -g -Wall -O0 -std=c99 #declaring the flags

CPROG= main.c memory.c project_1.c memzero.c mymemmove.c reverse.c bigtolittle.c atoi.c data.c dump_mem.c itoa.c littletobig.c # declaring all the C files

COBJ= data.c project_1.c main.c memory.c# Files for which object files are to be generated

HEAD= hw1.h memory.h project_1.h data.h # files for which header files are present

OBJ= main.o memory.o project_1.o data.o #files for which object files are to be generated

INCLUDE=./HEADER #giving the header path

PREP= main.i memory.i memzero.i mymemmove.i project_1.i reverse.i data.i dump_mem.i bigtolittle.i littletobig.i atoi.i itoa.i #all the preprocessor files

BBB= output root@192.168.7.2:home/ESE/project

ifeq ($(arch),bbb) # for defining the beagle bone board
CC=arm-linux-gnueabihf-gcc
else ifeq ($(arch),frdm) # for defining the freedom scale compiler
CC=arm-none-eabi
else ifeq ($(arch),host)# for taking the native compiler
CC=gcc
else 
CC=gcc #defining default compiler 
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
.PHONY: mymemmove.s
mymemmove.s: mymemmove.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: memzero.s
memzero.s: memzero.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^

.PHONY: reverse.s
reverse.s: reverse.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: data.s
data.s: data.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: maindata.s
maindata.s: maindata.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: itoa.s
itoa.s: itoa.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: atoi.s
atoi.s: atoi.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: dump_mem.s
dump_mem.s: dump_mem.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: littletobig.s
littletobig.s: litlletobig.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: bigtolittle.s
bigtolittle.s: bigtolittle.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^

.PHONY: %.o
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) $^ -c

.PHONY: compile-all
compile-all: $(OBJ)
	$(CC) $(CFLAGS) -I $(INCLUDE) $^ -c

Build: $(COBJ)
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
	rm -rf *.i *.o *.s main compail-all Build Build-lib libproject1.a libproject1.tar Mapfile output

