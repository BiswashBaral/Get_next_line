/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndanilov <ndanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:23:59 by amedvede          #+#    #+#             */
/*   Updated: 2018/12/06 23:14:27 by ndanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i] != 0)
		i++;
	if (s[i] == 0 && s[i] != (char)c)
		return (NULL);
	else if (s[i] == (char)c)
		return ((char *)&s[i]);
	return ((char *)&s[i]);
}
