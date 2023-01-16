#include "headers.h"
#include <stdio.h>
#include <stdlib.h>


int main(){


    pnode headNode = (pnode)malloc(sizeof(pnode));
    

    char command; 
    scanf("%c", &command);
    while(command != (char)EOF){
       // printf("%c\n", command);
        switch (command) {
                case 'A': 

                    //deleteGraph_cmd(pnode* head);
                    command = build_graph_cmd(&headNode);
                    printGraph_cmd(headNode);

                    continue;
                case 'B':  
                    //insert_node_cmd(pnode *head);
                    continue;
                case 'D': 
                    //delete_node_cmd(pnode *head);
                    continue;
                case 'S': // exit the while loop
                    //  shortsPath_cmd(pnode head);
                    continue;
                case 'T': 

                    // TSP_cmd(pnode head);
                    continue;
                default: 
                    exit(1); 
            }
    }
    return 0; 
}