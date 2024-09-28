/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:21:55 by ecortes-          #+#    #+#             */
/*   Updated: 2024/09/28 18:16:27 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bitperpixel / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

inline double ft_abs(double n)
{
	return (n * (-1.f * (n < 0)) + (n * (n >= 0)));
}
// z=z^2+c=a^2 - b^2 + c, 2 * a * b + c
inline	t_complex ft_mandelbrot(t_complex z, t_complex c)
{
	double	real_2;
	double	imag_2;

	real_2 = z.real * z.real;
	imag_2 = z.imag * z.imag;

	z.imag = 2 * z.real * z.imag + c.imag;
	z.real = real_2 - imag_2 + c.real;

	return (z);
}
//cambiar old_min a 0 y quitarlo de los argv
// PODEMOS CAMBIAR NEW_MAX Y NEW_MIN POR DOS DEFINE??
inline double scale(double unscaledNum, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaledNum - old_min)
            / (old_max - old_min) + new_min;
}

void handle_pixel(int x, int y, t_fractol *fr)
{
	t_complex z;
	t_complex c;
	int i;
	int color;

	i = -1;
	z.real = 0.0;
	z.imag = 0.0;

	c.real = scale(x, -2, +2, 0, 799);
	c.imag = scale(y, +2, -2, 0, 799);

	while(++i)
	{
		z = ft_mandelbrot(z, c);

		if((ft_abs(z.imag) >= 2.f || ft_abs(z.real) >= 2.f) || i < ITERATIONS)
		{
			color = scale(i, COLOR_BLACK, COLOR_WHITE, 0, ITERATIONS);
			ft_pixel_put(x, y, &fr->img, color);
			return;
		}
	}
}
void render(t_fractol *fr)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handle_pixel(x, y, fr);
        }
    }
}
