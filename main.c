/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:49:39 by efarhat           #+#    #+#             */
/*   Updated: 2022/11/30 19:43:32 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int		fd1;

	fd1 = open("file.txt", O_RDONLY);
	printf("line : %s", get_next_line(fd1));

	close(fd1);
	return (0);
}
