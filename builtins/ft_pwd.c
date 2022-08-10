/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:22:05 by kos               #+#    #+#             */
/*   Updated: 2022/08/10 19:35:45 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_pwd(t_env *env)
{
	t_list	*temp;

	temp = env->head;
	while (temp->next)
	{
		if (!ft_strncmp("PWD", temp->name, ft_strlen(temp->name)))
		{
			printf("%s\n", temp->value);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
