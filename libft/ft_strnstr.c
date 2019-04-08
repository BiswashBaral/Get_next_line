/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndanilov <ndanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:08:01 by amedvede          #+#    #+#             */
/*   Updated: 2018/12/06 23:14:48 by ndanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	itn;
	char	*it1;
	char	*it2;

	if (!*needle)
		return ((void *)haystack);
	while (len-- && *haystack)
	{
		if (*haystack == *needle)
		{
			itn = len;
			it1 = (void *)haystack + 1;
			it2 = (void *)needle + 1;
			while (itn-- && *it1 && *it2 && *it1 == *it2)
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
