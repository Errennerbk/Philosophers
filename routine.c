/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:17:41 by eerbek            #+#    #+#             */
/*   Updated: 2023/09/03 14:26:30 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{	// yemek yemek için iki elinde de çatal olması lazım o yüzden bir çatal aldığında onu kilitliyor ve yiyene kadar bırakmıyor.
	if (philo->eat_count == philo->table->number_of_must_eat)
		return ;
	pthread_mutex_lock(philo->rfork); // bir çatalı kitledi.
	print(philo, TAKEN_FORK);
	pthread_mutex_lock(philo->lfork); // ikinci çatalı da kitledi ve yemek yedi.
	print(philo, TAKEN_FORK);
	print(philo, IS_EATING);
	pthread_mutex_lock(&philo->table->count_eat); // yemek yeme sayısı kilitlendi çüünkü aynı anda bir kere artmasını istiyoruz.
	philo->eat_count++;	// yemek yeme sayısı artırıldı
	pthread_mutex_unlock(&philo->table->count_eat); // kilit açıldı.
	time_usleep(philo->table->time_to_eat); // yemek yerken geçen süre
	pthread_mutex_lock(&philo->table->eat_last); // son yeme süresi
	philo->last_eat = current_time(); // son yeme  sğresini şimdiki süre ile kıyasladı
	pthread_mutex_unlock(&philo->table->eat_last); // kilitler açıldı
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

void	philo_sleep(t_philo *philo)
{
	print(philo, IS_SLEEPING); // uyuduğunu yazdırdı
	time_usleep(philo->table->time_to_sleep); // uyurken geçeb süreyi hesapladı.
}

void	philo_think(t_philo *philo)
{
	print(philo, IS_THINKING); // ne düşünüyon la bebe.
}

void	*philo_routine(void *_philo)
{
	t_philo	*philo;
	int		stop;

	philo = (t_philo *)_philo; // philoyu threadse e tanımlıyoruz sen bu philosun işe başla gibi,
	if (philo->id % 2 == 0)
		time_usleep(10); // bekletme süresi,
	while (1)
	{
		pthread_mutex_lock(&philo->table->stop_count);
		stop = philo->table->stop;
		pthread_mutex_unlock(&philo->table->stop_count);
		if (stop == 1)
			break ; // eğer ölen philo var ise döngüyü kırıyor.
		philo_eat(philo); // philo yu yemek yemeye gönderiyo.
		philo_sleep(philo); // philoyu uyutuyo.
		philo_think(philo); // philoyu düşünmeye yolluyo.
	}
	return (NULL);
}