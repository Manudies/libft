#include <stdio.h>
#include "libft.h"

int g_result = 1;


void ft_ok(int condition, const char *test_name){
	if (condition)
		printf("\033[0;32m[OK]\033[0m %s\n", test_name);
	else
		{
			printf("\033[0;31m[KO]\033[0m %s\n", test_name);
			g_result = 0;
		}
}

void test_isalpha(void){
	printf("\033[38;5;214m[TEST FT_ISALPHA]\033[0m\n");
	ft_ok(ft_isalpha('A') == 1, "ft_isalpha('A')");
	ft_ok(ft_isalpha('z') == 1, "ft_isalpha('z')");
	ft_ok(ft_isalpha('1') == 0, "ft_isalpha('1')");
	ft_ok(ft_isalpha('*') == 0, "ft_isalpha('*')");
	ft_ok(ft_isalpha('a') == 1, "ft_isalpha('a')");
	ft_ok(ft_isalpha('Z') == 1, "ft_isalpha('Z')");
	ft_ok(ft_isalpha('5') == 0, "ft_isalpha('5')");
	ft_ok(ft_isalpha('^') == 0, "ft_isalpha('^')");
	printf("\n");
}

void test_isdigit(void){
	printf("\033[38;5;214m[TEST FT_ISDIGIT]\033[0m\n");
	ft_ok(ft_isdigit('9') == 1, "ft_isdigit('9')");
	ft_ok(ft_isdigit('5') == 1, "ft_isdigit('5')");
	ft_ok(ft_isdigit('0') == 1, "ft_isdigit('1')");
	ft_ok(ft_isdigit('a') == 0, "ft_isdigit('a')");
	ft_ok(ft_isdigit('A') == 0, "ft_isdigit('A')");
	ft_ok(ft_isdigit('Z') == 0, "ft_isdigit('Z')");
	ft_ok(ft_isdigit('z') == 0, "ft_isdigit('z')");
	ft_ok(ft_isdigit(';') == 0, "ft_isdigit(';')");
	printf("\n");
}

void test_isalnum(void){
	printf("\033[38;5;214m[TEST FT_ISALNUM]\033[0m\n");
	ft_ok(ft_isalnum('9') == 1, "ft_isalnum('9')");
	ft_ok(ft_isalnum('5') == 1, "ft_isalnum('5')");
	ft_ok(ft_isalnum('0') == 1, "ft_isalnum('0')");
	ft_ok(ft_isalnum('a') == 1, "ft_isalnum('a')");
	ft_ok(ft_isalnum('-') == 0, "ft_isalnum('-')");
	ft_ok(ft_isalnum('Z') == 1, "ft_isalnum('Z')");
	ft_ok(ft_isalnum('z') == 1, "ft_isalnum('z')");
	ft_ok(ft_isalnum(';') == 0, "ft_isalnum(';')");
	printf("\n");
}

void test_isascii(void){
	printf("\033[38;5;214m[TEST FT_ISASCII]\033[0m\n");
	ft_ok(ft_isascii('A') == 1, "ft_isascii('A')");
	ft_ok(ft_isascii(127) == 1, "ft_isascii(127)");
	ft_ok(ft_isascii(0) == 1, "ft_isascii(0)");
	ft_ok(ft_isascii(128) == 0, "ft_isascii(128)");
	ft_ok(ft_isascii(-1) == 0, "ft_isascii(-1)");
	printf("\n");
}

void test_isprint(void){
	printf("\033[38;5;214m[TEST FT_ISPRINT]\033[0m\n");
	ft_ok(ft_isprint(' ') == 1, "ft_isprint(' ')");
	ft_ok(ft_isprint('A') == 1, "ft_isprint('A')");
	ft_ok(ft_isprint('~') == 1, "ft_isprint('~')");
	ft_ok(ft_isprint(31) == 0, "ft_isprint(31)");
	ft_ok(ft_isprint(127) == 0, "ft_isprint(127)");
	printf("\n");
}

