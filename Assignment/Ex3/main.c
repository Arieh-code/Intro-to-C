#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include <string.h>

int main(void) 
{
    char *ptr = NULL;
    size_t size = 0;
    int ch;
    int counter = 0;
    while((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
        counter++;
        char *tmp = realloc(ptr, (size + 2) * sizeof(*tmp));
        if(!tmp) {
            printf("Memory not allocated");
            exit(0);
        }
        ptr = tmp;
        ptr[size++] = ch;
        ptr[size] = 0;
    }
    char *ptr_helper = ptr;
    char *ptr_final = NULL;
    size = 0; 
    while(*ptr_helper){
        if(*ptr_helper != ' '){
            char *final_temp = realloc(ptr_final, (size+2) * sizeof(*final_temp));
            if(!final_temp){
                printf("Memory not allocated");
                exit(0);
            }
            ptr_final = final_temp;
            ptr_final[size++] = *ptr_helper;
            ptr_final[size] = 0;
            ptr_helper++;
        }
        else{
            ptr_helper++;
        }
    }
    free(ptr);
    char *ptrf_helper = ptr_final;
    pnode temp = NULL;
    pnode *head = &temp;
    while(*ptrf_helper){
        if(*ptrf_helper == 'A'){
            ptrf_helper++;
            // first clear graph if one exist
            deleteGraph_cmd(head);
            temp = NULL;
            build_graph_cmd(head, ptrf_helper);
        }
        else if(*ptrf_helper == 'B'){
            ptrf_helper++;
            add_new_node(head, ptrf_helper);
        }
        else if(*ptrf_helper == 'D'){
            ptrf_helper++;
            delete_node_cmd(head, *ptrf_helper-'0');
        }
        else if(*ptrf_helper == 'S'){
            ptrf_helper++;
            int sp = shortsPath_cmd(temp, ptrf_helper);
            printf("Dijsktra shortest path: %d \n", sp);
        }
        else if(*ptrf_helper == 'T'){
            ptrf_helper++;
            TSP_cmd(temp, ptrf_helper);
        }
        else{
            ptrf_helper++;
        }
    }
    deleteGraph_cmd(head);
    free(ptr_final);
    return 0; 
}