/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:36:50 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/17 13:08:00 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h" // Inclui o header com structs e protótipos de funções.

// Protótipos locais (funções definidas neste ficheiro)
int		validate_args(int argc, char *number_str);   // Valida número de argumentos e se a string é numérica.
char	*get_dict_filename(int argc, char **argv);   // Retorna o nome do ficheiro de dicionário a usar.
int		process_conversion(char *dict_file, char *number_str); // Converte o número usando o dicionário.

int	main(int argc, char **argv)
{
	char	*dict_filename;   // Ponteiro para guardar o nome do ficheiro de dicionário.
	char	*number_string;   // Ponteiro para guardar o número em string.

	number_string = argv[argc - 1];          // Último argumento é sempre o número a converter.
	if (!validate_args(argc, number_string)) // Valida argumentos; se inválido, retorna 1 (erro).
		return (1);
	dict_filename = get_dict_filename(argc, argv); // Obtém o ficheiro de dicionário.
	return (process_conversion(dict_filename, number_string)); // Converte o número e retorna resultado.
}

int	validate_args(int argc, char *number_str)
{
	int	i;

	if (argc < 2 || argc > 3)       // Deve ter 1 ou 2 argumentos: opcional dicionário + número.
	{
		ft_putstr("Error\n");       // Mensagem de erro padrão.
		return (0);                 // Retorna 0 para indicar erro.
	}
	i = 0;
	while (number_str[i])            // Percorre cada caractere do número.
	{
		if (number_str[i] < '0' || number_str[i] > '9') // Se não for dígito.
		{
			ft_putstr("Error\n");   // Mensagem de erro.
			return (0);             // Retorna 0 para indicar erro.
		}
		i++;
	}
	return (1);                      // Retorna 1 se os argumentos forem válidos.
}

char	*get_dict_filename(int argc, char **argv)
{
	if (argc == 2)                   // Se não foi dado ficheiro de dicionário.
		return ("numbers.dict");     // Usa o dicionário padrão "numbers.dict".
	return (argv[1]);                // Caso contrário, retorna o ficheiro fornecido como argumento.
}

int	process_conversion(char *dict_file, char *number_str)
{
	t_dict			*dict;          // Ponteiro para a lista ligada do dicionário.
	char			*result;        // Ponteiro para string final do número por extenso.
	unsigned int	number;          // Número convertido de string para inteiro.

	dict = parse_dict(dict_file);    // Lê e cria a lista ligada do dicionário.
	if (!dict)                       // Se falhar a leitura do dicionário.
	{
		ft_putstr("Dict Error\n");   // Mensagem de erro de dicionário.
		return (1);
	}
	number = ft_atoi(number_str);    // Converte string para número inteiro.
	result = convert_number(number, dict); // Converte número em texto usando o dicionário.
	if (!result)                     // Se não conseguir converter.
	{
		ft_putstr("Dict Error\n");   // Mensagem de erro.
		free_dict(dict);             // Liberta memória do dicionário.
		return (1);
	}
	ft_putstr(result);               // Mostra resultado no ecrã.
	ft_putstr("\n");                 // Nova linha.
	free(result);                    // Liberta memória da string resultante.
	free_dict(dict);                 // Liberta memória do dicionário.
	return (0);                      // Retorna 0 indicando sucesso.
}
