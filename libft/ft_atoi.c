/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeali <reeali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:34:11 by reeali            #+#    #+#             */
/*   Updated: 2023/12/04 12:28:49 by reeali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sing;
	long	nb;

	i = 0;
	sing = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if (nb > (UINT32_MAX) && sing == 1)
		return (-1);
	if (nb > (UINT32_MAX) && sing == -1)
		return (0);
	return (nb * sing);
}

// int main()
// {
//     char str[] = "   -+123";
//     printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// }