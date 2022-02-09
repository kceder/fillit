/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kceder <kceder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:04:21 by kceder            #+#    #+#             */
/*   Updated: 2022/02/08 14:04:25 by kceder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_grid(char **grid, unsigned short *tetrimino)
{
	unsigned short	andgate;
	unsigned short	z;
	unsigned short	x;
	unsigned short	row;

	row = 0;
	z = 0;
	x = 32768;
	andgate = 0;
	while (z <= 15)
	{
		if (z % 4 == 0 && z != 0)
			row++;
		andgate = tetrimino[9] & (x >> z);
		if (andgate > 0)
			grid[tetrimino[7] + row][tetrimino[8] + z - row * 4] = tetrimino[6];
		z++;
	}
}

void	print_result(char **grid, unsigned short sqrsize)
{
	unsigned short	i;

	i = 0;
	while (i < sqrsize)
	{
		ft_putendl(grid[i]);
		i++;
	}
}

void	make_grid(unsigned short **tetriminos, unsigned short sqrsize,
				int tetri_count, unsigned short i)
{
	char			**grid;

	grid = (char **)malloc(sizeof(char *) * (sqrsize + 1));
	grid[sqrsize] = NULL;
	if (!grid)
		return ;
	while (i < sqrsize)
	{
		grid[i] = ft_strnew(sqrsize);
		if (!grid[i])
		{
			ft_free_array(grid);
			return ;
		}
		ft_memset(grid[i], '.', sqrsize);
		i++;
	}
	i = 0;
	while (i < tetri_count)
	{
		fill_grid(grid, tetriminos[i]);
		i++;
	}
	print_result(grid, sqrsize);
	ft_free_array(grid);
}

int	output(unsigned short sqrsize, unsigned short **tetriminos)
{
	int	i;
	int	tetri_count;

	i = 0;
	tetri_count = 0;
	while (tetriminos[i])
	{
		tetri_count++;
		i++;
	}
	i = 0;
	make_grid(tetriminos, sqrsize, tetri_count, 0);
	return (1);
}

unsigned short	*init_tetrimonos(int count)
{
	unsigned short	*tetriminos;
	int				i;

	tetriminos = (unsigned short *)malloc(sizeof(unsigned short) * count);
	if (!tetriminos)
		return (0);
	i = 0;
	while (i < count)
	{
		tetriminos[i] = 0;
		i++;
	}
	return (tetriminos);
}
