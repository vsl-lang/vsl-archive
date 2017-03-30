CC=g++-5
CPPFLAGS=-std=c++11 -lgmpxx -lgmp -Wall -O3
# -O3 -fno-exceptions

.PHONY: clean

default: vsl

gen:
	mkdir -p src/Parser/gen
	bison -Wno-other -o src/Parser/gen/parser.cpp -d -v src/Parser/parser.y
	flex -o src/Parser/gen/lexer.cpp src/Parser/lexer.l

basic_vsl:
	mkdir -p src/Parser/gen
	bison -Wno-other -o src/Parser/gen/parser.cpp -d -v src/Parser/parser.y
	flex -o src/Parser/gen/lexer.cpp src/Parser/lexer.l
	cp src/Parser/operators.hpp src/Parser/gen/
	cp src/Parser/nodes.hpp src/Parser/gen/
	$(CC) $(CPPFLAGS) src/Parser/gen/run.cpp src/Parser/gen/lexer.cpp src/Parser/gen/parser.cpp -lfl -o parser

astify:
	mkdir -p src/Parser/gen
	cp src/Parser/astify.cpp src/Parser/gen/run.cpp
	cp src/Parser/astify.hpp src/Parser/gen/run.hpp
	make basic_vsl

interpret:
	mkdir -p src/Parser/gen
	cp src/Parser/interpret.cpp src/Parser/gen/run.cpp
	cp src/Parser/interpret.hpp src/Parser/gen/run.hpp
	make basic_vsl

classes:
	$(CC) $(CPPFLAGS) src/Parser/VSL/Class/Class.cpp src/Parser/gen/lexer.cpp src/Parser/gen/parser.cpp -o classes

clean:
	mkdir -p src/Parser/gen
	rm -r src/Parser/gen

