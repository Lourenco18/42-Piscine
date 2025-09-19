/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:23:17 by xxxx          #+#    #+#             */
/*   Updated: 2025/09/15 19:23:17 by xxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_split.c */
#include <stdlib.h>

static int is_sep(char c, char *charset)
{
    int i = 0;
    while (charset[i])
    {
        if (charset[i] == c)
            return (1);
        i++;
    }
    return (0);
}

static int count_words(char *s, char *cs)
{
    int i = 0;
    int cnt = 0;
    while (s[i])
    {
        while (s[i] && is_sep(s[i], cs))
            i++;
        if (s[i] && !is_sep(s[i], cs))
        {
            cnt++;
            while (s[i] && !is_sep(s[i], cs))
                i++;
        }
    }
    return (cnt);
}

static char *substr_dup(char *s, int start, int len)
{
    char *p = (char *)malloc(len + 1);
    int i = 0;
    if (!p) return (0);
    while (i < len)
    {
        p[i] = s[start + i];
        i++;
    }
    p[i] = '\0';
    return (p);
}

char **ft_split(char *str, char *charset)
{
    int words = count_words(str, charset);
    char **res = (char **)malloc((words + 1) * sizeof(char *));
    int i = 0;
    int w = 0;
    int start;
    int len;

    if (!res) return (0);
    while (str[i])
    {
        while (str[i] && is_sep(str[i], charset))
            i++;
        if (str[i] && !is_sep(str[i], charset))
        {
            start = i;
            len = 0;
            while (str[i] && !is_sep(str[i], charset))
            {
                len++;
                i++;
            }
            res[w++] = substr_dup(str, start, len);
            if (!res[w - 1])
            {
                /* em caso de falha libertar já alocado */
                while (w - 1 >= 0)
                    free(res[--w]);
                free(res);
                return (0);
            }
        }
    }
    res[w] = 0;
    return (res);
}
