/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:13:41 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 01:20:46 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_split(char **split_result)
{
	char	**ptr;

	ptr = split_result;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(split_result);
}

static char	**push_args(char **to, char **av)
{
	char	**tmp;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 1;
	k = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' ') != NULL)
		{
			tmp = ft_split(av[i], ' ');
			j = 0;
			while (tmp[j])
			{
				to[k++] = ft_strdup(tmp[j++]);
			}
			ft_free_split(tmp);
		}
		else
			to[k++] = ft_strdup(av[i]);
		i++;
	}
	to[k] = NULL;
	return (to);
}

static	char	**create_args(size_t length, char **av)
{
	char	**arg;

	arg = (char **)malloc(sizeof(char *) * (length + 1));
	if (arg == NULL)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	return (push_args(arg, av));
}

char	**ft_parse_args(char **av)
{
	char	**tmp;
	size_t	i;
	size_t	count;

	i = 1;
	count = 1;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
		{
			tmp = ft_split(av[i], ' ');
			count += ft_arraysize(tmp) - 1;
		}
		else
			count++;
		i++;
	}
	return (create_args((count), av));
}
