/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:21:28 by ecortes-          #+#    #+#             */
/*   Updated: 2024/09/30 10:23:06 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


//follow the documentation:
//https://harm-smits.github.io/42docs/libs/minilibx/events.html#hooking-into-events


//Prototype of event functions
//las teclas https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
int key_handle(int keycode, t_fractol *fr)
{
	if(keycode == XK_Escape)
		close_handle(fr);
	else if(keycode == XK_minus)
	{
		if(fr->ITERATIONS > 10)
			fr->ITERATIONS -= 10;
	}
	else if(keycode == XK_plus)
		fr->ITERATIONS += 10;
	else if(keycode == XK_Left)
		fr->shiftx -= 0.5;
	else if(keycode == XK_Right)
		fr->shiftx += 0.5;
	else if(keycode == XK_Up)
		fr->shifty += 0.5;
	else if(keycode == XK_Down)
		fr->shifty -= 0.5;
	render(fr);
	return (0);
}

int close_handle(t_fractol *fr)
{
	mlx_destroy_image(fr->mlx_conn, fr->img.img_ptr);
	mlx_destroy_window(fr->mlx_conn, fr->mlx_window);
	mlx_destroy_display(fr->mlx_conn);
	free(fr->mlx_conn);
	exit(EXIT_SUCCESS);
	return (0);
}