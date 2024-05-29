/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:06:18 by pokpalae          #+#    #+#             */
/*   Updated: 2024/05/29 14:29:30 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	instructions(void)
{
	ft_printf("\nWelcome to the fractal exploration!\nSadly, MiniLibX's ");
	ft_printf("limited capabilities result in slow rendering 😞\n");
	ft_printf("\nTo move the fractal:	Press keys: W, A, S, D or Left, ");
	ft_printf("Right, Up, Down arrows\nTo zoom in:		Scroll mouse wheel");
	ft_printf(" up\nTo zoom out:		Scroll mouse wheel down\n");
	ft_printf("To switch colours:	Press: Space bar\n");
	ft_printf("To increase iterations:	Press key: + (from the number pad)\n");
	ft_printf("To decrease iterations:	Press key: -\n");
	ft_printf("To rotate Julia:	Mouse left or right click\n");
	ft_printf("To quit:		Press key: ESC or click X on window, or ^C on ");
	ft_printf("command line\n\nTry: <./fractal julia -0.4 +0.6> or <./fra");
	ft_printf("ctol julia -0.835 -0.2321>\n\nWARNING: Attempting to resize");
	ft_printf(" or maximize the window will lose you to the black abyss!\n");
}

void	print_error(void)
{
	perror("MALLOC ERROR: ");
	exit(EXIT_FAILURE);
}

void	zoom_in(t_fractol *fract, double mouse_r, double mouse_i)
{
	double	zoom_factor;

	zoom_factor = 0.95;
	fract->shift_r += (mouse_r - fract->shift_r) * (1 - zoom_factor);
	fract->shift_i += (mouse_i - fract->shift_i) * (1 - zoom_factor);
	fract->zoom *= zoom_factor;
}

void	zoom_out(t_fractol *fract, double mouse_r, double mouse_i)
{
	double	zoom_factor;

	zoom_factor = 1.01;
	fract->shift_r += (mouse_r - fract->shift_r) * (1 - zoom_factor);
	fract->shift_i += (mouse_i - fract->shift_i) * (1 - zoom_factor);
	fract->zoom *= zoom_factor;
}
