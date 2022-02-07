/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:38:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/02/07 15:15:12 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	error(char *str)
{
	ft_putendl_fd(str, (int)stderr);
	ft_putendl_fd(str, 2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_tetri		list[MAX_TETRI + 1];
	uint16_t	map[16];
	int			number_of_piece;
	int			size;

	ft_bzero(list, sizeof(t_tetri) * (MAX_TETRI + 1));
	if (argc != 2)
		return (error("usage: fillit input_file"));
	number_of_piece = read_tetri(open(argv[1], O_RDONLY), list);
	if (number_of_piece < 0)
		return (error("error"));
	size = solve(list, number_of_piece, map);
	if (size == 0)
		return (error("error"));
	print_result(list, size);
	return (0);
}
