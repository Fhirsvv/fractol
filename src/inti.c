/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:42:12 by ecortes-          #+#    #+#             */
/*   Updated: 2024/10/04 17:27:37 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//follow the documentation:
//https://harm-smits.github.io/42docs/libs/minilibx/events.html /
static	void	events_init(t_fractol *fr)
{
	mlx_hook(fr->mlx_window, KeyPress, KeyPressMask, &key_handle, fr);
	mlx_hook(fr->mlx_window, ButtonPress, ButtonPressMask, &mouse_handle, fr);
	mlx_hook(fr->mlx_window, DestroyNotify, StructureNotifyMask,
		&close_handle, fr);
}

void	data_init(t_fractol *fr)
{
	fr->ITERATIONS = ITERATIONS_DEF;
	fr->shiftx = 0.f;
	fr->shifty = 0.f;
	fr->scale = 2.f;
	fr->prev_iterations = -1;
	fr->color_table = NULL;
	fr->is_julia = 0;
	fr->julia_img = 0;
	fr->julia_real = 0;
}

static	void	malloc_error(void)
{
	perror("Problems in malloc\n");
	exit(EXIT_FAILURE);
}

void	fr_init(t_fractol *fr, char **argv)
{
	fr->mlx_conn = mlx_init();
	if (!fr->mlx_conn)
		malloc_error();
	fr->mlx_window = mlx_new_window(fr->mlx_conn, WIDTH, HEIGHT, argv[1]);
	if (fr->mlx_window == NULL)
	{
		mlx_destroy_display(fr->mlx_conn);
		free(fr->mlx_conn);
		malloc_error();
	}
	fr->img.img_ptr = mlx_new_image(fr->mlx_conn, WIDTH, HEIGHT);
	if (fr->img.img_ptr == NULL)
	{
		mlx_destroy_window(fr->mlx_conn, fr->mlx_window);
		mlx_destroy_display(fr->mlx_conn);
		free(fr->mlx_conn);
		malloc_error();
	}
	fr->img.pixel_ptr = mlx_get_data_addr(fr->img.img_ptr, &fr->img.bitperpixel,
			&fr->img.line_len, &fr->img.endian);
	data_init(fr);
	events_init(fr);
}

void	calculate_colors(t_fractol *fr)
{
	int	i;

	i = -1;
	if (fr->prev_iterations == fr->ITERATIONS)
		return ;
	fr->prev_iterations = fr->ITERATIONS;
	if (fr->color_table)
		free(fr->color_table);
	fr->color_table = malloc(fr->ITERATIONS * sizeof(int));
	if (!fr->color_table)
		malloc_error();
	while (++i < fr->ITERATIONS)
		fr->color_table[i] = scale2(i, COLOR_PSYCHEDLIC_PURPLE, COLOR_WHITE,
				fr->ITERATIONS);
}
