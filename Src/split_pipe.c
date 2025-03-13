/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:51:52 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/13 16:43:14 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_str(char const *s, char c)
{
	size_t	count;
	
	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s == '\'')
		{
			s++;
			count++;
			while (*s && *s != '\'')
				s++;
			if (*s == '\'')
				s++;
		}
		else if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	size_t	len;
	char	*new_word;
	size_t	i;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	new_word = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_word)
	{
		free_split(&new_word);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_word[i] = s[i];
		i++;
	}
	new_word[len] = '\0';
	return (new_word);
}

static void	working_quote(char *s, int *len)
{
	
}

char	**ft_split_pipe(char const *s, char c)
{
	char	**split;
	size_t	i;

	i = 0;
	split = malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!split)
		return (NULL);
	while (s && *s != '\0' && *s != '\n')
	{
		if (*s != c)
		{
			split[i] = get_word(s, c);
			if (!split[i])
				return (free_split(split), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		else   
			s++;
	}
	split[i] = NULL;
	return (split);
}

int main(void)
{
	char *s = "   Hello  'World How' Are We Doing 'AAAA AAAA' !     . ";
	char **split;

	split = ft_split_pipe(s, ' ');
	// printf("")
}