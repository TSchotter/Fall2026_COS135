# Makefile (case sensitive)

# First rule, automatically tries to run this
# 
oct26Test: main.o tools.o 
	gcc main.o tools.o -o oct26Test

# checks to see if main.c or tools.h has been
# recently changed, if it has, run the command
main.o: main.c tools.h
	gcc main.c -c

tools.o: tools.c tools.h
	gcc tools.c tools.h -c

# can run this with "make clean"
clean:
	rm *.o
	rm oct26Test