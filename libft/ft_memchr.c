/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manupc <manupc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:21 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/02 18:51:07 by manupc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char	*aux;
    size_t		i;

    aux = (const unsigned char *)s;
    i = 0;
    while (n > 0)
    {
        if (aux[i] == (unsigned char)c)
            return ((void *)aux + i);
        i++;
        n--;
    }
    return (NULL);
}