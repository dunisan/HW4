// here we will implement the edges functions. 

#include "edges.h"
#include <stdio.h>
#include <stdlib.h>


char createEdges(pnode *head){ 

    getchar(); // ignore the whitespace  
    
    char node;  
    node = getchar(); // expecting 'n' 
    if(node != 'n'){
        perror("invalid input");
        exit(1); 
    }

    while(1){

        int nodeNumber; // number of edge to insert in 
        scanf("%d", &nodeNumber);  

        int edgeTo, weight;  // the edge we are going to and it's weight
        char ch;       
        int i=0;
        int edge[3];   // not necceary 

        edge[0] = nodeNumber; 

        while(1){ 
            getchar(); // ignore white space
            ch = getchar();  // get the char - it might be EOF or next command of n
            if(isCommand(ch)){
                return ch; 
            }

            if(ch == 'n'){ 
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
                createTheEdges(edge,head); 
                
            } 

            
        }

    }
}



int createTheEdges(int arr[3],pnode *head){
    pnode curr= *head;
    pnode endpoint = *head; 
    


    while(curr != NULL && curr->node_num != arr[0]){
        if(curr->next==NULL){
            printf("\n\n Error - supposed to be a node\n"); 
            exit(1); 
        }
        curr = curr->next;
    }


    while(endpoint->node_num != arr[1]){
        if(endpoint->next==NULL){
            printf("\n\n Error - supposed to be a node\n"); 
            exit(1); 
        }
        endpoint = endpoint->next; 
    }


    while (curr->edges != NULL) {
        if(curr->edges->next == NULL){
            curr->edges = curr->edges->next; 
            break;  
        }
    }

    curr->edges = malloc(sizeof(pedge)); 
    curr->edges->endpoint = endpoint;  
    curr->edges->weight = arr[2]; 
    curr->edges->next = NULL; 


    return 0; 
}

