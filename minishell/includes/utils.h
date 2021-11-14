/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:08:00 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/20 16:20:52 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_data{
	int		argc;
	char	**argv;
	char	**env;
	char	**export;
	int		ret;
	char	*str;
	char	**cmds;
	int		child;
	int		err;
}					t_data;

typedef struct s_var
{
	char	*bef;
	char	*aft;
	char	*env;
	char	*aux;

}				t_var;

void			*ft_memset(void *str, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_init_param(t_data **prm, char **argv, char **env, int *ret);
char			**env_cpy(char **env, int add);
char			*ft_strdup(char *s);
int				ft_putstrs_fd(char *before, char *str, char *after, int fd);
void			put_prompt(char **env);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *s);
void			ft_addchr(char **str, char c);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			parser(t_data *prm);
int				check_semicolon(t_data *prm);
char			**ft_split_case(char *s, char c);
void			rm_char(char **str, int j);
char			*ft_strldup(const char *s, int len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isspace(int c);
int				ft_isalnum(int c);
int				ft_strlen_char(char *str, char c);
int				ft_strlen_env(char *str);
char			*ft_itoa(int n, int sign);
char			*get_env(char **envp, char *env);
int				count_args(char *str);
void			skip_spaces(char **str);
int				ft_strlen_arg(char *str);
int				ft_strlen_arg_token(char *str, char c);
int				is_token(char c);
void			set_args(char **argv, char *str, int argc);
void			command_or_pipe(t_data *prm, int j);
char			**check_command(char *str, t_data *prm);
void			copy_args1(t_data *prm);
int				count_redir(t_data *prm);
void			free_matrix(char **matrix);
int				check_builtins(int fd, t_data *prm);
int				check_builts(int fd, t_data *prm);
void			echo_command(t_data *prm, int fd);
void			change_dir(char *path, t_data *prm);
void			cd_command(t_data *prm);
void			env_command(t_data *prm, int fd);
int				check_errno(t_data *prm, char *str);
void			check_type(t_data *prm, char *str, char *path, int fd);
void			set_filename(int len, char **new, char *str);
void			set_path(char *str, char **path);
void			bash_command(t_data *prm);
void			child_sig_handler_bash(int sig);
char			**multiple_env(t_data *prm, int fd, int i);
void			exit_command(t_data *prm);
void			free_param(t_data *prm);
void			sort_env(char **env, int fd, char c);
void			put_env(char **aux, int fd);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				check_bin(int fd, t_data *prm);
char			*search_bin(char *str, DIR **dir, struct dirent **d,
					 t_data *prm);
void			exec_bin(int fd, char *path, t_data *prm);
char			**copy_args(t_data *prm);
void			child_sig_handler(int sig);
int				check_pipe(int *fds, t_data *prm, int j, int sons);
void			pipe_son(int *flag, int *fds, t_data *prm, int pos);
void			set_pipe_args(t_data *prm, int i);
void			switch_pipes(int *fds);
void			sig_handler(int sig);
void			ft_putstrlen_fd(char *s, int len, int fd);
void			ft_putstr_fd(char *s, int fd);
void			rm_token(char **arg);
int				set_fd(t_data *prm);
void			rm_backslash(char **arg, int *i);
int				check_export_error(char **argv, int *i);
void			export_value(t_data *prm, int *i);
int				get_next_line(int fd, char **line);
char			**export_command(t_data *prm, int j);
char			**unset_command(t_data *prm, int j);
char			**erase_env(char **env, int i);
int				redirect(t_data *prm, int i, int fd);
void			rl_replace_line (const char *text, int clear_undo);
char			*re_readdir( DIR **dir, struct dirent **d);
int				ft_num_size(int n, int sign);
int				strinwhile(char *str, int *i);
void			change_env2(t_var	*var, char **str);
char			*your_mom(char **paths, int i);
int				reread(DIR **dir, struct dirent **d);
int				exceptions(t_data *prm, char *c);

#endif