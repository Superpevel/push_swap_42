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
            new->next = *lst;
            (*lst)->prev = new;
			*lst = new;
		}
		else
			*lst = new;
	}
}

t_list	*sa(t_list *list)  // работает
{
	int t;
    int t1;
    while (list->next != NULL)
    {
        list = list->next;
    }
    t = list->data;
    list = list->prev;
    t1 = list->data;
    list->data = t;
    list = list->next;
    list->data = t1;
	return (list);
}

t_list	*ra(t_list *list)  
{
	int	t;
    int    t1;
    while (list->prev != NULL)
        list = list->prev;
    t = list->data;
    while (list->next != NULL)
        list = list->next;
    t1 = list->data;
    list->data = t;
    while (list->prev != NULL)
        list = list->prev;
    list->data = t1;
	return (list);
}

int find_min(t_list *a)
{
    int min = 2000;
    while(a)
    {
        printf("chack %d\n",a->data);
        if(a->data < min)
        {
            min = a->data;
        }
        a = a->next;
    }
    return min ;
}

t_list *pb(t_list **a,t_list *b)
{
    t_list *push_to_b;
    while ((*a)->next != NULL)
    {
       *a = (*a)->next;
    }
    while (b->next != NULL)
    {
       b = b->next;
    }
    push_to_b = *a;

    *a = (*a)->prev;
    push_to_b->prev = b;
    b->next = push_to_b;
    b = b->next;
    (*a)->next= NULL;
    return(b);
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
    b = ft_lstnew("12");
    i++;
    while (av[i] != NULL)
    {
        ft_lstadd_front(&a,ft_lstnew(av[i]));
        i++;
    }
    while (a->prev != NULL)
    {
        printf("%d",a->data);   
        a = a->prev;
    }
    b = pb(&a,b);
    printf("%d\n",b->data);
    // i  = find_min(a);
    // printf("min value is %d \n ", i);
    while (a->next != NULL)
    {
        printf("%d \n",a->data);
        a = a->next;
    }
    // printf("%d\n",a->data);
    return(0);
}
