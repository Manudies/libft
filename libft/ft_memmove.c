//Cabecera
//Cabecera
//Cabecera
//Cabecera
//Cabecera
//Cabecera
//Cabecera
//Cabecera
//Cabecera
//Cabecera
//Cabecera


#include"libft.h"

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *aux_dst;
	const unsigned char *aux_src;

	aux_dst = (unsigned char *)dst;
	aux_src = (const unsigned char *)src;

	if (dst == src || len == 0)
		return (dst);
	if (aux_dst < aux_src)
		return (ft_memcpy(dst, src, len));
	while (len > 0)
	{
		len--;
		aux_dst[len] = aux_src[len];
	}

	return (dst);
}
