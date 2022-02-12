/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:37:48 by tmoragli          #+#    #+#             */
/*   Updated: 2022/02/13 00:10:26 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	send_char(int pid, int binary, struct sigaction sa)
{
	sigaction(SIGUSR1, &sa, NULL);
	if (binary == 0)
		if (kill(pid, SIGUSR1) == -1)
			return (ft_printf("Error : can't send SIG1 signal\n"));
	if (binary == 1)
		if (kill(pid, SIGUSR2) == -1)
			return (ft_printf("Error : can't send SIG2 signal\n"));
	pause();
	return (0);
}

void	convert_char(int pid, char message, struct sigaction sa)
{
	char	c;
	int		binary;

	c = 0;
	while (c < 8)
	{
		binary = (message >> c++) & 1;
		usleep(300);
		send_char(pid, binary, sa);
	}
}

void	convert_array(int pid, char *str, struct sigaction sa)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		convert_char(pid, str[i], sa);
		i++;
	}
	convert_char(pid, 0, sa);
}

void	handler(int i)
{
	//ft_printf("mes %d\n", i);
	(void)i;
}

int main(int ac, char **av)
{
	struct sigaction sa;

	if (ac != 3)
		return (ft_printf("Wrong usage\nTry ./client 'PID' 'message'\n"));
	sa.sa_handler = handler;
	//ft_printf("PID : %d\n", getpid());
	convert_array(ft_atoi(av[1]), av[2], sa);
}