void test_strlen(void){
	printf("\033[38;5;214m[TEST FT_STRLEN]\033[0m\n");
	ft_ok(ft_strlen("ChatGPT") == 7, "ft_strlen(\"ChatGPT\")");
	ft_ok(ft_strlen("hola") == 4, "ft_strlen(\"hola\")");
	ft_ok(ft_strlen("") == 0, "ft_strlen(\"\")");
	ft_ok(ft_strlen("42Urduliz") == 9, "ft_strlen(\"42Urduliz\")");
	printf("\n");
}

void test_memset(void){
	printf("\033[38;5;214m[TEST FT_MEMSET]\033[0m\n");
    char buffer[6] = "aaaaa"; // Crea un buffer inicializado a "aaaaa"

    // Aplicamos ft_memset para cambiar los 3 primeros caracteres a 'X'
	printf("char buffer[6] = 'aaaaa';\n");
    printf("ft_memset(buffer, 'X', 3)\n");
	ft_memset(buffer, 'X', 3);

    // Ahora buffer debería ser "XXXaa"
    ft_ok(buffer[0] == 'X', "ft_memset buffer[0] == 'X'");
    ft_ok(buffer[1] == 'X', "ft_memset buffer[1] == 'X'");
    ft_ok(buffer[2] == 'X', "ft_memset buffer[2] == 'X'");
    ft_ok(buffer[3] == 'a', "ft_memset buffer[3] == 'a'");
    ft_ok(buffer[4] == 'a', "ft_memset buffer[4] == 'a'");
	printf("\n");

	printf("ft_memset(buffer, 'Z', 5)\n");
	ft_memset(buffer, 'Z', 5); // Cambiamos las 5 posiciones
	ft_ok(buffer[0] == 'Z', "ft_memset full buffer[0] == 'Z'");
	ft_ok(buffer[1] == 'Z', "ft_memset full buffer[1] == 'Z'");
	ft_ok(buffer[2] == 'Z', "ft_memset full buffer[2] == 'Z'");
	ft_ok(buffer[3] == 'Z', "ft_memset full buffer[3] == 'Z'");
	ft_ok(buffer[4] == 'Z', "ft_memset full buffer[4] == 'Z'");
	printf("\n");

	printf("ft_memset(buffer, '\\0', 5) \n");
	ft_memset(buffer, '\0', 5); // Rellenamos todo de ceros
	ft_ok(buffer[0] == '\0', "ft_memset null buffer[0] == '\\0'");
	ft_ok(buffer[1] == '\0', "ft_memset null buffer[1] == '\\0'");
	ft_ok(buffer[2] == '\0', "ft_memset null buffer[2] == '\\0'");
	ft_ok(buffer[3] == '\0', "ft_memset null buffer[3] == '\\0'");
	ft_ok(buffer[4] == '\0', "ft_memset null buffer[4] == '\\0'");
	printf("\n");

	// Primero volvemos a rellenar el buffer con 'A'
	printf("ft_memset(buffer, 'A', 5)\n");
	ft_memset(buffer, 'A', 5);

	// Ahora llamamos a ft_memset con len = 0
	printf("ft_memset(buffer, 'X', 0)\n");
	ft_memset(buffer, 'X', 0);

	// Verificamos que nada cambió
	ft_ok(buffer[0] == 'A', "ft_memset len=0 buffer[0] == 'A'");
	ft_ok(buffer[1] == 'A', "ft_memset len=0 buffer[1] == 'A'");
	ft_ok(buffer[2] == 'A', "ft_memset len=0 buffer[2] == 'A'");
	ft_ok(buffer[3] == 'A', "ft_memset len=0 buffer[3] == 'A'");
	ft_ok(buffer[4] == 'A', "ft_memset len=0 buffer[4] == 'A'");

	printf("\n");
}

