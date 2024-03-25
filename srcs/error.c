/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:45:13 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 01:08:45 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_number(const char *s)
{
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		if (s[i] == '-' || s[i] == '+')
		{
			i++;
			if (s[i] < '0' || '9' < s[i])
			{
				write(2, "Error\n", ft_strlen("Error\n"));
				exit(1);
			}
		}
		while (s[i])
		{
			if (s[i] < '0' || '9' < s[i])
			{
				write(2, "Error\n", ft_strlen("Error\n"));
				exit(1);
			}
			i++;
		}
	}
}

static void	handle_edgevalue(char *s)
{
	long long	result;
	int			flag;

	flag = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			flag *= -1;
		s++;
	}
	result = 0;
	while (*s)
	{
		result = (result * 10) + (*s - '0');
		if (result * flag < INT_MIN || INT_MAX < result * flag)
		{
			write(2, "Error\n", ft_strlen("Error\n"));
			exit(1);
		}
		s++;
	}
}

void	check_range(char *s)
{
	if (ft_strlen(s) == 0)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	handle_edgevalue(s);
}

static void	has_dupulicate(int *arr, int num, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		if (arr[i] == num)
		{
			write(2, "Error\n", ft_strlen("Error\n"));
			exit(1);
		}
		i++;
	}
}

void	check_samenum(int ac, char **av)
{
	int	*tmp;
	int	count;
	int	i;

	tmp = (int *)malloc(ac * sizeof(int));
	if (!tmp)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	i = 0;
	count = ac;
	while (count-- && av[i])
	{
		if (i > 0)
		{
			has_dupulicate(tmp, ft_atoi(av[i]), i);
		}
		tmp[i] = ft_atoi(av[i]);
		i++;
	}
	free(tmp);
}
