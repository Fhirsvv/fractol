/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:21:55 by ecortes-          #+#    #+#             */
/*   Updated: 2024/10/04 17:04:12 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// z=z^2+c=a^2 - b^2 + c, 2 * a * b + c
static inline	t_complex ft_mandelbrot(t_complex z, t_complex c)
{
	z.real_2 = z.real * z.real;
	z.imag_2 = z.imag * z.imag;

	z.imag = 2 * z.real * z.imag + c.imag;
	z.real = z.real_2 - z.imag_2 + c.real;
	
	return (z);
}
//old min siempre es 0
static inline double	scale(double unscaledNum, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * (unscaledNum - OLD_MIN)
			/ (old_max - OLD_MIN) + new_min;
}

static void handle_pixel_julia(int x, int y, t_fractol *fr)
{
	int			i;
	t_complex	z;
	t_complex	c;
	
	c.imag = fr->julia_img;
	c.real = fr->julia_real;
	z.real = scale(x, -fr->scale, fr->scale, 799) + fr->shiftx;
	z.imag = scale(y, fr->scale, -fr->scale, 799) + fr->shifty;
	i = 0;
	while(i < fr->ITERATIONS)
	{
		z = ft_mandelbrot(z, c);
		if(z.imag_2 + z.real_2 > 4)
		{
			my_pixel_put(x, y, &fr->img, fr->color_table[i]);
			return;
		}
		++i;
	}
	my_pixel_put(x, y, &fr->img, COLOR_BLACK);
}

	//z.real = scale(x, -fr->scale, fr->scale, 799) + fr->shiftx;
	//z.imag = scale(y, fr->scale, -fr->scale, 799) + fr->shifty;

	//c.real = (fr->julia_real * (fr->is_julia)) + (z.real * !(fr->is_julia));
    //c.imag = (fr->julia_img * (fr->julia_real)) + (z.imag * !(fr->is_julia));
static void handle_pixel_mandelbrot(int x, int y, t_fractol *fr)
{
	t_complex	z;
	t_complex	c;
	int		i;

	i = 0;
	c.real = scale(x, -fr->scale, fr->scale, 799) + fr->shiftx;
	c.imag = scale(y, fr->scale, -fr->scale, 799) + fr->shifty;
	z.real = 0;
	z.imag = 0;
	while(i < fr->ITERATIONS)
	{
		z = ft_mandelbrot(z, c);

		if(z.imag_2 + z.real_2 > 4)
		{
			my_pixel_put(x, y, &fr->img, fr->color_table[i]);
			return;
		}
		++i;
	}
	my_pixel_put(x, y, &fr->img, COLOR_BLACK);
}

void render(t_fractol *fr)
{
    int	x;
    int	y;

    y = -1;
	calculate_colors(fr);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if(fr->is_julia == 0)
				handle_pixel_mandelbrot(x, y, fr);
			else
				handle_pixel_julia(x, y, fr);
		}
	}
	mlx_put_image_to_window(fr->mlx_conn, fr->mlx_window, fr->img.img_ptr, 0, 0);
}
