/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasantos <dasantos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:58:46 by dsilva-c          #+#    #+#             */
/*   Updated: 2025/09/17 13:08:00 by dasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"  // Inclui o header com structs e protótipos de funções.

// -------- Função que escreve uma string no stdout --------
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])                   // Percorre todos os caracteres da string.
	{
		write(1, &str[i], 1);       // Escreve caractere por caractere no terminal.
		i++;
	}
}

// -------- Função que retorna o tamanho de uma string --------
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])                 // Conta os caracteres até ao '\0'.
		len++;
	return (len);                    // Retorna o tamanho total da string.
}

// -------- Função que converte string em inteiro --------
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;                        // Guarda o sinal (+ ou -).
	result = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) // Ignora espaços e caracteres de tabulação/linha.
		i++;
	while (str[i] == '+' || str[i] == '-')               // Lê sinais no início.
	{
		if (str[i] == '-') 
			sign *= -1;             // Alterna o sinal se encontrar '-'.
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')               // Converte dígitos em número.
	{
		result = (result * 10) + (str[i] - '0');        // Multiplica anterior por 10 e soma novo dígito.
		i++;
	}
	return (result * sign);         // Aplica sinal e retorna o inteiro.
}

// -------- Função que duplica uma string --------
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(src);            // Calcula o tamanho da string de origem.
	dest = malloc(sizeof(char) * (len + 1)); // Aloca memória para a nova string (+1 para '\0').
	if (!dest)                       // Verifica se a alocação falhou.
		return (NULL);
	i = 0;
	while (src[i])                    // Copia cada caractere da string de origem.
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';                  // Adiciona terminador de string.
	return (dest);                    // Retorna a nova string duplicada.
}
