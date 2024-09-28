/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:42:12 by ecortes-          #+#    #+#             */
/*   Updated: 2024/09/28 16:56:59 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
}
