/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:18:59 by eerbek            #+#    #+#             */
/*   Updated: 2023/08/29 20:05:39 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_init(t_philo *philo, t_table *table, int i)
{
    philo->id = i + 1;
    philo->table = table;
    philo->eat_count = 0;
    philo->last_eat = current_time();
    //pthread_mutex_init(&table->forks[i], NULL);
    philo->rfork = malloc(sizeof(pthread_mutex_t));
    philo->lfork = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(philo->rfork,NULL);
    pthread_mutex_init(philo->lfork,NULL);
}

void    fork_init(t_philo *philo, t_table *table, int i)
{
    if (i - 1 < 0)
        philo->rfork = table->forks + (table->nop - 1);
    else
        philo->rfork = &table->forks[i - 1];
    philo->lfork = &table->forks[i];

}