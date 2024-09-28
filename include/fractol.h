#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include "libft/libft.h"
#include <math.h>
#include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Arguments must be:\n\t./fractol mandelbrot\n\t./fractol julia <real> <imaginary>\n"
#define WIDTH 800
#define HEIGHT 800

typedef struct s_complex
{
	double real;
	double imag;
} t_complex;

typedef struct s_img
{
	void *img_ptr;
	char *pixel_ptr;
	int bitperpixel;
	int endian;
	int line_len;

}	t_img;

typedef struct s_fractol
{
	void *mlx_conn;
	void *mlx_window;
	t_img img;

	//char *title;

}	t_fractol;

void fr_init(t_fractol *fr, char **argv);

#endif