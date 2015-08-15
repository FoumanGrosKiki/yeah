/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <gjacot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 16:58:28 by gjacot            #+#    #+#             */
/*   Updated: 2015/08/15 22:55:07 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	matchst(char *s1, char *s2, int *j, int *i)
{
	if (s2[*j] == '\0')
		return (1);
	while (s2[*j] != s1[*i] && s1[*i] != '\0')
	{
		(*i)++;
		if (s2[*j] == '\0')
			return (0);
	}
	return (0);
}

int	match(char *s1, char *s2)
{
	int i;
	int j;
	int st;

	st = 0;
	i = 0;
	j = 0;
	while (s2[j] != '\0')
	{
		while (s2[j] == '*')
		{
			st++;
			j++;
			matchst(s1, s2, &j, &i);
		}
		if (s2[j] != s1[i] && st != 1)
		{
			return (0);
		}
		i++;
		j++;
	}
	return (1);
}
