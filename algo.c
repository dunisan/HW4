#include "graph.h"
#include "headers.h"
#include <stdio.h>



/******************************
        SHORTEST_PATH 
******************************/ 

int shortestPath_cmd(pnode head, int sourceNode, int destinationNode)
{


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






void swap(int nodes[], int i, int j) 
{ 
    int temp; 
    temp = nodes[i]; 
    nodes[i] = nodes[j]; 
    nodes[j] = temp;

} 


void TSP_cmd(pnode head)
{
    // getting input and inserting number to an array
    int p;
    scanf("%d", &p);
    int result = __INT_MAX__;

    int *nums = (int *)(malloc(sizeof(int) * p));


    
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &nums[i]);
    }

    // checking every possible vertex to start from
    for (int i = 0; i < p; i++)
    {
        swap(nums, 0, i);
        permute(head, nums, p, 0, &result);
        swap(nums, i, 0);
    }

    if (result == __INT_MAX__)
    {
        result = -1;
    }


    free(nums);



    printf("TSP shortest path: %d \n", result);
}

void permute(pnode head, int *arr, int k, int curr, int *result)
{
    // only 2 nodes -run dijakstra 
    if (k == 2)
    {
        int distance = shortestPath_cmd(head, arr[0], arr[1]);


        if (distance != -1 && (curr + distance) < *result)
        {
            *result = (curr + distance);
        }


        return;
    }

    //check for all pathes 
    for (int i = 1; i < k; i++)
    {
        swap(arr, 1, i);
        int dist = shortestPath_cmd(head, arr[0], arr[1]);
        if (dist == -1)
        {
            return;
        }
        permute(head, arr + 1, k - 1, curr + dist, result);
        swap(arr, i, 1);
    }
}