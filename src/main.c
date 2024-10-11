/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:51:12 by edu               #+#    #+#             */
/*   Updated: 2024/10/11 12:42:11 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	check_if_nb(char *str)
{
	int	i;	

	if (!str)
		return (1);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
		i++;
	if (str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'))
		return (1);
	return (0);
}

static int	is_letterstr(int argc, char **argv)
{
	if (argc == 2)
		return (0);
	else if (argc == 4)
	{
		if (check_if_nb(argv[2]) || check_if_nb (argv[3]))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fr;

	if (((argc == 2 && ft_strcmp("mandelbrot", argv[1]) == 0)
			|| (argc == 4 && ft_strcmp("julia", argv[1]) == 0))
		&& !is_letterstr(argc, argv))
	{
		fr_init(&fr, argv);
		if (ft_strcmp("julia", argv[1]) == 0)
		{
			fr.julia_real = atoi_double(argv[2]);
			fr.julia_img = atoi_double(argv[3]);
			fr.is_julia = 1;
		}
		render(&fr);
		mlx_loop(fr.mlx_conn);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/* el offset es la posición dentro del buffer de la imagen donde está
	almacenado el píxel en las coordenadas (x, y).
 
 Se utiliza un casting a unsigned int * para asegurarse de que se escriben 4 
 bytes (32 bits) en la posición de memoria correspondiente al píxel,
  que es el tamaño típico para un color en formato RGB o RGBA.*/
void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bitperpixel / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}
