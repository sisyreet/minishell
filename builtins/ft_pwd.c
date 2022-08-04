/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kos <kos@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:22:05 by kos               #+#    #+#             */
/*   Updated: 2022/07/21 21:34:11 by kos              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_pwd(t_env *env)
{
	t_list *temp;

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