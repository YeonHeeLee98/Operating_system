TARGET = 20175327
OBJS = main.o tcp.o file.o

$(TARGET) : $(OBJS)
	gcc -lm -o $@ $^
.c.o : 
	gcc -g -c $<

main.o : main.c main.h tcp.h file.h
tcp.o : tcp.c tcp.h
file.o : file.c file.h

clean : 
	rm $(OBJS)
