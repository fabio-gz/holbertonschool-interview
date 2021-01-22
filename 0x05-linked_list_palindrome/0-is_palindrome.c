#include "lists.h"

/**
 * cpalidrome - checks if it's a palindrome
 * @left: left node
 * @right: right node
 * Return: 0 if not a palindrome
 */
int cpalindrome(listint_t **left, listint_t *right)
{
	int link_li;

	if (right == NULL)
		return (1);

	link_li = cpalindrome(left, right->next);

	if (link_li == 0)
		return (0);

	link_li = (right->n == (*left)->n);
	*left = (*left)->next;

	return (link_li);
}
/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: head
 * Return: 1 if its palidrome
 */
int is_palindrome(listint_t **head)
{
	int link_li = cpalindrome(head, *head);
	return (link_li);
}
