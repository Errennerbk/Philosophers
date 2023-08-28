/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:31:19 by icelebi           #+#    #+#             */
/*   Updated: 2023/08/28 17:18:35 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    
    if(control(ac,av) == 1)
    {   
        t_table *table;   
        table = set_arg(av,ac);  
        printf("obaaaaaaa");
    }
    else
        arg_check(ac);
    
}