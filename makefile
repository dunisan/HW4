CC = gcc
FLAGS = -Wall
SOURCES = graph.c main.c
HEADERS = graph.h  headers.h
OBJS = $(SOURCES:.c=.o)

all: graph
	
graph: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o graph
	
##main.o: main.c headers.h graph.h
##	$(CC) $(FLAGS) -c main.c -o main.o

##graph.o: 


%.o: %.c $(HEADERS)
	$(CC) -Wall -c $< -o $@


    
clean: 
	rm *.o graph
