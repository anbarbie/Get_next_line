/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 00:57:38 by antbarbi          #+#    #+#             */
/*   Updated: 2019/12/17 00:57:38 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd1;
	int fd2;
	int fd3;
	int ret;
	char *line;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	fd3 = open("wahoo.txt", O_RDONLY);
	while ((ret = get_next_line(fd1, &line)) > 0)
	{
		printf("[%d] %s\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("[%d] %s\n", ret, line);
	while ((ret = get_next_line(fd2, &line)) > 0)
	{
		printf("[%d] %s\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("[%d] %s\n", ret, line);
	while ((ret = get_next_line(fd3, &line)) > 0)
	{
		printf("[%d] %s\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("[%d] %s\n", ret, line);
	free(line);
}