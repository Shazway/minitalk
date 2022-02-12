/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 23:55:47 by tmoragli          #+#    #+#             */
/*   Updated: 2021/08/11 18:50:51 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s(t_data *parsing, char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		parsing->count += 6;
		return ;
	}
	else
		ft_printarray(s, parsing);
}
