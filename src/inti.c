/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:42:12 by ecortes-          #+#    #+#             */
/*   Updated: 2024/09/30 11:54:52 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//follow the documentation:
//https://harm-smits.github.io/42docs/libs/minilibx/events.html#hooking-into-events
static void events_init(t_fractol *fr)
{
    mlx_hook(fr->mlx_window, KeyPress, KeyPressMask, &key_handle, fr);
   // mlx_hook(fr->mlx_window, ButtonPress, ButtonPressMask, &mouse_handle, fr);
    mlx_hook(fr->mlx_window, DestroyNotify, StructureNotifyMask, &close_handle, fr);
}

void data_init(t_fractol *fr)
{
    fr->ITERATIONS = ITERATIONS_DEF;
    fr->shiftx = 0.f;
    fr->shifty = 0.f;
    fr->scale = 2.f;
}

static void malloc_error()
{
    perror("Problems in malloc\n");
    exit(EXIT_FAILURE);
}

void fr_init(t_fractol *fr, char **argv)
{
    //fr->title = argv[1];
    fr->mlx_conn = mlx_init();
    if(!fr->mlx_conn)
        malloc_error();
    fr->mlx_window = mlx_new_window(fr->mlx_conn, WIDTH, HEIGHT, argv[1]);
    if(fr->mlx_window == NULL)
    {
        mlx_destroy_display(fr->mlx_conn);
        free(fr->mlx_conn);
        malloc_error();
    }
    fr->img.img_ptr = mlx_new_image(fr->mlx_conn, WIDTH, HEIGHT);
    if(fr->img.img_ptr == NULL)
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
