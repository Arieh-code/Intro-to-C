#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include <string.h>


void build_graph_cmd(pnode *head, char *str){
    // first clear graph if one exist
    // 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
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

void add_new_node(pnode *head, char *str){
    // 5 0 4 2 1 B
    int node_id = *str -'0';
    str++;
    // 0 4 2 1 B
    // flag to check if the node exists
    int flag = 0; 
    pnode index = *head;
    while(index != NULL){
        if(index->node_num == node_id){
            flag = 1;
            index = index->next;
        }
        else{
            index = index->next;
        }
        
    }
    if(!flag){
        pnode new = NULL;
        new = (pnode)malloc(sizeof(node));
        if(new == NULL){
            printf("No memory allocated");
            exit(0);
        }
        new->node_num = node_id;
        new->next = NULL;
        new->edges = NULL;
        if(*head == NULL){
            *head = new;
        }
        else{
            pnode currentNode = *head;
            while(currentNode->next != NULL){
                currentNode = currentNode->next;
            }
            currentNode->next = new;
        }
        // 0 4 2 1
        pedge edge_head = NULL;
        while(*str != 'B' && *str != 'T' && *str!='A' && *str != 'S'){
            pedge new_edge = (pedge)malloc(sizeof(edge));
            if(new_edge == NULL){
                printf("No memory allocated");
                exit(0);
            }
            // 0 4 2 1
            new_edge->endpoint = getNode(head, *str-'0');
            str++;
            // 4 2 1
            new_edge->weight = *str-'0';
            new_edge->next = NULL;
            
            if(new->edges == NULL){
                new->edges = new_edge;
                edge_head = new_edge;
            }
            else{
                edge_head->next = new_edge;
                edge_head = edge_head->next;
            }
            str++;

        }

    }
    else{
        pnode temp = getNode(head, node_id);
        pedge curr = NULL;
        curr = temp->edges;
        pedge eptr = NULL;
        while(curr != NULL){
            eptr = curr->next;
            free(curr);
            curr = eptr;
        }
        temp->edges = NULL;
        pedge edge_head = NULL;
        // 0 4 2 1
        while(*str != 'B' && *str != 'T' && *str!='A' && *str != 'S'){
            pedge new_edge = (pedge)malloc(sizeof(edge));
            if(new_edge == NULL){
                printf("No memory allocated");
                exit(0);
            }
            new_edge->endpoint = getNode(head, *str-'0');
            str++;
            new_edge->next = NULL;
            // 4 2 1
            new_edge->weight = *str-'0';
            if(temp->edges == NULL){
                temp->edges = new_edge;
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

void delete_node_cmd(pnode *head, char *str){
    
}












int main(){
    // A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
    char input [30] = "A4n02533n20411n13702TB10421B\0", *ptr;
    ptr = input; 
    pnode temp = NULL;
    pnode *head = &temp;
    ptr++;
    build_graph_cmd(head, ptr);
    while(*ptr != 'B'){
        ptr++;
    }
    ptr++;
    add_new_node(head, ptr);
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
