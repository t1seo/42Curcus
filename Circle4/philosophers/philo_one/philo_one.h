/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:06:53 by tseo              #+#    #+#             */
/*   Updated: 2021/05/07 21:42:44 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE
# define PHILO_ONE

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/*
** ERROR MESSAGES
*/
# define WRONG_ARGC "Error: The number of arguments is incorrect"
# define WRONG_ARGS "Error: It contains the wrong argument"
# define MALLOC_FAIL "Error: Memory allocation failed"

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
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
}					t_info;

typedef struct		s_philo
{
	int				idx;
	int				fork_1;
	int				fork_2;
	int				num_of_eat;
	unsigned long	last_ate_time;
	pthread_t		tid;
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
int					print_message(t_philo *philo, t_status status, unsigned long cur_time);

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
void				set_table(void);
void				unset_table(void);

/*
** ROUTINE
*/
void				start_eating(void);

/*
** CHECKER
*/
void				*check_status(void *arg);


#endif
