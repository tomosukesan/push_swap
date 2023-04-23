#include "push_swap.h"

void	print_listnum(t_list *lst)
{
	//t_list	*last;

	//last = lst;
	//while (last->next != NULL)
	//{
	//	printf("num:	%d, rank:	%u\n", last->num, last->rank);
	//	last = last->next;
	//}
	t_list	*target;

	if (lst == NULL)
		return ;
	target = lst->next;
	while (target->rank != -1)
	{
		printf("num:	%d, rank:	%d\n", target->num, target->rank);
		target = target->next;
	}
}

int	main(int argc, char *argv[])
{
	push_swap(argv);
	(void) argc;
	//(void) argv;
	//print_listnum();

	//while (1){}
	return (0);
}
