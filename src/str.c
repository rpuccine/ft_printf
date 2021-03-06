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

int		str_cmp(const char *str, const char *sample, int nb)
{
	if (!(*sample))
		return (nb);
	if (!(*str) || *str != *sample)
		return (-1);
	return (str_cmp(++str, ++sample, ++nb));
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
}

size_t	ft_strlen(const char *str)
{
	int	ret;

	ret = 0;
	if (!str)
		return (0);
	while (*str++)
		ret++;
	return (ret);
}

size_t	ft_strlen_w(const wchar_t *str_w)
{
	int	ret;

	ret = 0;
	while (str_w[ret])
		ret++;
	printf("strlen_w = %d\n", ret);
	return (ret);
}

void	prefix_with_c(char **str, char c, int nb_c)
{
	int		len_str;
	int		i;
	char	*new;

	len_str = ft_strlen(*str);
	new = (char *)malloc(sizeof(char) * (len_str + nb_c + 1));
	i = -1;
	while (++i < nb_c)
		new[i] = c;
	i = -1;
	while (++i < len_str)
		new[i + nb_c] = (*str)[i];
	new[i + nb_c] = '\0';
	free(*str);
	*str = new;
}

void	suffix_with_c(char **str, char c, int nb_c)
{
	int		len_str;
	int		i;
	char	*new;

	len_str = ft_strlen(*str);
	new = (char *)malloc(sizeof(char) * (len_str + nb_c + 1));
	i = -1;
	while (++i < len_str)
		new[i] = (*str)[i];
	i = -1;
	while (++i < nb_c)
		new[i + len_str] = c;
	new[i + len_str] = '\0';
	free(*str);
	*str = new;
}

void	concat_prefix(char **str, char *prefix)
{
	int		len1;
	int		len2;
	int		i;
	char	*new;

	len1 = ft_strlen(*str);
	len2 = ft_strlen(prefix);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	i = -1;
	while (++i < len2)
		new[i] = prefix[i];
	i = -1;
	while (++i < len1)
		new[len2 + i] = (*str)[i];
	new[len1 + len2] = '\0';
	free(*str);
	*str = new;
}

void	concat_suffix(char **str, char *suffix)
{
	int		len1;
	int		len2;
	int		i;
	char	*new;

	len1 = ft_strlen(*str);
	len2 = ft_strlen(suffix);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	i = -1;
	while (++i < len1)
		new[i] = (*str)[i];
	i = -1;
	while (++i < len2)
		new[len1 + i] = suffix[i];
	new[len1 + len2] = '\0';
	//free(*str);
	*str = new;
}
