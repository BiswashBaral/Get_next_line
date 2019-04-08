/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndanilov <ndanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 05:19:58 by amedvede          #+#    #+#             */
/*   Updated: 2018/12/06 23:13:14 by ndanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char *str;

	str = (unsigned char *)ptr;
	while (num--)
		*str++ = (unsigned char)value;
	return (ptr);
}
