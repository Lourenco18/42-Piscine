/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx <xxx@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:58:33 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/17 13:08:00 by xxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h" // Inclui o header com structs e protótipos de funções.

// -------- Função que procura uma chave no dicionário e retorna o valor --------
char	*find_in_dict(unsigned int key, t_dict *dict)
{
	t_dict			*current;    // Nó atual da lista ligada.
	unsigned int	dict_key;    // Chave convertida para inteiro.

	current = dict;
	while (current)                // Percorre toda a lista ligada.
	{
		dict_key = (unsigned int)ft_atoi(current->key); // Converte key string para inteiro.
		if (dict_key == key)       // Se encontrar a chave desejada.
			return (current->value); // Retorna o valor correspondente.
		current = current->next;   // Avança para próximo nó.
	}
	return (NULL);                 // Retorna NULL se não encontrar.
}

// -------- Função que converte números maiores por escala (mil, milhão, etc) --------
char	*convert_scale(unsigned int nb, unsigned int scale, t_dict *dict)
{
	char	*left;        // Parte antes da escala (ex: "dois" em 2.000).
	char	*scale_word;  // Palavra da escala (ex: "mil").
	char	*remaining;   // Parte restante do número.
	char	*result;      // Resultado parcial.
	char	*temp;        // Resultado final temporário.

	left = convert_number(nb / scale, dict);       // Converte parte inteira da divisão pela escala.
	scale_word = find_in_dict(scale, dict);        // Procura palavra da escala no dicionário.
	result = join_strings(left, scale_word);       // Junta número e escala (ex: "dois mil").
	free(left);
	if (nb % scale == 0)                           // Se não houver resto.
		return (result);
	remaining = convert_number(nb % scale, dict);  // Converte o restante do número.
	temp = join_strings(result, remaining);        // Junta resultado principal com restante.
	free(result);
	free(remaining);
	return (temp);
}

// -------- Função que converte centenas (100-999) --------
char	*convert_hundreds(unsigned int nb, t_dict *dict)
{
	char	*temp;          // Número da centena convertido.
	char	*hundred_word;  // Palavra "cem" ou "cento".
	char	*remaining;     // Restante da centena.
	char	*result;        // Resultado parcial.

	temp = convert_number(nb / 100, dict); // Converte a parte das centenas.
	hundred_word = find_in_dict(100, dict); // Procura palavra "100" no dicionário.
	result = join_strings(temp, hundred_word); // Junta centenas (ex: "dois cem").
	free(temp);
	if (nb % 100 == 0)                     // Se não houver restante.
		return (result);
	remaining = convert_number(nb % 100, dict); // Converte o restante (tens e unidades).
	temp = join_strings(result, remaining);     // Junta centenas e restante.
	free(result);
	free(remaining);
	return (temp);
}

// -------- Função que converte dezenas (20-99) --------
char	*convert_tens(unsigned int nb, t_dict *dict)
{
	char	*temp;   // Palavra da dezena exata (20,30,40,...)
	char	*result; // Resultado final.

	temp = find_in_dict((nb / 10) * 10, dict); // Procura palavra da dezena (ex: 40 -> "quarenta").
	if (nb % 10 == 0)                           // Se não houver unidade, retorna só a dezena.
		return (ft_strdup(temp));
	result = join_strings(temp, convert_number(nb % 10, dict)); // Junta dezena + unidade (ex: "quarenta dois").
	return (result);
}
