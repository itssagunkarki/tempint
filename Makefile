CC = clang
CFLAG = -Og -g -finstrument-functions -std=c99 -Wall -Wextra -Wno-unused-parameter
LIB = -lm
DEP = $(wildcard *.h) 
OBJ := $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.asm,%.o,$(wildcard *.asm))
EXEC = integerlab

%.o: %.c $(DEP)
	$(CC) -c -o $@ $< $(CFLAG) $(OPTION)

%.o: %.asm $(DEP)
	$(CC) -c -o $@ $< $(CFLAG) $(OPTION)

integerlab: $(OBJ)
	$(CC) -o $@ $^ $(CFLAG) $(LIB) $(OPTION)

all: $(EXEC)

clean:
	rm -f $(OBJ) *~ core

clear: clean
	rm $(EXEC)
