# a varaible assignment
CC := gcc
# to refer to a varaible, $(variable name)

flags := -Wall -O2
# -O2 (capital "O") is a effeciency element for the compiler,
# frequently unspools loops, optimizes code.
# not as useful when debugging, also makes the exe larger
# other levels of optimization O1, O3. O3 is extremely optimized


# name of the rule or file: dependancies
dungeonTest: main.o tools.o
	$(CC) main.o tools.o $(flags) -o dungeonTest

main.o: main.c tools.h # if main.c or tools.h changes, run this again when we make
	$(CC) -c main.c

tools.o: tools.h tools.c # if the c or header file changes, run this again
	$(CC) -c tools.c

clean:  # common to have a clean command to remove all object files and executables
	rm *.o
	rm dungeonTest
