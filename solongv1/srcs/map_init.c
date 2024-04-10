/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:09:02 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/10 11:27:34 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_init(t_map *game, char *args)
{
	int fd;
	char *line;
	char *temp;
	char *result;

	if (!args)
		return (1);
	if (ft_strncmp(args + (ft_strlen(args) - 4), ".ber", 4) != 0)
		{
			ft_putstr_fd("Bad Map. Must end with .ber\n", 2);
			return (1);
		}
	fd = open(args, O_RDWR);
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = ft_strjoin(temp, line);
		temp = result;
	}
	close(fd);
	freenull(&line);
	return (0);
}

char	*map_to_str()
{
	
}