void test_bzero(void){
	printf("\033[38;5;214m[TEST FT_BZERO]\033[0m\n");
	printf("char buffer[6] = 'abcde'\n");
    char buffer[6] = "abcde"; // Buffer inicializado con letras

    // Aplicamos ft_bzero para poner a cero los 3 primeros caracteres
	printf("ft_bzero(buffer, 3)\n");
    ft_bzero(buffer, 3);

    ft_ok(buffer[0] == '\0', "ft_bzero buffer[0] == '\\0'");
    ft_ok(buffer[1] == '\0', "ft_bzero buffer[1] == '\\0'");
    ft_ok(buffer[2] == '\0', "ft_bzero buffer[2] == '\\0'");
    ft_ok(buffer[3] == 'd', "ft_bzero buffer[3] == 'd'");
    ft_ok(buffer[4] == 'e', "ft_bzero buffer[4] == 'e'");

	printf("\n");
}

void test_memcpy(void){
	printf("\033[38;5;214m[TEST FT_MEMCPY]\033[0m\n");

	// Caso 1: copiar n bytes normales
	char src1[] = "12345";
	char dst1[6] = "aaaaa";
	ft_memcpy(dst1, src1, 5);
	ft_ok(dst1[0] == '1', "ft_memcpy dst1[0] == '1'");
	ft_ok(dst1[1] == '2', "ft_memcpy dst1[1] == '2'");
	ft_ok(dst1[4] == '5', "ft_memcpy dst1[4] == '5'");

	// Caso 2: copiar 0 bytes (no debe tocar nada)
	char src2[] = "abcde";
	char dst2[] = "zzzzz";
	ft_memcpy(dst2, src2, 0);
	ft_ok(dst2[0] == 'z', "ft_memcpy len=0 no toca dst2[0]");

	// Caso 3: src y dst apuntan a lo mismo
	char buffer1[] = "abcd";
	ft_memcpy(buffer1, buffer1, 4);
	ft_ok(buffer1[0] == 'a', "ft_memcpy src==dst no rompe nada");

	// Caso 4: copiar bytes con \0 en medio
	char src3[] = {'a', '\0', 'c', 'd'};
	char dst3[4] = {'x', 'x', 'x', 'x'};
	ft_memcpy(dst3, src3, 4);
	ft_ok(dst3[1] == '\0', "ft_memcpy copia '\\0'");
	ft_ok(dst3[3] == 'd', "ft_memcpy dst3[3] == 'd'");

	// Caso 5: copiar bytes extendidos (\200-\377)
	unsigned char src4[] = {0, 128, 255};
	unsigned char dst4[3] = {9, 9, 9};
	ft_memcpy(dst4, src4, 3);
	ft_ok(dst4[1] == 128, "ft_memcpy copia byte 128");
	ft_ok(dst4[2] == 255, "ft_memcpy copia byte 255");

	printf("\n");
}

void test_memmove(void){
	printf("\033[38;5;214m[TEST FT_MEMMOVE]\033[0m\n");
	printf("char src1[6] = '12345'\n");
	printf("char dst1[6] = 'aaaaa'\n");
	char src1[6] = "12345";
	char dst1[6] = "aaaaa";
	printf("ft_memmove(dst1, src1, 5)\n");
	ft_memmove(dst1, src1, 5);
	ft_ok(dst1[0] == '1', "ft_memmove sin solape dst1[0] == '1'");
	ft_ok(dst1[1] == '2', "ft_memmove sin solape dst1[1] == '2'");
	ft_ok(dst1[4] == '5', "ft_memmove sin solape dst1[4] == '5'");

	printf("char src2[5] = 'zzzz'\n");
	printf("char dst2[5] = 'yyyy'\n");
	char src2[5] = "zzzz";
	char dst2[5] = "yyyy";
	printf("ft_memmove(dst2, src2, 0)\n");
	ft_memmove(dst2, src2, 0);
	ft_ok(dst2[0] == 'y', "ft_memmove len=0 dst2[0] unchanged");

	printf("char buffer1[5] = 'aaaa'\n");
	char buffer1[5] = "aaaa";
	printf("ft_memmove(buffer1, buffer1, 4)\n");
	ft_memmove(buffer1, buffer1, 4);
	ft_ok(buffer1[0] == 'a', "ft_memmove src==dst buffer[0] == 'a'");

	printf("char buffer2[10] = 'abcdefghi'\n");
	char buffer2[10] = "abcdefghi";
	printf("ft_memmove(buffer2 + 2, buffer2, 5)\n");
	ft_memmove(buffer2 + 2, buffer2, 5);
	ft_ok(buffer2[2] == 'a', "ft_memmove solapado buffer2[2] == 'a'");
	ft_ok(buffer2[3] == 'b', "ft_memmove solapado buffer2[3] == 'b'");
	ft_ok(buffer2[6] == 'e', "ft_memmove solapado buffer2[6] == 'e'");
	
	printf("\n");
}

