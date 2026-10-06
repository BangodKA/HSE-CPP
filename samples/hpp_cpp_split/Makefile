EXECUTABLES = ../../.executables
EXECUTABLE = $(EXECUTABLES)/$(notdir $(CURDIR))
SOURCES = $(filter-out main.cpp,$(wildcard *.cpp utils/*.cpp))

COMPILER_OPTS = --std=c++20 -Wall -Wextra -static-libsan -Wno-unused-variable
OPTIMIZATIONS = -O0

.DEFAULT_GOAL := all
.PHONY: all run clean

all: | $(EXECUTABLES)
	clang++ $(COMPILER_OPTS) $(OPTIMIZATIONS) main.cpp $(SOURCES) -o $(EXECUTABLE)

run: all
	$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

$(EXECUTABLES):
	mkdir -p $@
