/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:04:31 by merlich           #+#    #+#             */
/*   Updated: 2021/12/02 18:17:00 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>

	int	fd;
	char	*file = "1.txt";
	fd = open (file, O_RDONLY);
//	printf("%s", get_next_line(0));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	//printf("%s\n", NULL);
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// printf("LINE = %s\n", get_next_line(fd));
	// 	printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// 	printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// 	printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// printf("----------\nLINE = %s\n--------\n", get_next_line(fd));
	// 	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// 	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// 	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// 	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// 	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// 	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// 	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// 	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	close(fd);
//	ft_read();
	return(0);
}

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

