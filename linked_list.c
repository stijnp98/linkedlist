/*linked list project*/
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int add_to_list(linked_list *ll, char *s) {
	linked_list *element = (linked_list *) malloc(sizeof(linked_list));
	element = ll;

	while (element->next != NULL) {
		element = element->next;
	}
	linked_list *newelement = (linked_list *) malloc(sizeof(linked_list));
	element->next = newelement;
	newelement->data = s;
	newelement->index = element->index + 1;
	newelement->next = NULL;
	return newelement->index;
}

int display_item(linked_list *ll) {
	if (ll->data == NULL || ll == NULL) {
		return -1;
	} else {
		printf(ll->data);
	}
	return 0;
}

int display_list(linked_list *ll) {
	linked_list *element = (linked_list *) malloc(sizeof(linked_list));
	element = ll;

	while (element->next != NULL) {
		if (element->data == NULL || element == NULL) {
			return -1;
		}
		printf(element->data);
		element = element->next;

	}
	if (ll->next != NULL) {
		printf(element->data);
	}
	return element->index;
}

linked_list * search_from_list(linked_list *ll, char *s) {
	linked_list *element = (linked_list *) malloc(sizeof(linked_list));
	element = ll;

	while (element->next != NULL) {
		if (strcomp(element->data, s) == 1) {
			return element;
		}
		element = element->next;
	}
	if (strcomp(element->data, s) == 1) {
		return element;
	}

	return NULL;
}

//extra function to get an element on index number
linked_list * search_for_index(linked_list *ll, int index) {
	linked_list *element = (linked_list *) malloc(sizeof(linked_list));
	element = ll;

	while (element->next != NULL) {
		if (element->index == index) {
			return element;
		}
		element = element->next;
	}
	if (element->index == index) {
		return element;
	}

	return NULL;
}

int delete_from_list(linked_list *ll, int index) {
	linked_list *element = (linked_list *) malloc(sizeof(linked_list));
	linked_list *tempelement = (linked_list *) malloc(sizeof(linked_list));
	element = ll;
	int i = 0;
	int pointer = -1;

	while (element->next != NULL && pointer == -1) {
		if (element->index == index) {
			tempelement = ll;
			for (int j = 0; (index - 1) > j; j++) {
				tempelement = tempelement->next;
			}
			tempelement->next = tempelement->next->next;
			free(element);
			tempelement = ll;
			int j = 0;
			while (tempelement->next != NULL) {
				tempelement->index = j;
				tempelement = tempelement->next;
				j++;
			}
			pointer = j + 1;
		} else {
			element = element->next;
		}
	}
	if (element->index == index && pointer == -1) {
		tempelement = ll;
		for (int j = 0; (index - 1) > j; j++) {
			tempelement = tempelement->next;
		}
		tempelement->next = NULL;
		pointer = index;
		free(element);
	}
	free(tempelement);
	return pointer;
}

int empty_list(linked_list *ll){
	int size = 1;
	linked_list *element = (linked_list *) malloc(sizeof(linked_list));
	element = ll;
	while (element->next != NULL) {
		element = element->next;
		size++;
	}
	int count = 0;
	for(int j = size;0 < j;j--){
		linked_list *tempelement = (linked_list *) malloc(sizeof(linked_list));
		tempelement = ll;
		for(int i = 0;i < j;i++){
			tempelement = tempelement->next;
		}
		free(tempelement);
		count++;
	}
	char s[] = "";
	ll->next = NULL;
	ll->data = s;

	return count;
}

int swap_items(linked_list *f, linked_list *s){
	if(f == NULL || s == NULL){
		return -1;
	}
	int i = 0;
	for (i = 0; f->data[i] != '\0'; i++);
	char var [i + 2] = "";;
	copy_string(var,f->data);
	copy_string(f->data,s->data);
	copy_string(s->data,var);
	return 0;
}

int sort_list(linked_list *ll){
	linked_list *element = (linked_list *) malloc(sizeof(linked_list));
	element = ll;
	int count = 0;
while (element->next != NULL) {
	element = element->next;
	count++;
}
int i, j;
for(i=0;i<=count;i++)
     for(j=i+1;j<=count;j++){
      {
           if (strcomp(search_for_index(ll,i)->data,search_for_index(ll,j)->data) == 0)
           {
        	   swap_items(search_for_index(ll,i), search_for_index(ll,j));
           }
      }
 }
}

int linkedlist_status(linked_list *ll){
	linked_list *element = (linked_list *) malloc(sizeof(linked_list));
	element = ll;
	int count = 0;
	while (element->next != NULL) {
	element = element->next;
	count++;
}
	count++;
	return count;
}

//check or 2 string are equal
int strcomp(char input[], char check[]) {
	//0 a bigger than b
	//1 a and b equal
	//2 a smaller than b
	int i;
	for (i = 0; input[i] != '\0' || check[i] != '\0'; i++) {
		if (input[i] != check[i]) {
			if(input[i] > check[i]){
				return 0;
			}
			else{
				return 2;
			}
		}
	}
	return 1;
}

//copy one array to another
void copy_string(char d[], char s[]) {
  int c = 0;
  while (s[c] != '\0') {
    d[c] = s[c];
    c++;
  }
  d[c] = '\0';
}
