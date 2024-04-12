/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:03:28 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/11 14:07:42 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	freenull(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

int error_msg_exit(char *msg, t_map *game)
{
	write(2, msg, ft_strlen(msg));
	free(game);
	exit(1);
}
