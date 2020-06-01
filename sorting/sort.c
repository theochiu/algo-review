
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

	list = insertion_sort(list);
	// list = mergesort(list);

	// test list
	print_list(list);

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
	List * right_prev;
	while (temp != NULL && temp -> next != NULL) {
		temp = temp -> next -> next;
		right_prev = right;
		right = right -> next;
	}

	right_prev -> next = NULL;

	list = mergesort(list);
	right = mergesort(right);

	return merge(list, right);

}

List * mergesort_iter(List * list) {
	// perform mergesort iteratively
	return NULL; 	// compile
}

List * merge_iter(List * left, List * right) {
	// perform merge iteratively
	return NULL;
}

List * merge(List * left, List * right) {
	if (left == NULL)
		return right;
	if (right == NULL)
		return left;

	if (left -> val < right -> val) {
		left -> next = merge(left -> next, right);
		return left;
	}
	else {
		right -> next = merge(left, right -> next);
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
}

void check_sortedness(List * list) {
	// return 1 for sorted, 0 for not
	int prev = list -> val;
	list = list -> next;
	while (list != NULL) {
		if (list -> val < prev) {
			printf("The list is NOT sorted");
			return;
		}
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
		// pull a node
		List * pulled_node = list;
		list = list -> next;
		// cut link
		pulled_node -> next = NULL;

		// find insertion point
		List * insertion_point = sorted;
		List * insertion_point_prev = NULL;
		while (insertion_point != NULL && insertion_point -> val < pulled_node -> val) {
			insertion_point_prev = insertion_point;
			insertion_point = insertion_point -> next;
		}

		if (insertion_point_prev != NULL) 
			insertion_point_prev -> next = pulled_node;
		else
			sorted = pulled_node;

		pulled_node -> next = insertion_point;

	}
	return sorted;
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
			prev = list;
		}
		else {
			List * this = malloc(sizeof(List));
			this -> val = this_num;
			prev -> next = this;
			prev = this;
		}
	}
	fclose(fptr);
	prev -> next = NULL;
	return list;
}

