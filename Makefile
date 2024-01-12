MPICC := mpicc
GCC := gcc

DFLAGS := -Wall -Wextra
LFLAGS := -lm

EXECS := assignment1a\
		assignment1b\
		assignment1c\
		assignment1d

OBJS := function.o

all: $(EXECS)

%.o: %.c
	$(GCC) $(DFLAGS) -c $< -o $@

$(EXECS): %: %.c $(OBJS)
	$(MPICC) $(DFLAGS) $^ -o $@ $(LFLAGS)
	

.PHONY: all clean

clean:
	rm -f $(EXECS) $(OBJS)
