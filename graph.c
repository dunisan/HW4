#include "headers.h"








/*************************************************
                BUILD THE GRAPH
**************************************************/

char build_graph_cmd(pnode *head){  
    
    // get the size of the graph 
    int sizeOfGraph;  
    scanf("%d", &sizeOfGraph);

    //create graph with 'sizeOfGraph' nodes 
    createGraph(head, sizeOfGraph); // create n nodes 

    char command; // the next command on graph 

    command = createEdges(head);  

    return command; // return the next command to go to (B,T,S,... )
    

}



/****************************************
        CREATE N NODES OF GRAPH
*****************************************/
void createGraph(pnode *head, int n){

    // create the head of the graph

    (*head) = (pnode)(malloc(sizeof(pnode))); 
    (*head)->edges = NULL; 
    (*head)->node_num = 0; 


    pnode current = *head;
    
     //  create a linked list with sizeOfgraph nodes. 
    for(int i=0; i<n-1; i++)
    {

        current->next = (pnode)malloc(sizeof(pnode)); 
        current->next->edges = NULL;
        current->next->node_num = i+1; 
        
        current = current->next; 
    }
   
    return; 
}


/****************************************
print the graph
*****************************************/

void printGraph_cmd(pnode *head){
    printf("********************************************************\n");
    printf("********************************************************\n");
    printf("***--------------------------------------------------***\n");
    printf("***----[src]------------(weight)-------------->[dest]***\n");
    printf("***                                                  ***\n");
    pnode curr = *head;
 
    while (curr != NULL)
    {
        pedge current_edge = curr->edges;

        if (current_edge == NULL)
        {
            printf("***      [%d]                                         ***\n", curr->node_num);
        }

        while (current_edge != NULL)
        {

            printf("***      [%d]---------------(%d)------------->[%d]      ***\n", curr->node_num, current_edge->weight, current_edge->endpoint->node_num);
            current_edge = current_edge->next;

        }
        curr = curr->next; 
    printf("***                                                  ***\n");
        
    }
    printf("\n------------------------------------------------------\n");
    printf("********************************************************\n");
    printf("********************************************************\n");


}


void delete_node_cmd(pnode *head){  // delete a node. 
   
    int nodeNumber; 
    scanf("%d", &nodeNumber);

    // remove the inedges, edges and node
    removeInedges(head, nodeNumber);

    removeEdges(head, nodeNumber);

    remove_node(head, nodeNumber); 

    return;

}








/********************************************
              DELETE GRAPH 
*********************************************/


void deleteGraph_cmd(pnode* head){ // delete all of the graph 


    pnode curr = *head; 

    while(curr != NULL)
    { 
        removeEdges(head, curr->node_num);
        remove_node(head, curr->node_num);
        curr = curr->next ; 

    } 

    
    return; 



}