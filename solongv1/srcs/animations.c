/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:32:19 by jbremser          #+#    #+#             */
/*   Updated: 2024/05/13 17:38:19 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	animate(t_map *game, t_ani *ani)
{
	mlx_image_t *cur;
	mlx_image_t *next;
	int	c;
	int	n;

	if (!ani->enabled)
		return ;
	c = game->cur_frame % ani->len;
	n = (game->cur_frame + 1) % ani->len;
	cur = ani->animes[c];
	next = ani->animes[n];
	cur->instances[ani->ids[c]].enabled = false;
	next->instances[ani->ids[n]].enabled = true;
	// if (!ani->loop && c == 3)
	// 	ani->enabled = false;
}


void    animation_loop(void *param)
{
    t_map    *game;
	int i;

	game = param;
	game->emote_time += game->mlx->delta_time;
    if (game->emote_time > 0.166)
    {
        game->cur_frame++;
	
        animate(game, game->p_ani);
		i = 0;
		while (i < game->tokens)
        	animate(game, game->tokens_ani[i++]);
        game->emote_time = 0;
    }
}

static mlx_image_t	*png_to_img(mlx_t *mlx, char *file)
{
	mlx_texture_t	*tex;
	mlx_image_t		*temp;
	
    tex = mlx_load_png(file);
	temp = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	mlx_resize_image(temp, PIXELS, PIXELS);
	return (temp);
}

t_ani	*p_animes_init(t_map *game)
{
    t_ani	*ani;

	ani = malloc(sizeof(t_ani));
	ani->ids = malloc(sizeof(int *) * 4);
    ani->animes = malloc(sizeof(mlx_image_t *) * 4);
	ft_printf("address of ani:%p\n", ani);
	ft_printf("address of ani_ids:%p\n", ani->ids);
	ft_printf("address of ani_animes:%p\n", ani->animes);
	ani->pos.y = game->p_position.y;
	ani->pos.x = game->p_position.x;
    ani->len = 4;
	ani->animes[0] = png_to_img(game->mlx, "./assets/anis/priest1_v2_1.png");
	ft_printf("address of animes[0]:%p\n", ani->animes[0]);
	ani->animes[1] = png_to_img(game->mlx, "./assets/anis/priest1_v2_2.png");
	ft_printf("address of animes[1]:%p\n", ani->animes[1]);
	ani->animes[2] = png_to_img(game->mlx, "./assets/anis/priest1_v2_3.png");
	ft_printf("address of animes[2]:%p\n", ani->animes[2]);
	ani->animes[3] = png_to_img(game->mlx, "./assets/anis/priest1_v2_4.png");
	ft_printf("address of animes[3]:%p\n", ani->animes[3]);
	if (!ani)
	{
		write(2, "Error loading anis\n", 19);
		return (NULL);
	}
	return (ani);
}
t_ani	*t_animes_init(t_map *game)
{
    t_ani	*ani;

	ani = malloc(sizeof(t_ani));
	ani->ids = malloc(sizeof(int *) * 4);
    ani->animes = malloc(sizeof(mlx_image_t *) * 4);
	ani->pos.y = game->p_position.y;
	ani->pos.x = game->p_position.x;
    ani->len = 4;
	ani->animes[0] = png_to_img(game->mlx, "./assets/anis/skull_v2_1.png");
	ani->animes[1] = png_to_img(game->mlx, "./assets/anis/skull_v2_2.png");
	ani->animes[2] = png_to_img(game->mlx, "./assets/anis/skull_v2_3.png");
	ani->animes[3] = png_to_img(game->mlx, "./assets/anis/skull_v2_4.png");
	if (!ani)
	{
		write(2, "Error loading anis\n", 19);
		return (NULL);
	}
	return (ani);
}
// t_ani	*e_animes_init(t_map *game)
// {
//     t_ani	*ani;

// 	ani = malloc(sizeof(t_ani));
// 	ani->ids = malloc(sizeof(int *) * 4);
//     ani->animes = malloc(sizeof(mlx_image_t *) * 4);
// 	ani->pos.y = game->p_position.y;
// 	ani->pos.x = game->p_position.x;
//     ani->len = 4;
// 	ani->animes[0] = png_to_img(game->mlx, "./assets/anis/priest1_v2_1.png");
// 	ani->animes[1] = png_to_img(game->mlx, "./assets/anis/priest1_v2_2.png");
// 	ani->animes[3] = png_to_img(game->mlx, "./assets/anis/priest1_v2_4.png");
// 	ani->animes[2] = png_to_img(game->mlx, "./assets/anis/priest1_v2_3.png");
// 	if (!ani)
// 	{
// 		write(2, "Error loading anis\n", 19);
// 		return (NULL);
// 	}
// 	return (ani);
// }
/*
mlx_id = mlx_img_to_window(...)

animes
image1
image2
image3

ids
2
2
2

image1[mlx_id]
image2[mlx_id]



*/
