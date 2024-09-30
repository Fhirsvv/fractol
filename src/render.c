/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:21:55 by ecortes-          #+#    #+#             */
/*   Updated: 2024/09/30 18:50:07 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* el offset es la posición dentro del buffer de la imagen donde está almacenado elç
 píxel en las coordenadas (x, y).
 
 Se utiliza un casting a unsigned int * para asegurarse de que se escriben 4 bytes 
 (32 bits) en la posición de memoria correspondiente al píxel,
  que es el tamaño típico para un color en formato RGB o RGBA.*/
static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bitperpixel / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

// z=z^2+c=a^2 - b^2 + c, 2 * a * b + c
static inline	t_complex ft_mandelbrot(t_complex z, t_complex c)
{
	z.real_2 = z.real * z.real;
	z.imag_2 = z.imag * z.imag;

	z.imag = 2 * z.real * z.imag + c.imag;
	z.real = z.real_2 - z.imag_2 + c.real;
	
	return (z);
}
//cambiar old_min a 0 y quitarlo de los argv
// PODEMOS CAMBIAR NEW_MAX Y NEW_MIN POR DOS DEFINE??
static inline double	scale(double unscaledNum, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * (unscaledNum - OLD_MIN)
			/ (old_max - OLD_MIN) + new_min;
}

static void handle_pixel(int x, int y, t_fractol *fr)
{
	t_complex	z;
	t_complex	c;
	int		i;

	i = 0;
	z.real = 0.0;
	z.imag = 0.0;

	c.real = scale(x, -fr->scale, fr->scale, 799) + fr->shiftx;
	c.imag = scale(y, fr->scale, -fr->scale, 799) + fr->shifty;

	while(i < fr->ITERATIONS)
	{
		z = ft_mandelbrot(z, c);

		if(z.imag_2 + z.real_2 > 4)
		{
			//color = scale(i, COLOR_PSYCHEDLIC_PURPLE, COLOR_WHITE, fr->ITERATIONS);
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
            handle_pixel(x, y, fr);
        }
    }
	mlx_put_image_to_window(fr->mlx_conn, fr->mlx_window, fr->img.img_ptr, 0, 0);
}
