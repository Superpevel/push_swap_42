#ifndef PUSHSWAP_H
# define PUSHSWAP_H
    typedef struct s_list
    {
        int data;
        struct s_list	*next;
        struct s_list	*prev;  
        int need_swap;
        int flag;
        int order;
    } t_list;

    typedef struct s_mas
    {
        int data;
        int index;
        struct s_list	*next;
        struct s_list	*prev;  
    } t_mas;

    typedef struct s_main
    {
        int flag;
        int next;
        int mid;
        int max;
        int index;
    } t_main;  
int	ft_atoi(const char *str);
#endif 
