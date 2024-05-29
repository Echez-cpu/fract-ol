/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:18:00 by pokpalae          #+#    #+#             */
/*   Updated: 2024/05/29 20:21:14 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	blend_colors(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - t) * ((color1 >> 16) & 0xFF) + t * ((color2 >> 16) & 0xFF)
			* 5);
	g = (int)((1 - t) * ((color1 >> 8) & 0xFF) + t * ((color2 >> 8) & 0xFF)
			* 5);
	b = (int)((1 - t) * (color1 & 0xFF) + t * (color2 & 0xFF) * 5);
	r = (int)(r + (255 - r) * t * 1.5);
	g = (int)(g + (255 - g) * t * 0.2);
	b = (int)(b + (255 - b) * t * 4);
	return ((r << 16) | (g << 8) | b);
}

void	shift_colors(t_fractol *fract)
{
	static int	colors[] = {WHITE, PASTELPINK, GREEN, BLUE, MAGENTA, LIME,
			ORANGE, PURPLE, AQUA, PINK, ELECTRIC, LIGHTENING, LAVA, YELLOW,
			PASTELYELLOW};
	static int	color_index = 0;

	;
	color_index = (color_index + 1) % (sizeof(colors) / sizeof(colors[0]));
	fract->current_color = colors[color_index];
	render_fractol(fract);
}
