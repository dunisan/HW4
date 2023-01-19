#include "headers.h"



/******************************
        SHORTEST_PATH 
******************************/ 

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
    printf("%d\n", dest->pathDistance);
    return dest->pathDistance;
}


/***************************************
    DIJKASRA_NEXT_NODE_TO_CHECK 
****************************************/

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


