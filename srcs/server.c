/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:37:45 by tmoragli          #+#    #+#             */
/*   Updated: 2022/02/13 14:18:57 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_content	g_data;

void	display_message_flush(void)
{
	write(1, g_data.str, ft_strlen(g_data.str));
	write(1, "\n", 1);
	free(g_data.str);
	g_data.str = NULL;
	g_data.i = 0;
	g_data.c = 0;
}

void	convert_signal(int binary)
{
	char	*tmp;

	g_data.buffer[BUFFER_SIZE] = '\0';
	g_data.c |= (binary << g_data.i++);
	if (g_data.i > 7)
	{
		if (g_data.j == BUFFER_SIZE || g_data.c == 0)
		{
			tmp = g_data.str;
			g_data.str = ft_strjoin(g_data.str, g_data.buffer);
			g_data.j = 0;
			ft_memset(g_data.buffer, 0, BUFFER_SIZE);
			free(tmp);
			if (g_data.c == 0)
			{
				display_message_flush();
				return ;
			}
		}
		g_data.buffer[g_data.j] = g_data.c;
		g_data.j++;
		g_data.i = 0;
		g_data.c = 0;
	}
}

void	sig_info(int signal, siginfo_t *s, void *trash)
{
	(void)trash;
	if (signal == SIGUSR1)
		convert_signal(0);
	if (signal == SIGUSR2)
		convert_signal(1);
	usleep(2);
	g_data.pid = s->si_pid;
	kill(g_data.pid, SIGUSR1);
}

int	hook_signals(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) == -1)
		return (0);
	if (sigaction(SIGUSR2, sa, NULL) == -1)
		return (0);
	return (1);
}

int	main(void)
{
	struct sigaction	*sa;

	if (getpid() == -1)
		return (1);
	sa = malloc(sizeof(struct sigaction));
	if (!sa)
		return (1);
	sa->sa_sigaction = sig_info;
	g_data.i = 0;
	g_data.c = 0;
	g_data.j = 0;
	g_data.str = NULL;
	ft_memset(g_data.buffer, 0, BUFFER_SIZE);
	ft_printf("PID : %d\n", getpid());
	while (hook_signals(sa))
		pause();
	free(sa);
	return (0);
}
