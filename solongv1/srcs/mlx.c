/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:29:23 by jbremser          #+#    #+#             */
/*   Updated: 2024/05/14 11:42:07 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img *images_init(t_map *game)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	ft_printf("address of assets:%p\n", assets);
	load_wall_asset(game, assets);
	load_floor_asset(game, assets);
	// load_token_asset(game, assets);
	// load_player_asset(game, assets);
	load_exit_o_asset(game, assets);
	load_exit_c_asset(game, assets);
	if (!assets->wall || !assets->floor ||/* !assets->token */
		/* !assets->player ||*/ !assets->exit_open || !assets->exit_closed)
	{
		free(assets);
		return (NULL);
	}
	return (assets);
}

static void window_init(t_map	*game)
{
	t_img	*images;
	t_ani	*p_animes;
	// t_ani	*exit_animes;

	game->mlx = mlx_init((game->columns) * PIXELS,
			game->rows * PIXELS, "So_Long", false);
	if (!game->mlx)
		error_exit_array("MLX error \n", game, game->map);
	images = images_init(game);
	if (!images)
		error_exit_array("MLX error \n", game, game->map);
	p_animes = p_animes_init(game);
	game->tokens_ani = malloc(sizeof(t_ani) * game->tokens);
	while (game->token_index < game->tokens)
		game->tokens_ani[game->token_index++] = t_animes_init(game);
	game->token_index = 0;		
	ft_printf("after tokens_ani loaded\n");	
	// exit_animes = e_animes_init(game);
	if (!p_animes || !game->tokens_ani)
		error_exit_array("MLX error \n", game, game->map);
	game->images = images;
	game->p_ani = p_animes;
	// game->e_ani = exit_animes;
}


static void key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*game;

	game = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		mlx_close_window(game->mlx);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)  
		&& keydata.action == MLX_PRESS)
		move_up(game);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)  
		&& keydata.action == MLX_PRESS)
		move_down(game);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)  
		&& keydata.action == MLX_PRESS)
		move_left(game);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)  
		&& keydata.action == MLX_PRESS)
		move_right(game);
}

	// else if (keydata.key == MLX_KEY_B && keydata.action == MLX_PRESS)
	// {
	// 	mlx_loop_hook(game->mlx, emote, game);
	// 	emote(game);
	// 	ft_printf("\nI made you LOOK!\n");
	// }
// void    emote_hook(void *param)
// {
//     t_map        *game;

//     game = param;   
//     game->emote_time += game->mlx->delta_time;
//     // ft_printf("%i\n", game->emote_time);
//     if (game->emote_time > 2)
//     {
//         game->can_i_emote = true;        
//         game->emote_time = 0;
//     }
// }
// static void delete_images(mlx_t	*mlx, t_img	*images)
// {
// 	mlx_delete_image(mlx, images->wall);
// 	mlx_delete_image(mlx, images->player);
// 	mlx_delete_image(mlx, images->floor);
// 	mlx_delete_image(mlx, images->token);
// 	mlx_delete_image(mlx, images->exit_closed);
// 	mlx_delete_image(mlx, images->exit_open);
// }

void mlx_starter(t_map *game)
{
	window_init(game);
	map_render(game);
	mlx_loop_hook(game->mlx, animation_loop, game);
	mlx_key_hook(game->mlx, key_hook, game);
	step_counter_init(game);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game->images->floor);
	mlx_delete_image(game->mlx, game->images->token);
	mlx_delete_image(game->mlx, game->images->exit_closed);
	mlx_delete_image(game->mlx, game->images->exit_open);
	free_animes(game->mlx, game->p_ani);
	while (game->token_index-- > 0)
		free_animes(game->mlx, game->tokens_ani[game->token_index]);
	mlx_terminate(game->mlx);
}

	// delete_images(game->mlx, game->images);
	/*free up images and animations using mlx_delete*/
	// mlx_delete_image(game->mlx, game->p_ani->image);
	// mlx_delete_image(game->mlx, game->images->player);