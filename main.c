/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kceder <kceder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:04:32 by kceder            #+#    #+#             */
/*   Updated: 2022/02/08 14:04:37 by kceder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_line_correct(char *line, int i, int ret)
{
	int	count;

	count = 0;
	if (i == 5 && ret == 0)
		return (-1);
	if (ret == 0)
		return (1);
	if (i == 4)
		return (line_correct_util(line[0], ret, i));
	else
	{
		if (line == NULL)
			return (0);
		while (line[count])
		{
			if (line[count] != '.' && line[count] != '#')
				return (0);
			count++;
		}
		if (count == 4)
			return (1);
		return (0);
	}
}

unsigned short	check_around(char **array, int i, int find)
{
	int	count;
	int	leftmost;
	int	upmost;

	count = 0;
	leftmost = 5;
	upmost = 5;
	count = check_around_loop(array, &find, &leftmost, &upmost);
	if (count >= 6 && find == 4)
	{
		if (i > 5)
			return (to_binary(array, i - 6, upmost, leftmost));
		else
			return (to_binary(array, 0, upmost, leftmost));
	}
	return (0);
}

unsigned short	array_util(unsigned short *tetriminos, int *i,
					char **array, unsigned short *tetri_count)
{
	int	temp;

	temp = *i;
	array[temp] = NULL;
	tetriminos[*tetri_count] = check_around(array, 0, 0);
	if (!(tetriminos[*tetri_count]))
		return (0);
	*tetri_count = *tetri_count + 1;
	*i = 0;
	while (*i < temp)
	{
		ft_bzero(array[*i], 5);
		free(array[*i]);
		array[*i] = NULL;
		(*i)++;
	}
	*i = 0;
	return (1);
}

unsigned short	*read_to_array(char **array, int fd, int i, int ret)
{
	char			*line;
	unsigned short	tetri_count;
	unsigned short	*tetriminos;
	int				result;

	result = 0;
	tetriminos = init_tetrimonos(27);
	line = NULL;
	tetri_count = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		result = check_line_correct(line, i, ret);
		if (result == 0 || (ret == 0 && i < 4))
			return (free_tetri_and_line(line, tetriminos, result, ret));
		if (result == -1)
			return (free_tetri_and_line(line, tetriminos, result, ret));
		if (i == 5 || ret == 0)
			if (!array_util(tetriminos, &i, array, &tetri_count))
				return (free_tetri_and_line(line, tetriminos, -1, ret));
		if (!free_func(array, line, i, ret))
			break ;
		i++;
	}
	return (tetriminos);
}

int	main(int argc, char **argv)
{
	int				fd;
	char			**array;
	unsigned short	*tetriminos;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit <source file>");
		return (0);
	}
	array = NULL;
	array = ft_new_array(array, 6);
	fd = open(argv[1], O_RDONLY);
	tetriminos = read_to_array(array, fd, 0, 1);
	if (!tetriminos)
	{
		ft_free_array(array);
		ft_putendl("error");
		return (0);
	}
	free(array);
	solve_tetrimino(tetriminos);
	return (1);
}
