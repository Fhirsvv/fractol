/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:40:14 by ecortes-          #+#    #+#             */
/*   Updated: 2024/10/02 12:37:52 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str[0])
		return (-1);
	while (str[i])
	{
		i++;
	}
	return (i);
}
void	ft_putstr_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}
double	scale2(double unscaledNum, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * (unscaledNum - OLD_MIN)
			/ (old_max - OLD_MIN) + new_min;
}

double atoi_double(char *s)
{
	long integer;
	double fraction;
	double pow;
	int sign;

	integer = 0;
	fraction = 0;
	sign = 1;
	pow = 1;
	while((*s >= 9 && *s <= 13) || *s == ' ')
		++s;
	while(*s == '+' || *s == '-')
		if(*s++ == '-')
			sign = -sign;
	while(*s != '.' && *s)
		integer = (integer * 10) + (*s++ - '0');
	if(*s == '.')
		++s;
	while(*s)
	{
		pow /= 10;
		fraction = fraction + (*s++ - 48) * pow;
	}
	return (sign * (integer + fraction));
}
