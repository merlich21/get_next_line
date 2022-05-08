/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:04:31 by merlich           #+#    #+#             */
/*   Updated: 2021/12/02 20:42:39 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int	i = 0;
	int	fd;
	char	*s;
	
	i = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd != -1)
	{
		while (i < 1000)
		{
			s = get_next_line(fd);
			printf("%s", s);
			i++;
		}
		close(fd);
	}
	return (0);
}
