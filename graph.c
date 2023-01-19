#include "graph.h"
#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edges.h"
#include "nodes.h"
#include <unistd.h>



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



/****************************************
create n nodes of the graph - linked list
*********************************/
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


void delete_node_cmd(pnode *head){  // delete a node. 
   
    int nodeNumber; 
    scanf("%d", &nodeNumber);

    // remove the inedges, edges and node

    removeInedges(head, nodeNumber);
    removeEdges(head, nodeNumber);
    remove_node(head, nodeNumber); 

    return;

}


int shortestPath_cmd(pnode head)
{

    printf("start of shortest path\n");
    int sourceNode, destinationNode; 
    scanf("%d %d", &sourceNode, &destinationNode); 
    pnode source;
    pnode dest;
    pnode current = head;

    // find the source node and the distination node && Initialize all nodes.pathDistance and node.visited 
    while (current != NULL)
    {
        current->pathDistance = __INT_MAX__; // initialize every node to be with max distance 
        current->visited = 0;       // initialize every node to be 'not visited' 


        if (current->node_num == sourceNode){
            source = current; // this is the source node 
            source->pathDistance = 0;   // This is the distance from the source (itself)
        }
        else if (current->node_num == destinationNode){
            dest = current; // this is the destination node. 
        }
        current = current->next;     
    }


    // dijkstra

    current = source; // point to the souce node 
    while (current)
    {
        current->visited = 1; // mark the current edge as visited. 
        pedge currentEdge = current->edges; // point to the first edge of node 

        // pass all edges and update the path distance of endpoint if needed 
        while (currentEdge != NULL){

            // if we found a shorter length to the next endpoint of every node so update the endpoint pathDistance
            if (!currentEdge->endpoint->visited && current->pathDistance + currentEdge->weight < currentEdge->endpoint->pathDistance)
            {
                currentEdge->endpoint->pathDistance = current->pathDistance + currentEdge->weight;
            }
            currentEdge = currentEdge->next;
        }
        // go to the next min node .
        current = dijkasraNextNodeToCheck(head);
    }
    
    if (dest->pathDistance == __INT_MAX__)
    {
        dest->pathDistance = -1;
    }

    printf(" the shortest [ath %d\n", dest->pathDistance);
    return dest->pathDistance;
}


pnode dijkasraNextNodeToCheck(pnode head)
{
    int min = __INT_MAX__;
    pnode temp = NULL;
    while (head)
    {
        if (!head->visited && head->pathDistance < min)
        {
            min = head->pathDistance;
            temp = head;
        }
        head = head->next;
    }
    return temp;
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