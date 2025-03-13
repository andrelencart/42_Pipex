/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:51:52 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/13 17:36:48 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

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

static	void working_quote(char const **s, int *len, char c)
{
	while (*s[*len] != '\0')
	{
		printf("A");
		if (*s[*len] == '\'')
		{
			printf("B ");
			len++;
			s++;
			while (*s[*len] != '\'')
			{
				printf("C ");
				len++;
				s++;
			}
			s++;
			len++;
		}
		else if (*s[*len] == c)
			break;
		else
		{
			s++;
			len++;
		}
	}
}

static char	*get_word(char const *s, char c, int *len)
{
	char	*new_word;
	size_t	i;

	len = 0;
	working_quote(&s, len, c);
	len++;
	new_word = malloc(sizeof(char) * (*len + 1));
	printf("len: %zu\n", len);
	if (!new_word)
	{
		free_split(&new_word);
		return (NULL);
	}
	i = 0;
	ft_strlcpy(new_word, s, len);
	new_word[*len] = '\0';
	printf("new_word:%s\n", new_word);
	return (new_word);
}

char	**ft_split_pipe(char const *s, char c)
{
	char	**split;
	size_t	i;
	int len;

	i = 0;
	split = malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!split)
		return (NULL);
	printf("count: %d\n", count_str(s, c));
	while (s && *s != '\0' && *s != '\n')
	{
		if (*s != c)
		{
			len = 0;
			split[i] = get_word(s, c, &len);
			if (!split[i])
				return (free_split(split), NULL);
			i++;
			working_quote(&s, &len, c);
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
	int i;

	split = ft_split_pipe(s, ' ');
	while (split[i])
	{
		printf("word:%s\n", split[i]);
		i++;
	}
}