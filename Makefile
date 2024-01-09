MPICC := mpicc
GCC := gcc

DFLAGS := -Wall -Wextra

EXECS := assignment1a\
		assignment1b
OBJS := function.o

all: $(EXECS)

%.o: %.c
	$(GCC) $(DFLAGS) -c $< -o $@

assignment1a: assignment1a.c $(OBJS)
	$(MPICC) $(DFLAGS) $^ -o $@

assignment1b: assignment1b.c $(OBJS)
	$(MPICC) $(DFLAGS) $^ -o $@

.PHONY: all clean

clean:
	rm -f $(EXECS) $(OBJS)
