/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeali <reeali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:12:13 by reeali            #+#    #+#             */
/*   Updated: 2023/07/11 14:17:19 by reeali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int ch)
{
	while (ch >= 97 && ch <= 122)
	{
		ch = ch - 32;
	}
	return (ch);
}
// #include <stdio.h>
/*int main()
{
	printf("%c", ft_toupper('a'));
}*/