/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:29:08 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/17 14:32:38 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_arg
{
	int						total;
	int						t_to_die;
	int						t_to_eat;
	int						t_to_sleep;
	int						m_eat;
	long					start_t;
	int						nb_p_finish;
	int						stop;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
}							t_arg;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*r_f;
	pthread_mutex_t			l_f;
	t_arg					*pa;
	long					last_meal;
	int						nb_eat;
	int						finish;
}							t_philo;

typedef struct s_p
{
	t_arg					a;
	t_philo					*ph;
}							t_p;

void			ft_putstr_fd(char *s, int fd);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
void			table_activity(t_philo *ph);
int				parse_args(int argc, char **argv, t_p *p);
int				initialize(t_p *p);
int				create_threads(t_p *p);
int				my_return(char *str);
void			write_status(char *str, t_philo *ph);

long			curr_time_mil(void);

int				check_death(t_philo *ph, int i);
int				check_death2(t_p *p);

#endif