#include "push_swap.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			result++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (result);
}

static char	*get_word(const char *s, char c)
{
	size_t	len;
	char	*result;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		result[len] = s[len];
		len++;
	}
	result[len] = '\0';
	return (result);
}

static char	**abort_split(char **words, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < word_count)
	{
		while (s[i] && s[i] == c)
			i++;
		result[j] = get_word(&s[i], c);
		if (!result[j])
			return (abort_split(result, j));
		while (s[i] && s[i] != c)
			i++;
	}
	result[word_count] = NULL;
	return (result);
}
static int	ft_check_set(char const c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (2);
	return (0);
}

int	check_for_tab(char const *s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_check_set(s1[i++]) == 2)
			return (0);
	}
	return (1);
}

char	*ft_strtrim(char const *s1)
{
	char *result;
	size_t size;

	if (!s1)
		return (NULL);
	if (!check_for_tab(s1))
		return (NULL);
	while (*s1 && ft_check_set(*s1) == 1)
		s1++;
	size = ft_strlen(s1);
	while (size != 0 && ft_check_set(s1[size - 1]) == 1)
		size--;
	result = (char *)malloc(size + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *)s1, size + 1);
	return (result);
}