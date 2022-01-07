#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>


void build_graph_cmd(pnode *head, char *str){
    // first clear graph if one exist
    deleteGraph_cmd(head);
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
        while(*str != 'B' && *str != 'T' && *str!='A' && *str != 'S' && *str != 'D'){
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
        while(*str != 'B' && *str != 'T' && *str!='A' && *str != 'S' && *str != 'D'){
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

void delete_node_cmd(pnode *head, int id){
    // if head is null return nothing
    if(*head == NULL){
        return;
    }
    // find the node we want to remove
    pnode remove_Node = getNode(head, id);
    // pointer helper
    pnode Node_temp = NULL;
    // if the head is the node we are delteing then head and pointing the next one to be head
    if((*head) == remove_Node){
        Node_temp = (*head)->next;
        *head = Node_temp;
    }
    else{
        // node isn't the head
        pnode index = *head;
        // find the node and remove it from the linked list
        while(index->next != NULL){
            if(index->next->node_num == id){
                if(index->next->next == NULL){
                    index->next = NULL;
                    break;
                }
                else{
                    index->next = index->next->next;
                }
            }
            index = index->next;
        }
    }
    // this stage is the deleting the edged stage and at the end removing the node
    pnode currN = *head;
    pedge currE = NULL;
    pedge tempE = NULL;
    while(currN != NULL){
        if(currN->edges != NULL){
            if(currN->edges->endpoint == remove_Node){
                tempE = currN->edges->next;
            }
            else{
                currE = currN->edges;
                while(currE->next != NULL){
                    if(currE->next->endpoint == remove_Node){
                        tempE = currE->next->next;
                        free(currE->next);
                        currE->next = tempE;
                        break;
                    }
                    currE = currE->next;
                }
            }
        }
        currN = currN->next;
    }
    currE = remove_Node->edges;
    tempE = NULL;
    while(currE != NULL){
        tempE = currE->next;
        free(currE);
        currE = tempE;
    }
    free(remove_Node);
}

// function to find shortest path, using Dijkstra algorithm
int shortsPath_cmd(pnode head, char *str){
    // getting the two src_id that we are looking for
    int src = *str - '0';
    str++;
    int dest = *str - '0'; 
    pnode curr = head;
    // number of nodes counter
    int number_ofNodes = 0; 
    while(curr != NULL){
        if(curr->node_num != src){
            curr->shortest_time = INT_MAX;
        }
        else{
            curr->shortest_time = 0;
        }
        curr->explored = 0;
        number_ofNodes++;
        curr = curr->next;
    }
    pnode src_node = head;
    // find the src node that i start from
    while(src_node->node_num != src ){
        src_node = src_node->next;
    }
    // mark node as explored 
    src_node->explored = 1; 
    pedge edge_head = src_node->edges;
    // if edged from first node are none, there are no directions from there. return max int
    if(edge_head == NULL){
        return INT_MAX;
    }
    // loop till all nodes are visited
    int node_count = 0; 
    while(node_count < number_ofNodes){
        int min = INT_MAX;
        int next_node_id = 0;
        while(edge_head != NULL){
            if(edge_head->weight <= edge_head->endpoint->shortest_time){
                edge_head->endpoint->shortest_time = edge_head->weight + src_node->shortest_time;
                if(edge_head->endpoint->shortest_time <= min && edge_head->endpoint->explored == 0){
                    min = edge_head->endpoint->shortest_time;
                    next_node_id = edge_head->endpoint->node_num;
                }
            }
            edge_head = edge_head->next;
        }
        src_node = head;
        while(src_node->node_num != next_node_id){
            src_node = src_node->next;
        }
        edge_head = src_node->edges;
        node_count++;
    }
    // find the node we are travelling to
    pnode final = head;
    while(final->node_num != dest){
        final = final->next;
    }
    // return the node shortest time 
    return final->shortest_time;
}


void TSP_cmd(pnode head, char *str){
    // minimum wiehgt
   int min_weight = INT_MAX;
   // get the size of the list of cities
   int size = *str - '0';
   // array of the route
   int route [size];
   for(int i = 0; i<size; i++){
       str++;
       route[i] = *str -'0';
   }
   // permute the options of visiting the cities
   // this is where i found the information https://www.codesdope.com/blog/article/generating-permutations-of-all-elements-of-an-arra/
   permute(route, 0, size-1, &min_weight, size, head);
   if (min_weight == INT_MAX){
        printf("TSP shortest path: -1 \n");
    }
    else{
        printf("TSP shortest path: %d \n", min_weight);
    }
}

// function to swap 
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// function to permute taken from this site https://www.codesdope.com/blog/article/generating-permutations-of-all-elements-of-an-arra/
void permute(int *route, int start, int end, int *min_weight, int size, pnode head)
{
    int i;
    if (start == end){
        int tmpWeight = minPath(route, size, head);
        if(tmpWeight < *min_weight){
            *min_weight = tmpWeight;
        }
    }
    else
    {
        for (i = start; i <= end; i++){
            swap((route+start), (route+i));
            permute(route, start+1, end, min_weight, size, head);
            swap((route+start), (route+i));
        }
    }
}

// for each permutation use shortest path to find the travel time
int minPath(int* route, int size, pnode head){
    // if size is 0 return 0
    if (size <=1 ){
        return 0;
    }
    else{
        // else call shortest path on the two following nodes
        int sum = 0;
        for (int i = 0; i < size-1; i++)
        {   
            char str[3] = {route[i]+'0',route[i+1]+'0'};
            char *ptr; 
            ptr = str;
            int dij = shortsPath_cmd(head, ptr);
            if (dij == INT_MAX){
                return INT_MAX;
            }
            else{
                sum += dij;
            }
        }
        return sum;
    }
}

// function to delete graph
void deleteGraph_cmd(pnode* head) {
    if(*head == NULL){
        return;
    }

    pnode currentNode = *head;
    pnode nextNode;

    while (currentNode != NULL) {
        pedge currentEdge = NULL;
        currentEdge = currentNode->edges;
        pedge nextEdge = NULL;
        
        while(currentEdge != NULL) {
            nextEdge = currentEdge->next;
            free(currentEdge);
            currentEdge = nextEdge;
        }
        
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    head = NULL;
}














// int main(){
//     char input[51] = "A4n02533n20411n13702n3T3213B50421T42135B62314T3136";
//     char *ptr_final = input;
//     pnode temp = NULL;
//     pnode *head = &temp;
//     printf("%s\n", ptr_final);
//     while(*ptr_final){
//         if(*ptr_final == 'A'){
//             ptr_final++;
//             build_graph_cmd(head, ptr_final);
//         }
//         else if(*ptr_final == 'B'){
//             ptr_final++;
//             add_new_node(head, ptr_final);
//         }
//         else if(*ptr_final == 'D'){
//             ptr_final++;
//             delete_node_cmd(head, *ptr_final-'0');
//         }
//         else if(*ptr_final == 'S'){
//             ptr_final++;
//             int sp = shortsPath_cmd(temp, ptr_final);
//             printf("Dijsktra shortest path: %d\n", sp);
//         }
//         else if(*ptr_final == 'T'){
//             ptr_final++;
//             TSP_cmd(temp, ptr_final);
//         }
//         else{
//             ptr_final++;
//         }
//     }
//     printf("i am here\n");
//     return 0; 
// }