void test_strlcpy(void){
	printf("\033[38;5;214m[TEST FT_STRLCPY]\033[0m\n");
	char src1[] = "Hola";
	char dst1[10];

	size_t len1 = ft_strlcpy(dst1, src1, 10);
	ft_ok(len1 == 4, "ft_strlcpy len == 4 (src1)");
	ft_ok(dst1[0] == 'H', "ft_strlcpy dst1[0] == 'H'");
	ft_ok(dst1[3] == 'a', "ft_strlcpy dst1[3] == 'a'");
	ft_ok(dst1[4] == '\0', "ft_strlcpy dst1[4] == '\\0'");

	// Caso: tamaño exacto
	char dst2[5];
	size_t len2 = ft_strlcpy(dst2, src1, 5);
	ft_ok(len2 == 4, "ft_strlcpy len == 4 (dst2)");
	ft_ok(dst2[4] == '\0', "ft_strlcpy dst2[4] == '\\0'");

	// Caso: dst más pequeño que src (truncamiento)
	char dst3[3];
	size_t len3 = ft_strlcpy(dst3, "ABCDEFG", 3);
	ft_ok(len3 == 7, "ft_strlcpy len == 7 (src too big)");
	ft_ok(dst3[0] == 'A', "ft_strlcpy dst3[0] == 'A'");
	ft_ok(dst3[1] == 'B', "ft_strlcpy dst3[1] == 'B'");
	ft_ok(dst3[2] == '\0', "ft_strlcpy dst3[2] == '\\0'");

	// Caso: size == 0
	char dst4[5] = "XXXX";
	size_t len4 = ft_strlcpy(dst4, "Test", 0);
	ft_ok(len4 == 4, "ft_strlcpy len == 4 (size == 0)");
	ft_ok(dst4[0] == 'X', "ft_strlcpy dst4 unchanged if size == 0");

	printf("\n");
}

void test_strlcat(void){
	printf("\033[38;5;214m[TEST FT_STRLCAT]\033[0m\n");
	// Caso 1: espacio suficiente para concatenar todo
	char buffer1[20] = "Hello, ";
	size_t result1 = ft_strlcat(buffer1, "world!", 20);
	ft_ok(result1 == 13, "ft_strlcat full concat return == 13");
	ft_ok(buffer1[7] == 'w', "ft_strlcat buffer1[7] == 'w'");
	ft_ok(buffer1[12] == '!', "ft_strlcat buffer1[12] == '!'");
	ft_ok(buffer1[13] == '\0', "ft_strlcat ends with '\\0'");

	// Caso 2: espacio limitado, truncamiento esperado
	char buffer2[10] = "42";
	size_t result2 = ft_strlcat(buffer2, "Urduliz", 10);
	ft_ok(result2 == 9, "ft_strlcat truncado return == 9");
	ft_ok(buffer2[9] == '\0', "ft_strlcat truncado ends with '\\0'");

	// Caso 3: size menor que dst_len, no se concatena
	char buffer3[5] = "Data";
	size_t result3 = ft_strlcat(buffer3, "42", 2);
	ft_ok(result3 == 2 + 2, "ft_strlcat no copy return == 4");
	ft_ok(buffer3[0] == 'D', "ft_strlcat no copy keeps dst[0]");

	// Caso 4: size == 0, no se concatena
	char buffer4[10] = "Inicio";
	size_t result4 = ft_strlcat(buffer4, "Nada", 0);
	ft_ok(result4 == ft_strlen("Nada"), "ft_strlcat size=0 return == strlen(src)");

	printf("\n");
}

