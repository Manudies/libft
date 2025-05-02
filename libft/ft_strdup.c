/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manupc <manupc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:37 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/02 20:16:56 by manupc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
    char	*str;

    str = malloc(ft_strlen(s1) + 1);
    if (!str)
        return (NULL);
    ft_memcpy(str, s1, ft_strlen(s1) + 1);
    return (str);
}
