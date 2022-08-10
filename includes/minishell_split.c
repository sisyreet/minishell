/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:13:52 by kos               #+#    #+#             */
/*   Updated: 2022/08/10 19:36:14 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**minishell_split(char *line, char sep)
{
	int		i;
	char	**splitted;

	i = 0;
	splitted = malloc(sizeof(char *) * 2);
	if (!splitted)
		return (0);
	while (line[i] != sep)
	{	
		i++;
	}
	splitted[0] = malloc(sizeof(char) * i + 1);
	if (!splitted[0])
		return (0);
	ft_strlcpy(splitted[0], line, i + 1);
	splitted[1] = malloc(sizeof(char) * (ft_strlen(&line[i]) + 1));
	if (!splitted[1])
		return (0);
	ft_strlcpy(splitted[1], &line[i + 1], ft_strlen(&line[i]));
	return (splitted);
}
