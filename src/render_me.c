/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_me.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:43:05 by pokpalae          #+#    #+#             */
/*   Updated: 2024/05/29 20:42:14 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	fractol_set_c(t_fractol *z, t_fractol *c, t_fractol *fract)
{
	if (!ft_strncmp(fract->title, "Julia", 5))
	{
		c->cmplx_r = fract->julia_r;
		c->cmplx_i = fract->julia_i;
	}
	else
	{
		c->cmplx_r = z->cmplx_r;
		c->cmplx_i = z->cmplx_i;
	}
}

static void	ft_put_pixel(int x, int y, t_fractol *fract, int rgb)
{
	int	offset;

	offset = (y * fract->img_line + x * (fract->img_bpp / 8));
	*(unsigned int *)(fract->img_addr + offset) = rgb;
}

static void	map_to_pixel(int x, int y, t_fractol *fract)
{
	t_fractol	z;
	t_fractol	c;
	int			i;
	int			rgb;

	i = 0;
	z.cmplx_r = (map((t_map_coords){x, -2, +2, 0, WIDTH}) * fract->zoom)
		+ fract->shift_r;
	z.cmplx_i = (map((t_map_coords){y, +2, -2, 0, HEIGHT}) * fract->zoom)
		+ fract->shift_i;
	fractol_set_c(&z, &c, fract);
	while (i < fract->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.cmplx_r * z.cmplx_r) + (z.cmplx_i
				* z.cmplx_i) > fract->hypotenuse)
		{
			rgb = blend_colors(BLACK, fract->current_color, (double)i
					/ fract->iterations);
			ft_put_pixel(x, y, fract, rgb);
			return ;
		}
		i++;
	}
	ft_put_pixel(x, y, fract, BLACK);
}

void	render_fractol(t_fractol *fract)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			map_to_pixel(x, y, fract);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx_connect, fract->window, fract->img, 0,
		0);
}
