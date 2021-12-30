#include <stdio.h>
#include "graph.h"
#include <stdlib.h>


void build_graph_cmd(pnode *head){
    int sizeGraph;
    scanf("%d", &sizeGraph);
    for(int i = 0; i<sizeGraph; i++){
        insert_node_cmd(head, i);
    }
    char n = '#';
    scanf("%c", &n);
    int num = 0; 
    scanf("%d", &num);
    add_edge_tonode(head, num);   
}

void add_edge_tonode(pnode *head, int id){
    pnode index = *head;
    while(index->node_num != id){
        index = index->next;
    }
    pedge e = index->edges;
    if(e == NULL){
        scanf
    }
    while(e->next != NULL){
        e = e->next;
    }
    
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





int main(){
    pnode temp = NULL;
    pnode *head = &temp;
    build_graph_cmd(head);
    while(temp!=NULL){
        printf("%d\n", temp->node_num);
        temp = temp->next;
    }
    return 0; 
}
