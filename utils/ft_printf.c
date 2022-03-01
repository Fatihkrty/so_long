/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:39:28 by fkaratay          #+#    #+#             */
/*   Updated: 2022/02/22 19:01:00 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	ft_str(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (*str)
		write(1, str++, 1);
}

void	ft_convertbase(long number, int base)
{
	if (number < 0)
	{
		number = -number;
		write(1, "-", 1);
	}
	if (number >= base)
		ft_convertbase(number / base, base);
	write(1, &"0123456789"[number % base], 1);
}

void	scdiu_control(va_list ap, const char **str)
{
	if (**str == '%' && *(*str + 1) == 's')
	{
		ft_str(va_arg(ap, char *));
		(*str) += 2;
	}
	else if (**str == '%' && *(*str + 1) == 'd')
	{
		ft_convertbase(va_arg(ap, int), 10);
		(*str) += 2;
	}
}

void	ft_printf(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		scdiu_control(ap, &str);
		if (*str && *str != '%')
			write(1, str++, 1);
	}
	va_end(ap);
}
