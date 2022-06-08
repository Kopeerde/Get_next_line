/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:49:29 by kmendes-          #+#    #+#             */
/*   Updated: 2022/06/07 14:50:11 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = s;
	while (i < n)
	{
		res[i] = '\0';
		i++;
	}
}

/**
 * This function takes 3 parameters, a destination string, a source string and
 * the size of the destination.
 * It then copy the source into the destination up to size - 1 and ensure that
 * the string is null-terminated.
 * If the source is smaller than the destination, it fills the blank space with
 * null characters.
 * The returned value is the size that the function was able to fill into the
 * destination (generally, it send the size back.).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < size - 1)
	{
		dst[i] = (unsigned char) src[i];
		i++;
	}
	dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}

/**
 * This function takes two parameters, a string and a char as an integer.
 * It will then return a pointer towrd the first time the character appear
 * in the string. If the character is not found, it will return a NULL pointer.
 * >>> ft_strchr("Hello World", 'o')
 * "o World"
 * >>> ft_strchr("Hello World", '\0')
 * ""
 * >>> ft_strchr("Hello World", 'k')
 * (NULL)
*/
char	*ft_strchr(const char *s, int c)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	res = (char *)s;
	i = 0;
	while (res[i])
	{
		if (res[i] == (unsigned char) c)
		{
			i++;
			return (&res[i]);
		}
		i++;
	}
	if (res[i] == (unsigned char) c)
		return (&res[i]);
	return (NULL);
}

/**
 * This function takes a string as parameter and return the number of characters
 * the string have.
 * >>> ft_strlen("Hello World")
 * 11
 * >>> ft_strlen("foo bar")
 * 6
 * >>> ft_strlen("")
 * 0
*/
size_t	ft_strlen(const char *string)
{
	size_t	i;

	if (!string || !(*string))
		return (0);
	i = 0;
	while (string[i] && string[i] != 10)
		i++;
	if (string[i] == 10)
		i++;
	return (i);
}

/**
 * This function takes two strings as arguments and concatenate them into a
 * new variable while keeping the originals untouched.
 */
char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	len_s2;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (*s2 && i < len_s1 + len_s2)
	{
		res[i] = *s2;
		i++;
		s2++;
	}
	if (*s1)
		free(s1);
	res[i] = 0;
	return (res);
}
