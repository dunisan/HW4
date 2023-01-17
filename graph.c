#include "graph.h"
#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edges.h"



void createGraph(pnode *head, int n); // create graph with n nodes 

/*************************************************
Build the graph. 
create n nodes and than insert all te given edges. 
**************************************************/

char build_graph_cmd(pnode *head){  
    
    // get the size of the graph 
    int sizeOfGraph = 0;  
    scanf("%d", &sizeOfGraph);

    //create graph with 'sizeOfGraph' nodes 
    createGraph(head, sizeOfGraph);

    char command; // the next command on graph 
    command = createEdges(head);  

    return command; // return the next command to go to (B,T,S,... )
    

}

/*******************************************
check if a given char is a type of a command
******************************************/
int isCommand(char *ch){
    if(strcmp(ch, "T") == 0 || strcmp(ch, "B") == 0  || strcmp(ch, "S") == 0 ){
        return 1;
    }
    return 0;
}


/****************************************
create n nodes of the graph - linked list
*********************************/
void createGraph(pnode *head, int n){
    
    pnode current = *head;
    
    //  create a linked list with sizeOfgraph nodes. 

    for(int i=0; i<n; i++){
        current->edges = NULL;
        current->node_num = i; 
       
        if(i == n-1){
            break;
        }    
        current->next = (pnode)malloc(sizeof(pnode)); 
        current = current->next; 

    }
         
   
    return; 
}


/***************
print the graph
***************/

void printGraph_cmd(pnode *head){
    printf("********************************************************\n");
    printf("--------------------------------------------------------\n");
    printf("Graph representation [src]--------(weight)------->[dest]\n\n");
    
    pnode curr = *head;
 
    while (curr != NULL)
    {
        /************ NEVER BREAKS ************/ 

        pedge current_edge = curr->edges;
        if (current_edge == NULL)
        {
            printf("[%d]\n", curr->node_num);

        }

        while (current_edge != NULL)
        {
            printf("[%d]---------(%d)--------->[%d]\n", curr->node_num, current_edge->weight, current_edge->endpoint->node_num);
            current_edge = current_edge->next;


        }

        curr = curr->next; 

        
    }
    printf("\n---------------------------------------------------------\n");
    printf("**********************************************************\n");

}

