// here we will implement the edges functions. 

#include "edges.h"
#include <stdio.h>
#include <stdlib.h>

/**********************************************
The function parses output and create a node 
at a time. 
***********************************************/

char createEdges(pnode *head){ 

    getchar(); // ignore the whitespace  
    
    // get the first 'n'
    char node;  
    node = getchar(); // expecting 'n' 
    if(node != 'n'){
        perror("invalid input");
        exit(1); 
    }

    // get all of the edges
    while(1){

        // get the number of the source node
        int nodeNumber;  
        scanf("%d", &nodeNumber);  

        // get the destination node and the weight of edge
        int destEdge, weight;  // the edge we are going to and it's weight
        
        char ch[3];   // The given char might be a new command or an EOF or 'n'         
        int i=0;   
        int edge[3];   // the source node, destination node, and the weight of edge 

        edge[0] = nodeNumber; 

        // get all edges of specific node 
        while(1){ 

            scanf("%s", ch);  // get the char - it might be EOF or next command of n

            // return the new command 
            if(isCommand(ch)){
                return ch[0]; 
            }
            
            // go back to get new edges for a node
            if(strcmp(ch, "n") == 0){ 
                break; 
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

            
        } // inner while

    }// extern while 
} // end of function 


/*******************
create a new node
*******************/


void createTheEdges(int arr[3],pnode *head){

    pnode curr= *head; // find the source node
    pnode endpoint = *head;  // find the destination node 
    
    // source node
    while(curr != NULL && curr->node_num != arr[0]){
        if(curr->next==NULL){
            printf("\n\n Error - supposed to be a node\n"); 
            exit(1); 
        }
        curr = curr->next;
    }

    // destination node 
    while(endpoint->node_num != arr[1]){
        if(endpoint->next==NULL){
            printf("\n\n Error - supposed to be a node\n"); 
            exit(1); 
        }
        endpoint = endpoint->next; 
    }

    // if edges = null -> insert the first edge
    if(curr->edges == NULL){
        curr->edges = malloc(sizeof(pedge)); 
        curr->edges->endpoint = endpoint;  
        curr->edges->weight = arr[2]; 
        curr->edges->next = NULL;

        return; 
    }

    // create the new edge

    pedge newedge = (pedge)malloc(sizeof(edge)); 
    newedge->endpoint = endpoint;  
    newedge->weight = arr[2]; 
    newedge->next = NULL; 

    // point the the first edge
    pedge temp = curr->edges;

    // move to the last edge
    while (temp->next != NULL) {
        //curr->edges = curr->edges->next;
        temp = temp->next;  
    }
    
    // insert the new edge it the end of the edges. 
    temp->next = newedge; 
 
    return; 
}

