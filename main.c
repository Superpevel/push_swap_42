#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>


void deleteList(t_list **head)
{
    t_list *prev= *head;
 
    while (*head)
    {
        *head = (*head)->next;
 
        printf("Deleting %d\n", prev->data);
        free(prev);
        prev = *head;
    }
}

void print_a(t_list *b)
{
    while (b->next != NULL)
        b = b->next;
    while (b->prev != NULL)
    {
        printf("%d vakue order %d\n",b->data,b->order);
        b = b->prev;
    }
    printf("%d vakue order %d\n",b->data,b->order);
}

int list_length(t_list *a)
 {
    int i = 1;
    if(a && &a)
    {
        while (a->prev!= NULL)
            a=a->prev;
        while (a->next!=NULL)
        {
            i++;
            a=a->next;
        }
        return(i);
    }
    else
    {
        return(0);
    }
}

t_mas	*ft_masnew(int data,int index)
{
	t_mas	*t;

	t = malloc(sizeof(t_mas));
	if (!t)
		return (NULL);
	t->data = data;
    t->index = index;
	t->next = NULL;
    t->prev = NULL;
	return (t);
}

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

void	ft_masadd_front(t_mas **lst, t_mas *new)
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


int pa(t_list **b,t_list **a)
{
    printf("len %d",list_length(*b));
    t_list *tmp;
    if (list_length(*b) == 1)
    {
        tmp = *b;
        deleteList(b);
    }
    ft_lstadd_front(a,tmp);
}
int p(t_list **a,t_list **b)
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

    return(1);
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

int array_sorted(t_list *a)
{
     int i;

     while (a->prev!= NULL)
         a=a->prev;
     i = a->data;
     while (a->next!=NULL)
     {
        if (!(a->next->data < i))
            return(1);
        a=a->next;
        i = a->data;
     }
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

int next_max_find(t_list *a,int min)
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
         if(a->data > min_next && (min < a->data))
         {
             min_next = a->data;
             min_ind = i;
         }
         a = a->prev;
         i++;
     }
     return min_ind;
 }

 int is_smaller(t_list **a,int i,int rotation)
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
     if (rotation == 0)
     {
        if(si > next_min_ind)
        {
            return(next_min_ind);
        }
     }
     else
     {
        if(si < next_min_ind)
        {
            return(next_min_ind);
        }         
     }
     return(-1);
 }

 int max_find(t_list **a,int i,int rotation)
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
     next_min_ind = next_max_find(*a,(*a)->data);
     if (rotation == 0)
     {
        if(si > next_min_ind)
        {
            return(next_min_ind);
        }
     }
     else
     {
        if(si < next_min_ind)
        {
            return(next_min_ind);
        }         
     }
     return(-1);
 }

