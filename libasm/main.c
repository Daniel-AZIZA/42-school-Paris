/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:53:58 by daziza            #+#    #+#             */
/*   Updated: 2021/03/13 19:54:00 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	ft_main_strlen(void)
{
	printf("--------------------------------------------------\n");
	printf("-------------------ft_strlen----------------------\n");
	printf("--------------------------------------------------\n\n");
	
	printf("ft_strlen :\n");
	printf("%zd\n", ft_strlen("hello world !"));
	printf("strlen :\n");
	printf("%zd\n", strlen("hello world !"));
	printf("\n------------------\n");

	printf("ft_strlen :\n");
	printf("%zd\n", ft_strlen("a"));
	printf("strlen : \n");
	printf("%zd\n", strlen("a"));
	printf("\n------------------\n");

	printf("ft_strlen : \n");
	printf("%zd\n", ft_strlen("sjnrzyjzryjzyr"));
	printf("strlen : \n");
	printf("%zd\n", strlen("sjnrzyjzryjzyr"));
	printf("\n------------------\n");

	printf("ft_strlen : \n");
	printf("%zd\n", ft_strlen(""));
	printf("strlen : \n");
	printf("%zd\n\n", strlen(""));	
}

void	ft_main_strcpy(void)
{
	printf("--------------------------------------------------\n");
	printf("-------------------ft_strcpy----------------------\n");
	printf("--------------------------------------------------\n\n");
	
	char	str1[] = "hello wolrd !";
	char	str2[] = "a";
	char	str3[] = "abcdef";
	char	str4[] = " ";
	char	str5[] = "-_-";
	char	str6[] = "123";
	char	str7[] = "             ";

	printf("ft_strcpy :\n");
	printf("%s\n", ft_strcpy(str7, str1));
	printf("strcpy :\n");
	printf("%s\n\n", strcpy(str7, str1));

	printf("ft_strcpy :\n");
	printf("%s\n", ft_strcpy(str1, str2));
	printf("strcpy :\n");
	printf("%s\n\n", strcpy(str1, str2));

	printf("ft_strcpy :\n");
	printf("%s\n", ft_strcpy(str3, str4));
	printf("strcpy :\n");
	printf("%s\n\n", strcpy(str3, str4));

	printf("ft_strcpy :\n");
	printf("%s\n", ft_strcpy(str5, str6));
	printf("strcpy :\n");
	printf("%s\n\n", strcpy(str5, str6));}

void	ft_main_strcmp(void)
{
	printf("--------------------------------------------------\n");
	printf("-------------------ft_strcmp----------------------\n");
	printf("--------------------------------------------------\n\n");

	printf("ft_strcmp :\n");
	printf("%d\n", ft_strcmp("hello wolrd !", "hello wolrd !"));
	printf("strcmp :\n");
	printf("%d\n\n", strcmp("hello wolrd !", "hello wolrd !"));

	printf("ft_strcmp :\n");
	printf("%d\n", ft_strcmp("", "hello wolrd !"));
	printf("strcmp :\n");
	printf("%d\n\n", strcmp("", "hello wolrd !"));

	printf("ft_strcmp :\n");
	printf("%d\n", ft_strcmp("hehehehe", "hello wolrd !"));
	printf("strcmp :\n");
	printf("%d\n\n", strcmp("hehehehe", "hello wolrd !"));

	printf("ft_strcmp :\n");
	printf("%d\n", ft_strcmp("a", "z"));
	printf("strcmp :\n");
	printf("%d\n\n", strcmp("a", "z"));

	printf("ft_strcmp :\n");
	printf("%d\n", ft_strcmp("z", "a"));
	printf("strcmp :\n");
	printf("%d\n\n", strcmp("z", "a"));
}

void	ft_main_write(void)
{
	printf("--------------------------------------------------\n");
	printf("-------------------ft_write-----------------------\n");
	printf("--------------------------------------------------\n\n");

	ft_write(1, "ft_write :\n", 11);
	printf("\nretour : %zd\n", ft_write(1, "hello wolrd !", 13));
	ft_write(1, "\nwrite :\n", 9) ;
	printf("\nretour : %zd\n", write(1, "hello wolrd !", 13));
	printf("\n---------------------\n\n");
	
	ft_write(1, "ft_write :\n", 11);
	printf("\nretour : %zd\n", ft_write(0, "hello wolrd !", 13));
	ft_write(1, "\nwrite :\n", 9) ;
	printf("\nretour : %zd\n", write(0, "hello wolrd !", 13));
	printf("\n---------------------\n\n");

	ft_write(1, "ft_write :\n", 11);
	printf("\nretour : %zd\n", ft_write(-1, "hello wolrd !", 13));
	ft_write(1, "\nwrite :\n", 9) ;
	printf("\nretour : %zd\n", write(-1, "hello wolrd !", 13));
	printf("\n---------------------\n\n");

	ft_write(1, "ft_write :\n", 11);
	printf("\nretour : %zd\n", ft_write(-10, "hello wolrd !", 13));
	ft_write(1, "\nwrite :\n", 9) ;
	printf("\nretour : %zd\n", write(-10, "hello wolrd !", 13));
	printf("\n---------------------\n\n");

	ft_write(1, "ft_write :\n", 11);
	printf("\nreturn = %zd\n", ft_write(156, "hello world !", 13));
 	printf("errno : %d\n\n", errno);
	ft_write(1, "write :\n", 9);
	errno = 0;
	printf("\nreturn = %zd\n", write(156, "hello world !", 13));
 	printf("errno : %d\n\n", errno);
}

void	ft_main_read(void)
{
	int	fd;
	int	ret;
	char	buf[1000];
	char	buffer[1000];

	printf("--------------------------------------------------\n");
	printf("-------------------ft_read------------------------\n");
	printf("--------------------------------------------------\n\n");

	printf("ft_read : \n");   
    	fd = open("HW.txt", O_RDONLY);
    	ret = ft_read(fd, buf, 13);
    	buf[ret] = '\0';
	printf("buf = %s / ret = %d\n", buf, ret);
	close(fd);
	printf("read : \n");
	fd = open("HW.txt", O_RDONLY);
	ret = read(fd, buf, 13);
	buf[ret] = '\0';
	printf("buf = %s / ret = %d\n", buf, ret);
    	close(fd);
	printf("\n");
	
	printf("ft_read : \n");   
    	fd = open("HW.txt", O_RDONLY);
    	ret = ft_read(fd, buf, 10);
    	buf[ret] = '\0';
	printf("buf = %s / ret = %d\n", buf, ret);
	close(fd);
	printf("read : \n");
	fd = open("HW.txt", O_RDONLY);
	ret = read(fd, buf, 10);
	buf[ret] = '\0';
	printf("buf = %s / ret = %d\n", buf, ret);
    	close(fd);
	printf("\n");

	printf("ft_read : \n");   
    	fd = open("FAIL.txt", O_RDONLY);
    	ret = ft_read(fd, buf, 13);
    	buf[ret] = '\0';
	printf("buf = %s / ret = %d\n", buf, ret);
	close(fd);
	printf("read : \n");
	fd = open("FAIL.txt", O_RDONLY);
	ret = read(fd, buf, 13);
	buf[ret] = '\0';
	printf("buf = %s / ret = %d\n", buf, ret);
    	close(fd);
	printf("\n");

	printf("ft_read : \n");
    	fd = open("FAIL.txt", O_RDONLY);
    	ret = ft_read(fd, buf, 13);
 	printf("errno : %d\n", errno);
    	buf[ret] = '\0';
	printf("buf = %s / ret = %d\n", buf, ret);
	close(fd);
	errno = 0;
	printf("read : \n");
	fd = open("FAIL.txt", O_RDONLY);
	ret = read(fd, buf, 13);
 	printf("errno : %d\n", errno);
	buf[ret] = '\0';
	printf("buf = %s / ret = %d\n", buf, ret);
    	close(fd);
	printf("\n");

	
	printf("ft_read : \n");
    	ret = ft_read(-1, buffer, 2);
 	printf("errno : %d\n", errno);
	printf("buf: %s, ret = %d\n", buffer, ret);
	close(fd);
	errno = 0;
	printf("read : \n");
	ret = read(-1, buffer, 2);
 	printf("errno : %d\n", errno);
	printf("buf: %s, ret = %d\n\n", buffer, ret);
}

void	ft_main_strdup(void)
{
    	printf("--------------------------------------------------\n");
	printf("-------------------ft_strdup----------------------\n");
	printf("--------------------------------------------------\n\n");


	printf("ft_strdup :\n");
	printf("%s\n", ft_strdup("hello wolrd !"));
    	printf("strdup :\n");
	printf("%s\n\n", strdup("hello world !"));

    	printf("ft_strdup :\n");
	printf("%s\n", ft_strdup("a"));
    	printf("strdup :\n");
	printf("%s\n\n", strdup("a"));

    	printf("ft_strdup :\n");
	printf("%s\n", ft_strdup("0123456789abcdef"));
    	printf("strdup :\n");
	printf("%s\n\n", strdup("0123456789abcdef"));

	printf("ft_strdup :\n");
	printf("%s\n", ft_strdup(""));
    	printf("strdup :\n");
	printf("%s\n", strdup(""));}

int	main(void)
{
	ft_main_strlen();
	ft_main_strcpy();
	ft_main_strcmp();
	ft_main_write();
	ft_main_read();
	ft_main_strdup();

	return (0);
}
