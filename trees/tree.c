
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// spacing for printing b tree
#define COUNT 10

int main(int argc, char * * argv) {

	char * filename;
	if (argc > 1)
		filename = argv[1];
	else
		filename = "tree1.txt";

	// read in tree
	Tree * tree = read_tree(filename);

	// visualize tree
	print_tree_2d(tree, 0);

	// deallocate
	free_tree(tree);
}

Tree * read_tree(char * filename) {
	// build BST from 
	FILE * fptr = fopen(filename, "r");
	if (fptr == NULL) {
		fprintf(stderr, "%s\n", "fopen fail");
		return NULL;
	}
	Tree * root = NULL;
	int num;
	while (!feof(fptr)) {
		// read in number
		fscanf(fptr, "%d\n", &num);

		// create new node
		Tree * node = malloc(sizeof(Tree));
		node -> val = num;
		node -> left = NULL;
		node -> right = NULL;

		// insert node into greater tree (as leaf)

		// first node
		if (root == NULL) 
			root = node;
		else {
			// traverse until correct loc
			Tree * temp = root;
			while (temp != NULL) {
				if (num < temp -> val) {
					if (temp -> left != NULL)
						// traverse left
						temp = temp -> left;
					else {
						temp -> left = node;
						break;
					}
				}
				else {
					if (temp -> right != NULL)
						// traverse right
						temp = temp -> right;
					else {
						temp -> right = node;
						break;
					}
				}
			}

		}
	}
	fclose(fptr);
	return root;
}

void free_tree(Tree * tree) {
	if (tree == NULL)
		return;
	free_tree(tree -> left);
	free_tree(tree -> right);
	free(tree);
}

void print_tree_2d(Tree * tree, int space) {
	if (tree == NULL)
		return;

	space += COUNT;

	print_tree_2d(tree -> right, space);

	// actual printing
	printf("\n");
	for (int i=COUNT; i<space; i++)
		printf(" ");
	printf("%d\n", tree -> val);

	print_tree_2d(tree -> left, space);
}
