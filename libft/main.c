#include <stdio.h>
#include "libft.h"

void ft_ok(int condition, const char *test_name)
{
	if (condition)
		printf("\033[0;32m[OK]\033[0m %s\n", test_name);
	else
		printf("\033[0;31m[KO]\033[0m %s\n", test_name);
}


void test_memset(void)
{
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
}

void test_bzero(void)
{
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
}

void test_memmove(void)
{
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

void test_strlcpy(void)
{
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

void test_strlcat(void)
{
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

void test_toupper(void)
{
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

void test_tolower(void)
{
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

void test_strchr(void)
{
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


int main(void)
{
	// Test ft_isalpha
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

	// Test ft_isdigit
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

	// Test ft_isalnum
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

	// Test ft_isascii
	printf("\033[38;5;214m[TEST FT_ISASCII]\033[0m\n");
	ft_ok(ft_isascii('A') == 1, "ft_isascii('A')");
	ft_ok(ft_isascii(127) == 1, "ft_isascii(127)");
	ft_ok(ft_isascii(0) == 1, "ft_isascii(0)");
	ft_ok(ft_isascii(128) == 0, "ft_isascii(128)");
	ft_ok(ft_isascii(-1) == 0, "ft_isascii(-1)");
	printf("\n");

	// Test ft_isprint
	printf("\033[38;5;214m[TEST FT_ISPRINT]\033[0m\n");
	ft_ok(ft_isprint(' ') == 1, "ft_isprint(' ')");
	ft_ok(ft_isprint('A') == 1, "ft_isprint('A')");
	ft_ok(ft_isprint('~') == 1, "ft_isprint('~')");
	ft_ok(ft_isprint(31) == 0, "ft_isprint(31)");
	ft_ok(ft_isprint(127) == 0, "ft_isprint(127)");
	printf("\n");

	// Test ft_strlen
	printf("\033[38;5;214m[TEST FT_STRLEN]\033[0m\n");
	ft_ok(ft_strlen("ChatGPT") == 7, "ft_strlen(\"ChatGPT\")");
	ft_ok(ft_strlen("hola") == 4, "ft_strlen(\"hola\")");
	ft_ok(ft_strlen("") == 0, "ft_strlen(\"\")");
	ft_ok(ft_strlen("42Urduliz") == 9, "ft_strlen(\"42Urduliz\")");
	printf("\n");

	// Test ft_memset
	printf("\033[38;5;214m[TEST FT_MEMSET]\033[0m\n");
	test_memset();
	printf("\n");

	// Test ft_bzero
	printf("\033[38;5;214m[TEST FT_BZERO]\033[0m\n");
	test_bzero();
	printf("\n");

	// Test ft_memmove
	printf("\033[38;5;214m[TEST FT_MEMMOVE]\033[0m\n");
	test_memmove();

	// Test ft_strlcpy
	printf("\033[38;5;214m[TEST FT_STRLCPY]\033[0m\n");
	test_strlcpy();

	// Test ft_strlcat
	printf("\033[38;5;214m[TEST FT_STRLCAT]\033[0m\n");
	test_strlcat();

	// Test ft_toupper
	printf("\033[38;5;214m[TEST FT_TOUPPER]\033[0m\n");
	test_toupper();

	// Test ft_tolower
	printf("\033[38;5;214m[TEST FT_TOLOWER]\033[0m\n");
	test_tolower();

	// Test ft_strchr
	printf("\033[38;5;214m[TEST FT_STRCHR]\033[0m\n");
	test_strchr();

	return (0);
}

