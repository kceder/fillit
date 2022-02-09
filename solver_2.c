/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kceder <kceder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:04:06 by kceder            #+#    #+#             */
/*   Updated: 2022/02/08 14:04:09 by kceder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_height(unsigned short *arr)
{
	unsigned short	height;
	unsigned short	z;
	int				x;
	int				j;

	height = 0;
	j = 0;
	z = 0;
	x = 32768;
	while (j < 4)
	{
		z = 0;
		while (z < 15)
		{
			if (arr[j] & (x >> z))
			{
				height++;
				break ;
			}
			z++;
		}
		j++;
	}
	arr[4] = height;
}

void	array_info(unsigned short **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		get_height(arr[i]);
		get_width(arr[i]);
		arr[i][6] = 'A' + i;
		i++;
	}
}

unsigned short	**tetri_to_array(unsigned short *tetriminos, int arr_len)
{
	unsigned short	**arr;
	int				i;

	i = 0;
	arr = (unsigned short **)malloc(sizeof(unsigned short *) * (arr_len + 1));
	if (!arr)
		return (0);
	arr[arr_len] = NULL;
	while (i < arr_len)
	{
		arr[i] = (unsigned short *)malloc(sizeof(unsigned short) * 10);
		if (!arr[i])
		{
			ft_free_array((char **)arr);
			return (0);
		}
		i++;
	}
	rowify_tetrimino(arr_len, arr, tetriminos);
	array_info(arr);
	return (arr);
}

void	rowify_tetrimino(int arr_len, unsigned short **arr,
		unsigned short *tetriminos)
{
	int				i;
	int				j;
	unsigned short	tmp;

	i = 0;
	while (i < arr_len)
	{
		j = 0;
		while (j < 4)
		{
			tmp = tetriminos[i] >> (12 - (j * 4));
			tmp = tmp << (12 - (j * 4));
			tmp = tmp << (j * 4);
			tmp = tmp >> (j * 4);
			tmp = tmp << (j * 4);
			arr[i][j] = tmp;
			arr[i][9] = tetriminos[i];
			j++;
		}
		i++;
	}
}

int	check_addable_to_sqr(unsigned short minimum_sqr, unsigned short *arr,
							unsigned short *start)
{
	unsigned short	temporary_counter;

	temporary_counter = find_temp_counter(arr);
	if ((arr[5] + temporary_counter) > minimum_sqr)
	{
		move_by_one(arr, temporary_counter);
		*start = *start + 1;
		temporary_counter = 0;
		if ((*start + arr[4]) > minimum_sqr)
		{
			move_by_one(arr, temporary_counter);
			*start = 0;
			return (0);
		}
		return (1);
	}
	else if ((*start + arr[4]) > minimum_sqr)
	{
		move_by_one(arr, temporary_counter);
		*start = 0;
		return (0);
	}
	else
		return (-1);
}
