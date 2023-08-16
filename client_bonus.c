/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:14:43 by hdeniz            #+#    #+#             */
/*   Updated: 2023/06/17 16:14:46 by hdeniz           ###   ########.fr       */
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
#    int usleep(useconds_t usec);
*/
/* INCLUDES */

/* CONSTANTS */
#define ERROR_M " ERROR - Try: ./client_bonus <PID> '<MESSAGE>' \n"
/* CONSTANTS */

/* PROTOTYPES */
static __inline__ void	send_data(char byte, int pid);
static __inline__ void	send_pid(int pid);
static __inline__ void	event(register int eax);
/* PROTOTYPES */

int
	main(int argc, char *argv[])
{
	int	pid;
	int	ecx;

	ecx = -1;
	pid = 0;
	signal(SIGUSR1, event);
	if (argc == 3)
	{
		while (++ecx, argv[1][ecx])
			pid = (pid * 10) + (argv[1][ecx] & 15);
		ecx = -1;
		send_pid(pid);
		while (++ecx, argv[2][ecx])
			send_data(argv[2][ecx], pid);
		send_data(0, pid);
	}
	else
		write(1, ERROR_M, 48);
	return (0);
}

static __inline__ void
	send_pid(int pid)
{
	register char	ecx;
	register short	eax;

	eax = getpid();
	ecx = -1;
	while (++ecx, ecx < 16)
	{
		if (eax << (short)ecx & 32768)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

static __inline__ void
	send_data(char byte, int pid)
{
	register char	ecx;

	ecx = -1;
	while (++ecx, ecx < 8)
	{
		if (byte << ecx & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

static __inline__ void
	event(register int eax)
{
	if (eax == SIGUSR1)
		write(1, "SENT APPROVED!\n", 15);
}
