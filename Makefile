OUTDIR?=out
SRCDIR?=revisions/rev4
EXECUTABLE=$(OUTDIR)/demosthenes

CFILES=\
 $(SRCDIR)/roach_bag/zeroes.c \
 $(SRCDIR)/roach_bag/memory.c \
 $(SRCDIR)/roach_bag/soup.c \
 $(SRCDIR)/roach_bag/smoking_heap.c \
 $(SRCDIR)/roach_bag/mud.c \
 $(SRCDIR)/roach_bag/cc_memory.cc \
 $(SRCDIR)/driver/entry.c \
 $(SRCDIR)/stadium/stadium.c \
 $(SRCDIR)/stadium2/stadium2.c \
 $(SRCDIR)/stadium3/stadium3.c  

CC=gcc
CXXFLAGS=-ansi -Wall -pedantic -I $(SRCDIR)/include
CFLAGS=-ansi -Wall -pedantic -I $(SRCDIR)/include

EXE_OBJECTS := $(addprefix $(OUTDIR)/,$(addsuffix .o,$(basename $(notdir $(CFILES)))))
VPATH:=$(dir $(CFILES)) $(OUTDIR)

all: $(OUTDIR) compile
    
compile: $(EXECUTABLE)

clean:
	-rm -rf $(EXECUTABLE) core* $(OUTDIR)/*.o


$(OUTDIR)/%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@
    
$(OUTDIR)/%.o: %.cc
	$(CXX) -c $< $(CFLAGS) -o $@
            
$(OUTDIR):
	-mkdir -p $(OUTDIR)
	
$(EXECUTABLE): $(EXE_OBJECTS)
	$(CXX) $^ -o $@
