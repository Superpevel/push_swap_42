#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>



int list_length(t_list *a)
{
    int i = 0;

    while (a->prev!= NULL)
        a=a->prev;
    while (a->next!=NULL)
    {
        i++;
        a=a->next;
    }
    return(i);
}

int is_sorted(t_list *t)
{
    int min; 
    int flag = 0;
    if(t)
    {
        min =t->data;
        while (t->prev !=NULL)
        {
            if(min > t->data)
            {
                flag = 1;
                break;
            }
            min = t->data;
            t = t->prev;
        }
    }
    else
    {
        flag = 0;
    }
    return(flag);
}

void print_a(t_list **b)
{
    if(b)
    {
    while ((*b)->next != NULL)
        *b = (*b)->next;
    while ((*b)->prev != NULL)
    {
        printf("%d a\n",(*b)->data);
        printf("%d a need swap\n",(*b)->need_swap);  
        *b = (*b)->prev;
    }
    printf("%d a\n",(*b)->data);
    printf("%d a need swap\n",(*b)->need_swap);  
    }
    else
        printf("no elem");
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

t_list	*ft_lstnew(char *data)
{
	t_list	*t;

	t = malloc(sizeof(t_list));
	if (!t)
		return (NULL);
	t->data = ft_atoi(data);
    t->need_swap = 0;
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
    while ((*list)->next !=NULL)
    {
         *list = (*list)->next;
    }
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
        if(a->data <= min)
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
    if(b)
    {
        if(list_length(*a) > 0)
        {
            while ((*a)->next != NULL)
            {
            *a = (*a)->next;
            }
                if (*b)
                {
                while ((*b)->next != NULL)
                    *b = (*b)->next;
                push_to_b = *a;
                *a = (*a)->prev;
                push_to_b->prev = *b;
                (*b)->next = push_to_b;
                *b = (*b)->next;
                (*a)->next= NULL;
                while ((*b)->next != NULL)
                    *b = (*b)->next;
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
        else
        {
            // while ((*b)->next != NULL)
            // {
            //     *b = (*b)->next;
            // }
            // push_to_b = *a;
            // push_to_b->next = NULL;
            // push_to_b->prev = *b;
            free(*a);
            printf("was");
            // *b = push_to_b;
        }
    }
    else
    {
       while((*a)->next !=NULL)
           *a = (*a)->next;
        push_to_b = *a;
        *a = (*a)->prev;
        push_to_b->prev = NULL; 
        push_to_b->next = NULL;
        b = &push_to_b;
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

void mark_next(int i,t_list **a)
{
    while ((*a)->next !=NULL)
    {
        *a = (*a)->next;
    }
    while (i != 0)
    {
        *a = (*a)->prev;
        i--;
    }
    (*a)->need_swap = 1;
    while ((*a)->next !=NULL)
    {
        *a = (*a)->next;
    }   
}

t_list *p_n(t_list *a,t_list **b)
{
    t_list *push_min;

    push_min = a;
    push_min->prev = *b;
    push_min->next = NULL;
    *b  = push_min;
    a = NULL;
    return(a);
}
int next_min_find(t_list *a,int min)
{
    int min_next;
    int min_ind = 0;
    int i = 0;

    while (a->next != NULL)
    {
        a = a->next;
    }
    min_next = a->data;
    i = 0;
    while(a)
    {
        if(a->data < min_next && (min < a->data))
        {
            min_next = a->data;
            min_ind = i;
        }
        a = a->prev;
        i++;
    }
    return min_ind;
}

int is_smaller(t_list **a,int i)
{
    int next_min_ind;
    int status;
    int min;
    int si;

    si = i;
    while ((*a)->next != NULL)
    {
        *a = (*a)->next;
    }
    while (i != 0)
    {
        *a = (*a)->prev;
        i--;
    }
    next_min_ind = next_min_find(*a,(*a)->data);
    if(si > next_min_ind)
    {

        mark_next(next_min_ind,a);
        is_smaller(a,next_min_ind);
    }
    while ((*a)->next!=NULL)
    {
        *a = (*a)->next;
    }
    // printf("%d data and need swap %d \n",(*a)->prev->prev->prev->data,(*a)->prev->prev->prev->need_swap);
    return(0);
}



void push_min(t_list **a,t_list **b)
{
    int i;
    int first = 0;
    int count = 0;
    int status;
    while (*a != NULL)
    {
        i = find_min(*a);
        // printf("%d chto\n",i);
        status = is_smaller(a,i);
        while (i > 0)
        {
            count = 0;
            while((*a)->need_swap == 1)
            {
                if((*a)->need_swap == 1)
                {
                    p(a,b);
                    printf("pb\n");
                    if(list_length(*b) > 0)
                    {
                        if(i != 1)
                        {
                            r(a);
                            r(b);
                            printf("rr\n");
                        }
                        else
                        {
                            r(b);
                            printf("rb\n");
                        }
                    }
                    if(first>0)
                    {
                        count++;
                    }
                    i--;
                }
            }
            if(list_length(*a) > 0)
            {
                r(a);
                printf("ra\n");
            }
            i--;
        }

        if(list_length(*a) == 0)
        {
            *a = p_n(*a,b);
            printf("pb\n");
            if(count>0 || first == 0)
            {
                if(list_length(*b) > 0)
                {
                    r(b);
                    printf("rb\n");
                }
            }
            
        }
        else
        {
            p(a,b);
            printf("pb\n");
            if(count>0 || first==0)
            {
                if(list_length(*b) > 0)
                {
                    r(b);
                    printf("rb\n");
                }
            }
        }
        while (count>0)
        {
            if(list_length(*b) > 0)
            {
                rra(b);
                printf("rrb\n");
            }
            count--;
        }
        first++;
    }
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
    // print_a(&b);
    // p(&a,&b);
    // p(&a,&b);
    // a = p_n(a,&b);
    // p(&b,&a);
    while (b->next !=NULL)
       b =  b->next;

    while (b->prev !=NULL)
    {
        p(&b,&a);
        printf("pa\n");   
    }
    printf("pa\n");     
    // }
 
    // printf("pb\n");
    // p(&a,&b);
    // print_a(a);
    // print_b(b);
    return(0);
}
