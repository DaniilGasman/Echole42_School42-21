/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:46:17 by nfedayki          #+#    #+#             */
/*   Updated: 2020/11/25 18:50:02 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char		*ft_strndup(const char *s, size_t n)
{
	char	*str_one_word;

	if (!(str_one_word = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	str_one_word = ft_memcpy(str_one_word, s, n);
	str_one_word[n] = '\0';
	return (str_one_word);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		find_word;
	int		write_word;
	char	**tab_word;

	i = 0;
	write_word = 0;
	if (!(tab_word = malloc(sizeof(char*) * ((ft_word_count(s, c)) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		find_word = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > find_word)
		{
			tab_word[write_word] = ft_strndup(s + find_word, i - find_word);
			write_word++;
		}
	}
	tab_word[write_word] = NULL;
	return (tab_word);
}
