/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeali <reeali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:24:07 by reeali            #+#    #+#             */
/*   Updated: 2023/11/30 17:50:34 by reeali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	isnum(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	error(void)
{
	write(1, "The pid is wrong or the signal did not resive", 47);
	exit(0);
}

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if ((temp_char & 1) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;
	int		i;

	if (ac == 3 && isnum(av[1]))
	{
		pid = ft_atoi(av[1]);
		if (kill(pid, 0) == -1)
			error();
		i = 0;
		message = av[2];
		while (message[i])
		{
			send_signal(pid, message[i]);
			i++;
		}
		send_signal(pid, '\n');
		ft_printf("\n");
	}
	else
		write(1, "There is something wrong!", 26);
	return (0);
}
