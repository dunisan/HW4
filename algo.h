#include "graph.h"

int shortestPath_cmd(pnode head, int sourceNode, int destinationNode);
pnode dijkasraNextNodeToCheck(pnode head);
void TSP_cmd(pnode head);   // t shortest path
void swap(int nodes[], int i, int j);

void check(pnode head, int *arr, int k, int curr, int *result);
