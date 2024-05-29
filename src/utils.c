/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:26:28 by pokpalae          #+#    #+#             */
/*   Updated: 2024/05/29 14:56:32 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	atodl(char *str)
{
	long	int_part;
	double	fractional;
	double	power;
	int		sign;

	int_part = 0;
	fractional = 0;
	sign = 1;
	power = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str && (*str >= '0' && *str <= '9'))
		int_part = (int_part * 10) + (*str++ - '0');
	if (*str == '.')
		++str;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		power /= 10;
		fractional = fractional + (*str++ - '0') * power;
	}
	return ((int_part + fractional) * sign);
}

double	map(t_map_coords coords)
{
	return ((coords.new_max - coords.new_min) * (coords.unscaled_num
			- coords.old_min) / (coords.old_max - coords.old_min)
		+ coords.new_min);
}

t_fractol	square_complex(t_fractol z)
{
	t_fractol	result;

	result.cmplx_r = (z.cmplx_r * z.cmplx_r) - (z.cmplx_i * z.cmplx_i);
	result.cmplx_i = 2 * z.cmplx_r * z.cmplx_i;
	return (result);
}

t_fractol	sum_complex(t_fractol z1, t_fractol z2)
{
	t_fractol	result;

	result.cmplx_r = z1.cmplx_r + z2.cmplx_r;
	result.cmplx_i = z1.cmplx_i + z2.cmplx_i;
	return (result);
}
