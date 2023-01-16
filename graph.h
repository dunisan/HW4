
#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

// The struct for the edges 
typedef struct edge_ {
    int weight;     // the weight of the edge
    pnode endpoint;     // The node that the edge goes to 
    struct edge_ *next; // I do not understand what is this for.. maybe the next edge of the node? 
} edge, *pedge;


// struct of the grapg nodes 
typedef struct GRAPH_NODE_ {
    int node_num;   // the node number
    pedge edges;    // a pointer to list of the edges of each nodes 
    struct GRAPH_NODE_ *next;   // the next node on the graph 
} node, *pnode;



char build_graph_cmd(pnode *head);  // build the graph, a pointer to head of graph
void insert_node_cmd(pnode *head);  // insert a new node. head is the pointer to the head of graph
void delete_node_cmd(pnode *head);  // delete a node. 
void printGraph_cmd(pnode *head); //for self debug
void deleteGraph_cmd(pnode* head); // delete all of the graph 
void shortsPath_cmd(pnode head);   // find the shortest path 
void TSP_cmd(pnode head);   // t shortest path 

#endif
