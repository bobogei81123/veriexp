
LEXER = lexer.l
LEX = lex
LEXFLAGS = 
LEXCPP = lexer.cpp

BISON = bison
BISONFLAGS = 
PARSER = parser.y
PARCPP = parser.cpp

CPP = g++
CPPFLAGS = -O2 -Wall -Wshadow -DDEBUG

SOURCES = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SOURCES))

EXEC = main
CC = 
MAIN = main.cpp

all: exec

exec: lex $(OBJS) 
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(EXEC)

lex: par $(LEXCPP) lexer.o
	
$(LEXCPP): $(LEXER)
	$(LEX) -o $(LEXCPP) $(LEXER) 

par: $(PARCPP) parser.o

$(PARCPP): $(PARSER)
	$(BISON) -d -o $(PARCPP) $(PARSER)

clean:
	rm -f *.o

%.o: %.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

test: all
	./$(EXEC)

.phony: all lexer clean
