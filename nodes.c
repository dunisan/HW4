#include "headers.h"



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
    CREATE A NEW NODE - if needed
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

/***************************************
            REMOVE A NODE
****************************************/
void remove_node(pnode *head, int n){
    
    pnode curr= *head; // find the source node

    // the node to delete is the first 
    if(curr->node_num == n)
    {
        // check if their is a next node
        if(curr->next != NULL)
        {
            free(*head);
            *head = (*head)->next;
        }
        else{
            free(*head); 
            *head = NULL; 
            return; 
        }
    }

    // the node is not first 
    
    while(curr->next != NULL)
    {
        if(curr->next->node_num == n)
        {
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
    }
}


/****************************
    PRINT LIST OF NODES
****************************/

void printNodes(pnode *head){

    pnode curr = *head; 
    while(curr->next != NULL){
        printf("[%d] ----  >", curr->node_num); 
        curr = curr->next;
    }
    printf("[%d]\n", curr->node_num); 
}


