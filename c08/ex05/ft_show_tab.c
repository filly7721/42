/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:06:26 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/12 18:16:26 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

void	ft_putnum(int i)
{
	char	c;

	c = (i % 10) + '0';
	if (i > 9)
		ft_putnum(i / 10);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnum(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

// #include <stdlib.h>
// char	*ft_strdup(char *src)
// {
// 	char	*dest;
// 	int		i;
//
// 	i = 0;
// 	while (src[i] != '\0')
// 		i++;
// 	dest = malloc((i + 1) * sizeof(char));
// 	i = 0;
// 	if (!(dest))
// 		return (NULL);
// 	while (src[i] != '\0')
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }
//
// int	ft_strlen(char *str)
// {
// 	int	i;
//
// 	i = 0;
// 	while(str[i] != '\0')
// 		i++;
// 	return (i);
// }
//
// struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
// {
// 	t_stock_str	*tab;
// 	int			i;
//
// 	tab = (t_stock_str*) malloc(sizeof(t_stock_str) * (ac + 1));
// 	if (!tab)
// 		return (NULL);
// 	i = 0;
// 	while (i < ac)
// 	{
// 		tab[i].size = ft_strlen(av[i]);
// 		tab[i].str = av[i];
// 		tab[i].copy = ft_strdup(av[i]);
// 		i++;
// 	}
// 	tab[i].size = 0;
// 	tab[i].str = 0;
// 	tab[i].copy = 0;
// 	return (tab);
// }
//
// int main(int ac, char **av)
// {
//
// 	struct s_stock_str* stacks = ft_strs_to_tab(ac - 1, &av[1]);
// 	int i;
//
// 	i = 0;
// 	while (i < ac - 1)
// 	{
// 		stacks[i++].copy[0] += 1;
// 	}
//
// 	ft_show_tab(stacks);
//
// }
//
// typedef struct s_stock_str
// {
// int size;
// char *str;
// char *copy;
// } t_stock_str;