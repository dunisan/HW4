#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"
#include "graph.h"
#include <unistd.h>


int main(){


    pnode headNode = NULL;// (pnode)malloc(sizeof(pnode)); 
    
    char command; 
    scanf("%c", &command); 

    while(command != (char)EOF){
        printf("%c\n", command);

        switch (command) {
                case 'A': 
                    
                    //deleteGraph_cmd(pnode* head);
                    command = build_graph_cmd(&headNode);
                    printGraph_cmd(&headNode);
                    continue;

                case 'B':  
                    insert_node_cmd(&headNode);
                    printGraph_cmd(&headNode);
                    scanf(" %c", &command);
                    continue;
                case 'D': 
                    delete_node_cmd(&headNode);
                    printGraph_cmd(&headNode);
                    scanf(" %c", &command);

                    continue;
                case 'S': // exit the while loop
                    command = shortestPath_cmd(headNode);
                    scanf(" %c", &command);
                    continue;
                case 'T': 
                    exit(1);
                    // TSP_cmd(pnode head);
                    continue;
                default: 
                    free(headNode); 
                    exit(1); 
            }
    }
    return 0; 
}