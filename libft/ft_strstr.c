/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndanilov <ndanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:08:20 by amedvede          #+#    #+#             */
/*   Updated: 2018/12/06 23:14:51 by ndanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*it1;
	char	*it2;

	if (!*needle)
		return ((void *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			it1 = (void *)haystack + 1;
			it2 = (void *)needle + 1;
			while (*it1 && *it2 && *it1 == *it2)
			{
				++it1;
				++it2;
			}
			if (!*it2)
				return ((void *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
