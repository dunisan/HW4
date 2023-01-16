#include "headers.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

    /*******
    Here we will put our main method. 
    the main will get input from user.  
    here is an example: A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 -- will create a new graph
                        B 5 0 4 2 1 -- will create a new node with edges 
                        D 2 -- will delete a node
                        S 2 4  -- will find the shoretest path 
                        T 3 2 0 5  -- will find a path that passes through all the given nodes 

                        so in the project we need to represent a pragh. 
                        represent a node
                        represent edges. 
                        
                        



    **********/ 
    
    pnode headNode = (pnode)malloc(sizeof(pnode));
    

    printf("%p\n", &headNode);
    char command; 
    scanf("%c", &command);
    while(command != (char)EOF){

        switch (command) {
                case 'A': 

                    //deleteGraph_cmd(pnode* head);
                    command = build_graph_cmd(&headNode);
                    printf("main %d\n", headNode->node_num);
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