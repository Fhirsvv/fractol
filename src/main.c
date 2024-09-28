/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:51:12 by edu               #+#    #+#             */
/*   Updated: 2024/09/28 18:54:37 by ecortes-         ###   ########.fr       */
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
		render(&fr);
		mlx_loop(fr.mlx_conn); //loop event (key, mouse,..)
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
