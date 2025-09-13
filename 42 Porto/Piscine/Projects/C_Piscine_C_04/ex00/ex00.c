/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:52:31 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/13 16:54:19 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
#include <stdio.h>

int ft_strlen(char *str);
/*
int main(void)
{
    char str1[] = "Piscine 42!";
 

    printf("Tamanho de \"%s\" = %d\n", str1, ft_strlen(str1));
   

    return 0;
}*/