void test_toupper(void){
	printf("\033[38;5;214m[TEST FT_TOUPPER]\033[0m\n");
	// Letras minúsculas → deben convertirse
	ft_ok(ft_toupper('a') == 'A', "ft_toupper('a') == 'A'");
	ft_ok(ft_toupper('m') == 'M', "ft_toupper('m') == 'M'");
	ft_ok(ft_toupper('z') == 'Z', "ft_toupper('z') == 'Z'");

	// Letras mayúsculas → no cambian
	ft_ok(ft_toupper('A') == 'A', "ft_toupper('A') == 'A'");
	ft_ok(ft_toupper('Z') == 'Z', "ft_toupper('Z') == 'Z'");

	// Números y símbolos → no cambian
	ft_ok(ft_toupper('0') == '0', "ft_toupper('0') == '0'");
	ft_ok(ft_toupper('9') == '9', "ft_toupper('9') == '9'");
	ft_ok(ft_toupper('!') == '!', "ft_toupper('!') == '!'");
	ft_ok(ft_toupper(' ') == ' ', "ft_toupper(' ') == ' '");

	printf("\n");
}

void test_tolower(void){
	printf("\033[38;5;214m[TEST FT_TOLOWER]\033[0m\n");
	// Letras mayúsculas → deben convertirse
	ft_ok(ft_tolower('A') == 'a', "ft_tolower('A') == 'a'");
	ft_ok(ft_tolower('M') == 'm', "ft_tolower('M') == 'm'");
	ft_ok(ft_tolower('Z') == 'z', "ft_tolower('Z') == 'z'");

	// Letras minúsculas → no cambian
	ft_ok(ft_tolower('a') == 'a', "ft_tolower('a') == 'a'");
	ft_ok(ft_tolower('z') == 'z', "ft_tolower('z') == 'z'");

	// Números y símbolos → no cambian
	ft_ok(ft_tolower('0') == '0', "ft_tolower('0') == '0'");
	ft_ok(ft_tolower('9') == '9', "ft_tolower('9') == '9'");
	ft_ok(ft_tolower('@') == '@', "ft_tolower('@') == '@'");
	ft_ok(ft_tolower(' ') == ' ', "ft_tolower(' ') == ' '");

	printf("\n");
}

void test_strchr(void){
	printf("\033[38;5;214m[TEST FT_STRCHR]\033[0m\n");
	// Caso 1: carácter en medio
	char *s1 = "42Urduliz";
	char *res1 = ft_strchr(s1, 'r');
	ft_ok(res1 == &s1[3], "ft_strchr(s1, 'r') apunta a s1[3]");

	// Caso 2: primer carácter
	char *res2 = ft_strchr(s1, '4');
	ft_ok(res2 == s1, "ft_strchr(s1, '4') apunta al inicio");

	// Caso 3: último carácter
	char *res3 = ft_strchr(s1, 'z');
	ft_ok(res3 == &s1[8], "ft_strchr(s1, 'z') apunta a s1[8]");

	// Caso 4: carácter no está
	char *res4 = ft_strchr(s1, 'X');
	ft_ok(res4 == NULL, "ft_strchr(s1, 'X') == NULL");

	// Caso 5: buscar '\0'
	char *res5 = ft_strchr(s1, '\0');
	ft_ok(res5 == &s1[9], "ft_strchr(s1, '\\0') apunta al final");

	printf("\n");
}

void test_strrchr(void){
	printf("\033[38;5;214m[TEST FT_STRRCPY]\033[0m\n");
	char *s1 = "banana";

	// Última aparición de 'a'
	char *res1 = ft_strrchr(s1, 'a');
	ft_ok(res1 == &s1[5], "ft_strrchr(s1, 'a') apunta a s1[5]");

	// Primera y última aparición son la misma
	char *s2 = "chat";
	char *res2 = ft_strrchr(s2, 'c');
	ft_ok(res2 == s2, "ft_strrchr(s2, 'c') apunta al inicio");

	// Carácter no existente
	char *res3 = ft_strrchr(s1, 'x');
	ft_ok(res3 == NULL, "ft_strrchr(s1, 'x') == NULL");

	// Buscar '\0'
	char *res4 = ft_strrchr(s1, '\0');
	ft_ok(res4 == &s1[6], "ft_strrchr(s1, '\\0') apunta al final");

	printf("\n");
}

