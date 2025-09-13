/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:12:50 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/13 17:18:31 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

static void	print_nbr(long nbr, char *base, int size)
{
	char	c;

	if (nbr >= size)
		print_nbr(nbr / size, base, size);
	c = base[nbr % size];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	long	nb;

	size = 0;
	while (base[size])
		size++;
	if (!check_base(base))
		return ;
	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	print_nbr(nb, base, size);
}
