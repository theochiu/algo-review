
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
#COVERAGE = -fprofile-arcs -ftest-coverage
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) $(COVERAGE)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose


# list all .c files
SRCS = tree.c

# object files are created by converting .c to .o
OBJS = $(SRCS:%.c=%.o)

main: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o main

# convert .c to .o 
.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 
	
memcheck: main
	valgrind --tool=memcheck --verbose --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="valgrind.txt" ./main 

clean: # remove all machine generated files
	rm -f main *.o *.out *gcda *gcno *gcov

run: main
	./main 

test1: main
	./main 

