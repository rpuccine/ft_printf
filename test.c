#include <stdlib.h>
#include <stdio.h>
#include "includes/ft_printf.h"


int		main()
{

	char	*str = "pipi prout";
	//printf("coucou gros pd\n");
	printf("		char %7zd\n\
		short %7zd\n\
		int %7zd\n\
		long %7zd\n\
		long long %7zd\n\
		size_t %7zd\n\
		intmax_t - %jd\n\
		intmax_t + %jd\n\n",
		sizeof(char),
		sizeof(short),
		sizeof(int),
		sizeof(long),
		sizeof(long long),
		sizeof(size_t),
		INTMAX_MIN,
		INTMAX_MAX
		);
	printf("true Printf: %#x puis %35.7d\n", 31, 45);
	printf("true Printf: %d puis %35.7d\n", 31, 45);
	printf("true Printf: %+d puis %35.7d\n", 31, 45);
	printf("true Printf: % d puis %35.7d\n", 31, 45);
	printf("true Printf: %+ d puis %35.7d\n", 31, 45);
	printf("true Printf: % +7.3d puis %35.7d\n", 31, 45);
	printf("true Printf: %+++# 7.3d puis %35.7d\n", 31, 45);
	printf("true Printf: %++#+ 7.3x puis %35.7d\n", 31, 45);
	printf("true Printf: %-+7.3d puis %35.7d\n", 31, 45);
	printf("true Printf: %-#7.3x puis %35.7d\n", 31, 45);
	printf("true Printf: %-#+7.3x puis %35.7d\n", 31, 45);
	printf("true Printf: %% puis %35.7d\n", 31);

	printf("true Printf: %7c \n", str[0]);
	printf("true Printf: %-7c \n", str[0]);
	printf("true Printf: %s \n", str);
	printf("true Printf: %.3s \n", str);

	printf("true Printf: %hhd \n", 59000);
	printf("true Printf: %hd \n", 59000);

	/*printf("cou %x\n", 31);
	printf("cou %d\n", -31);
	printf("cou %i\n", 31);
	printf("cou %u\n", -31);
	printf("cou %o\n\n", 31);*/

	printf("\n");


	ft_printf("fals printf: %#x puis %35.7d\n", 31, 45);
	ft_printf("fals printf: %d puis %35.7d\n", 31, 45);
	ft_printf("fals printf: %+d puis %35.7d\n", 31, 45);
	ft_printf("fals printf: % d puis %35.7d\n", 31, 45);
	ft_printf("fals printf: %+ d puis %35.7d\n", 31, 45);
	ft_printf("fals printf: % +7.3d puis %35.7d\n", 31, 45);
	ft_printf("fals printf: %+++# 7.3d puis %35.7d\n", 31, 45);
	ft_printf("fals printf: %++#+ 7.3x puis %35.7d\n", 31, 45);
	ft_printf("fals printf: %-+7.3d puis %35.7d\n", 31, 45);
	ft_printf("fals printf: %-#7.3x puis %35.7d\n", 31, 45);
	ft_printf("fals printf: %-#+7.3x puis %35.7d\n", 31, 45);
	ft_printf("fals printf: %% puis %35.7d\n", 31);

	ft_printf("fals printf: %7c \n", str[0]);
	ft_printf("fals printf: %-7c \n", str[0]);
	ft_printf("fals printf: %s \n", str);
	ft_printf("fals printf: %.3s \n", str);

	ft_printf("fals printf: %hhd \n", 59000);
	ft_printf("fals printf: %hd \n", 59000);


	/*ft_printf("cou %x\n", 31);
	ft_printf("cou %d\n", -31);
	ft_printf("cou %i\n", 31);
	ft_printf("cou %u\n", -31);
	ft_printf("cou %o\n", 31);*/

	//ft_printf("coucou gros pd\n");
	//ft_printf("coucou %d pd\n", 5);
	return (0);
}