/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:54:30 by eerbek            #+#    #+#             */
/*   Updated: 2023/09/03 14:41:44 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_threads(t_table *table)
{
	int	i;

	pthread_mutex_init(&table->stop_count, NULL);
	pthread_mutex_init(&table->count_eat, NULL);
	pthread_mutex_init(&table->eat_last, NULL); // threadlern mutexleri oluşturuluyor.
	pthread_mutex_init(&table->is_print, NULL);
	pthread_mutex_init(&table->is_die, NULL);
	i = -1;
	while (++i < table->number_of_philo)
		philo_init(&table->philos[i], table, i); // her philonun ayrı olarak oluşturulduğu yer.
	i = -1;
	while (++i < table->number_of_philo)
		fork_init(&table->philos[i], table, i); // her forkun ayrı olarak oluşturulduğu yer.
	i = -1;
	while (++i < table->number_of_philo)
		pthread_create(&table->philos[i].thread, NULL, // threadler asıl burda oluşuyor işe başladıkları yer,
			philo_routine, table->philos + i); // threadlere iş gönderiliyor.
	die_check(table); // ölme kontrolü burda yapılıyor.
}

void	end_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->number_of_philo)
	{
		if (table->number_of_philo == 1)
			pthread_detach(table->philos[i].thread);
		pthread_join(table->philos[i].thread, NULL); // thradein işini bitirine kadar beklemesini sağlar.
	}
	pthread_mutex_destroy(&table->stop_count);
	pthread_mutex_destroy(&table->count_eat);
	pthread_mutex_destroy(&table->eat_last); // mutexleri kapatır.
	pthread_mutex_destroy(&table->is_die);
	pthread_mutex_destroy(&table->is_print);
	i = 0;
	while (i < table->number_of_philo)
		pthread_mutex_destroy(&table->forks[i++]);
	free (table->forks);
	free (table->philos);
	free (table);
}
