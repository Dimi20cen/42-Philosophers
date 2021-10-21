/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:23:04 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/17 14:12:43 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//when someone dies the ending function joins the threads
//and destroyes the mutexes
void	ending(t_p *p)
{
	int	i;

	i = -1;
	while (!check_death2(p))
		usleep(1000);
	while (++i < p->a.total)
		pthread_join(p->ph[i].thread_id, NULL);
	pthread_mutex_destroy(&p->a.write_mutex);
	i = -1;
	while (++i < p->a.total)
		pthread_mutex_destroy(&p->ph[i].l_f);
	if (p->a.stop == 2)
		printf("Each philosopher ate %d times\n", p->a.m_eat);
	free(p->ph);
}

int	main(int argc, char **argv)
{
	t_p		p;

	if (!(parse_args(argc, argv, &p)))
		return (my_return("Invalid arguments\n"));
	p.ph = malloc(sizeof(t_philo) * p.a.total);
	if (!p.ph)
		return (my_return("Malloc returned NULL\n"));
	if (!initialize(&p) || !create_threads(&p))
	{
		free(p.ph);
		return (0);
	}
	ending(&p);
}
