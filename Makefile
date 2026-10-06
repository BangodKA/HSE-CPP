EXECUTABLES = .executables
OBJECT = .object
ASSEMBLY = .assembly
PREPROCESS = .preprocess
UTILS = utils
MODULES = main float types template

COMPILER_OPTS = --std=c++20 -Wall -Wextra -static-libsan -Wno-unused-variable
OPTIMIZATIONS = -O0

.PHONY: run clean all main float types template
.PHONY: executables object assembly preprocess
.PHONY: $(MODULES:=.o) $(MODULES:=.asm) $(MODULES:=.prp)
.SECONDARY: $(addprefix $(PREPROCESS)/,$(addsuffix .ii,$(MODULES))) \
            $(addprefix $(ASSEMBLY)/,$(addsuffix .s,$(MODULES))) \
            $(addprefix $(OBJECT)/,$(addsuffix .o,$(MODULES)))

vpath %.cpp $(UTILS)

run:
	./$(EXECUTABLES)/main

clean:
	rm -rf ./$(EXECUTABLES) ./$(OBJECT) ./$(ASSEMBLY) ./$(PREPROCESS)

# BUILD
all: executables main.o float.o types.o template.o
all: LINK_OBJECTS = ./$(OBJECT)/*
main: executables main.o
main: LINK_OBJECTS = ./$(OBJECT)/main.o
float: executables main.o float.o
float: LINK_OBJECTS = ./$(OBJECT)/main.o ./$(OBJECT)/float.o
types: executables main.o types.o
types: LINK_OBJECTS = ./$(OBJECT)/main.o ./$(OBJECT)/types.o
template: executables main.o template.o
template: LINK_OBJECTS = ./$(OBJECT)/main.o ./$(OBJECT)/template.o

all main float types template:
	clang++ $(LINK_OBJECTS) -o ./$(EXECUTABLES)/main $(COMPILER_OPTS) $(OPTIMIZATIONS)

# OBJECTS. *.o. Добавить -x assembler, если расширение входного не *.s.
$(MODULES:=.o): %.o: object %.asm
	clang++ -c ./$(ASSEMBLY)/$*.s -o ./$(OBJECT)/$*.o $(COMPILER_OPTS) $(OPTIMIZATIONS)

# ASSEMBLY. *.s. Добавить -x c++-cpp-output, если расширение входного не *.ii.
$(MODULES:=.asm): %.asm: assembly %.prp
	clang++ -S ./$(PREPROCESS)/$*.ii -o ./$(ASSEMBLY)/$*.s $(OPTIMIZATIONS) $(COMPILER_OPTS)

# PREPROCESS. *.ii. Добавить -x c++, если расширение входного не *.cpp.
$(MODULES:=.prp): %.prp: %.cpp preprocess
	clang++ -E $< -o ./$(PREPROCESS)/$*.ii $(COMPILER_OPTS) $(OPTIMIZATIONS)

# FOLDERS
executables: $(EXECUTABLES)
object: $(OBJECT)
assembly: $(ASSEMBLY)
preprocess: $(PREPROCESS)

$(EXECUTABLES) $(OBJECT) $(ASSEMBLY) $(PREPROCESS):
	mkdir -p $@
