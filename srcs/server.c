/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:37:45 by tmoragli          #+#    #+#             */
/*   Updated: 2022/02/12 04:52:31 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_content data;

void	convert_signal(int binary)
{
	data.c |= (binary << data.i++);
	if (data.i > 7)
	{
		data.str = ft_strjoin(data.str, &data.c);
		if (data.c == '\0')
		{
			write(1, data.str, ft_strlen(data.str));
			write(1, "\n", 1);
			data.str = NULL;
		}
		data.i = 0;
		data.c = 0;
	}
}

void	handler(int signal, siginfo_t *s, void *trash)
{
	(void)trash;
	//ft_printf("signal recieved %d\n", signal);
	if (signal == SIGUSR1)
		convert_signal(0);
	if (signal == SIGUSR2)
		convert_signal(1);
	data.pid = s->si_pid;
	ft_printf("[%d]\n", data.pid);
	//kill(data.pid, SIGUSR1);
}

int	hook_signals(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, sa, NULL) == -1)
		return (1);
	return (0);
}

int	main()
{
	struct sigaction	*sa;

	if (getpid() == -1)
		return (1);
	sa = malloc(sizeof(struct sigaction));
	sa->sa_sigaction = handler;
	data.i = 0;
	data.c = 0;
	ft_printf("PID : %d\n", getpid());
	hook_signals(sa);
	while (1)
		pause();
	return (0);
}