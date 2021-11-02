/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:57:48 by yusong            #+#    #+#             */
/*   Updated: 2021/11/02 12:24:26 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

void	*safeMalloc(int malloc_size)
{
	void	*tmp;

	tmp = malloc(malloc_size);
	if (!tmp)
		errorExit("Malloc");
	return (tmp);
}

static size_t	g_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	if (s == 0)
		return (0);
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dest == 0 || src == 0)
		return (0);
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (i < len && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}

char	**ft_split(char *s, char c)
{
	char	**ret;
	size_t	i;
	char	*start;
	size_t	len;

	if (!s)
		return (0);
	ret = (char **)safeMalloc(sizeof(char *) * (g_cnt(s, c) + 1));
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			len = s - start + 1;
			ret[i] = (char *)safeMalloc(sizeof(char) * len);
			ft_strlcpy(ret[i++], start, len);
		}
		else
			s++;
	}
	ret[i] = 0;
	return (ret);
}
