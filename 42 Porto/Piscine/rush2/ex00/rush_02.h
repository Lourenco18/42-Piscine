/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:26:24 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/14 18:28:26 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}	t_dict;

t_dict	*parse_dict(char *filename);
void	free_dict(t_dict *dict);
char	*convert_number(unsigned int nb, t_dict *dict);
char	*convert_scale(unsigned int nb, unsigned int scale, t_dict *dict);
char	*convert_hundreds(unsigned int nb, t_dict *dict);
char	*convert_tens(unsigned int nb, t_dict *dict);
char	*find_in_dict(unsigned int key, t_dict *dict);
char	*join_strings(char *s1, char *s2);
char	*copy_join_strings(char *result, char *s1, char *s2, int len1);
char	*read_file(char *filename);
t_dict	*create_dict_node(char *key, char *value);
void	skip_spaces(char *str, int *i);
int		extract_key_value(char *str, int *i, char *key, char *value);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
int		ft_is_numeric(char *str);

#endif
