/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:18:15 by eerbek            #+#    #+#             */
/*   Updated: 2023/09/03 14:07:37 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_err(char *str)
{
	printf("%s", str);
	return (0);
}

unsigned int	unsigned_atoi(char *str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	if (!str || str < 0)
		return (0);
	while (*(str + ++i))
		res = (res * 10) + (*(str + i) - '0');
	return (res);
}

void	print(t_philo *philo, char *str)
{
	uint64_t	i;

	i = time_from_start(philo->table);
	pthread_mutex_lock(&philo->table->is_print);
	pthread_mutex_lock(&philo->table->stop_count);
	if (!philo->table->stop)
		printf("\033[0;36m%llu \033[0;32m%llu %s\033[0m\n", i, philo->id, str);
	pthread_mutex_unlock(&philo->table->stop_count);
	pthread_mutex_unlock(&philo->table->is_print);
}
