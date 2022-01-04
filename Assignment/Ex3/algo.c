#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include <string.h>


void build_graph_cmd(pnode *head, char *str){
    // first clear graph if one exist
    int sizeGraph;
    sizeGraph = *str-'0';
    for(int i = 0; i<sizeGraph; i++){
        insert_node_cmd(head, i);
    }
    str++;
    printf("%c\n", *str);
     // n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
    add_edge_tonode(head, str);
}

void insert_node_cmd(pnode *head, int id){
    pnode index = *head;
    pnode src = (pnode)malloc(sizeof(node));
    src->node_num = id;
    src->next = NULL;
    src->edges = NULL;
    if(src == NULL){
        exit(0);
    }
    if(index == NULL){
        *head = src;
    }
    else{
        while(index->next != NULL){
            index = index->next;
        }
        index->next = src;
    }
}

void add_edge_tonode(pnode *head, char *str){
    // n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 T
    while(*str != 'T'){
        str++;
        // 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 T
        int node_id = *str - '0';
        str++;
        // 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 T
        int counter = 0;
        pnode node_src = *head;
        while(node_src->node_num != node_id){
            node_src = node_src->next;
        }
        pedge edge_head = node_src->edges;
        // 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 T
        while(*str != 'n' || *str != 'T'){
            pedge new_edge = (pedge)malloc(sizeof(edge));
            if(new_edge == NULL){
                exit(0);
            }
            pnode node_dest = *head;
            while(node_dest->node_num!=*str-'0'){
                node_dest = node_dest->next;
            }
            // addint endpoint.
            new_edge->endpoint = node_dest;
            str++;
            // 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 T
            // adding weight 
            new_edge->weight = *str - '0';
            // makeing next Null
            new_edge->next = NULL;
            // linking the new edge
            if(edge_head == NULL){
                edge_head = new_edge;
            }
            else{
                while(edge_head != NULL){
                    edge_head = edge_head->next;
                }
                edge_head = new_edge;
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
    return 0; 
}
