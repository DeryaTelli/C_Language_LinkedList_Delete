#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

void write_linkedlist(node* n) {
    node* temp = n;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("-----------------------------------------\n");
}

struct Node* create_linkedlist(int data) {
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void add_node_head_of_linkedlist(struct Node** linkedlist, int data) {
    node* new_linkedlist = create_linkedlist(data);
    new_linkedlist->next = *linkedlist;
    *linkedlist = new_linkedlist;
}

void add_node_end_of_linkedlist(struct Node** linkedlist, int data) {
    node* temp = *linkedlist;

    if (*linkedlist == NULL) {
        *linkedlist = create_linkedlist(data);
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = create_linkedlist(data);
    }
}

void delete_node_from_linkedlist(struct Node** linkedlist, int data){
	node* iter= *linkedlist;
	node* temp;
	if((*linkedlist)==NULL){
		printf("Linked list is empty\n");
	}
	else if((*linkedlist)->data == data )
	{
		temp= (*linkedlist)->next;// linkedlisten sonrakini temp olarak belirledik 
		free(*linkedlist);// linkerlisti sildik 
		*linkedlist = temp; // yeni linkerlisti temp yaptik 
		
	}
	else{
		while (iter !=NULL && iter->data!=data){
			temp=iter;
			iter=iter->next;
		}
		if(iter==NULL){
			printf("Data is not found \n");
		}
		else{
			temp->next=iter->next;
			free(iter);
		}
	}
}
int main() {
    node* root = create_linkedlist(3);
    add_node_end_of_linkedlist(&root, 4);
    add_node_head_of_linkedlist(&root, 2);
    add_node_end_of_linkedlist(&root, 5);
    add_node_head_of_linkedlist(&root, 1);
    add_node_end_of_linkedlist(&root, 6);
    write_linkedlist(root);
    
    node* root2 = NULL;
    delete_node_from_linkedlist(&root2,4);
    
    delete_node_from_linkedlist(&root,10);
    write_linkedlist(root);
    

    return 0;
}

