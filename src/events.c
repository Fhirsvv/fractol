/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:21:28 by ecortes-          #+#    #+#             */
/*   Updated: 2024/10/02 12:34:38 by ecortes-         ###   ########.fr       */
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
		fr->shiftx -= 0.3 * fr->scale;
	else if(keycode == XK_Right)
		fr->shiftx += 0.3 * fr->scale;
	else if(keycode == XK_Up)
		fr->shifty += 0.3 * fr->scale;
	else if(keycode == XK_Down)
		fr->shifty -= 0.3 * fr->scale;

	render(fr);
	return (0);
}

int close_handle(t_fractol *fr)
{
	mlx_destroy_image(fr->mlx_conn, fr->img.img_ptr);
	mlx_destroy_window(fr->mlx_conn, fr->mlx_window);
	mlx_destroy_display(fr->mlx_conn);
	free(fr->mlx_conn);
	free(fr->color_table);
	exit(EXIT_SUCCESS);
	return (0);
}

/*zoom in-up scroll == 5
zoom out-down scroll == 4*/
int mouse_handle(int button, int x, int y, t_fractol *fr)
{
	if(button == Button5)
		fr->scale *= 1.05;
	else if(button == Button4)
		fr->scale *= 0.95;
	(void)x;
	(void)y;
	render(fr);
	return (0);
}
