/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:14:11 by pokpalae          #+#    #+#             */
/*   Updated: 2024/05/29 20:26:45 by pokpalae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define MAGENTA 0xFF00FF
# define LIME 0xCCFF00
# define ORANGE 0xFF6600
# define PURPLE 0x9932CC
# define AQUA 0x33CCCC
# define PINK 0xFF66B2
# define ELECTRIC 0x0066FF
# define LIGHTENING 0x00CCFF
# define LAVA 0xFF3300
# define YELLOW 0xFFFF00
# define PASTELYELLOW 0xFFFF99
# define PASTELPINK 0xFFB6C1

typedef struct s_fractol
{
	char	*title;
	void	*mlx_connect;
	void	*window;
	void	*img;
	char	*img_addr;
	int		img_bpp;
	int		img_line;
	int		img_endian;
	double	cmplx_r;
	double	cmplx_i;
	double	hypotenuse;
	int		iterations;
	double	shift_r;
	double	shift_i;
	double	zoom;
	int		current_color;
	double	julia_r;
	double	julia_i;
}			t_fractol;

typedef struct s_map_coords
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}			t_map_coords;

void		fractol_init(t_fractol *fract);

void		render_fractol(t_fractol *fract);
int			blend_colors(int colour1, int colour2, double t);
void		shift_colors(t_fractol *fract);

int			handle_key(int keysym, t_fractol *fract);
int			handle_mouse(int button, int x, int y, t_fractol *fract);
int			clean_me(t_fractol *fract);
void		instructions(void);

double		map(t_map_coords coords);
t_fractol	sum_complex(t_fractol z1, t_fractol z2);
t_fractol	square_complex(t_fractol z);
void		print_error(void);
double		atodl(char *s);
void		zoom_in(t_fractol *fract, double mouse_r, double mouse_i);
void		zoom_out(t_fractol *fract, double mouse_r, double mouse_i);

#endif
