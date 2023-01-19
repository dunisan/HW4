#include "graph.h"
#include "headers.h"
#include "edges.h" 
#include "nodes.h"
//#include <cstddef>
#include <stdio.h>
#include <stdlib.h>


/***************************************
           INSERT A NEW NODE
***************************************/
void insert_node_cmd(pnode *head){

    int numberOfNode, destinationNode, weight; 
    scanf("%d %d %d", &numberOfNode, &destinationNode, &weight); 
   
    int edge[3] = {numberOfNode,destinationNode,weight};  // the source node, destination node, and the weight of edge  
           
    removeEdges(head,  numberOfNode);
    createNewNode(head, numberOfNode);
    
    createNewEdge(edge,head); // create the new edge 

            
    return;
    
}


/******************************************
If node does not exists - create a new one
*******************************************/

void createNewNode(pnode *head, int numberOfNode){

    pnode current = *head;

    // check if their is the node. if not - insert a new; 

    while(current->next != NULL){
        if(current->node_num == numberOfNode){
            return; 
        }
        current = current->next; 
    } 
    if(current->node_num == numberOfNode)
    {
        return; 
    }
    else
    {
        current->next = (pnode)malloc(sizeof(pnode)); 
        current->next->edges = NULL;
        current->next->node_num = numberOfNode; 
 
    }
    
    return; 
} 


void remove_node(pnode *head, int n){
    
    pnode curr= *head; // find the source node

    // the node to delete is the first 
    if(curr->node_num == n){

        // check if their is a next node
        if(curr->next != NULL){
            *head = (*head)->next;
        }
        else{
            *head = NULL; 
            free(*head); 
            return; 
        }
    }

    // the node is not first 

    while(curr->next != NULL){
        if(curr->next->node_num == n){
          //  printf("%d\n", curr->next->node_num);
            if(curr->next->next != NULL){
                free(curr->next); 
                curr->next = curr->next->next;
                return;
            }
            else{
                free(curr->next);
                curr->next = NULL; 
                return; 
            }
        }
        curr = curr->next;

        if(curr->next == NULL){
            return;
        } 
    }

    printf("Error - the node doesn't exits\n");  
}


void printNodes(pnode *head){

    pnode curr = *head; 
    while(curr->next != NULL){
        printf("[%d] ----  >", curr->node_num); 
        curr = curr->next;
    }
    printf("[%d]\n", curr->node_num); 
}


