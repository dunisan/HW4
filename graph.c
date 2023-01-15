#include "headers.h"

// build the graph, a pointer to head of graph


void build_graph_cmd(pnode *head){  
    
    int sizeOfGraph = 0; 
    scanf("%d", &sizeOfGraph);

    printf("%p\n", head);
    printf("%lu\n", sizeof(**head)); // the size of the struct 
    printf("%lu\n", sizeof(node)); // the size of the struct 


    // //*head is the address of the node. head is the adress of the pointer. pnode is a pointer to node. 
    // *head =  (pnode)malloc(sizeof(head)); // malloc - return an adress and onvert to node adrees 
    //                                                 // *head points to the first byte of the first node
    // // create 'sizeOfGraph' node. 
    // // createGraph(head, sizeOfGraph)
    node *current = *head;
    for(int i=1;i<=sizeOfGraph;i++){
        *head = (node *)malloc(sizeof(node)); 
        *head->node_num=i; 
        current = current->next; 
    }                                      

    free(*head); 

}
















//void insert_node_cmd(pnode *head);  // insert a new node. head is the pointer to the head of graph
//void delete_node_cmd(pnode *head);  // delete a node. 
//void printGraph_cmd(pnode head); //for self debug
//void deleteGraph_cmd(pnode* head); // delete all of the graph 
//void shortsPath_cmd(pnode head);   // find the shortest path 
//void TSP_cmd(pnode head);   // t shortest path 
