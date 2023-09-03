/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:18:59 by eerbek            #+#    #+#             */
/*   Updated: 2023/09/03 14:00:20 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_table *table, int i)
{
	philo->id = i + 1;
	philo->table = table;
	philo->eat_count = 0;
	philo->last_eat = current_time();
	pthread_mutex_init(&table->forks[i], NULL);
}

void	fork_init(t_philo *philo, t_table *table, int i)
{
	if (i - 1 < 0)
		philo->rfork = table->forks + (table->number_of_philo - 1);
	else
		philo->rfork = &table->forks[i - 1];
	philo->lfork = &table->forks[i];
}