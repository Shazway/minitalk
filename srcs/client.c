/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:37:48 by tmoragli          #+#    #+#             */
/*   Updated: 2022/02/14 02:31:10 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

struct sigaction	g_sa;

int	send_char(int pid, int binary)
{
	if (binary == 0)
		if (kill(pid, SIGUSR1) == -1)
			return (ft_printf("Error : can't send SIG1 signal\n"));
	if (binary == 1)
		if (kill(pid, SIGUSR2) == -1)
			return (ft_printf("Error : can't send SIG2 signal\n"));
	pause();
	return (0);
}

int	convert_char(int pid, char message)
{
	char	c;
	int		binary;

	c = 0;
	while (c < 8)
	{
		binary = (message >> c++) & 1;
		if (send_char(pid, binary))
			return (1);
	}
	return (0);
}

int	convert_array(int pid, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (convert_char(pid, str[i]))
			return (1);
		i++;
	}
	if (convert_char(pid, '\0'))
		return (1);
	return (0);
}

void	handler(int i)
{
	sigaction(SIGUSR1, &g_sa, NULL);
	usleep(1);
	(void)i;
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (ft_printf("Wrong usage\nTry ./client 'PID' 'message'\n"));
	g_sa.sa_handler = handler;
	sigaction(SIGUSR1, &g_sa, NULL);
	if (convert_array(ft_atoi(av[1]), av[2]))
		return (1);
	return (0);
}
