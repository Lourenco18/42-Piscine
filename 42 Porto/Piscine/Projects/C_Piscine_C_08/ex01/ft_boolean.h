/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:54:18 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 09:57:26 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#include <unistd.h>

typedef int t_bool;

#define TRUE 1
#define FALSE 0

#define EVEN(n) ((n) % 2 == 0)
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG  "I have an odd number of arguments.\n"
#define SUCCESS 0

#endif /* FT_BOOLEAN_H */
