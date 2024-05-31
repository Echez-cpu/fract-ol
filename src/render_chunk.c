/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:47 by pokpalae          #+#    #+#             */
/*   Updated: 2024/05/31 12:15:42 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	render_fractol_chunk(t_fractol *fract)
{
	int	y;
	int	x;

	y = fract->chunk_y;
	while (y < fract->chunk_y + CHUNK_SIZE && y < HEIGHT)
	{
		x = fract->chunk_x;
		while (x < fract->chunk_x + CHUNK_SIZE && x < WIDTH)
		{
			map_to_pixel(x, y, fract);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx_connect, fract->window, fract->img, 0,
		0);
	fract->chunk_x += CHUNK_SIZE;
	if (fract->chunk_x >= WIDTH)
	{
		fract->chunk_x = 0;
		fract->chunk_y += CHUNK_SIZE;
	}
}

int	render_loop(t_fractol *fract)
{
	if (fract->chunk_y < HEIGHT)
	{
		render_fractol_chunk(fract);
	}
	return (0);
}

void	start_rendering(t_fractol *fract)
{
	fract->chunk_x = 0;
	fract->chunk_y = 0;
	mlx_loop_hook(fract->mlx_connect, render_loop, fract);
}

void	render_fractol(t_fractol *fract)
{
	start_rendering(fract);
}
