/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kos <kos@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:21:56 by kos               #+#    #+#             */
/*   Updated: 2022/07/26 21:31:59 by kos              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{	
	char			*name;
	char			*value;
	struct s_list	*next;
}	t_list;

typedef struct s_env
{
	t_list	*head;
	int		num_of_env_vars;
}	t_env;

/* utils */
size_t	ft_strlen(const char *line);
int		ft_strncmp(char *first, char *second, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**minishell_split(char *line, char sep);
void	ft_error_message(char *msg);

/* builtins */
void	get_env_vars(char **envp, t_env *env);
void	set_env_var_value(t_env *env, char *var_name, char *new_value);
char	*get_env_var_value(t_env *env, char *var_name);
void	add_new_var(t_list *head, char *var_name, char *value);
void	print_env(t_env *env);
void	ft_echo(char *text, int flag);
int		ft_pwd(t_env *env);
int		ft_export(t_env *env, char *var_name, char *value);
int		ft_unset(t_env *env, char *var_name);
void	ft_cd(t_env *env, char *path);

#endif