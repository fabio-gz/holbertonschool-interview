#include "binary_trees.h"

/**
 * binary_tree_size - binary tree size
 * @tree: root node
 * Return: Size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	int left, right, size;

	if (!tree)
		return (0);

	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);
	size = left + right;
	return (size + 1);
}

/**
 * binary_tree_is_full - checks if tree is full
 * @tree: root node
 * Return: 1 if null
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_is_full(tree->left) &&
		binary_tree_is_full(tree->right));
}

/**
 * binary_tree_is_perfect - checks if tree is perfect
 * @tree: root node
 * Return: 1 if perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	if (binary_tree_is_full(tree) && (left == right))
		return (1);

	return (0);
}

/**
 * findParent - finds parent node
 * @root: the root node
 * Return: a pointer to the parent node
 */
heap_t *findParent(heap_t *root)
{
	heap_t *p;
	int l, r, ld, rd;

	if (!root)
		return (NULL);

	p = root;
	l = binary_tree_size(p->left);
	r = binary_tree_size(p->right);
	ld = binary_tree_is_perfect(p->left);
	rd = binary_tree_is_perfect(p->right);
	if (!l || !r)
		return (p);
	if (!ld || (ld && rd && l == r))
		return (findParent(p->left));
	else if (!rd || (ld && rd && l > r))
		return (findParent(p->right));
	return (p);
}

/**
 * swap - swaps the nodes
 * @node: node
 */
void swap(heap_t **node)
{
	heap_t *current;
	int tmp;

	current = *node;
	while (current->parent)
	{
		if (current->parent->n < current->n)
		{
			tmp = current->parent->n;
			current->parent->n = current->n;
			current->n = tmp;
			*node = current->parent;
		}
		current = current->parent;
	}
}

/**
 * heap_insert - inserts a max-heap
 * @root: pointer to a root.
 * @value: new node value
 * Return: new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *parent;

	parent = findParent(*root);
	new = binary_tree_node(parent, value);
	if(!new)
		return (NULL);
	if (!parent)
		*root = new;
	else if (!parent->left)
		parent->left = new;
	else
		parent->right = new;
	swap(&new);
	return (new);
}