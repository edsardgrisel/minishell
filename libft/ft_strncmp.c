/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:55:23 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/04/29 15:04:19 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (u_s1[i] == '\0' || u_s2[i] == '\0')
		{
			return (u_s1[i] - u_s2[i]);
		}
		if (u_s1[i] < u_s2[i])
		{
			return (u_s1[i] - u_s2[i]);
		}
		if (u_s1[i] > u_s2[i])
		{
			return (u_s1[i] - u_s2[i]);
		}
		i++;
	}
	return (0);
}