void test_strncmp(void){
	printf("\033[38;5;214m[TEST FT_STRNCMP]\033[0m\n");

	// Comparación igual hasta n
	ft_ok(ft_strncmp("hola", "hola", 4) == 0, "strncmp iguales hasta n");

	// Primera diferencia en mitad
	ft_ok(ft_strncmp("hola", "holi", 4) < 0, "strncmp diferencia en última letra");


	// Diferencia al principio
	ft_ok(ft_strncmp("cola", "hola", 4) < 0, "strncmp diferencia al principio");

	// Diferencia justo después del límite → debe devolver 0
	ft_ok(ft_strncmp("abcdef", "abcxyz", 3) == 0, "strncmp iguales en los 3 primeros");

	// Una cadena vacía
	ft_ok(ft_strncmp("", "", 1) == 0, "strncmp dos vacías con n=1");
	ft_ok(ft_strncmp("", "a", 1) < 0, "strncmp \"\" < \"a\" con n=1");
	ft_ok(ft_strncmp("a", "", 1) > 0, "strncmp \"a\" > \"\" con n=1");

	// n = 0 → debe devolver 0 siempre
	ft_ok(ft_strncmp("abc", "xyz", 0) == 0, "strncmp con n=0 siempre == 0");

	// Cadenas largas iguales, n corta
	ft_ok(ft_strncmp("abcdefghijklmnop", "abcdefghijklmnop", 5) == 0, "strncmp largas, iguales hasta 5");

	// Cadenas largas, primera diferencia fuera del límite
	ft_ok(ft_strncmp("abcdef", "abcdez", 5) == 0, "strncmp diferencia fuera de límite");

	// Diferencia con carácter negativo (signed/unsigned test)
	ft_ok(ft_strncmp("\200", "\0", 1) > 0, "strncmp compara como unsigned char");

	printf("\n");
}

void test_memchr(void){
	printf("\033[38;5;214m[TEST FT_MEMCHR]\033[0m\n");

	// Caso 1: carácter presente en medio
	char data1[] = "42Urduliz";
	void *res1 = ft_memchr(data1, 'r', 10);
	ft_ok(res1 == &data1[3], "ft_memchr(data1, 'r', 10) → data1[3]");

	// Caso 2: carácter al final
	void *res2 = ft_memchr(data1, 'z', 10);
	ft_ok(res2 == &data1[8], "ft_memchr(data1, 'z', 10) → data1[8]");

	// Caso 3: carácter no está
	void *res3 = ft_memchr(data1, 'X', 10);
	ft_ok(res3 == NULL, "ft_memchr(data1, 'X', 10) == NULL");

	// Caso 4: buscar '\0'
	char data2[] = "abc\0def";
	void *res4 = ft_memchr(data2, '\0', 7);
	ft_ok(res4 == &data2[3], "ft_memchr(data2, '\\0', 7) → data2[3]");

	// Caso 5: n = 0 → nunca encuentra nada
	char data3[] = "abcdef";
	void *res5 = ft_memchr(data3, 'a', 0);
	ft_ok(res5 == NULL, "ft_memchr(data3, 'a', 0) == NULL");

	// Caso 6: byte extendido (\200)
	unsigned char data4[] = {0, 1, 127, 128, 255};
	void *res6 = ft_memchr(data4, 255, 5);
	ft_ok(res6 == &data4[4], "ft_memchr(data4, 255, 5) → data4[4]");

	printf("\n");
}

