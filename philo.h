/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:52:36 by icelebi           #+#    #+#             */
/*   Updated: 2023/08/28 17:23:10 by icelebi          ###   ########.fr       */
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
    int eat;
    int sleep;
    int fork_status;
    int last_eat;
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
      int *forks;
      uint64_t death_time;
      uint64_t time;
      pthread_mutex_t m_eat_time;
      pthread_mutex_t m_think_time;
      pthread_mutex_t m_sleep_time;
      
} t_table;

int num_cont(int ac, char **av);
int control(int ac, char **av);
void arg_check();
t_table *set_arg(char **arg, int ac);
uint64_t	current_time(void);
int ft_p_atoi(char *s);

# endif