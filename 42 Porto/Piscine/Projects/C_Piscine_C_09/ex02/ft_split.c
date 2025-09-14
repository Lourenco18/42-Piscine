/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:00:56 by dasantos          #+#    #+#             */
/*   Updated: 2025/09/14 10:03:05 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int is_sep(char c, char *charset)
{
    int i = 0;
    while (charset && charset[i])
    {
        if (charset[i] == c)
            return 1;
        i++;
    }
    return 0;
}

static int word_count(char *str, char *charset)
{
    int i = 0;
    int count = 0;
    while (str && str[i])
    {
        while (str[i] && is_sep(str[i], charset))
            i++;
        if (str[i] && !is_sep(str[i], charset))
        {
            count++;
            while (str[i] && !is_sep(str[i], charset))
                i++;
        }
    }
    return count;
}

static char *dup_part(char *str, int start, int len)
{
    char *s = (char *)malloc(len + 1);
    int i;
    if (!s) return NULL;
    for (i = 0; i < len; i++)
        s[i] = str[start + i];
    s[len] = '\0';
    return s;
}

char **ft_split(char *str, char *charset)
{
    int words = word_count(str, charset);
    char **res = (char **)malloc((words + 1) * sizeof(char *));
    int i = 0, w = 0, start;

    if (!res) return NULL;
    while (str && str[i] && w < words)
    {
        while (str[i] && is_sep(str[i], charset))
            i++;
        start = i;
        while (str[i] && !is_sep(str[i], charset))
            i++;
        res[w] = dup_part(str, start, i - start);
        if (!res[w])
        {
            int j;
            for (j = 0; j < w; j++) free(res[j]);
            free(res);
            return NULL;
        }
        w++;
    }
    res[w] = NULL;
    return res;
}
