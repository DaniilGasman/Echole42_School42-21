/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:38:26 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/17 17:00:35 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int	line_init(char **line, int reco, int ret)
{
	*line = malloc((reco + 1) * sizeof(char));
	if (*line == NULL)
		return (-1);
	((*line)[reco]) = '\0';
	return (ret);
}

static int	recursive_get_line(char **line, int fd, int reco)
{
	char	buffer;
	int		ret;

	ret = read(fd, &buffer, 1);
	if (ret == 1)
	{
		if (buffer == '\n' || buffer == '\0')
			return (line_init(line, reco, 1));
		else
		{
			ret = recursive_get_line(line, fd, reco + 1);
			if ((*line) != NULL)
				((*line)[reco]) = buffer;
			return (ret);
		}
	}
	else if (ret == 0)
		return (line_init(line, reco, 0));
	return (-1);
}

int	ft_recurcive_gnl(int fd, char **line)
{
	char	buffer;

	if (fd < 0 || !line || read(fd, &buffer, 0) < 0)
		return (-1);
	*line = NULL;
	return (recursive_get_line(line, fd, 0));
}
