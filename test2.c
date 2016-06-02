#include <stdlib.h>
#include <stdio.h>
#include "includes/ft_printf.h"
#include <locale.h>

int		main()
{
	char* l = setlocale(LC_ALL, "");
	if (l == NULL)
	{
		printf("Locale not set\n\n");
	}
	else
	{
		printf("Locale set to %s\n\n", l);
	}


	printf("%5%\n");
	printf("%   %\n", "test");
	printf("%#x\n", 0);
	printf("%#.x\n", 0);
	printf("%#.x\n", 250);

	printf("\n");

	ft_printf("%5%\n");
	ft_printf("%   %\n", "test");
	ft_printf("%#x\n", 0);
	ft_printf("%#.x\n", 0);
	ft_printf("%#.x\n", 250);
	return (0);
}
