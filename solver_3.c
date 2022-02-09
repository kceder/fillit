/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kceder <kceder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:03:53 by kceder            #+#    #+#             */
/*   Updated: 2022/02/08 14:03:58 by kceder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_by_one(unsigned short *ptr, int flag)
{
	unsigned short	i;

	i = 0;
	if (flag == 0)
		return ;
	if (flag == -1)
	{
		while (i < 4)
		{
			ptr[i] = ptr[i] >> 1;
			i++;
		}
	}
	else
	{
		while (i < 4)
		{
			ptr[i] = ptr[i] << flag;
			i++;
		}
	}
}

void	remove_from_grid(unsigned short *ptr, unsigned short *arr,
							unsigned short start)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ptr[start + i] = ptr[start + i] ^ arr[i];
		i++;
	}
}

void	add_to_grid(unsigned short *tetrimino, unsigned short *grid,
						unsigned short start, unsigned short counter)
{
	unsigned short	i;

	i = 0;
	while (i < 4)
	{
		grid[start + i] = grid[start + i] | tetrimino[i];
		tetrimino[8] = counter;
		tetrimino[7] = start;
		i++;
	}
}

int	find_tetri_place(unsigned short *arr, unsigned short *grid,
						unsigned short *start, unsigned short min_sqr)
{
	unsigned short	counter;

	counter = find_temp_counter(arr);
	while (1)
	{	
		if (within_borders(&counter, min_sqr, arr, start) == -1)
			return (-1);
		if (((grid[*start] | arr[0]) == (grid[*start] ^ arr[0]))
			&& ((grid[*start + 1] | arr[1]) == (grid[*start + 1] ^ arr[1]))
			&& ((grid[*start + 2] | arr[2]) == (grid[*start + 2] ^ arr[2]))
			&& ((grid[*start + 3] | arr[3]) == (grid[*start + 3] ^ arr[3])))
			return (1);
		else
		{
			move_by_one(arr, -1);
			counter = counter + 1;
		}
	}
}

int	within_borders(unsigned short *counter, unsigned short min_sqr,
					unsigned short *arr, unsigned short *start)
{
	if ((*counter + arr[5]) > min_sqr)
	{
		move_by_one(arr, *counter);
		*start = *start + 1;
		*counter = 0;
		if ((*start + arr[4]) > min_sqr)
		{
			move_by_one(arr, *counter);
			*start = 0;
			return (-1);
		}
	}
	if ((*start + arr[4]) > min_sqr)
	{
		move_by_one(arr, *counter);
		*start = 0;
		return (-1);
	}
	return (0);
}
