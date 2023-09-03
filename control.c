/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:47:10 by eerbek            #+#    #+#             */
/*   Updated: 2023/09/03 14:07:35 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <stdio.h>

static int	ft_check_args(void)
{
	printf(" ____________________________________________________ \n");
	printf("|            Please enter 4 or 5 arguments           |\n");
	printf("|____________________________________________________|\n");
	printf("|             [1][Number of philosophers]            |\n");
	printf("|             [2][Time to die]                       |\n");
	printf("|             [3][Time to eat]                       |\n");
	printf("|             [4][Time to sleep]                     |\n");
	printf("|             [5][Number of meals]                   |\n");
	printf("|____________________________________________________|\n");
	return (0);
}

static int	input_ac_control(int ac, char **av)
{
	register int	i;

	i = 1;
	if (ac <= 4 || ac >= 7)
		return (ft_check_args());
	while (i < ac)
	{
		if (is_digit(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_max(char **av)
{
	register int	i;

	i = 1;
	while (av[i])
	{
		if (unsigned_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_control(int ac, char **av)
{
	if (input_ac_control(ac, av) == 0)
		return (ft_err("Incorret argument!\n"));
	if (ft_check_max(av) == 0)
		return (ft_err("Invalid argument!\n"));
	return (1);
}
