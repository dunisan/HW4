// here we will implement the edges functions. 

#include "headers.h"
#include <stdio.h>

/**********************************************
The function parses output and create a node 
at a time. 
***********************************************/

char createEdges(pnode *head){ 

    // get the first 'n'
    char node;  
    scanf(" %c", &node);

    if(node != 'n'){
        perror("invalid input");
        exit(1); 
    }

    // prepare the creation of the edges
    while(1)
    {
        int sourceNode;  // get the number of the source node
        scanf("%d", &sourceNode);  

        char command;   // The given char might be a new command or an EOF or 'n'         
        int edge[3];   // edge[0] - source node.. edge[1] - destination node.. edge[2] - weight

        edge[0] = sourceNode; 
        
        int i=0; 

    
        while(1){ 

            scanf(" %c", &command);  // get the char - it might be EOF or next command of n
  
            if(isCommand(command)){      // return the new command

                return command; 
            }
           
            if(command ==  'n'){  // go back to get new edge for a node
                break; 
            }

            int destNode, weight;          // get the destination node and the weight of edge
             
            // get a desination node and the weight of the node
            if(i%2==0){
                destNode = command - '0'; // conver num to int
                edge[1] = destNode;    
                i+=1;      
            }
            else{
                weight = command - '0';
                edge[2] = weight; 
                i-=1; 

                createNewEdge(edge,head); // create the new edge 
            } 
        }
    }
}


/*******************
create a new node
*******************/


void createNewEdge(int arr[3],pnode *head){
    pnode curr= *head; // find the source node
    pnode endpoint = NULL;  // find the destination node 
    pnode sourcenode = NULL; 

    while(curr != NULL)
    {

        if(curr->node_num == arr[0]){
            sourcenode = curr; 
        }

        if(curr->node_num == arr[1]){
            endpoint = curr; 
        }

        curr = curr->next; 
    }

    // create the new edge 
    pedge newedge = (pedge)malloc(sizeof(edge));
    newedge->next = NULL;
    newedge->endpoint = endpoint; 
    newedge->weight = arr[2];

    // if no edges insert to beggining
    if(sourcenode->edges == NULL)
    {
        sourcenode->edges = newedge; // insert the new edge 

    }

    else
    {

        pedge tempedge = sourcenode->edges;

        // move to the last existing edge
        while (tempedge->next != NULL)
        {
            tempedge = tempedge->next;  
        }
        
        // insert the new edge it the end of the edges. 
        tempedge->next = newedge; 
    
    }

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
        pedge *temp = &tempedge->next; 
        tempedge = NULL;
        free(tempedge); 
        tempedge = *temp;

    }
    
    return;
    

}

void removeInedges(pnode *head, int n){
    pnode tempnode = *head; 

    while(tempnode->next != NULL){

        // if the current node is the node that we are deleting(no edges to itself)

        if(tempnode->node_num  == n){
            tempnode = tempnode->next;
            continue;
        }

        pedge tempedge = tempnode->edges; 
        
        // if no edges - continue to the next node
        if(tempedge == NULL){
            tempnode = tempnode->next;
            continue;
        }

        /*****************************************************************
         pass over the edges and search to a edge that his endpoint.nodenum is n
         if their is so tell the prev node to pint to the next.
         *****************************************************************/

        // if the first edge goes to n 
        if(tempedge->endpoint->node_num == n){
            if(tempedge->next != NULL){

                tempnode->edges = tempnode->edges->next;
                tempedge = NULL; 
                free(tempedge);

            }
            else{
                tempnode->edges = NULL; 
                free(tempnode->edges);
            }

            continue; // to the next node; 
        }

        // the edge might be in the middle
        while (tempedge->next != NULL) {
            if(tempedge->next->endpoint->node_num == n){

                // if their is a next node 
                if(tempedge->next->next != NULL){
                    tempedge->next = tempedge->next->next;
                }
                else {
                    tempedge->next = NULL; 
                }
                
                
                free(tempedge->next);
                continue; // found the edge - no need to go the next edge  
            }

            tempedge = tempedge->next;
        }

        tempnode = tempnode->next; 

    }


}


/*******************************************
check if a given char is a type of a command
******************************************/
int isCommand(char ch){
  //  if(strcmp(ch, "T") == 0 || strcmp(ch, "B") == 0  || strcmp(ch, "S") == 0  || strcmp(ch, "D") == 0 ){
    if(ch == 'T' || ch == 'B' || ch == 'S' || ch == 'D' || ch == 'A')
    {
        return 1;
    }
 
    

    return 0;
}
