IDIR =../include
CC=gcc
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

_DEPS =
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o calculation.o logic.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: calculator

calculator: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~
	rm -f calculator
	rm -f *.o

etags:
	find . -type f -iname "*.[ch]" | xargs etags --append
