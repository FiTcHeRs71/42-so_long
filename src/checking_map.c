/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:57:48 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/19 09:57:48 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(t_mlx *mlx, char **args)
{
	size_t	i;
	int		size;

	i = 0;
	mlx->len = ft_strlen(args[0]);
	while (args[i])
	{
		check_arg(args[i], mlx);
		size = ft_strlen(args[i]);
		if (mlx->len != size)
		{
			ft_error("The map must be rectangular.\n", mlx);
		}
		i++;
	}
	check_flag(mlx);
	valide_path(mlx);
}

void	check_arg(char *line, t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isascii(line[i]))
		{
			ft_error("only ascii parameters.\n", mlx);
		}
		if (!ft_strchr("10EPC", line[i]))
		{
			ft_error("Missing parameters.\n", mlx);
		}
		if(ft_strncmp(line, "\n\n", ft_strlen(line)))
		{
			ft_error("Empty line in the map.\n", mlx);
		}
		ft_count_and_check_args(line[i], mlx);
		i++;
	}
}

void	ft_count_and_check_args(char c, t_mlx *mlx) // struct
{
	if (c == 'P')
	{
		mlx->flag_p += 1;
	}
	if (c == 'E')
	{
		mlx->flag_e += 1;
	}
	if (c == 'C')
	{
		mlx->flag_c += 1;
	}
}

void	check_flag(t_mlx *mlx)
{
	if (mlx->flag_c == 0)
	{
		ft_error("Need at least one food item.\n", mlx);
	}
	if (mlx->flag_e != 1)
	{
		ft_error("Need only one exit.\n", mlx);
	}
	if (mlx->flag_p != 1)
	{
		ft_error("Need only one player.\n", mlx);
	}
}
