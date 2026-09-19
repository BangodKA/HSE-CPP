EXECUTABLES = .executables
OBJECT = .object
ASSEMBLY = .assembly
PREPROCESS = .preprocess
UTILS = utils

COMPILER_OPTS = --std=c++20 -Wall -Wextra -static-libsan -Wno-unused-variable
OPTIMIZATIONS = -O0

run:
	./$(EXECUTABLES)/main

clean:
	rm -rf ./$(EXECUTABLES) ./$(OBJECT) ./$(ASSEMBLY) ./$(PREPROCESS)

# BUILD

all: executables main.o float.o types.o template.o
	clang++ ./$(OBJECT)/* -o ./$(EXECUTABLES)/main $(COMPILER_OPTS) $(OPTIMIZATIONS)

main_only: executables main.o
	clang++ ./$(OBJECT)/main.o -o ./$(EXECUTABLES)/main $(COMPILER_OPTS) $(OPTIMIZATIONS)

float: executables main.o float.o
	clang++ ./$(OBJECT)/main.o ./$(OBJECT)/float.o  -o ./$(EXECUTABLES)/main $(COMPILER_OPTS) $(OPTIMIZATIONS)

types: executables main.o types.o
	clang++ ./$(OBJECT)/main.o ./$(OBJECT)/types.o  -o ./$(EXECUTABLES)/main $(COMPILER_OPTS) $(OPTIMIZATIONS)

template: executables main.o template.o
	clang++ ./$(OBJECT)/main.o ./$(OBJECT)/template.o  -o ./$(EXECUTABLES)/main $(COMPILER_OPTS) $(OPTIMIZATIONS)

# OBJECTS. *.o. Добавить -x assembler, если расширение входного не *.s

main.o: object main.asm
	clang++ -c ./$(ASSEMBLY)/main.s -o ./$(OBJECT)/main.o $(COMPILER_OPTS) $(OPTIMIZATIONS)

float.o: object float.asm
	clang++ -c ./$(ASSEMBLY)/float.s -o ./$(OBJECT)/float.o $(COMPILER_OPTS) $(OPTIMIZATIONS)

types.o: object types.asm
	clang++ -c ./$(ASSEMBLY)/types.s -o ./$(OBJECT)/types.o $(COMPILER_OPTS) $(OPTIMIZATIONS)

template.o: object template.asm
	clang++ -c ./$(ASSEMBLY)/template.s -o ./$(OBJECT)/template.o $(COMPILER_OPTS) $(OPTIMIZATIONS)

# ASSEMBLY. *.s. Добавить -x c++-cpp-output, если расширение входного не *.ii

main.asm: assembly main.prp
	clang++ -S ./$(PREPROCESS)/main.ii -o ./$(ASSEMBLY)/main.s $(OPTIMIZATIONS) $(COMPILER_OPTS)

float.asm: assembly float.prp
	clang++ -S ./$(PREPROCESS)/float.ii -o ./$(ASSEMBLY)/float.s $(OPTIMIZATIONS) $(COMPILER_OPTS)

types.asm: assembly types.prp
	clang++ -S ./$(PREPROCESS)/types.ii -o ./$(ASSEMBLY)/types.s $(OPTIMIZATIONS) $(COMPILER_OPTS)

template.asm: assembly template.prp
	clang++ -S ./$(PREPROCESS)/template.ii -o ./$(ASSEMBLY)/template.s $(OPTIMIZATIONS) $(COMPILER_OPTS)

# PREPROCESS. *.ii. Добавить -x c++, если расширение входного не *.cpp

main.prp: preprocess
	clang++ -E main.cpp -o ./$(PREPROCESS)/main.ii $(COMPILER_OPTS) $(OPTIMIZATIONS)

float.prp: preprocess
	clang++ -E $(UTILS)/float.cpp -o ./$(PREPROCESS)/float.ii $(COMPILER_OPTS) $(OPTIMIZATIONS)

types.prp: preprocess
	clang++ -E $(UTILS)/types.cpp -o ./$(PREPROCESS)/types.ii $(COMPILER_OPTS) $(OPTIMIZATIONS)

template.prp: preprocess
	clang++ -E $(UTILS)/template.cpp -o ./$(PREPROCESS)/template.ii $(COMPILER_OPTS) $(OPTIMIZATIONS)

# FOLDERS

executables:
	mkdir -p $(EXECUTABLES)
object:
	mkdir -p $(OBJECT)
assembly:
	mkdir -p $(ASSEMBLY)
preprocess:
	mkdir -p $(PREPROCESS)
