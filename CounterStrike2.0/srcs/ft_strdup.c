#include "../inc/header.h"

char	*ft_strnnldup(char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i] && s1[i] != '\n')
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}
