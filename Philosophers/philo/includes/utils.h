#ifndef UTILS_H

# define UTILS_H

# include "string.h"
# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "sys/time.h"
# include "pthread.h"

struct	s_philo;

typedef struct s_plist
{
	int				p_pos;
	int				left_fork;
	int				right_fork;
	int				eating;
	int				ate;
	uint64_t		last_eat;
	pthread_t		self_th;
	struct s_philo	*philo_struct;
}	t_plist;

typedef struct s_philo
{	
	pthread_mutex_t	message;
	pthread_mutex_t	*forks;
	pthread_mutex_t	check_dead;
	uint64_t		die;
	uint64_t		eat;
	uint64_t		sleep;
	uint64_t		start_time;
	t_plist			*list;
	char			*err_msg;
	int				p_nbr;
	int				p_d;
	int				p_e;
	int				p_s;
	int				must_eat_flag;
	int				dead_flag;
	int				must_eat_search;
	int				total_eat;
}	t_philo;

uint64_t		ft_time(void);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
void			*must_eat(void *philos);
void			*ft_death_control(void *cur_p);
void			print_message(t_plist *cur_philo, char *str);
void			if_sleep(int __unused i, __unused t_philo *philo);
void			free_mutex(t_philo *philo);
void			*ft_live(void *cur_p);
void			lock_fork(t_plist *cur_philo);
void			unlock_fork(t_plist *cur_philo);
void			eat(t_plist *cur_philo);
char			*ft_strdup(char *s1);
int				ft_philo_init(t_philo **philo);
int				ft_atoi(const char *str);
int				ft_strlen(char *s);
int				lets_go(t_philo *philo);
int				fork_creator(t_philo *philo);

#endif