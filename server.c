/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:03:43 by tnaton            #+#    #+#             */
/*   Updated: 2022/01/11 09:13:04 by tnaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_char	*g_begin = NULL;

void	putlist(void)
{
	t_char	*tmp;
	t_char	*temp;

	tmp = g_begin->first;
	while (tmp)
	{
		write(1, &tmp->c, 1);
		temp = tmp->next;
		free(tmp);
		tmp = temp;
	}
	g_begin = NULL;
	write(1, "\n", 1);
}

void	addnew(void)
{
	t_char					*new;

	new = (t_char *)malloc(sizeof(t_char));
	new->i = 7;
	new->c = 0;
	if (!g_begin)
		new->first = new;
	else
	{
		new->first = g_begin->first;
		g_begin->next = new;
	}
	new->next = NULL;
	g_begin = new;
}

void	test(int signal, siginfo_t *info, void *x)
{
	if (!g_begin || g_begin->i == -1)
		addnew();
	if (signal == SIGUSR1)
		g_begin->c |= 0 << g_begin->i;
	else
		g_begin->c |= 1 << g_begin->i;
	g_begin->i--;
	if (g_begin && g_begin->i == -1 && g_begin->c == '\0')
		putlist();
	kill(info->si_pid, SIGUSR2);
}

void	clean(void)
{
	t_char	*tmp;
	t_char	*temp;

	if (g_begin)
	{
		tmp = g_begin->first;
		while (tmp)
		{
			temp = tmp->next;
			free(tmp);
			tmp = temp;
		}
	}
	g_begin = NULL;
}

int	main(void)
{
	int					i;
	struct sigaction	s_signal;

	i = getpid();
	ft_putstr_fd("pid : ", 1);
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
	s_signal.sa_sigaction = &test;
	s_signal.sa_flags = SA_SIGINFO;
	sigemptyset(&s_signal.sa_mask);
	sigaddset(&s_signal.sa_mask, SIGUSR1);
	sigaddset(&s_signal.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &s_signal, NULL);
	sigaction(SIGUSR2, &s_signal, NULL);
	while (1)
	{
		if (!sleep(1))
		{
			clean();
			pause();
		}
	}
}
