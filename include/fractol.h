#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <math.h>
# include <limits.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"

#define ERROR_MESSAGE "Arguments must be:\n\t./fractol mandelbrot\n\t./fractol julia <real> <imaginary>\n"

#define WIDTH 800
#define HEIGHT 800
#define ITERATIONS_DEF 32

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
#define COLOR_GOLD  				(0xFFD700)

#define OLD_MIN 0


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

	size_t ITERATIONS;
	double shiftx;
	double shifty;
	double scale;

	//char *title;

}	t_fractol;

//---INTI---
void fr_init(t_fractol *fr, char **argv);

//---RENDER---
void render(t_fractol *fr);

//---UTILS---
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
int	ft_strcmp(char *s1, char *s2);

//---EVENTS---
int key_handle(int keycode, t_fractol *fr);
int close_handle(t_fractol *fr);

#endif