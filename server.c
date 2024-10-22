/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeali <reeali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:24:15 by reeali            #+#    #+#             */
/*   Updated: 2023/12/04 12:31:23 by reeali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static unsigned char	ch;
	static int				i;

	if (sig == SIGUSR1)
		ch = (ch << 1) | 1;
	if (sig == SIGUSR2)
		ch = (ch << 1) | 0;
	i++;
	if (i == 8)
	{
		write(1, &ch, 1);
		if (ch == '\0')
			write(1, "\n", 1);
		i = 0;
		ch = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("server pid: %d", pid);
	ft_printf("\n");
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
