/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:49:36 by kmendes-          #+#    #+#             */
/*   Updated: 2022/06/07 14:50:15 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	check_prev_buff(char **res, char *buffer)
{
	if (!ft_strchr(buffer, 10))
	{
		*res = ft_strjoin(*res, buffer);
		if (ft_strchr(buffer, 0))
			buffer[0] = 0;
	}
	else
	{
		*res = ft_strjoin(*res, buffer);
		ft_strlcpy(buffer, &buffer[ft_strlen(buffer)], BUFFER_SIZE);
		return (1);
	}
	return (0);
}

static void	*gnl(int fd, char *prev_buff, char **res)
{
	char	*string;

	string = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!string)
		return (NULL);
	ft_bzero(string, BUFFER_SIZE);
	while (read(fd, string, BUFFER_SIZE))
	{
		string[BUFFER_SIZE] = 0;
		if (ft_strchr(string, 10))
		{
			*res = ft_strjoin(*res, string);
			ft_strlcpy(prev_buff, ft_strchr(string, 10), BUFFER_SIZE);
			free(string);
			return (*res);
		}
		*res = ft_strjoin(*res, string);
		ft_bzero(string, BUFFER_SIZE);
	}
	free(string);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	prev_buff[BUFFER_SIZE];

	res = "";
	if (*prev_buff)
		if (check_prev_buff(&res, prev_buff))
			return (res);
	if (fd == -1 || read(fd, 0, 0))
		return (NULL);
	gnl(fd, prev_buff, &res);
	if (*res)
		return (res);
	return (NULL);
}

/*
#include <fcntl.h>

int main()
{
	char *ksk;

	// RUN WITHING CLION
//	int file = open("./Testing/nl", O_RDONLY);
//	int file = open("./Testing/trump_ipsum", O_RDONLY);
//	int file = open("./Testing/empty", O_RDONLY);
//	int file = open("./Testing/41_no_nl", O_RDONLY);
//	int file = open("./Testing/41_with_nl", O_RDONLY);
//	int file = open("./Testing/42_no_nl", O_RDONLY);
//	int file = open("./Testing/42_with_nl", O_RDONLY);
	int file = open("./Testing/43_no_nl", O_RDONLY);
//	int file = open("./Testing/43_with_nl", O_RDONLY);
//	int file = open("./Testing/alternate_line_nl_no_nl", O_RDONLY);
//	int file = open("./Testing/alternate_line_nl_with_nl", O_RDONLY);
//	int file = open("./Testing/big_line_no_nl", O_RDONLY);
//	int file = open("./Testing/big_line_with_nl", O_RDONLY);
//	int file = open("./Testing/multiple_line_no_nl", O_RDONLY);
//	int file = open("./Testing/multiple_line_with_nl", O_RDONLY);
//	int file = open("./Testing/multiple_nlx5", O_RDONLY);

	// RUN OUTSIDE CLION
//	int file = open("./cmake-build-debug/Testing/nl", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/trump_ipsum", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/empty", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/41_no_nl", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/41_with_nl", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/42_no_nl", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/42_with_nl", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/43_no_nl", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/43_with_nl", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/alternate_line_nl_no_nl", );
//	int file = open("./cmake-build-debug/Testing/alternate_line_nl_with_nl", );
//	int file = open("./cmake-build-debug/Testing/big_line_no_nl", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/big_line_with_nl", O_RDONLY);
//	int file = open("./cmake-build-debug/Testing/multiple_line_no_nl", );
//	int file = open("./cmake-build-debug/Testing/multiple_line_with_nl", );
//	int file = open("./cmake-build-debug/Testing/multiple_nlx5", O_RDONLY);

	for (int i = 0; i < 3; i++)
	{
		ksk = get_next_line(file);
		printf("%s", ksk);
//		usleep(150000);
		free(ksk);
	}
	close(file);
	return 0;
}
*/