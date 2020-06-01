#ifndef __SORT_H_
#define __SORT_H_

typedef struct List {
	int val;
	struct List * next;
} List;

List * read_file(char * filename);

void free_list(List * l);

List * insertion_sort(List * list);

void check_sortedness(List * list);

void print_list(List * list);

List * mergesort(List * list_head);

List * merge(List * head1, List * head2);

List * mergesort_iter(List * list_head);

List * merge_iter(List * head1, List * head2);

#endif