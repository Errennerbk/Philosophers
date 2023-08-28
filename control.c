/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:03:27 by icelebi           #+#    #+#             */
/*   Updated: 2023/08/28 17:22:04 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

t_table *set_arg(char **arg, int ac)
{
    t_table *table;
    
    table = malloc(sizeof(t_table));
    if(!table)
        return NULL;
    table->nop = ft_p_atoi(arg[1]);
    table->death_time = ft_p_atoi(arg[2]);
    table->eat_time = ft_p_atoi(arg[3]);
    table->sleep_time = ft_p_atoi(arg[4]);
    if(ac == 6)
        table->must_eat_count = ft_p_atoi(arg[5]);
    table->must_eat_count = -1;
    table->philo = malloc(sizeof(t_philo) * table->nop);
    table->forks = malloc(sizeof(t_philo)* table->nop);
    table->time = current_time();
    table->stop = 0;
    return table;
}

void arg_check()
{
    printf("eksik veya fazla arguman girildi,incorrect");
}

int control(int ac, char **av)
{
    if(ac == 5 || ac == 6)
    {
        if(num_cont(ac,av) == 1)
        {
            set_arg(av,ac);
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;

}

int num_cont(int ac, char **av)
{
   int i = 1;
   int j;
    while(i < ac)
    {
        j = 0;
        while(av[i][j])
        {
            if(av[i][j] <= 57 && av[i][j] >= 48)
                j++;
            else
                return 0;
        }
        i++;
    }
    return 1;
}