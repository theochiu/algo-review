#ifndef __SORT_H_
#define __SORT_H_

typedef struct List {
	int val;
	struct List * next;
	struct List * prev;
} List;

List * read_file(char * filename);

void free_list(List * l);

List * insertion_sort(List * list);

void swap(List * node1, List * node2);

void insert(List ** result_list, List * input_node);

void check_sortedness(List * list);

void print_list(List * list);

List * mergesort(List * list_head);

List * merge(List * head1, List * head2);

#endif