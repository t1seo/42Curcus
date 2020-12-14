#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return (s);
}

char		*ft_strdup(char *s)
{
	if (!s)
		return (0);
	int len = ft_strlen(s);

	char *ret;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);

	int i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	int len = ft_strlen(s1) + ft_strlen(s2);
	char *ret;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);

	int i = -1;
	if (ret)
	{
		while (*s1)
			ret[++i] = *s1++;
		while (*s2)
			ret[++i] = *s2++;
	}
	ret[++i] = 0;
	return (ret);
}

char	*ft_strappend(char *s1, char *s2)
{
	char *tmp;

	if (!s1)
	{
		s1 = ft_strdup(s2);
		return (s1);
	}
	else
	{
		tmp = ft_strjoin(s1, s2);
		free(s1);
		s1 = tmp;
		return (s1);
	}
}

int		get_line(char **strs, char **line, char *ptr)
{
	char *tmp;

	if (ptr != 0)
	{
		*ptr = 0;
		*line = ft_strdup(*strs);
		tmp = ft_strdup(ptr + 1);
		free(*strs);
		*strs = tmp;
		return (1);
	}
	if (*strs != 0)
	{
		*line = *strs;
		*strs = 0;
	}
	else
	{
		*line = ft_strdup("");
	}
	return (0);
}

int		get_next_line(char **line)
{
	static char		*strs;
	char			buf[BUFFER_SIZE + 1];
	char			*ptr;
	int				rd_size;

	if (!line || BUFFER_SIZE < 1)
		return (-1);
	while ((ptr = ft_strchr(strs, '\n')) == 0 && (rd_size = read(0, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = 0;
		strs = ft_strappend(strs, buf);
	}

	if (rd_size < 0)
		return (-1);
	return (get_line(&strs, line, ptr));
}
