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
	printf("@moulitest: %#.x, %#.0x\n", 0, 0);
	printf("%0+5d\n", 42);
	//printf("@moulitest: %s\n", NULL);
	printf("%03.2d\n", 1);
	printf("%03.2d\n", -1);
	printf("%3.2d\n", 1);
	printf("@moulitest: %.10d\n", -42);

	printf("\n");

	ft_printf("%5%\n");
	ft_printf("%   %\n", "test");
	ft_printf("%#x\n", 0);
	ft_printf("%#.x\n", 0);
	ft_printf("%#.x\n", 250);
	ft_printf("@moulitest: %#.x, %#.0x\n", 0, 0);
	ft_printf("%0+5d\n", 42);
	//ft_printf("@moulitest: %s\n", NULL);
	ft_printf("%03.2d\n", 1);
	ft_printf("%03.2d\n", -1);
	ft_printf("%3.2d\n", 1);
	ft_printf("@moulitest: %.10d\n", -42);
	return (0);
}
