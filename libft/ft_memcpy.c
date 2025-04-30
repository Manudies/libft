//CABECERA
//CABECERA
//CABECERA
//CABECERA
//CABECERA
//CABECERA
//CABECERA
//CABECERA
//CABECERA
//CABECERA
//CABECERA


#include"libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *aux_dst;
    unsigned char *aux_src;

    aux_dst = (unsigned char *)dst;
    aux_src = (unsigned char *)src;
    if (dst == src)
        return (dst);
    while (n > 0)
    {
        *aux_dst = *aux_src;
        aux_dst++;
        aux_src++;
        n--;
    }
    return (dst);
}