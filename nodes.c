#include "headers.h"



/***************************************
           INSERT A NEW NODE
***************************************/
char insert_node_cmd(pnode *head){
   
    int sourceNode;  // get the number of the source node
    scanf("%d", &sourceNode);  

    removeEdges(head,  sourceNode);
    createNewNode(head, sourceNode);

    char command;   // The given char might be a new command or an EOF or 'n'         
    int edge[3];   // edge[0] - source node.. edge[1] - destination node.. edge[2] - weight

    edge[0] = sourceNode; 
    
    int i=0; 

    while(1){ 

        scanf(" %c", &command);  // get the char - it might be EOF or next command of n

        if(isCommand(command)){      // return the new command

            return command; 
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

    

           
    
    
    createNewEdge(edge,head); // create the new edge 

            
    return command;
    
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
        current->next = (pnode)malloc(sizeof(node)); 
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

    pnode prev = NULL; 

    while(curr != NULL){
        if(curr->node_num == n){
            break; 
        }
        prev = curr; 
        curr = curr->next; 
    }

    if(curr == NULL){
        return; 
    }


    if(prev==NULL)
    {
        *head = curr->next; 
    }
    else{
        prev->next = curr->next;
    }

    free(curr); 
     
            
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


