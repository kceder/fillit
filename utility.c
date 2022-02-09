/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kceder <kceder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:59:50 by pietari           #+#    #+#             */
/*   Updated: 2022/02/07 17:48:21 by kceder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	to_binary(char **array, int i, int uppermost, int leftmost)
{
	int	tetrimino;
	int	shift;
	int	j;

	tetrimino = 0;
	shift = 15;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i + uppermost > 3 || j + leftmost > 3)
			{
				shift--;
				j++;
				continue ;
			}
			else if (array[uppermost + i][leftmost + j] == '#')
				tetrimino = tetrimino | (1 << shift);
			shift--;
			j++;
		}
		i++;
	}
	return (tetrimino);
}

unsigned short	shortcuts(const unsigned short *tetriminos,
	unsigned short sqrsize, const unsigned short tetri_count)
{
	unsigned short		i;
	int					flag1;
	int					flag2;
	int					flag3;

	i = 0;
	flag1 = 0;
	flag2 = 0;
	flag3 = 0;
	while (i < tetri_count)
	{
		if (tetriminos[i] == 61440)
			flag1 = 1;
		if (tetriminos[i] == 34952)
			flag2 = 1;
		if (tetriminos[i] == 52224)
			flag3 = 1;
		i++;
	}
	if (tetri_count == 1 && flag3 == 1)
		return (2);
	if (sqrsize <= 4 && (!flag1 || !flag2))
		return (3 + flag1 + flag2);
	else
		return (sqrsize);
}

int	free_func(char **array, char *line, int i, int ret)
{
	if (ret == 0)
		return (0);
	array[i] = ft_strnew(5);
	ft_strcpy(array[i], line);
	free(line);
	return (1);
}

unsigned short	*free_tetri_and_line(char *line, unsigned short *tetriminos,
					int res, int ret)
{
	if (ret == 0)
	{
		free(tetriminos);
		return (NULL);
	}
	if (res == -1)
	{
		free(line);
		free(tetriminos);
		return (NULL);
	}
	else
	{
		free(tetriminos);
		free(line);
		return (NULL);
	}
}

int	line_correct_util(char ch, int ret, int i)
{
	if (ch == '\0')
		return (1);
	if (ret == 0 && i == 4)
		return (1);
	return (0);
}
