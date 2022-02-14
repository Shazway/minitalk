/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:09:22 by tmoragli          #+#    #+#             */
/*   Updated: 2022/02/14 01:04:21 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define ERR_SIGNAL "No signal could be sent\n"
# define ERR_ARG "Wrong usage\nTry : ./client PID *message*\n"
# define ERR_PID "The PID must be a valid number\n"
# define BUFFER_SIZE 42

typedef struct s_content
{
	char				c;
	int					i;
	int					j;
	char				*str;
	char				buffer[BUFFER_SIZE + 1];
	int					pid;
	struct sigaction	*sa;
}				t_content;

#endif