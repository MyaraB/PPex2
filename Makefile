CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o
FLAGS =-Wall -g

all:mybanks mybankd mains maind

mains:$(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a
	
maind:$(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyBank.so
	
mybanks:$(OBJECTS_LIB)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)
	
mybankd:$(OBJECTS_LIB)
	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB)
		
main.o: myBank.h main.c
	$(CC) $(FLAGS) -c -o main.o main.c
					
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c -o myBank.o myBank.c
	
.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maind
