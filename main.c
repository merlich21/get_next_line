/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:04:31 by merlich           #+#    #+#             */
/*   Updated: 2022/05/08 20:48:16 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int	i = 0;
	int	fd;
	char	*s;
	
	i = 0;
	fd = open("example.txt", O_RDONLY);
	// fd = 0;  // You can read from stdin (uncomment this row for this)
	if (fd == -1)
		return (-1);
	else
	{
		s = get_next_line(fd);
		while (s)
		{
			printf("%s", s);
			s = get_next_line(fd);
		}
		close(fd);
	}
	return (0);
}
