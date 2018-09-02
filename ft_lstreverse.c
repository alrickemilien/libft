#include "libft.h"

void	ft_lstreverse(t_list **lst)
{
	t_list	*before;
	t_list	*current;

	if (!*lst || !(*lst)->next)
		return ;
	current = *lst;
	before = *lst;
	*lst = (*lst)->next;
	current->next = NULL;
	while ((*lst)->next)
	{
		current = *lst;
		*lst = (*lst)->next;
		current->next = before;
		before = current;
	}
	(*lst)->next = before;
}
