#include "binary_trees.h"
/**
 * binary_tree_node - binary tree node
 * @parent: parent node
 * @value: node value
 * Return: pointer to node
 */
avl_t *binary_tree_node(avl_t *parent, int value)
{
	avl_t *tnode;

	tnode = malloc(sizeof(avl_t));
	if (!tnode)
		return (NULL);

	tnode->n = value;
	tnode->parent = parent;
	tnode->left = NULL;
	tnode->right = NULL;
	return (tnode);
}
/**
 * heap_insert - inserts a node
 * @root: head
 * @array: elements in the tree
 * @size: tree size
 * @start: start of the array
 * Return: pointer to new node
 */
avl_t *heap_insert(avl_t **root, int size, int start, int *array)
{
	int mid = (start + size) / 2;
	avl_t *tnode = NULL;

	if (size < start)
		return (NULL);
	tnode = binary_tree_node(*root, array[mid]);
	if (mid != start)
		tnode->left = heap_insert(&tnode, mid - 1, start, array);
	if (mid != size)
		tnode->right = heap_insert(&tnode, size, mid + 1, array);
	return (tnode);
}
/**
 * sorted_array_to_avl - Sorts array into avl binary tree
 * @array: elements in the tree
 * @size: tree size
 * Return: pointer to root node
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	root = heap_insert(&root, size - 1, 0, array);
	return (root);
}
