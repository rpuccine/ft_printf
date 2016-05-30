#include <stdlib.h>
#include <stdio.h>
#include "includes/ft_printf.h"
#include <locale.h>

int		main()
{
	char* l = setlocale(LC_ALL, "");
	if (l == NULL)
	{
		printf("Locale not set\n");
	}
	else
	{
		printf("Locale set to %s\n", l);
	}


	printf("int = %d -- char = %lc \n", 35, L'\u0386');
	return (0);
}
