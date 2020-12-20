#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node
 * @number: node value
 * Return: address of the new node
 */

listint_t *insert_node(listint_t **head, int number){
    
    listint_t *new, *tmp;
    tmp = *head;

    new = malloc(sizeof(listint_t));

    if(new == NULL)
        return (NULL);

    new->n = number;

    if (!tmp || tmp->n > new->n)
	{
		new->next = tmp;
		*head = new;
	}

    while (tmp->next != NULL && tmp->next->n < new->n){
		tmp = tmp->next;
    }
	new->next = tmp->next;
	tmp->next = new;

    return(new);
}