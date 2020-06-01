
// binary tree
typedef struct Tree {
	struct Tree * left; 
	struct Tree * right;
	int val;
} Tree;

Tree * read_tree(char * filename);

void print_tree_2d(Tree * tree, int s);

void free_tree(Tree * tree);
