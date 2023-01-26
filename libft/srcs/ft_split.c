/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:50:34 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/14 23:08:18 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_array_size(char const *str, char charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == charset)
			str++;
		if (*str != charset && *str)
			count++;
		while (*str != charset && *str)
			str++;
	}
	return (count);
}

static char	*get_next_word(char const *str, char charset)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != charset)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static int	check_error_exit(char *string, char **result)
{
	if (string == NULL)
	{
		while (*result)
			free(*result++);
		free(result);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**result;

	i = 0;
	count = get_array_size(s, c);
	result = malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != c && *s)
		{
			result[i] = get_next_word(s, c);
			if (check_error_exit(result[i++], result))
				return (NULL);
		}
		while (*s != c && *s)
			s++;
	}
	result[i] = 0;
	return (result);
}

// int	main(void)
// {
// 	char	**result;

// 	result = ft_split("lorem ipsum dolor sit", ' ');
// 	for (int i = 0; result[i] ; i++)
// 	{
// 		printf("%s\n", result[i]);
// 		free(result[i]);
// 	}
// 	if (!result)
// 		printf(" OKOKKKKKKK\n");
// 	else
// 		free(result);
// }
