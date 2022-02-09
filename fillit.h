/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kceder <kceder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:51:22 by kceder            #+#    #+#             */
/*   Updated: 2022/02/07 17:51:27 by kceder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

unsigned short	find_temp_counter(unsigned short *arr);
void			move_by_one(unsigned short *ptr, int flag);
void			remove_from_grid(unsigned short *ptr, unsigned short *arr,
					unsigned short start);
void			add_to_grid(unsigned short *tetrimino, unsigned short *grid,
					unsigned short start, unsigned short counter);
int				find_tetri_place(unsigned short *arr, unsigned short *grid,
					unsigned short *start, unsigned short min_sqr);
int				within_borders(unsigned short *counter, unsigned short min_sqr,
					unsigned short *arr, unsigned short *start);
void			get_height(unsigned short *arr);
void			array_info(unsigned short **arr);
unsigned short	**tetri_to_array(unsigned short *tetriminos, int arr_len);
void			rowify_tetrimino(int arr_len, unsigned short **arr,
					unsigned short *tetriminos);
int				check_addable_to_sqr(unsigned short minimum_sqr,
					unsigned short *arr,
					unsigned short *start);
int				tetrimino_mover_recursion(unsigned short **arr,
					unsigned short *grid,
					unsigned short minimum_sqr,
					unsigned short start);
void			get_width(unsigned short *arr);
int				grid_maker(unsigned short *tetriminos,
					unsigned short minimum_sqr,
					unsigned short arr_len);
int				solver_main(unsigned short *tetrArr, unsigned short minimum_sqr,
					unsigned short count);
int				output(unsigned short sqrsize, unsigned short **tetriminos);
void			make_grid(unsigned short **tetriminos, unsigned short sqrsize,
					int tetri_count, unsigned short i);
void			print_result(char **grid, unsigned short sqrsize);
void			fill_grid(char **grid, unsigned short *tetrimino);
void			solve_tetrimino(unsigned short *tetriminos);
void			up_most_left_most(int i, int j, int *leftmost, int *upmost);
unsigned short	counter(char **array, int i, int j);
unsigned short	check_around(char **array, int i, int find);
unsigned short	check_around_loop(char **array, int *find,
					int *leftmost, int *upmost);
unsigned short	sqroot(unsigned short count);
int				to_binary(char **array, int i, int uppermost, int leftmost);
unsigned short	shortcuts(const unsigned short *tetriminos,
					unsigned short sqrsize, const unsigned short tetri_count);
int				get_next_line(const int fd, char **line);
int				free_func(char **array, char *line, int i, int ret);
int				line_correct_util(char ch, int ret, int i);
unsigned short	*free_tetri_and_line(char *line, unsigned short *tetriminos,
					int res, int ret);
unsigned short	*init_tetrimonos(int count);

#endif