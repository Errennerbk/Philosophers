/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerbek <eerbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:17:50 by eerbek            #+#    #+#             */
/*   Updated: 2023/08/29 20:17:52 by eerbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>


typedef struct s_philo
{
    uint64_t id;
    struct s_table *table;
    pthread_t thread;
    int think;
    int last_eat;
    int sleep;
    int fork_status;
    int eat_count;
    pthread_mutex_t *lfork;
    pthread_mutex_t *rfork;
    
} t_philo;

typedef struct s_table
{
      t_philo *philo;
      int nop;
      int eat_time;
      int think_time;
      int sleep_time;
      int must_eat_count;
      int stop;
      uint64_t death_time;
      uint64_t time;
      pthread_mutex_t *forks;
      pthread_mutex_t m_eat_time;
      pthread_mutex_t m_think_time;
      pthread_mutex_t m_sleep_time;
      pthread_mutex_t m_last_eat;
      pthread_mutex_t is_print;
      pthread_mutex_t is_die;
      
} t_table;

int num_cont(int ac, char **av);
int control(int ac, char **av);
void arg_check();
t_table *set_arg(char **arg, int ac);
uint64_t	current_time(void);
int ft_p_atoi(char *s);
void    *philo_routine(void *id_philo);
void start_threads(t_table *table);
void philo_init(t_philo *philo, t_table *table, int i);
void    fork_init(t_philo *philo, t_table *table, int i);

# endif