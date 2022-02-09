/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kceder <kceder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:03:36 by kceder            #+#    #+#             */
/*   Updated: 2022/02/08 14:03:40 by kceder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	find_temp_counter(unsigned short *arr)
{
	unsigned short	i;
	unsigned short	value;
	unsigned short	counter;
	unsigned short	tmp;

	value = arr[0] | arr[1] | arr[2] | arr[3];
	i = 15;
	counter = 0;
	while (i > 0)
	{
		tmp = 1 << i;
		if (tmp & value)
			return (counter);
		counter++;
		i--;
	}
	return (0);
}

int	tetrimino_mover_recursion(unsigned short **arr,
								unsigned short *grid,
									unsigned short minimum_sqr,
										unsigned short start)
{
	static unsigned short	i;

	if (find_tetri_place(arr[i], grid, &start, minimum_sqr) == -1)
		return (0);
	else
	{
		add_to_grid(arr[i], grid, start, find_temp_counter(arr[i]));
		if (arr[i + 1] == NULL)
		{
			output(minimum_sqr, arr);
			return (1);
		}
		i++;
		if (!tetrimino_mover_recursion(arr, grid, minimum_sqr, 0))
		{
			i--;
			remove_from_grid(grid, arr[i], start);
			move_by_one(arr[i], -1);
			if (!check_addable_to_sqr(minimum_sqr, arr[i], &start))
				return (0);
			return (tetrimino_mover_recursion(arr, grid, minimum_sqr, start));
		}
		return (1);
	}
}

void	get_width(unsigned short *arr)
{
	unsigned short	i;
	unsigned short	value;
	unsigned short	counter;
	unsigned short	tmp;

	value = arr[0] | arr[1] | arr[2] | arr[3];
	i = 15;
	counter = 0;
	while (i > 0)
	{
		tmp = 1 << i;
		if (tmp & value)
			counter++;
		i--;
	}
	arr[5] = counter;
}

int	grid_maker(unsigned short *tetriminos, unsigned short minimum_sqr,
				unsigned short arr_len)
{
	unsigned short	grid[16];
	unsigned short	**arr;
	int				i;

	i = 0;
	while (i <= 16)
	{
		grid[i] = 0;
		i++;
	}
	arr = tetri_to_array(tetriminos, arr_len);
	if (!tetrimino_mover_recursion(arr, grid, minimum_sqr, 0))
	{
		ft_free_array((char **)arr);
		return (0);
	}
	ft_free_array((char **)arr);
	free(tetriminos);
	return (1);
}

int	solver_main(unsigned short *tetriminos, unsigned short minimum_sqr,
	unsigned short count)
{
	minimum_sqr = shortcuts(tetriminos, minimum_sqr, count);
	while (!grid_maker(tetriminos, minimum_sqr, count))
		minimum_sqr++;
	return (1);
}
