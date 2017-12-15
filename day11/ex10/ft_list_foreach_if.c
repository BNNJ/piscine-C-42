#include "ft_list.h"
#include "unistd.h"

void	ft_putstr_rot13(void *str)
{
	char *tmp;

	tmp = (char*)str;
	while (*tmp)
	{
		if ((*tmp >= 'a' && *tmp <= 'm') || (*tmp >= 'A' && *tmp <= 'M'))
			*tmp += 13;
		else if ((*tmp > 'm' && *tmp <= 'z') || (*tmp > 'M' && *tmp <= 'Z'))
			*tmp -= 13;
		write(1, tmp++, 1);
	}
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return *s1 - *s2 == 0 ? 1 : 0;
}

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
							void *data_ref, int (*cmp)())
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if (cmp(list_ptr->data, data_ref))
			f(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *tmp;

	tmp = *begin_list;
	if (*begin_list)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list *list_ptr;
	int i;

	i = 0;
	list_ptr = 0;
	while (++i < ac)
		ft_list_push_back(&list_ptr, av[i]);
	return list_ptr;
}

int	 	main(int argc, char **argv)
{
	t_list *list = ft_list_push_params(argc, argv);
	if (argc == 1)
		write(1, "Arguments required\n", 19);
	else
		ft_list_foreach_if(list, ft_putstr_rot13, "Friend", ft_strcmp);
	return 0;
}