// here we will implement the edges functions. 

#include "edges.h"


char createEdges(pnode *head){ 

    getchar(); // ignore the whitespace  
    
    char node;  
    node = getchar(); // expecting 'n' 
    printf("%c", node); 
    if(node != 'n'){
        perror("invalid input");
        exit(1); 
    }

    while(1){

        int nodeNumber; // number of edge to insert in 
        scanf("%d", &nodeNumber);  
        printf("we are now inserting edges into node number %d\n", nodeNumber); 

        int edgeTo, weight;  // the edge we are going to and it's weight
        char ch;       
        int i=0;
        int edge[3];   // not necceary 

        edge[0] = nodeNumber; 

        while(1){ 
            getchar(); // ignore white space
            ch = getchar();  // get the char - it might be EOF or next command of n
            if(isCommand(ch)){
                printf("move on to the next command");
                return ch; 
            }

            if(ch == 'n'){ 
                printf("Insert a new node\n"); 
                break; 
            }

            if(i%2==0){
                edgeTo = ch -'0'; // conver num to int
                edge[1] = edgeTo;    
                i+=1;      
            }
            else{
                weight = ch - '0';
                edge[2] = weight; 
                i-=1; 
                printf("[%d,%d]\n",edge[0],edge[1]);
                printf("try insert a new edge\n");

                createTheEdges(edge,head); 
                printGraph_cmd(head); 
                
            } 

            
        }

    }
}



int createTheEdges(int arr[3],pnode *head){
    pnode curr= *head;
    pnode endpoint = *head; 


    while(curr != NULL && curr->node_num != arr[0]){
        curr = curr->next;
    }

    while(endpoint->node_num != arr[1]){
        endpoint = endpoint->next; 
    }
    
    pedge currEdge = curr->edges; 

    while (currEdge != NULL) {
        currEdge = currEdge->next; 
    }

    currEdge = (pedge)malloc(sizeof(pedge)); 
    currEdge->endpoint = endpoint;  
    currEdge->weight = arr[2]; 
    currEdge->next = NULL; 
    



    return 0; 
}

