#include <stdio.h>
#include "graph.h"
int main()
{
    pnode temp = NULL;
    pnode *head = &temp;
    char input = '\0';
    while (scanf("%c", &input) != EOF){
        if (input == 'A'){
            build_graph_cmd(head);
        }
        else if (input == 'B'){
            insert_node_cmd(head);
        }
        else if (input == 'D'){
            delete_node_cmd(head);
        }
        else if (input == 'S'){
            
        }
        else if (input == 'T') {
            
        }
    }
    return 0;
}