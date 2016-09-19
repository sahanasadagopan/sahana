OBJ= main.o hw1.o
SRC= main.c hw1.c #project.c #memory.c #data.c
ASM = main.s hw1.s
Preprocessed = main.i #project.i #memory.i #data.i
VPATH : memory data project

vpath %.s asm-file
vpath %.i preprocessed	
vpath %.c source
vpath %.h HEADER
	
