/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:22:58 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/17 14:30:02 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(char *s, t_philo *ph)
{
	long	time;

	time = curr_time_mil() - ph->pa->start_t;
	if (!check_death(ph, 0))
	{
		if (ft_strcmp(s, "died\n") == 0)
			printf("\033[1;31m");
		else if (ft_strcmp(s, "has taken a fork\n") == 0)
			printf("\033[0;37m");
		else if (ft_strcmp(s, "is sleeping\n") == 0)
			printf("\033[0;36m");
		else if (ft_strcmp(s, "is eating\n") == 0)
			printf("\033[0;32m");
		else if (ft_strcmp(s, "is thinking\n") == 0)
			printf("\033[0;35m");
		printf("%04ld ", time);
		printf("Philo %d %s", ph->id, s);
	}
}

void	sleep_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	usleep(ph->pa->t_to_sleep * 1000);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is thinking\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
}

void	table_activity(t_philo *ph)
{
	pthread_mutex_lock(&ph->l_f);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	if (!ph->r_f)
	{
		usleep((ph->pa->t_to_die * 2) * 1000);
		return ;
	}
	pthread_mutex_lock(ph->r_f);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is eating\n", ph);
	pthread_mutex_lock(&ph->pa->time_eat);
	ph->last_meal = curr_time_mil();
	pthread_mutex_unlock(&ph->pa->time_eat);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	usleep(ph->pa->t_to_eat * 1000);
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(&ph->l_f);
	sleep_think(ph);
}
