#ifndef PUSHSWAP_H
# define PUSHSWAP_H
    typedef struct s_list
    {
        int data;
        struct s_list	*next;
        struct s_list	*prev;  
        int need_swap;
    } t_list;
int	ft_atoi(const char *str);
#endif 
