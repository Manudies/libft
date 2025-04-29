/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:19:24 by mdiestre          #+#    #+#             */
/*   Updated: 2025/04/29 13:25:36 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void ft_bzero(void *s, size_t n)
{
    unsigned char *aux;

    aux = (unsigned char *)s;
    while (n > 0)
    {
        *aux = 0;
        aux++;
        n--;
    }
}
