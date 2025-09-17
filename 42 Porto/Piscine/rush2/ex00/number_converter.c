/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:43:27 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/17 13:08:00 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h" // Inclui o header com structs e protótipos de funções.

// -------- Função principal que converte um número em texto --------
char	*convert_number(unsigned int nb, t_dict *dict)
{
	char	*result;  // Ponteiro para armazenar a string resultante.

	if (nb == 0)                       // Caso especial: zero.
		return (ft_strdup(find_in_dict(0, dict))); // Retorna "zero" usando o dicionário.

	result = find_in_dict(nb, dict);   // Tenta encontrar número diretamente no dicionário.
	if (result && nb < 20)             // Se encontrado e menor que 20 (0-19), retorna a palavra.
		return (ft_strdup(result));

	if (nb < 100)                      // Números entre 20 e 99.
		return (convert_tens(nb, dict));   // Chama função que trata dezenas.

	if (nb < 1000)                     // Números entre 100 e 999.
		return (convert_hundreds(nb, dict)); // Chama função que trata centenas.

	if (nb < 1000000)                  // Números entre 1.000 e 999.999.
		return (convert_scale(nb, 1000, dict)); // Trata milhares.

	if (nb < 1000000000)               // Números entre 1 milhão e 999 milhões.
		return (convert_scale(nb, 1000000, dict)); // Trata milhões.

	return (NULL);                     // Se número for maior que 999.999.999, não suporta.
}
