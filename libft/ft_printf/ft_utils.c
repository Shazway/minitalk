/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:31:41 by tmoragli          #+#    #+#             */
/*   Updated: 2021/08/12 15:04:43 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(char c, t_data *parsing)
{	
	write(1, &c, 1);
	parsing->count++;
}

void	ft_printarray(char *str, t_data *parsing)
{
	while (str && *str)
	{
		write(1, str, 1);
		str++;
		parsing->count++;
	}
}
