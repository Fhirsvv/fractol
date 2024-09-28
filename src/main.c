/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:51:12 by edu               #+#    #+#             */
/*   Updated: 2024/09/28 16:45:41 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int main(int argc, char **argv)
{
	t_fractol fr;

	if ((argc == 2 && ft_strcmp("mandelbrot", argv[1]) == 0)
		|| (argc == 4 && ft_strcmp("julia", argv[1]) == 0))
	{
		fr_init(&fr, argv);
		fr_render(&fr);
		mlx_loop(fr.mlx_conn); //loop event (key, mouse,..)
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

// z=z^2+c=a^2 - b^2 + c, 2 * a * b + c
inline	t_complex ft_mandelbrot(t_complex z, t_complex c)
{
	double	real_2;
	double	imag_2;

	real_2 = z.real * z.real;
	imag_2 = z.imag * z.imag;

	z.imag = 2 * z.real * z.imag + c.imag; // Asegúrate de sumar c.imag aquí
	z.real = real_2 - imag_2 + c.real;

	return (z);
}