/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:35:39 by saazcon-          #+#    #+#             */
/*   Updated: 2023/03/08 19:57:02 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_init_xpm(struct s_data *d, char *path)
{
	void	*xpm;

	xpm = mlx_xpm_file_to_image(d->mlx, path, &d->w, &d->h);
	if (!xpm)
		ft_error(d);
	return (xpm);
}

void	ft_init_img(struct s_data *d)
{
	d->y = d->num_l * 64;
	d->x = d->num_c * 64;
	d->floor = ft_init_xpm(d, "textures/floor.xpm");
	d->wall = ft_init_xpm(d, "textures/wall.xpm");
	d->coin = ft_init_xpm(d, "textures/coin.xpm");
	d->main = ft_init_xpm(d, "textures/main.xpm");
	d->exit = ft_init_xpm(d, "textures/exit.xpm");
}

void	ft_put_img(char letter, int i, struct s_data *d)
{
	int	xx;
	int	yy;

	yy = (i / (d->num_c + 1)) * 64;
	xx = (i % (d->num_c + 1)) * 64;
	if (letter == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->wall, xx, yy);
	else if (letter == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->floor, xx, yy);
	else if (letter == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->coin, xx, yy);
	else if (letter == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->exit, xx, yy);
	else if (letter == 'P')
	{
		d->main_init = i;
		mlx_put_image_to_window(d->mlx, d->win, d->main, xx, yy);
	}
}

void	ft_init_map(struct s_data *d)
{
	int	i;

	i = 0;
	while (d->map[i])
	{
		ft_put_img(d->map[i], i, d);
		i++;
	}
}
