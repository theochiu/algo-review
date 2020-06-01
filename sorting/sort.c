
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

int main(int argc, char * *argv) {
	char * filename;
	if (argc < 3) {
		printf("no number given, sorting 10.txt\n");
		filename = "10.txt";
	}
	else {
		filename = argv[2];
	}

	// read in file
	List * list = read_file(filename);

	// list = insertion_sort(list);
	list = mergesort(list);

	// test list
	// print_list(list);

	// check to see if sorted 
	check_sortedness(list);

	// free list
	free_list(list);

	return 0;

}

List * mergesort(List * list) {
	// base case
	if (list == NULL || list -> next == NULL)
		return list;

	List * temp = list;
	List * right = list;

	while (temp != NULL && temp -> next != NULL) {
		temp = temp -> next -> next;
		right = right -> next;
	}

	right -> prev -> next = NULL;
	right -> prev = NULL;

	list = mergesort(list);
	right = mergesort(right);

	return merge(list, right);

}

List * merge(List * left, List * right) {
	if (left == NULL)
		return right;
	if (right == NULL)
		return left;

	if (left -> val < right -> val) {
		left -> next = merge(left -> next, right);
		left -> next -> prev = left;
		left -> prev = NULL;
		return left;
	}
	else {
		right -> next = merge(left, right -> next);
		right -> next -> prev = right;
		right -> prev = NULL;
		return right;
	}
}

void print_list(List * list) {
	List * l = list;
	
	printf("\n\nprinting contents of list\n");
	printf("%d\n", l -> val);

	while (l -> next != NULL) {
		printf("%d\n", l -> next -> val);
		l = l -> next;
	}

	printf("\n\nprinting contents of list BACKWARDS\n");
	while (l != NULL) {
		printf("%d\n", l -> val);
		l = l -> prev;
	}
}

void check_sortedness(List * list) {
	// return 1 for sorted, 0 for not
	int prev = list -> val;
	list = list -> next;
	while (list != NULL) {
		if (list -> val < prev)
			printf("The list is NOT sorted");
		list = list -> next;
	}
	printf("The list is sorted\n");
}

List * insertion_sort(List * list) {
	// place first element in sorted list and remove from unsorted list
	List * sorted = list;
	list = list -> next;
	sorted -> next = NULL;
	
	// insert values from unsorted 1 by 1 into sorted
	while (list != NULL) {
		List * next = list -> next;
		insert(&sorted, list);
		list = next;
	}
	return sorted;
}

void insert(List ** result_list, List * input_node) {
	// cut input_node from rest of list
	input_node -> prev = NULL;
	input_node -> next = NULL;
	List * insert_point = *result_list;
	List * insert_point_prev = NULL;
	// find insertion point
	while (input_node -> val > insert_point -> val) {
		insert_point_prev = insert_point;
		insert_point = insert_point -> next;
		if (insert_point == NULL)
			break;
	}
	// perform insertion

	// handle ancestor node
	if (insert_point_prev != NULL) {
		insert_point_prev -> next = input_node;
		input_node -> prev = insert_point_prev;
		
	}
	else {
		* result_list = input_node;
	}

	// handle child node
	if (insert_point != NULL) {
		input_node -> next = insert_point;
		insert_point -> prev = input_node;
	}
	else {
		insert_point_prev -> next = input_node;
	}


}

void swap(List * node1, List * node2) {
	// swap by value
	List * ancestor1 = node1 -> prev;
	List * ancestor2 = node2 -> prev;
	List * child1 = node1 -> next;
	List * child2 = node2 -> next;
	ancestor1 -> next = node2;
	node2 -> next = child1;
	ancestor2 -> next = child1;
	node1 -> next = child2;
}

void free_list(List * l) {
	List * temp;
	while (l != NULL) {
		temp = l -> next;
		free(l);
		l = temp;
	}
}

List * read_file(char * filename) {
	FILE * fptr = fopen(filename, "r");
	if (fptr == NULL) {
		fprintf(stderr, "fopen fail\n");
		return NULL;
	}

	List * list = NULL;
	List * prev = NULL;

	int this_num;
	while (!feof(fptr)) {
		// read in a number
		fscanf(fptr, "%d\n", &this_num);
		// first node
		if (list == NULL) {
			list = malloc(sizeof(List));
			list -> val = this_num;
			list -> prev = NULL;
			prev = list;
		}
		else {
			List * this = malloc(sizeof(List));
			this -> val = this_num;
			this -> prev = prev;
			prev -> next = this;
			prev = this;
		}
	}
	fclose(fptr);
	prev -> next = NULL;
	return list;
}

