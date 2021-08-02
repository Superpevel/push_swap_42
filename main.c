#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>
t_list	*ft_lstnew(char *data)
{
	t_list	*t;

	t = malloc(sizeof(t_list));
	if (!t)
		return (NULL);
	t->data = ft_atoi(data);
	t->next = NULL;
    t->prev = NULL;
	return (t);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
    if (lst)
	{
		if (*lst)
		{
            while ((*lst)->prev != NULL)
            {
                *lst = (*lst)->prev;
            }
            new->next = *lst;
            (*lst)->prev = new;
			*lst = new;
		}
		else
			*lst = new;
	}
}

void	s(t_list **list)
{
	int t;
    int t1;
    while ((*list)->next != NULL)
    {
        *list = (*list)->next;
    }
    t = (*list)->data;
    *list = (*list)->prev;
    t1 = (*list)->data;
    (*list)->data = t;
    *list = (*list)->next;
    (*list)->data = t1;
}

void	r(t_list **list)  
{
    t_list *lst;
    while ((*list)->next != NULL)
    {
        *list = (*list)->next;
    }
    lst = *list;
    *list = (*list)->prev;
    (*list)->next = NULL;
    lst->prev = NULL;
    while ((*list)->prev != NULL)
        *list = (*list)->prev;
    lst->next = *list;
    (*list)->prev = lst;
}

void	rra(t_list **list)  
{
    t_list *lst;
    while ((*list)->prev != NULL)
    {
        *list = (*list)->prev;
    }
    lst = *list;
    *list = (*list)->next;
    (*list)->prev = NULL;
    lst->next = NULL;
    while ((*list)->next != NULL)
        *list = (*list)->next;
    lst->prev = *list;
    (*list)->next = lst;
}

int find_min(t_list *a)
{
    int min;
    int min_ind = 0;
    int i = 0;

    while (a->next != NULL)
    {
        a = a->next;
    }
    min = a->data;
    i = 0;
    while(a)
    {
        if(a->data < min)
        {
            min = a->data;
            min_ind = i;
        }
        a = a->prev;
        i++;
    }
    return min_ind;
}


void p(t_list **a,t_list **b)
{
    t_list *push_to_b;

    while ((*a)->next != NULL)
    {
       *a = (*a)->next;
    }
    if (*b)
    {
    while ((*b)->next != NULL)
    {
       *b = (*b)->next;
    }
    push_to_b = *a;
    *a = (*a)->prev;
    push_to_b->prev = *b;
    (*b)->next = push_to_b;
    *b = (*b)->next;
    (*a)->next= NULL;
    }
    else
    {
       push_to_b = *a;
       *a = (*a)->prev;
       (*a)->next = NULL;
       push_to_b->next = NULL;
       push_to_b->prev = NULL;
       *b = push_to_b;
    }
}

void pp(t_list **a,t_list **b)
{
    int sw;
    while ((*a)->next != NULL)
    {
       *a = (*a)->next;
    }
    while ((*b)->next != NULL)
    {
       *b = (*b)->next;
    }
    sw = (*a)->data;
    (*a)->data = (*b)->data;
    (*b)->data = sw;
}

int array_val(t_list *list)
{
    int i = 0;
    while (list->next != NULL)
    {
        i++;
    }
    return(i);
}

int array_sorted()
{
    return(0);
}

void push_min(t_list **a,t_list **b)
{
    int i;
    while ((*a)->prev !=NULL)
    {
    i = find_min(*a);
    while (i !=0)
    {
        r(a);
        printf("ra\n");
        i--;
    }
        p(a,b);
        printf("pb\n");
    }
}

void print_a(t_list *b)
{
    while (b->next != NULL)
        b = b->next;
    while (b->prev != NULL)
    {
        printf("%d a\n",b->data);
        b = b->prev;
    }
    printf("%d a\n",b->data);
}

void print_b(t_list *b)
{
    while (b->next != NULL)
        b = b->next;
    while (b->prev != NULL)
    {
        printf("%d b\n",b->data);
        b = b->prev;
    }
    printf("%d b\n",b->data);
}
int main(int ac, char **av)
{
    int i;
    t_list *a;
    t_list *b;
    i = 1;
    if(ac < 3)
        return(0);
    a = ft_lstnew(av[i]);
    i++;
    while (av[i] != NULL)
    {
        ft_lstadd_front(&a,ft_lstnew(av[i]));
        i++;
    }
    while (a->next != NULL)
    {
        a= a->next;
    }
    push_min(&a,&b);
    while (b->next !=NULL)
        b = b->next;

    while (b->prev !=NULL)
    {
        p(&b,&a);
        printf("pa\n");      
    }
    printf("pa\n");      
    // printf("pb\n");
    // p(&a,&b);
    // print_a(a);
    // print_b(b);
    return(0);
}
