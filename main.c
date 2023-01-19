#include "headers.h"



int main(){


    pnode headNode = NULL;
    
    char command; 
    scanf("%c", &command); 
    int sourceNode, destinationNode; 

    while(!feof(stdin)){
       // printf("%c\n", command);
        switch (command) {
                case 'A': 
                    
                    deleteGraph_cmd(&headNode);
                    command = build_graph_cmd(&headNode);
                    //printGraph_cmd(&headNode);
                    continue;

                case 'B':  
                    command = insert_node_cmd(&headNode);
                    //printGraph_cmd(&headNode);
                   // scanf(" %c", &command);
                    continue;
                case 'D': 
                    delete_node_cmd(&headNode);
                 //   printGraph_cmd(&headNode);
                    scanf(" %c", &command);

                    continue;
                case 'S': // exit the while loop
                    
                    scanf("%d %d", &sourceNode, &destinationNode); 
                    int shortPath = shortestPath_cmd(headNode, sourceNode, destinationNode);
                    printf("Dijsktra shortest path: %d \n", shortPath);

                    scanf(" %c", &command);
                    continue;
                case 'T': 
                    TSP_cmd(headNode);
                    scanf(" %c", &command);
                    continue;
                default: 
                    free(headNode); 
                    exit(1); 
            }
    }

    return 0; 
}