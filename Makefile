
LEXER = lexer.l
LEX = lex
LEXFLAGS = 
LEXCPP = lexer.cpp

BISON = bison
BISONFLAGS = 
PARSER = parser.y
PARCPP = parser.cpp

CPP = g++
CPPFLAGS = -std=c++11 -O2 -Wall -Wshadow -DDEBUG -I.

MODULES = ast verilog context
#SOURCES = lexer.cpp parser.cpp
SOURCES = $(patsubst ./%, %, $(shell find . -name "*.cpp"))
OBJDIR = build
#SOURCES += $(foreach sdir, $(MODULES), $(wildcard $(sdir)/**/*.cpp))
OBJS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SOURCES))

NOH = main.h parser.h lexer.h

EXEC = main
CC = 
MAIN = main.cpp

dir_guard = @mkdir -p $(@D)

all: exec

exec: lex $(OBJS) 
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(EXEC)

lex: par $(LEXCPP) $(OBJDIR)/lexer.o
	
$(LEXCPP): $(LEXER)
	$(LEX) -o $(LEXCPP) $(LEXER) 

par: $(PARCPP) $(OBJDIR)/parser.o

$(PARCPP): $(PARSER)
	$(BISON) -d -o $(PARCPP) $(PARSER)

clean:
	rm -rf build/*

$(OBJDIR)/lexer.o: lexer.cpp
	$(dir_guard)
	g++ $(CPPFLAGS) -c -o $@ $<

$(OBJDIR)/parser.o: parser.cpp
	$(dir_guard)
	g++ $(CPPFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: %.cpp %.h
	$(dir_guard)
	g++ $(CPPFLAGS) -c -o $@ $<

$(NOH):

test: all
	./$(EXEC)

.phony: all lexer clean
