/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:10:27 by tseo              #+#    #+#             */
/*   Updated: 2021/04/04 18:56:43 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "./srcs/libasm.h"

void	ft_strlen_test(void)
{
	char *test1 = "";
	char *test2 = "Hello World!";
	char *test3 = "abcdefghijklmnopqrstuvwxyz";

	printf("===== TEST FT_STRLEN =====\n");
	printf("CASE 1: %lu %lu\n", strlen(test1), ft_strlen(test1));
	printf("CASE 2: %lu %lu\n", strlen(test2), ft_strlen(test2));
	printf("CASE 3: %lu %lu\n", strlen(test3), ft_strlen(test3));

	// NULL => SEGFAULT
	// printf("NULL: %lu\n", strlen(NULL));
	// printf("NULL: %lu\n", ft_strlen(NULL));

	printf("\n");
}

void	ft_strcpy_test(void)
{
	char dest1[30];
	char dest2[30];
	char *test1 = "";
	char *test2 = "Hello World!";
	char *test3 = "abcdefghijklmnopqrstuvwxyz";

	printf("===== TEST FT_STRCPY =====\n");
	printf("CASE 1: %s %s\n", strcpy(dest1, test1), ft_strcpy(dest2, test1));
	printf("CASE 2: %s %s\n", strcpy(dest1, test2), ft_strcpy(dest2, test2));
	printf("CASE 3: %s %s\n", strcpy(dest1, test3), ft_strcpy(dest2, test3));

	// NULL => SEGFAULT
	// printf("%s\n", strcpy(dest1, NULL));
	// printf("%s\n", ft_strcpy(dest2, NULL));

	printf("\n");
}

void	ft_strcmp_test(void)
{
	char *empty_string = "";
	char *test1 = "a";
	char *test2 = "b";
	char *test3 = "a";
	char *test4 = "libasm";
	char *test5 = "libft";

	printf("===== TEST FT_STRCMP =====\n");
	// both arguments are empty
	printf("Two Empty String TEST 1: %d %d\n", \
	strcmp(empty_string, empty_string), ft_strcmp(empty_string, empty_string));

	// one of arguments is empty string
	printf("One Empty String TEST 2: %d %d\n", \
	strcmp(empty_string, test1), ft_strcmp(empty_string, test1));
	printf("One Empty String TEST 3: %d %d\n", \
	strcmp(test1, empty_string), ft_strcmp(test1, empty_string));

	printf("TEST 4 : %d %d\n", \
	strcmp(test4, test4), ft_strcmp(test4, test4));
	printf("TEST 5 : %d %d\n", \
	strcmp(test5, test4), ft_strcmp(test5, test4));
	printf("TEST 6 : %d %d\n", \
	strcmp(test4, test5), ft_strcmp(test4, test5));

	printf("\n");
}

void	ft_write_test(void)
{
	char *str = "Hello, world!";
	int fd1 = open("sample1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	int fd2 = open("sample2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	int fd3 = open("wrong.txt", O_WRONLY, 0644);
	int fd4;

	printf("===== TEST FT_WRITE =====\n");
	// printf("WRITE: %zd\n", write(1, str, 13));
	// printf("FT_WRITE: %zd\n", ft_write(1, str, 13));
	// printf("WRITE: %zd\n", write(1, "", 0));
	// printf("FT_WRITE: %zd\n", ft_write(1, "", 0));
	// printf("WRITE: %zd\n", write(-7, NULL, 0));
	// printf("FT_WRITE: %zd\n", ft_write(-7, NULL, 0));

	// write in files
	write(fd1, str, 13);
	ft_write(fd2, str, 13);

	// write in wrong file
	// write(fd3, str, 13);
	// ft_write(fd3, str, 13);
	// write(fd4, str, 13);
	// ft_write(fd4, str, 13);

	close(fd1);
	close(fd2);
	printf("\n");
}

void	ft_read_test(void)
{
	int fd1 = open("sample1.txt", O_RDONLY);
	int fd2 = open("sample1.txt", O_RDONLY);
	int fd3 = open("wrong.txt", O_RDONLY);
	char a[10];
	char b[10];
	char str1[50];
	char str2[50];
	char str3[50];
	char str4[50];

	// STDIN TEST
	// read(0, a, sizeof(a));
	// a[9] = 0;
	// printf("%s\n", a);
	// ft_read(0, b, sizeof(b));
	// b[9] = 0;
	// printf("%s\n", b);

	printf("===== TEST FT_READ =====\n");
	printf("TEST READ: %zd %s\n", read(fd1, str1, 50), str1);
	printf("TEST FT_READ: %zd %s\n", ft_read(fd2, str2, 50), str2);
	printf("TEST READ: %zd\n", read(fd3, str3, 50));
	printf("TEST FT_READ: %zd\n", ft_read(fd3, str4, 50));

	close(fd1);
	close(fd2);
	printf("\n");
}

void	ft_strdup_test(void)
{
	char *src = "Hello, world!";
	char *empty = "";
	char *dst1;
	char *dst2;

	printf("===== TEST FT_STRDUP =====\n");
	dst1 = strdup(src);
	dst2 = ft_strdup(src);
	printf("strdup : %s\n", dst1);
	printf("ft_strdup : %s\n", dst2);

	// empty string
	dst1 = strdup(empty);
	dst2 = ft_strdup(empty);
	printf("strdup : %s\n", dst1);
	printf("ft_strdup : %s\n", dst2);

	// NULL => SEGFAULT
	// dst1 = strdup(NULL);
	// dst2 = ft_strdup(NULL);
	// printf("strdup : %s\n", dst1);
	// printf("ft_strdup : %s\n", dst2);

	printf("\n");
}

int		main(void)
{
	// ft_strlen_test();
	// ft_strcpy_test();
	// ft_strcmp_test();
	ft_write_test();
	// ft_read_test();
	// ft_strdup_test();

	return (0);
}
