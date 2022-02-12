/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:37:45 by tmoragli          #+#    #+#             */
/*   Updated: 2022/02/13 00:07:43 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_content data;

void	convert_signal(int binary)
{
	char	*tmp;

	data.buffer[BUFFER_SIZE] = '\0';
	data.c |= (binary << data.i++);
	if (data.i > 7)
	{
		//ft_printf("%c\n", data.c);
		if (data.j == BUFFER_SIZE || data.c == 0)
		{
			//ft_printf("je suis ici %s\n", data.buffer);
			tmp = data.str;
			data.str = ft_strjoin(data.str, data.buffer);
			data.j = 0;
			ft_memset(data.buffer, 0, BUFFER_SIZE);
			free(tmp);
			if (data.c == 0)
			{

				write(1, data.str, ft_strlen(data.str));
				write(1, "\n", 1);
				free(data.str);
				data.str = NULL;
				data.i = 0;
				data.c = 0;
				return ;
			}
		}
		data.buffer[data.j] = data.c;
		data.j++;
		data.i = 0;
		data.c = 0;
	}
}

void	sig_info(int signal, siginfo_t *s, void *trash)
{
	(void)trash;
	usleep(150);
	if (signal == SIGUSR1)
		convert_signal(0);
	if (signal == SIGUSR2)
		convert_signal(1);
	data.pid = s->si_pid;
	kill(data.pid, SIGUSR1);
	//ft_printf("[%d]\n", data.pid);
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
	sa->sa_sigaction = sig_info;
	data.i = 0;
	data.c = 0;
	data.j = 0;
	data.str = NULL;
	ft_memset(data.buffer, 0, BUFFER_SIZE);
	ft_printf("PID : %d\n", getpid());
	while (1)
	{
		hook_signals(sa);
		pause();
	}
	free(sa);
	return (0);
}