# Project1
Introduction
This project is given in the class where three memory functions are given and five data functions are given. This project deals with the compilation of these C files the Various C files are made which follow as certain pathway during compilation. Inittially the C files are made into Preprocessor file, ASM-file,object file,and executable files. In this project all the preprocessor, asm and object files a=can be created saperately or all together.

Making targets

Examples to write a target
Target name:<Target dependencies>
	recipe for the target ($(compiler) $(Flags) linkling (output files))

There are various targets created and each are explained below:
Target 1: Preprocessor:Each target has dependencies which are mentioned. Then various targets have saperate unique recipes that compile the c files and the output .i files are generated for each .c files.
	All these files are saved in a folder called preprocessor
	Here all the libraries of <stdio.h> is copied and pasted into the .i files.
	In this case target name: $(CPROG)
				  gcc Cflags -E $(CPROG) 
Target 2:asm-files: This creats the assembly files .The recipes are made such that each assembly file is being commited and all the assembly files are created.ANd all these files are saved in a folder called asm-files
	In this case Target name: $(CPROG)
	 		          gcc CFLAGS -S $(CPROG)
Target 3: Object files: THis creats the object files singularly and each object file is saved in the main directory.
	Target name:$(CPROG)
		    gcc  $(CFLAGS) -I <path-included> -c
Target 4: Compile-all: All the object files are being generated all at once bt they are not linked. THe recipe of this is similar to the target 3 recepie.

Target 5: Build: In thid target the executable files are being created and the dependencies are being generated.
	Target name :Build:$(OBJ)
		     gcc CFLAGS CPROG -o <outputfile>
		     gcc CFLAGS CPROG -o <outputfile> > dependenciesfile.dep
		     size of the object file
		     object dump of the file is done
Target 6:Here the library is build in which all the c files are being copied an archieve is generated where al;l the c files are being stored.
	Target name:Build-lib:$(CPROG)
			      archive is created and all the c files are copied into the archive

		     
		  
 Phony targets are assigned to each of the targets so that there is no conflict if there are files generated with the same target name.
For getting the output for the memory and data files the variable in Cobj variable should be changed with alll the main files are given together then a error of overaping main function or defining main twice comes.

The same makefile can be accesed by cloning it to beagle bone and compiling it natively on beagle bone.