void test_memcmp(void){
	printf("\033[38;5;214m[TEST FT_MEMCMP]\033[0m\n");

	// Caso 1: bloques idénticos
	char a1[] = "abcde";
	char a2[] = "abcde";
	ft_ok(ft_memcmp(a1, a2, 5) == 0, "memcmp bloques iguales");

	// Caso 2: primera diferencia al principio
	char b1[] = "abc";
	char b2[] = "xbc";
	ft_ok(ft_memcmp(b1, b2, 3) < 0, "memcmp diferencia al inicio");

	// Caso 3: primera diferencia en el medio
	char c1[] = "aXc";
	char c2[] = "aYc";
	ft_ok(ft_memcmp(c1, c2, 3) < 0, "memcmp diferencia en medio");

	// Caso 4: misma cadena, pero n = 0
	ft_ok(ft_memcmp("abc", "xyz", 0) == 0, "memcmp con n = 0 → igual");

	// Caso 5: comparación corta, no alcanza diferencias
	ft_ok(ft_memcmp("abcdef", "abcXYZ", 3) == 0, "memcmp iguales en los primeros 3 bytes");

	// Caso 6: diferencia en byte con valor >127 (signed vs unsigned)
	unsigned char d1[] = {0x01, 0x7F, 0x80};
	unsigned char d2[] = {0x01, 0x7F, 0x00};
	ft_ok(ft_memcmp(d1, d2, 3) > 0, "memcmp bytes extendidos unsigned (0x80 > 0x00)");

	// Caso 7: buffer con \0 en medio
	char e1[] = {'a', '\0', 'c'};
	char e2[] = {'a', '\0', 'd'};
	ft_ok(ft_memcmp(e1, e2, 3) < 0, "memcmp no se detiene en '\\0'");

	printf("\n");
}

void test_strnstr(void){
	printf("\033[38;5;214m[TEST FT_STRNSTR]\033[0m\n");

	// Caso 1: needle dentro de haystack
	char *hay1 = "Esto es una cadena de prueba";
	char *res1 = ft_strnstr(hay1, "cadena", 25);
	ft_ok(res1 == &hay1[12], "ft_strnstr encuentra 'cadena' en haystack");

	// Caso 2: needle justo al final, pero cabe
	char *res2 = ft_strnstr("123456789", "789", 9);
	ft_ok(res2 != NULL && res2[0] == '7', "ft_strnstr encuentra al final con len suficiente");

	// Caso 3: needle no cabe dentro de len
	char *res3 = ft_strnstr("123456789", "789", 8);
	ft_ok(res3 == NULL, "ft_strnstr no encuentra si len es demasiado corto");

	// Caso 4: needle vacío → debe devolver haystack
	char *res4 = ft_strnstr("abc", "", 3);
	ft_ok(ft_strncmp(res4, "abc", 3) == 0, "...");

	// Caso 5: len = 0 → siempre NULL, excepto si needle vacío
	char *res5 = ft_strnstr("abc", "a", 0);
	ft_ok(res5 == NULL, "ft_strnstr len=0 y needle != '' devuelve NULL");

	char *res6 = ft_strnstr("abc", "", 0);
	ft_ok(ft_strncmp(res6, "abc", 3) == 0, "...");

	// Caso 6: no aparece en haystack
	char *res7 = ft_strnstr("abcdef", "xyz", 6);
	ft_ok(res7 == NULL, "ft_strnstr con needle inexistente devuelve NULL");

	printf("\n");
}

