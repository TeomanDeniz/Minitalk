/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:06:43 by hdeniz            #+#    #+#             */
/*   Updated: 2023/06/17 16:07:10 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* INCLUDES */
#include <signal.h>/*
# define SIGUSR1 30
# define SIGUSR2 31
#   void *signal(int sig, void (*handler) (int));
#    int kill(pid_t pid, int sig);
#    int getpid(void);
*/
#include <unistd.h>/*
#    int write(int fd, const void *buf, size_t nbyte);
#    int pause(void);
*/
/* INCLUDES */

/* PROTOTYPES */
static __inline__ void	event(register int eax);
static __inline__ void	write_pid(register int number);
static __inline__ int	get_pid_and_correct(unsigned short byte);
/* PROTOTYPES */

int
	main(void)
{
	write(1, "SEVER - PID(", 12);
	write_pid(getpid());
	write(1, ")\n", 2);
	signal(SIGUSR1, event);
	signal(SIGUSR2, event);
	while (1)
		pause();
	return (0);
}

static __inline__ void
	event(register int eax)
{
	static unsigned char	index;
	static unsigned char	character;

	index = index + 0;
	character = character + 0;
	if (eax == SIGUSR1)
		character = (character << 1) | 1;
	else if (eax == SIGUSR2)
		character = (character << 1);
	if (++index, index >= 8)
	{
		if (get_pid_and_correct(character))
			write(1, &character, 1);
		index = 0;
		character = 0;
	}
}

static __inline__ int
	get_pid_and_correct(unsigned short byte)
{
	static unsigned char		remember;
	static unsigned short int	pid;

	remember = remember + 0;
	pid = pid + 0U;
	if (remember >= 2)
	{
		if (byte)
			kill(pid, SIGUSR1);
		else
		{
			remember = 0;
			pid = 0;
		}
		return (1);
	}
	pid += (unsigned short)(byte << (8 * (++remember == 1)));
	return (0);
}

static __inline__ void
	write_pid(register int number)
{
	char	character;

	if (number <= 9)
	{
		character = number + '0';
		write(1, &character, 1);
	}
	else
	{
		write_pid(number / 10);
		write_pid(number % 10);
	}
}
