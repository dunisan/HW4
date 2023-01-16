#include "graph.h"
#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edges.h"


#define WORD 4 
// build the graph, a pointer to head of graph

void createGraph(pnode *head, int n); // create grapg with n nodes 

/*
Build the graph. 
create n nodes and than insert all te given edges. 
*/
char build_graph_cmd(pnode *head){  
    
    // get the size of the graph 
    int sizeOfGraph = 0;  
    scanf("%d", &sizeOfGraph);
    //create graph with 'sizeOfGraph' nodes 
    createGraph(head, sizeOfGraph);
    char command; 
    command = createEdges(head); 

    return command; 
    

}

int isCommand(char ch){
    if(ch == 'A' || ch == 'B' || ch == 'T'){
        return 1;
    }
    return 0;
}



void createGraph(pnode *head, int n){
    
    pnode current = *head;

    //  create a linked list with sizeOfgraph nodes. 

    for(int i=0; i<n; i++){
        current->edges = NULL;
        current->node_num = i; 
        printf("node number %d \n", current->node_num); 
       
        if(i == n-1){
            break;
        }    
        current->next = (pnode)malloc(sizeof(pnode)); 
        current = current->next; 

    }
         
   
    return; 
}















//void insert_node_cmd(pnode *head);  // insert a new node. head is the pointer to the head of graph
//void delete_node_cmd(pnode *head);  // delete a node. 
void printGraph_cmd(pnode *head){
    pnode current = *head; 

    printf("*******************************************************************************************************************\n");
    while(current!=NULL){
        pedge currEdge = current->edges; 

        printf("node number %d ------------------->    " , current->node_num);
        while(currEdge!=NULL){
            printf("%d", currEdge->endpoint->node_num);
            
            if(currEdge->next==NULL){
                break; 
            } 

        }
        printf("\n\n");
        if(current->next == NULL){
            break; 
        }
        current = current->next; 
    
    }

    printf("********************************************************************************************************************\n");

}
//void deleteGraph_cmd(pnode* head); // delete all of the graph 
//void shortsPath_cmd(pnode head);   // find the shortest path 
//void TSP_cmd(pnode head);   // t shortest path 
