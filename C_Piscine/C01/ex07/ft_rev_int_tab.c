/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:02:30 by lbengoec          #+#    #+#             */
/*   Updated: 2022/07/10 18:51:13 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *start, int *end);

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;

	start = 0;
	end = size - 1;
	while (start < (size / 2))
	{
		ft_swap(&(tab[start]), &(tab[end]));
		start++;
		end--;
	}
}

void	ft_swap(int *start, int *end)
{
	int	temp;

	temp = *start;
	*start = *end;
	*end = temp;
}
