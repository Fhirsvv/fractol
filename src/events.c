/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:21:28 by ecortes-          #+#    #+#             */
/*   Updated: 2024/09/29 20:56:44 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


//follow the documentation:
//https://harm-smits.github.io/42docs/libs/minilibx/events.html#hooking-into-events


//Prototype of event functions
//las teclas https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
int key_handle(int keycode, t_fractol *fr)
{
	if(keycode == XK_scape)
		close_handle(fr);
	else if(keycode == XK_minus)
		fr->ITERATIONS -= 10;
	else if(keycode == XK_plus)
		fr->ITERATIONS += 10;
	else if(keycode == XK_Left)
		fr->shiftx += 0.5;
	else if(keycode == XK_Up)
		fr->shifty -= 0.5;
	else if(keycode == XK_Right)
		fr->shifty -= 0.5;
	else if(keycode == XK_Down)
		fr->shifty += 0.5;
	
		
}