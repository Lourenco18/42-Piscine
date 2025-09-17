/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:43:27 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/14 18:02:32 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*convert_number(unsigned int nb, t_dict *dict)
{
	char	*result;

	if (nb == 0)
		return (ft_strdup(find_in_dict(0, dict)));
	result = find_in_dict(nb, dict);
	if (result && nb < 20)
		return (ft_strdup(result));
	if (nb < 100)
		return (convert_tens(nb, dict));
	if (nb < 1000)
		return (convert_hundreds(nb, dict));
	if (nb < 1000000)
		return (convert_scale(nb, 1000, dict));
	if (nb < 1000000000)
		return (convert_scale(nb, 1000000, dict));
	return (NULL);
}
