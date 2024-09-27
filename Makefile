SOURCES := $(shell find . -name '*.cpp' ! -name 'main.cpp')
HEADERS := $(shell find . -name '*.h')
OBJECTS := $(SOURCES:.cpp=.o)
MAIN_OBJECT := main.o

CC = g++
CFLAGS = -std=c++17
ANTLR_ARGS = -I /usr/local/include/antlr4-runtime/ -lantlr4-runtime
LLVM_ARGS = `llvm-config --ldflags --system-libs --libs all`
LEXER_FILE := $(shell find . -iname '*lexer.g4')
PARSER_FILE := $(shell find . -iname '*parser.g4')
.PHONY: main clean antlr run gdb

run: main
	./main

gdb: main
	gdb ./main

main: ${OBJECTS} ${MAIN_OBJECT}
	${CC} ${CFLAGS} ${OBJECTS} ${MAIN_OBJECT} ${ANTLR_ARGS} ${LLVM_ARGS} -o $@

antlr:
	java -jar /usr/local/lib/antlr-4.13.0-complete.jar -Dlanguage=Cpp ${LEXER_FILE}
	java -jar /usr/local/lib/antlr-4.13.0-complete.jar -Dlanguage=Cpp -no-listener -visitor ${PARSER_FILE}

%.o: %.cpp
	${CC} ${CFLAGS} ${ANTLR_ARGS} -c $< -o $@

main.o: main.cpp $(HEADERS)
	${CC} ${CFLAGS} ${ANTLR_ARGS} ${LLVM_ARGS} -c $< -o $@

clean:
	rm -f ${OBJECTS} ${MAIN_OBJECT}
	rm -f main