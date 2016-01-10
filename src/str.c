/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:03:53 by rpuccine          #+#    #+#             */
/*   Updated: 2016/01/07 16:03:56 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	ret;

	ret = 0;
	while (*str++)
		ret++;
	return (ret);
}

void	concat_prefix(char **str, char *prefix)
{
	int		len1;
	int		len2;
	int		i;
	char	*new;

	len1 = ft_strlen(*str);
	len2 = ft_strlen(prefix);
	new = (char *)malloc(sizeof(char) * (len1 + len2));
	i = -1;
	while (++i < len2)
		new[i] = prefix[i];
	i = -1;
	while (++i < len1)
		new[len2 + i] = (*str)[i];
	//free(*str);
	*str = new;
}
