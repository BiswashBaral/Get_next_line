/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndanilov <ndanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:07:27 by amedvede          #+#    #+#             */
/*   Updated: 2018/12/06 23:14:44 by ndanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int			i;
	int			j;

	i = -1;
	j = (int)ft_strlen(s1);
	while (*(s2 + ++i) && i < (int)n)
		*(s1 + j++) = *(s2 + i);
	*(s1 + j) = '\0';
	return (s1);
}
