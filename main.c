/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:53:32 by eerbek            #+#    #+#             */
/*   Updated: 2023/09/03 14:39:09 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (ft_control(ac, av) == 0) // argümanları kontrol ediyor
		return (1);
	table = parse(ac, av); // argümanların ne olduğunu atoi ile int e çevirip table strcutına tanımlıyor
	if (table != NULL)
	{
		if (table->number_of_philo > 0)
		{
			start_threads(table); // threadsl lerin başlatıldığı yer
			end_threads(table); // threadsları kapattığımız yer
		}
	}
	return (0);
}

t_table	*parse(int ac, char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->number_of_philo = unsigned_atoi(av[1]); // ilk argüman philosopher sayısı
	table->time_to_die = unsigned_atoi(av[2]); // iknici argüman ölme süresi
	table->time_to_eat = unsigned_atoi(av[3]); // 3. argüman yemek yerken geçirdiği süre
	table->time_to_sleep = unsigned_atoi(av[4]); // 4. ise uyurken geçirilen süre
	table->number_of_must_eat = -1;
	if (ac == 6)
		table->number_of_must_eat = unsigned_atoi(av[5]);
	table->philos = malloc(sizeof(t_philo) * table->number_of_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->number_of_philo);
	table->time = current_time();
	table->stop = 0;
	return (table);
}
