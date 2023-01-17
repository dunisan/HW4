#include "headers.h"
#include "edges.h" 
#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>
// here we will implement the nodes functions

char insert_node_cmd(pnode *head){

    int numberOfNode; 
    scanf("%d", &numberOfNode); 

    removeEdges(head,  numberOfNode);

    
    createNewNode(head, numberOfNode);

    int destEdge, weight;  // the edge we are going to and it's weight
        
    int i=0;   
    int edge[3];   // the source node, destination node, and the weight of edge 
    char ch[20];
    edge[0] = numberOfNode; 

    // get all edges of specific node 
    while(1){ 

        scanf("%s", ch);  // get the char - it might be EOF or next command of n
        
        printf("check if command %s\n", ch);
        // return the new command 
        if(isCommand(ch)){
            return ch[0]; 
        }
        
                    
        // get a desination node and the weight of the node
        if(i%2==0){
            destEdge = atoi(ch); // conver num to int
            edge[1] = destEdge;    
            i+=1;      
        }
        else{
            weight = atoi(ch);
            edge[2] = weight; 
            i-=1; 
            
            
            createTheEdges(edge,head); // create the new edge 

            
            
        } 

    }
}

void createNewNode(pnode *head, int numberOfNode){

    pnode current = *head;

    while(current->next != NULL){
        if(current->node_num == numberOfNode){
            return; 
        }
        current = current->next; 
    } 

    
    current->next = (pnode)malloc(sizeof(pnode)); 
    
    current->edges = NULL;
    current->node_num = numberOfNode; 
 

    

    return; 
} 


void remove_node(pnode *head, int n){
    pnode curr= *head; // find the source node

    // source node
    while(curr != NULL && curr->node_num != n){
        if(curr->next==NULL){
            printf("Error - invalid node\n"); 
            return;
        }
        curr = curr->next; //2, 3, 4, 5 
    }

    //removeEdges(edges);
    free(curr);  
    printGraph_cmd(head);
}


void printNodes(pnode *head){

    pnode curr = *head; 
    while(curr->next != NULL){
        printf("[%d] ----  >", curr->node_num); 
        curr = curr->next;
    }
    printf("[%d]\n", curr->node_num); 
}
