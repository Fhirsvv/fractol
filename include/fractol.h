#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include "libft/libft.h"
#include <math.h>
#include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Arguments must be:\n\t./fractol mandelbrot\n\t./fractol julia <real> <imaginary>\n"

#define WIDTH 800
#define HEIGHT 800
#define ITERATIONS 42


#define COLOR_BLACK         (0x000000) // Black
#define COLOR_WHITE         (0xFFFFFF) // White
#define COLOR_PSYCHEDLIC_RED        (0xFF1F1F) // Bright Red
#define COLOR_PSYCHEDLIC_GREEN      (0x1FFF1F) // Bright Green
#define COLOR_PSYCHEDLIC_BLUE       (0x1F1FFF) // Bright Blue
#define COLOR_PSYCHEDLIC_YELLOW     (0xFFFF1F) // Bright Yellow
#define COLOR_PSYCHEDLIC_CYAN       (0x1FFFFF) // Bright Cyan
#define COLOR_PSYCHEDLIC_MAGENTA    (0xFF1FFF) // Bright Magenta
#define COLOR_PSYCHEDLIC_ORANGE     (0xFF7F00) // Bright Orange
#define COLOR_PSYCHEDLIC_PURPLE     (0x7F00FF) // Bright Purple
#define COLOR_PSYCHEDLIC_PINK       (0xFF1F7F) // Bright Pink

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