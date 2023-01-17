// here we will implement the edges functions. 

#include "edges.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

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
        curr = curr->next; //2, 3, 4, 5 
    }

    
    // go over to destination node  
    while(endpoint != NULL && endpoint->node_num != arr[1]){
        if(endpoint->next == NULL){
            printf("Error - unvalid destination node\n"); 
            exit(1); 
        }
        endpoint = endpoint->next; 
    }


    // if edges = null -> insert the first edge

    if(curr->edges == NULL){
        //create the new edge 
        pedge newedge = (pedge)malloc(sizeof(edge));
        newedge->next = NULL;
        newedge->endpoint = endpoint; 
        newedge->weight = arr[2]; 

        curr->edges = newedge; // insert the new edge 
        

        curr->edges->endpoint = endpoint;  
        
        // insert into the distination node an inedge. 
        endpoint->inedges = (pedge)malloc(sizeof(pedge)); 
        endpoint->inedges = curr->edges; 


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
    
    //printGraph_cmd(head);
    
 
    return; 
}


void removeEdges(pnode *head, int number){
    
    pnode curr= *head; // find the source node

    if(curr == NULL){
        return; 
    }
    
    // source node
    while(curr->next != NULL && curr->node_num != number){
        curr = curr->next; 
    }

    // their isnt the wanted node
    if(curr->node_num != number){
        return; 
    }

    // their is no edges for the node 
    if(curr->edges == NULL){
        return;
    }

    // free all edges of the current node
    pedge tempedge = curr->edges; 
    curr->edges = NULL;
    while(tempedge->next != NULL){
         
        free(tempedge); 
        tempedge = tempedge->next; 

    }
    printNodes(head);
    printGraph_cmd(head);
    return;
    

}
