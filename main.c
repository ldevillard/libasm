/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:06:00 by ldevilla          #+#    #+#             */
/*   Updated: 2021/02/14 11:11:41 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFER 100

size_t		ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, const void *buf, size_t count);
char	*ft_strdup(const char *s1);

int		ft_check_arg(char *str)
{
	if (str[0] == 's' && str[1] == 't' && str[2] == 'r'
		&& str[3] == 'l' && str[4] == 'e' && str[5] == 'n'
		&& str[6] == '\0')
		return (1);
	if (str[0] == 's' && str[1] == 't' && str[2] == 'r'
		&& str[3] == 'c' && str[4] == 'p' && str[5] == 'y'
		&& str[6] == '\0')
		return (2);
	if (str[0] == 's' && str[1] == 't' && str[2] == 'r'
		&& str[3] == 'c' && str[4] == 'm' && str[5] == 'p'
		&& str[6] == '\0')
		return (3);
	if (str[0] == 'w' && str[1] == 'r' && str[2] == 'i'
		&& str[3] == 't' && str[4] == 'e' && str[5] == '\0')
		return (4);
	if (str[0] == 'r' && str[1] == 'e' && str[2] == 'a'
		&& str[3] == 'd' && str[4] == '\0')
		return (5);
	if (str[0] == 's' && str[1] == 't' && str[2] == 'r'
		&& str[3] == 'd' && str[4] == 'u' && str[5] == 'p'
		&& str[6] == '\0')
		return (6);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	s1[] = "Salut ca va ?";
	char	s2[] = "Hey how are you ?";
	
	fd = 1;
	fd = open("test.txt", O_RDWR);
	printf("\033[0;32m");
	if (ac == 2 && ft_check_arg(av[1]))
	{
		if (ft_check_arg(av[1]) == 1)
		{
			printf("YOU : '%s' = %zu\n", s1, ft_strlen(s1));
			printf("\033[0;35m");
			printf("EXPECTED : '%s' = %lu\n", s1, strlen(s1));
		}
		else if (ft_check_arg(av[1]) == 2)
		{
			printf("YOU : '%s' = '%s'\n", s1, ft_strcpy(s2, s1));
			printf("\033[0;35m");
			printf("EXPECTED : '%s' = '%s'\n", s1, strcpy(s2, s1));
		}
		else if (ft_check_arg(av[1]) == 3)
		{
			printf("YOU : '%s' = '%d'\n", s1, ft_strcmp(s1, s2));
			printf("\033[0;35m");
			printf("EXPECTED : '%s' = '%d'\n", s1, strcmp(s1, s2));
		}
		else if (ft_check_arg(av[1]) == 4)
		{
			int i = ft_write(fd, s1, ft_strlen(s1));
			printf("\n");
			printf("YOU : %d\nERRNO : %d\n", i, errno);
			printf("\033[0;35m");
			int j = write(fd, s1, ft_strlen(s1));
			printf("\n");
			printf("EXPECTED : %d\nERRNO : %d\n", j, errno);
			/*When you read in a file, the offset 
			may be advance so the second read call 
			may return 0, try to invert them to check*/
		}
		else if (ft_check_arg(av[1]) == 5)
		{
			char *line = malloc(sizeof(char) * BUFFER + 1);
			line[BUFFER] = '\0';
			int i = ft_read(fd, line, BUFFER);
			printf("LINE : %s", line);
			printf("YOU : %d\nERRNO : %d\n", i, errno);
			printf("\033[0;35m");
			int j = read(fd, line, BUFFER);
			printf("LINE : %s", line);
			printf("EXPECTED : %d\nERRNO : %d\n", j, errno);
			free(line);
		}
		else if (ft_check_arg(av[1]) == 6)
		{
			char *line;
			line = ft_strdup(s1);
			printf("YOU : '%s' = '%s'\n", s1, line);
			free(line);
			printf("\033[0;35m");
			line = strdup(s1);			
			printf("EXPECTED : '%s' = '%s'\n", s1, line);
			free(line);
		}
	}
	else if (ac == 1 || !ft_check_arg(av[1]))
	{
		printf("\033[0;31m");
		printf("./a.out <function>\n");
	}
	printf("\033[0m");
	return 0;
}