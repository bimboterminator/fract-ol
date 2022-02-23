/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:50:14 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/23 15:17:46 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void	print_help(void);
static int parse_args(int argc, char **argv, int *width, int *height);
static int get_arg(char *str);
static t_fract*	init_fractol(int type, int width, int height);

int	main(int argc, char **argv)
{
	t_fract	*fractol;
	int		width;
	int		height;
	int		type;

	width = 0;
	height = 0;
	type = -1;
	if (argc == 1)
		print_help();
	else
		type = parse_args(argc, argv, &width, &height);
	fractol = init_fractol(type, width, height);
	if (!fractol)
		return (1);
	draw_fractol(fractol);
	mlx_loop(fractol->win->mlx);
	return (0);
}

static t_fract	*init_fractol(int type, int width, int height)
{
	t_fract	*fractol;

	fractol = init(width, height);
	if (!fractol)
		return (NULL);
	fractol->type = type;
	mlx_hook(fractol->win->win, 2, 0, key_pressed, fractol);
	mlx_hook(fractol->win->win, 17, 0, close_win, fractol);
	mlx_hook(fractol->win->win, 4, 0, zoom, fractol);
	mlx_hook(fractol->win->win, 5, 0, zoom, fractol);
	return (fractol);
}

static void	print_help(void)
{
	ft_putstr_fd("Fract'ol's Usage:\n\t./fractol [options & args] frac_name\n\n", 1);
	ft_putstr_fd("Frac_names: \n", 1);
	ft_putstr_fd("Julia\n",1);
	ft_putstr_fd("Mandelbrot\n\n", 1);
	ft_putstr_fd("Options:\n", 1);
	ft_putstr_fd("[-w int] -- Initial window width (default 640)\n", 1);
	ft_putstr_fd("[-h int] -- Initial window height (default 480)\n", 1);
	exit(0);
}

static int	parse_args(int argc, char **argv, int *width, int *height)
{
	int	type;
	int	i;

	i = 1;
	type = -1;
	if (!ft_strncmp(argv[argc - 1], "Julia", 6))
		type = JULIA;
	else if(!ft_strncmp(argv[argc - 1], "Mandelbrot", 11))
		type = MANDELBROT;
	else
		print_help();
	while (i < argc - 1)
	{
		if (*width && *height)
			print_help();
		if (ft_strncmp(argv[i], "-w", 3) && ft_strncmp(argv[i], "-h", 3))
			print_help();
		else if (!ft_strncmp(argv[i], "-w", 3) && i + 1 != argc - 1)
			*width = get_arg(argv[++i]);
		else if (!ft_strncmp(argv[i], "-h", 3) && i + 1 != argc -1)
			*height = get_arg(argv[++i]);
		i++;
	}
	return (type);
}

static int	get_arg(char *str)
{
	int	i;
	int	val;
	
	i = 0;
	val = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		val = ft_atoi(str);
	if (str[i] != '\0' || val <= 0)
	{
		ft_putstr_fd("Invalid arg: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		print_help();
	}
	return (val);
}