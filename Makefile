CC=g++-5
CPPFLAGS=-std=c++11 -lgmpxx -lgmp -Wall -O3
# -O3 -fno-exceptions

.PHONY: clean

default: vsl

gen:
	mkdir -p src/gen
	bison -Wno-other -o src/gen/parser.cpp -d -v src/parser.y
	flex -o src/gen/lexer.cpp src/lexer.l

basic_vsl:
	mkdir -p src/gen
	bison -Wno-other -o src/gen/parser.cpp -d -v src/parser.y
	flex -o src/gen/lexer.cpp src/lexer.l
	cp src/operators.hpp src/gen/
	$(CC) $(CPPFLAGS) src/gen/run.cpp src/gen/lexer.cpp src/gen/parser.cpp -lfl -o parser

astify:
	mkdir -p src/gen
	cp src/astify.cpp src/gen/run.cpp
	cp src/astify.hpp src/src/gen/run.hpp
	make basic_vsl

interpret:
	mkdir -p src/gen
	cp src/interpret.cpp src/gen/run.cpp
	cp src/interpret.hpp src/gen/run.hpp
	make basic_vsl

classes:
	$(CC) $(CPPFLAGS) src/VSL/Class/Class.cpp src/gen/lexer.cpp src/gen/parser.cpp -o classes

clean:
	mkdir -p src/gen
	rm -r src/gen

