#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include <string.h>


void build_graph_cmd(pnode *head, char *str){
    // first clear graph if one exist
    int sizeGraph;
    sizeGraph = *str-'0';
    insert_node_cmd(head, sizeGraph);
    str++;
    // n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
    add_edge_tonode(head, str);
}

// function to get node 
pnode getNode(pnode *head, int id) {
    // if head is null there are no nodes
    if(head == NULL) {
        return NULL;
    }
    // create curr node
    pnode curr = *head;
    // go next untill found node id 
    while(curr != NULL && curr->node_num != id) {
        curr = curr->next;
    }
    // return node
    return curr;
}

// add node to graph
void insert_node_cmd(pnode *head, int size){
    // if size of graph is 0 return nothing
    if(size == 0){
        return;
    }
    // temp node 
    pnode temp = NULL;
    // allocate memory for node
    temp = (pnode)malloc(sizeof(node));
    if(temp == NULL){
        printf("No memory allocated\n");
        exit(0);
    }
    // first node will always be 0
    temp->node_num = 0;
    temp->next = NULL;
    *head = temp;
    pnode curr = temp;
    // link the rest of the nodes
    for(int i = 1; i< size; i++){
        pnode new = NULL;
        new = (pnode)malloc(sizeof(node));
        if(new == NULL){
            printf("No memory allocated");
            exit(0);
        }

        new->node_num = i; 
        new->next = NULL;
        curr->next = new;
        curr = curr->next;
    }
}

// function to add edged to nodes
void add_edge_tonode(pnode *head, char *str){
    // n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 T
    while(*str != 'T'){
        str++;
        // 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 T
        int node_id = *str - '0';
        str++;
        // 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 T
        pnode node_src = getNode(head, node_id);
        node_src->edges = NULL;
        pedge edge_head = NULL;        
        while(*str != 'n' && *str != 'T'){
            pedge new_edge = (pedge)malloc(sizeof(edge));
            if(new_edge == NULL){
                printf("No memory allocated");
                exit(0);
            }
            new_edge->endpoint = getNode(head, *str-'0');
            str++;
            // 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 T
            new_edge->weight = *str-'0';
            new_edge->next = NULL;
            if(node_src->edges == NULL){
                node_src->edges = new_edge;
                edge_head = new_edge;
            }
            else{
                edge_head->next = new_edge;
                edge_head = edge_head->next;
            }
            str++;
        }
    } 
}          













int main(){
    // A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
    char input [23] = "A4n02533n20411n13702T\0", *ptr;
    ptr = input; 
    pnode temp = NULL;
    pnode *head = &temp;
    ptr++;
    build_graph_cmd(head, ptr);
    while(temp!=NULL){
        printf("Node num : %d\n", temp->node_num);
        while(temp->edges!=NULL){
            printf("Weight: %d\n", temp->edges->weight);
            temp->edges = temp->edges->next;
        }
        temp = temp->next;
    }
    return 0; 
}
