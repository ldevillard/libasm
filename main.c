/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:06:00 by ldevilla          #+#    #+#             */
/*   Updated: 2021/02/09 11:11:00 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, const void *buf, size_t count);
char	*ft_strdup(const char *s1);
//void	start(void);

int	my_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int main(int ac, char **av)
{
	(void)ac;
	//start();
	//int a = 0x42424242;
	//char dest[10];

	//ft_strcpy(dest, "0123456789abcd")
	
	//printf("%d\n", ft_strlen(av[1]));
	//printf("%s\n", ft_strcpy(dst, src));
	//char *s1;
	//char *s2;
	//s1 = "\x01";
	//s2 = "\x01\x01";
	//printf("%d\n", ft_strcmp(s1, s2));
	//printf("%d\n", my_strcmp(s1, s2));
	//printf("%d\n", strcmp(s1, s2));
	//printf("WRITE : %zd\n", write(1, "\nHello World !\n", 15));
	//printf("FT_READ : %zd\n", ft_read(1, str, 10));
	
	//printf("READ : %zd\n", ft_read(1, str, 10));
	//printf("STR : %s\n", str);
	//printf("ERROR : %d\n", errno);
	//free(str);
	printf("%s\n", ft_strdup("lolilol"));
	printf("%s\n", strdup("lolilol"));
	return 0;
}