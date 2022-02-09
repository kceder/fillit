/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krisu <krisu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:37:29 by pietari           #+#    #+#             */
/*   Updated: 2022/02/09 15:25:16 by krisu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_tetrimino(unsigned short *tetriminos)
{
	unsigned short	count;
	unsigned short	min_sqr;

	count = 0;
	while (tetriminos[count])
		count++;
	if (count > 26)
	{
		ft_putendl("error");
	}
	min_sqr = sqroot(count);
	solver_main(tetriminos, min_sqr, count);
}

unsigned short	counter(char **array, int i, int j)
{
	unsigned short	count;

	count = 0;
	if (i + 1 <= 3 && array[i + 1][j] == '#')
		count++;
	if (i - 1 >= 0 && array[i - 1][j] == '#')
		count++;
	if (j + 1 <= 3 && array[i][j + 1] == '#')
		count++;
	if (j - 1 >= 0 && array[i][j - 1] == '#')
		count++;
	return (count);
}

void	up_most_left_most(int i, int j, int *leftmost, int *upmost)
{
	if (j < *leftmost)
		*leftmost = j;
	if (i < *upmost)
		*upmost = i;
}

unsigned short	check_around_loop(char **array, int *find,
					int *leftmost, int *upmost)
{
	int				i;
	int				j;
	unsigned short	count;

	i = 0;
	j = 0;
	count = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '#')
			{
				up_most_left_most(i, j, leftmost, upmost);
				count += counter(array, i, j);
				*find = *find + 1;
			}
			j++;
		}
		i++;
	}
	return (count);
}

unsigned short	sqroot(unsigned short count)
{
	unsigned short	sqroot;

	count = count * 4;
	sqroot = 1;
	while (sqroot * sqroot < count)
		sqroot++;
	return (sqroot);
}
