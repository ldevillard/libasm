/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:06:00 by ldevilla          #+#    #+#             */
/*   Updated: 2021/02/04 13:37:18 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
//void	start(void);

int main(int ac, char **av)
{
	(void)ac;
	//start();
	//int a = 0x42424242;
	//char dest[10];

	//ft_strcpy(dest, "0123456789abcd")
	
	//printf("%d\n", ft_strlen(av[1]));
	char dst[] = "test";
	char src[] = "lol";
	printf("%s\n", ft_strcpy(dst, src));
	return 0;
}