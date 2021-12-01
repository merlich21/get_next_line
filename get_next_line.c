/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:16:50 by merlich           #+#    #+#             */
/*   Updated: 2021/11/30 19:00:44 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 #include <stdio.h>

static size_t	ft_search(char *s, char c)
{
	size_t	ind;
	size_t	len;

	ind = 0;
	len = ft_strlen(s);
	while ((ind < len) && ((unsigned char) s[ind] != (unsigned char) c))
	{
		ind++;
	}
	// if (ind == len)
	// {
	// 	ind = -1;
	// }
	return (ind);
}

static char	*ft_get_new_tmp(char *tmp, char *buff)
{
	char	*tmp_old;

	tmp_old = tmp;
	tmp = ft_strjoin(tmp, buff);
	free(tmp_old);
	return (tmp);
}

// static int	ft_get_tmp(int fd, int res, char **buff, char **tmp)
// {
// 	res = read(fd, *buff, BUFFER_SIZE);
// 	*buff[res] = '\0';
// 	while ((ft_search(*buff, '\n') == -1) && (res > 0))
// 	{
// 		*tmp = ft_get_new_tmp(*tmp, *buff);
// 		res = read(fd, *buff, BUFFER_SIZE);
// 		*buff[res] = '\0';
// 	}
// 	return (res);
// }

static char	*ft_build_line(char *s, char *tmp, char *buff)
{
	int		index;
	char	*str;
	char	*line;

	index = ft_search(tmp, '\n');		//// Error -1
	if (index == -1)
		str = ft_substr(tmp, 0, ft_strlen(tmp));
	else
		str = ft_substr(tmp, 0, index + 1); //// Error -1
	line = ft_strjoin(s, str);
	free(str);
	ft_strdup(ft_strchr(buff, '\n'), s);
	free(buff);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	s[BUFFER_SIZE + 1] = "\0";
	int			res;
	char		*line;
	char		*tmp;
	char		*buff;

	res = 1;
	line = NULL;
	if ((ft_search(s, '\n') != ft_strlen(s)))
	{
		line = ft_substr(s, 0, ft_search(s, '\n') + 1);
		ft_strdup(ft_strchr(s, '\n'), s);
		return (line);
	}
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (NULL == tmp)
		return (NULL);
	tmp[0] = '\0';
	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (NULL == buff)
		return (NULL);
	buff[0] = '\0';
//	res = ft_get_tmp(fd, res, &buff, &tmp);
	res = read(fd, buff, BUFFER_SIZE);
	// if (res == 0 && s[0] != '\0')
	// {
	// 	line = s;
	// 	ft_strdup(ft_strchr(buff, '\n'), s);
	// 	return (line);
	// }
	if (res == -1 || (res == 0 && s[0] == '\0'))
	{
		free(tmp);
		free(buff);
		return (NULL);
	}
	buff[res] = '\0';
//	printf("%d\n", res);
	while ((ft_search(buff, '\n') == ft_strlen(buff)) && (res > 0)) // Error -1
	{
		tmp = ft_get_new_tmp(tmp, buff);
		res = read(fd, buff, BUFFER_SIZE);
	//	printf("%s\n", tmp);
	//	printf("%d\n", res);
		if (res == -1)
		{
			free(tmp);
			free(buff);
			return (NULL);
		}
		buff[res] = '\0';
	}
	tmp = ft_get_new_tmp(tmp, buff);
	// printf("_____%s\n", tmp);
	line = ft_build_line(s, tmp, buff);
	// printf("_____%s\n", line);
	return (line);
}

// int	main(void)
// {
// 	#include <sys/types.h>
// 	#include <sys/stat.h>
// 	#include <fcntl.h>

// 	int	fd;
// 	char	*file = "../1.txt";
// 	fd = open (file, O_RDONLY);
// //	printf("%s", get_next_line(0));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	//printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	//printf("%s\n", NULL);
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// printf("LINE = %s\n", get_next_line(fd));
// 	// 	printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// 	printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// 	printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
// 	// 	printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// 	printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// 	printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// 	printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// 	printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// 	printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// 	printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// 	printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	close(fd);
// //	ft_read();
// 	return(0);
// }

// int	main(void)
// {
// //	char const	s1[] = "Hello ";
// //	char const	s2[] = "World!\n";
// 	char	*s1 = "\nmy favorite animal is ";
// 	const char	*s2 = "CAT";
// 	char		*s = NULL;
// 	//char *s2 = s1 + 20;
// 	char *res = ft_strjoin(s1, s2);
// 	//char *res = ft_substr(s1, 0, ft_search(s1, 'm'));
// 	s = ft_strchr(s1, 'm');
// 	// if (!strcmp(res, "s my favorite animal is "))
// 	// {
// 	// 		write(1, "HELLO!", 6);
// 	// }
// 	printf("%s\n", res);
// 	printf("%s\n", s);
// //	write(1, res, ft_strlen(s1) + ft_strlen(s2));
// 	return (0);
// }

