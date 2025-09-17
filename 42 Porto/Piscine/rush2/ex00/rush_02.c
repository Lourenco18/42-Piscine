/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-c <dsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:36:50 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/14 17:51:46 by dsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		validate_args(int argc, char *number_str);
char	*get_dict_filename(int argc, char **argv);
int		process_conversion(char *dict_file, char *number_str);

int	main(int argc, char **argv)
{
	char	*dict_filename;
	char	*number_string;

	number_string = argv[argc - 1];
	if (!validate_args(argc, number_string))
		return (1);
	dict_filename = get_dict_filename(argc, argv);
	return (process_conversion(dict_filename, number_string));
}

int	validate_args(int argc, char *number_str)
{
	int	i;

	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	i = 0;
	while (number_str[i])
	{
		if (number_str[i] < '0' || number_str[i] > '9')
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

char	*get_dict_filename(int argc, char **argv)
{
	if (argc == 2)
		return ("numbers.dict");
	return (argv[1]);
}

int	process_conversion(char *dict_file, char *number_str)
{
	t_dict			*dict;
	char			*result;
	unsigned int	number;

	dict = parse_dict(dict_file);
	if (!dict)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	number = ft_atoi(number_str);
	result = convert_number(number, dict);
	if (!result)
	{
		ft_putstr("Dict Error\n");
		free_dict(dict);
		return (1);
	}
	ft_putstr(result);
	ft_putstr("\n");
	free(result);
	free_dict(dict);
	return (0);
}
