/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:06:53 by tseo              #+#    #+#             */
/*   Updated: 2021/05/14 20:57:45 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

/*
** ERROR MESSAGES
*/
# define WRONG_ARGC "Error: The number of arguments is incorrect"
# define WRONG_ARGS "Error: It contains the wrong argument"
# define MALLOC_FAIL "Error: Memory allocation failed"
# define SEM_FAIL "Error: Semaphore failed"

/*
** COLORS FOR PROMPT MESSAGES
*/
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_RESET "\x1b[0m"

/*
** PHILOSOPHER'S STATUS
*/
typedef enum	e_status
{
	TAKEN_FORK = 0,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}				t_status;

typedef struct		s_info
{
	int				num_of_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				num_of_must_eat;

	unsigned long	start_time;
	int				num_of_eating_done;
	int				num_of_dead;
	sem_t			*act;
	sem_t			*message;
	sem_t			*fork;
}					t_info;

typedef struct		s_philo
{
	int				idx;
	int				num_of_eat;
	unsigned long	last_ate_time;
	pid_t			pid;
}					t_philo;

extern t_info		g_info;
extern t_philo		*g_philos;

/*
** PARSER
*/
int					parse_argv(t_info *info, char **argv);

/*
** MESSAGE
*/
int					print_error(char *err_msg);
int					print_message(t_philo *philo, t_status status,
								unsigned long cur_time);

/*
** UTILS
*/
int					ft_atoi(const char *str);
unsigned long		get_time(void);
void				vsleep(unsigned long time);
int					is_num(char *num);

/*
** SETTING
*/
int					set_table(void);
void				unset_table(void);

/*
** ROUTINE
*/
void				start_eating(void);

/*
** CHECKER
*/
void				*check_status(void *arg);

/*
** CHECK PROCESS
*/
void				check_process(void);

#endif
