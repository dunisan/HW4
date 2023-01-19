#include "headers.h"



int main(){


    pnode headNode = NULL;
    
    char command; 
    scanf("%c", &command); 

    while(!feof(stdin)){

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
                    shortestPath_cmd(headNode);
                    scanf(" %c", &command);
                    continue;
                case 'T': 
                    // TSP_cmd(pnode head);
                    exit(1);
                    continue;
                default: 
                    free(headNode); 
                    exit(1); 
            }
    }
    return 0; 
}