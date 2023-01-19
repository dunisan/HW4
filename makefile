CC = gcc
FLAGS = -Wall
SOURCES = graph.c main.c edges.c nodes.c algo.c
HEADERS = graph.h  headers.h edges.h nodes.h algo.h
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
