/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:49:01 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/17 13:08:00 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h" // Inclui o header com structs e protótipos de funções.

// -------- Função que verifica se uma string contém apenas dígitos --------
int	ft_is_numeric(char *str)
{
	int	i;

	if (!str || !str[0])           // Se a string for NULL ou vazia, retorna 0.
		return (0);
	i = 0;
	while (str[i])                 // Percorre cada caractere da string.
	{
		if (str[i] < '0' || str[i] > '9') // Se encontrar algo que não seja dígito.
			return (0);                   // Retorna 0 (não numérico).
		i++;
	}
	return (1);                     // Retorna 1 se todos os caracteres forem numéricos.
}

// -------- Função que liberta memória de uma lista ligada de dicionário --------
void	free_dict(t_dict *dict)
{
	t_dict	*temp;

	while (dict)                    // Enquanto houver nós na lista.
	{
		temp = dict;                // Guarda nó atual.
		dict = dict->next;          // Avança para o próximo nó.
		free(temp->key);            // Liberta a string da chave.
		free(temp->value);          // Liberta a string do valor.
		free(temp);                 // Liberta o nó em si.
	}
}

// -------- Função que junta duas strings numa só (aloca memória nova) --------
char	*join_strings(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;

	if (!s1 && !s2)                // Se ambas forem NULL, retorna NULL.
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);      // Calcula tamanho da primeira string.
	if (s2)
		len2 = ft_strlen(s2);      // Calcula tamanho da segunda string.
	result = malloc(sizeof(char) * (len1 + len2 + 2)); // +1 para '\0', +1 possível espaço entre strings.
	if (!result)
		return (NULL);             // Retorna NULL se malloc falhar.
	return (copy_join_strings(result, s1, s2, len1)); // Chama função auxiliar para copiar as strings.
}

// -------- Função auxiliar que copia s1 e s2 para result, separadas por espaço --------
char	*copy_join_strings(char *result, char *s1, char *s2, int len1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 && s1[j])             // Copia a primeira string para result.
		result[i++] = s1[j++];
	if (len1 > 0 && s2)             // Se houver conteúdo em s1 e s2, adiciona espaço entre elas.
		result[i++] = ' ';
	j = 0;
	while (s2 && s2[j])             // Copia a segunda string para result.
		result[i++] = s2[j++];
	result[i] = '\0';               // Termina a string com '\0'.
	return (result);                 // Retorna string concatenada.
}
