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
        if(!tmp) {/* handle allocation error */}
        ptr = tmp;
        ptr[size++] = ch;
        ptr[size] = 0;
    }

    char *ptr_final = NULL;
    size = 0; 
    while(*ptr){
        if(*ptr != ' '){
            char *final_temp = realloc(ptr_final, (size+2) * sizeof(*final_temp));
            if(!final_temp){
                printf("Memory not allocated");
                exit(0);
            }
            ptr_final = final_temp;
            ptr_final[size++] = *ptr;
            ptr_final[size] = 0;
            ptr++;
        }
        else{
            ptr++;
        }
    }
    // free(ptr);
    pnode temp = NULL;
    pnode *head = &temp;
    while(*ptr_final){
        if(*ptr_final == 'A'){
            ptr_final++;
            build_graph_cmd(head, ptr_final);
        }
        else if(*ptr_final == 'B'){
            ptr_final++;
            add_new_node(head, ptr_final);
        }
        else if(*ptr_final == 'D'){
            ptr_final++;
            delete_node_cmd(head, *ptr_final-'0');
        }
        else if(*ptr_final == 'S'){
            ptr_final++;
            int sp = shortsPath_cmd(temp, ptr_final);
            printf("Dijsktra shortest path: %d\n", sp);
        }
        else if(*ptr_final == 'T'){
            ptr_final++;
            TSP_cmd(temp, ptr_final);
        }
        else{
            ptr_final++;
        }
    }
    deleteGraph_cmd(head);
    // free(ptr_final);
    return 0; 
}