void push_min(t_list **a,t_list **b)
{
    int i;
    int next_min;
    int first;
    int need_swap;
    int rotation;
    int index;
    first = 1;
    index=0;
    int need_swap_elements;
    int fetch = 0;
    need_swap_elements=0;
    while ((*a)->prev !=NULL && array_sorted(*a) != 0)
    {
        if (fetch==0)
        {
            i = find_min(*a); /// dobavit na is_sort + reverse find
            rotation = list_length(*a) - i +1;
            if (rotation < i)
            {
                i = rotation;
                rotation=1;
            }
            else
            {
                rotation = 0;
            }  
        }    
        else
            fetch=0;
        if (rotation == 1)
        {
                while (i !=0)
                {
                    next_min = is_smaller(a,i,rotation);
                    if (next_min==0 && list_length(*a)>2)
                    {
                        p(a,b);
                        printf("pb\n");
                        need_swap=1; 
                        need_swap_elements+=1; 
                        i-=1;            
                    }
                    if (i > 0)
                    {
                        rra(a);
                        printf("rra\n");
                        i--;
                    }
                }
                p(a,b);
                printf("pb\n");
                // need_swap_elements+=1; 
                i = find_min(*a);
                fetch=1;
                rotation = list_length(*a) - i + 1;
                if (rotation < i)
                {
                    i = rotation;
                    rotation=1;
                }
                else
                    rotation = 0;
                index = need_swap_elements;
                while (need_swap_elements >0 && list_length(*b) >0)
                {
                    // if (rotation == 0 && i > 1)
                    // {
                    //     printf("rr\n");
                    //     r(a);
                    //     r(b);
                    //     i--;
                    // }
                    // else
                    // {
                    printf("rb\n");
                    r(b);
                    // }
                    need_swap_elements--;
                }

                while (index>0)
                {
                    // if (rotation == 1 && i > 1)
                    // {
                    //     printf("rrr\n");
                    //     rra(a);
                    //     rra(b);
                    //     i--;
                    // }
                    // else
                    // {
                        printf("rrb\n");
                        rra(b);
                    // }
                    index--;                 
                }  
                if(need_swap)
                {
                    need_swap=0;
                }
        }
        if (rotation==0)
        {
                fetch=0;
                while (i !=0)
                {
                    next_min = is_smaller(a,i,rotation);
                    if (next_min==0 && list_length(*a)>2)
                    {
                        p(a,b);
                        printf("pb\n");
                        need_swap=1; 
                        need_swap_elements+=1; 
                        i-=1;            
                    }
                    if (i > 0)
                    {
                        r(a);
                        printf("ra\n");
                        i--;
                    }
                }
                p(a,b);
                printf("pb\n");
                if(list_length(*b)>100000)
                {
                    printf('rb\n');
                    r(b);
                }
                // i = find_min(*a);
                // fetch=1;
                // rotation = list_length(*a) - i + 1;
                // if (rotation < i)
                // {
                //     i = rotation;
                //     rotation=1;
                // }
                // else
                //     rotation = 0;
                
                index = need_swap_elements;
                while (need_swap_elements >0 && list_length(*b) >0)
                {
                    // if (rotation == 0)
                    // {
                    //     printf("rr\n");
                    //     r(a);
                    //     r(b);
                    //     i--;
                    // }
                    // else
                    // {
                        printf("rb\n");
                        r(b);
                    // }
                    need_swap_elements--;
                }
                while (index>0)
                {
                    // if (rotation == 1)
                    // {
                    //     printf("rrr\n");
                    //     rra(b);
                    //     rra(a);
                    //     i--;
                    // }
                    // else
                    // {
                        printf("rrb\n");
                        rra(b);                        
                    // }
                    index--;                 
                }  
                if(need_swap)
                {
                    need_swap=0;
                }
        }           
        need_swap_elements = 0;
        first = 0;
    }
}

void print_b(t_list *b)
{
    if (b)
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
}


int *sort_mas(int *mas,int length)
{
    int i = 0;
    int j;
    int max;
    int swap;

    while (i < length)
    {
        j = 0;
        max = mas[j];
        while (j < length - i)
        {
            if (mas[j]  > mas[j+1])
            {
                swap = mas[j+1];
                mas[j+1] = mas[j];
                mas[j] = swap; 
            }
            j++;
        }
        i++;
    }
    return(mas);
}

t_mas *get_list_from_mas(int *mas,int length)
{
    int i;
    int index;

    index = length;
    t_mas *list_mas;
    i = 0;
    list_mas = ft_masnew(mas[i],index-i);
    i++;
    while (i <= length)
    {
        ft_masadd_front(&list_mas,ft_masnew(mas[i],index-i));
        i++;
    }
    return(list_mas);

}

int *get_mas(t_list *a,int length)
{
    int i = 0;
    int *mas;
    t_mas *mas_list;
    mas = (int *)malloc(sizeof(int) * length); 
    while (i <= length)
    {
        mas[i] = a->data;
        a = a->prev;
        i++;
    }
    mas = sort_mas(mas,length);
    // mas_list = get_list_from_mas(mas,length);
    // printf("%d check list\n",mas_list->data);
    return(mas);
}

