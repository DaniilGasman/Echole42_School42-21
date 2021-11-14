/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:27:52 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/16 20:36:47 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_utils.h"

static size_t	ft_word_len(char const *s, char *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && !ft_isset(s[i], set))
	{
		i++;
		count++;
	}
	return (count);
}

static size_t	ft_word_count(char const *s, char *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_isset(s[i], set))
		{
			count++;
			i += ft_word_len(&s[i], set);
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_word_cpy(char *dst, const char *src, char *set)
{
	int	i;

	i = 0;
	while (src[i] && !ft_isset(src[i], set))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	**ft_free(char **ret, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char *set, int i, int k)
{
	char	**ret;

	if (s == NULL)
		return (NULL);
	ret = malloc((ft_word_count(s, set) + 2) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	while (s[i])
	{
		if (!(ft_isset(s[i], set)))
		{
			ret[k] = malloc(((ft_word_len(&s[i], set) + 2)) * sizeof(char));
			if (ret[k] == NULL)
				return (ft_free(ret, k));
			ft_word_cpy(ret[k++], &s[i], set);
			i += ft_word_len(&s[i], set);
		}
		else
			i++;
	}
	ret[k] = NULL;
	return (ret);
}