void test_atoi(void){
	printf("\033[38;5;214m[TEST FT_ATOI]\033[0m\n");

	// Casos normales
	ft_ok(ft_atoi("0") == 0, "ft_atoi(\"0\") == 0");
	ft_ok(ft_atoi("42") == 42, "ft_atoi(\"42\") == 42");
	ft_ok(ft_atoi("-42") == -42, "ft_atoi(\"-42\") == -42");
	ft_ok(ft_atoi("+123") == 123, "ft_atoi(\"+123\") == 123");

	// Espacios iniciales
	ft_ok(ft_atoi("   7") == 7, "ft_atoi(\"   7\") == 7");
	ft_ok(ft_atoi("\t\n\r  -99") == -99, "ft_atoi(\"\\t\\n\\r  -99\") == -99");

	// Texto después del número
	ft_ok(ft_atoi("123abc") == 123, "ft_atoi(\"123abc\") == 123");

	// Solo signo
	ft_ok(ft_atoi("+") == 0, "ft_atoi(\"+\") == 0");
	ft_ok(ft_atoi("-") == 0, "ft_atoi(\"-\") == 0");

	// Cadena vacía
	ft_ok(ft_atoi("") == 0, "ft_atoi(\"\") == 0");

	// Límite de int
	ft_ok(ft_atoi("2147483647") == 2147483647, "ft_atoi(\"2147483647\") == INT_MAX");
	ft_ok(ft_atoi("-2147483648") == -2147483648, "ft_atoi(\"-2147483648\") == INT_MIN");

	printf("\n");
}

void test_calloc(void){
	printf("\033[38;5;214m[TEST FT_CALLOC]\033[0m\n");

	// Caso normal
	char *str = ft_calloc(5, sizeof(char));
	ft_ok(str != NULL, "ft_calloc(5, sizeof(char)) != NULL");

	// Todos los bytes deben estar a 0
	int all_zero = 1;
	for (int i = 0; i < 5; i++)
		if (str[i] != 0)
			all_zero = 0;
	ft_ok(all_zero, "ft_calloc inicializa todo a cero");
	free(str);

	// count = 0
	char *empty1 = ft_calloc(0, sizeof(char));
	ft_ok(empty1 != NULL, "ft_calloc(0, size) devuelve puntero válido o NULL permitido");
	free(empty1);

	// size = 0
	char *empty2 = ft_calloc(5, 0);
	ft_ok(empty2 != NULL, "ft_calloc(count, 0) devuelve puntero válido o NULL permitido");
	free(empty2);

	printf("\n");
}

void test_strdup(void){
	printf("\033[38;5;214m[TEST FT_STRDUP]\033[0m\n");

	const char *src = "hola mundo";
	char *copy = ft_strdup(src);

	ft_ok(copy != NULL, "ft_strdup devuelve puntero válido");
	ft_ok(ft_strncmp(copy, src, ft_strlen(src)) == 0, "ft_strdup copia correctamente");
	ft_ok(copy != src, "ft_strdup devuelve un puntero distinto al original");
	free(copy);

	// Caso vacío
	char *empty = ft_strdup("");
	ft_ok(empty != NULL, "ft_strdup(\"\") != NULL");
	ft_ok(empty[0] == '\0', "ft_strdup(\"\") devuelve cadena vacía");
	free(empty);

	printf("\n");
}


int main(void)
{
	// Test ft_isalpha
	test_isalpha();

	// Test ft_isdigit
	test_isdigit();

	// Test ft_isalnum
	test_isalnum();

	// Test ft_isascii
	test_isascii();

	// Test ft_isprint
	test_isprint();

	// Test ft_strlen
	test_strlen();

	// Test ft_memset
	test_memset();

	// Test ft_bzero
	test_bzero();

	// Test ft_memcpy
	test_memcpy();	

	// Test ft_memmove
	test_memmove();

	// Test ft_strlcpy
	test_strlcpy();

	// Test ft_strlcat
	test_strlcat();

	// Test ft_toupper
	test_toupper();

	// Test ft_tolower

	test_tolower();

	// Test ft_strchr
	test_strchr();
	
	//Test strrchr
	test_strrchr();

	//Test strncmp
	test_strncmp();

	//Test memchr
	test_memchr();

	//Test memcmp
	test_memcmp();

	//Test strnstr
	test_strnstr();

	//Test stoi
	test_atoi();

	//Test calloc
	test_calloc();

	//Test strdup
	test_strdup();

	if (g_result)
	printf("\n\033[0;32m✅ TODOS LOS TESTS PASADOS\033[0m\n\n");
	else
	printf("\n\033[0;31m❌ ALGÚN TEST HA FALLADO\033[0m\n\n");

	return (0);
}

