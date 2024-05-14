/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:05:54 by jbremser          #+#    #+#             */
/*   Updated: 2024/05/14 11:26:27 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void load_wall_asset(t_map *game, t_img *img)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./assets/wall.png");
	if (!wall)
	{
		write(2, "Error loading png\n", 18);
		return ;
	}
	img->wall = mlx_texture_to_image(game->mlx, wall);
	mlx_delete_texture(wall);
	if (!img->wall)
	{
		mlx_close_window(game->mlx);
		write(2, "Error with texture to image\n", 28);
		return ;
	}
	mlx_resize_image(img->wall, PIXELS, PIXELS);
}

//  
// void load_player_asset(t_map *game, t_img *img)
// {
// 	mlx_texture_t	*player;

// 	player = mlx_load_png("./assets/player.png");
// 	if (!player)
// 	{
// 		write(2, "Error loading png\n", 18);
// 		return ;
// 	}
// 	img->player = mlx_texture_to_image(game->mlx, player);
// 	mlx_delete_texture(player);
// 	if (!img->player)
// 	{
// 		mlx_close_window(game->mlx);
// 		write(2, "Error with texture to image\n", 28);
// 		return ;
// 	}
// 	mlx_resize_image(img->player, PIXELS, PIXELS);
// }

void load_floor_asset(t_map *game, t_img *img)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./assets/floor.png");
	if (!floor)
	{
		write(2, "Error loading png\n", 18);
		return ;
	}
	img->floor = mlx_texture_to_image(game->mlx, floor);
	mlx_delete_texture(floor);
	if (!img->floor)
	{
		mlx_close_window(game->mlx);
		write(2, "Error with texture to image\n", 28);
		return ;
	}
	mlx_resize_image(img->floor, PIXELS, PIXELS);
}
void load_exit_o_asset(t_map *game, t_img *img)
{
	mlx_texture_t	*exit_open;

	exit_open = mlx_load_png("./assets/exit_open.png");
	if (!exit_open)
	{
		write(2, "Error loading png\n", 18);
		return ;
	}
	img->exit_open = mlx_texture_to_image(game->mlx, exit_open);
	mlx_delete_texture(exit_open);
	if (!img->exit_open)
	{
		mlx_close_window(game->mlx);
		write(2, "Error with texture to image\n", 28);
		return ;
	}
	mlx_resize_image(img->exit_open, PIXELS, PIXELS);
}
void load_exit_c_asset(t_map *game, t_img *img)
{
	mlx_texture_t	*exit_closed;

	exit_closed = mlx_load_png("./assets/exit_closed.png");
	if (!exit_closed)
	{
		write(2, "Error loading png\n", 18);
		return ;
	}
	img->exit_closed = mlx_texture_to_image(game->mlx, exit_closed);
	mlx_delete_texture(exit_closed);
	if (!img->exit_closed)
	{
		mlx_close_window(game->mlx);
		write(2, "Error with texture to image\n", 28);
		return ;
	}
	mlx_resize_image(img->exit_closed, PIXELS, PIXELS);
}