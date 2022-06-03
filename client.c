/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:38:42 by tnaton            #+#    #+#             */
/*   Updated: 2022/01/11 09:12:20 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_test(int signal)
{
	return ;
}

void	put_zero(int pid)
{
	int				i;

	i = 7;
	while (i >= 0)
	{
		usleep(15);
		kill(pid, SIGUSR1);
		signal(SIGUSR2, ft_test);
		usleep(200);
		i--;
	}
}

void	put_msg(int ac, char **av)
{
	unsigned char	test;
	int				i;
	int				j;

	i = 7;
	j = 0;
	while (av[2][j])
	{
		test = av[2][j];
		while (i >= 0)
		{
			usleep(15);
			if ((test >> i & 1) == 0)
				kill(ft_atoi(av[1]), SIGUSR1);
			else
				kill(ft_atoi(av[1]), SIGUSR2);
			signal(SIGUSR2, ft_test);
			usleep(200);
			i--;
		}
		i = 7;
		j++;
	}
	put_zero(ft_atoi(av[1]));
}

int	main(int ac, char **av)
{
	int				j;

	j = 0;
	if (ac != 3)
	{
		ft_putstr_fd("Il faut 2 parametres !\n", 2);
		return (1);
	}
	if (ft_atoi(av[1]) <= 0)
		return (ft_putstr_fd("Le PID n'est pas valide !\n", 2), 1);
	while (av[1][j])
	{
		if (!ft_isdigit(av[1][j]))
		{
			ft_putstr_fd("Le PID n'est pas valide !\n", 2);
			return (1);
		}
		j++;
	}
	put_msg(ac, av);
	return (0);
}