void print_mas(t_mas *mas)
{
    while (mas->prev != NULL)
    {
        mas = mas->prev;
    }
    while (mas->next)
    {
        printf("value %d  index %d\n",mas->data ,mas->index);
        mas = mas->next;
    }
    printf("value %d  index %d\n",mas->data ,mas->index);
}

void add_order(t_list *a,int *mas,int length)
{
    int i; 
    while (a->prev !=NULL)
        a = a->prev;

    while (i <= length)
    {
        if (a->data == mas[i])
        {
            a->order = i;
            i++;
            while (a->prev !=NULL)
                a = a->prev;
        }
        else
        {
            a = a->next;
        }
    }
}

int mas_len(int *mas)
{
    int i = 0;
    
    while (mas[i])
    {
        i++;
    }
    return(i);    
}
void  init_main(t_main **smain,int next)
{
    (*smain)->flag = 1;
    (*smain)->index = 0;
    (*smain)->next = next;

}

int get_mid(int *mas,t_main *main)
{
    int i;

    i = 0;
    while (mas[i])
    {
        if (mas[i] == 1)
            return(i);
        i++;
    }
    
}
int has_elements(int mid,t_list *a)
{
    if(!a && !&a)
    {
        return(0);
    }
    while (a->next !=NULL)
        a = a->next;
    if(a->data <= mid)
    {
            return(1);
    }   
    while (a->prev !=NULL)
    {
        if(a->data <= mid)
            return(1);
        a = a->prev;
    }
    if(a->data <= mid)
        return(1);
    return(0);
}

void sort2(int *mas,t_list **a,t_list **b,t_main **smain)
{
    int multiple = 4;

    print_b(*b);   
    while (list_length(*b) > 2)
    {
        (*smain)->mid = mas_len(mas)/multiple;
        multiple= multiple + 2;
        while (has_elements(mas[(*smain)->mid], *b))
        {
            while ((*b)->data <= mas[(*smain)->mid ])
            {
                if(list_length(*b) > 1)
                {
                    p(b,a);
                    while ((*b)->next != NULL)
                        (*b) = (*b)->next;
                }
                else
                    pa(b,a);     
                printf("pa\n"); 
            }
            if(list_length(*b) > 1)
            {
                r(b);
                while ((*b)->next !=NULL)
                    (*b) = (*b)->next;
                printf("ra\n");
            }
        }
        if(list_length(*b) == 0)
        {
            pa(b,a);
            printf("pa\n"); 
        } 
    }  
}

void new_sort(int *mas,t_list **a,t_list **b)
{
    t_main *smain;
    smain = (t_main *)malloc(sizeof(t_main));
    smain->flag = 0;
    smain->next = 0;
    int i = mas_len(mas);
    int mid;
    int l;
    smain->max = i-1;
    while ((*a)->next !=NULL)
        (*a) = (*a)->next;
    smain->mid = smain->max/2;

    while (has_elements(mas[smain->mid], *a))
    {
        while ((*a)->data <= mas[smain->mid ])
        {
            p(a,b);
            printf("pb\n");
            while ((*a)->next != NULL)
                (*a) = (*a)->next;
        }
        if(list_length(*a) > 1)
        {
            r(a);
            while ((*a)->next !=NULL)
                (*a) = (*a)->next;
            printf("ra\n");
        }
    }
    sort2(mas,a,b,&smain);
}

int main(int ac, char **av)
{
    int i;
    t_list *a;
    t_list *b;
    int *mas;
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
    i = list_length(a) - 1;
    while (a->next != NULL)
    {
        a= a->next;
    }
    mas = get_mas(a,i);
    add_order(a,mas,i);
    new_sort(mas,&a,&b);
    return(0);
}
