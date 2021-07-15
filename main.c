#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>
t_list	*ft_lstnew(char *data)
{
	t_list	*t;

	t = malloc(sizeof(t_list));
	if (!t)
		return (NULL);
	t->data = data;
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
	char	*t;
    char    *t1;
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
    while (av[i] !=NULL)
    {
        ft_lstadd_front(&a,ft_lstnew(av[i]));
        i++;
    }
    // a  = sa(a);
    while (a->next != NULL)
    {
        a = a->next;
    }
    while (a->prev != NULL)
    {
        printf("%s 2\n",a->data);
        a = a->prev;
    }  
    printf("%s\n",a->data);
    return(0);
}
