#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (0);
		++s;
	}
	return ((char*)s);
}

char		*ft_strdup(const char *s)
{
	char	*ret;
	int		i;

	if (!(ret = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;

	if (!s1 && !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = -1;
	if (str)
	{
		while (*s1)
			str[++i] = *s1++;
		while (*s2)
			str[++i] = *s2++;
	}
	str[++i] = 0;
	return (str);
}

char		*ft_strappend(char *s1, char *s2)
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


static int		get_line(char **strs, char **line, char *ptr, int fd)
{
	char *tmp;

	if (ptr != 0)
	{
		*ptr = 0;
		*line = ft_strdup(strs[fd]);
		tmp = ft_strdup(ptr + 1);
		free(strs[fd]);
		strs[fd] = tmp;
		return (1);
	}
	if (strs[fd] != 0)
	{
		*line = strs[fd];
		strs[fd] = 0;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*strs[MAX_FD];
	char			buf[BUFFER_SIZE + 1];
	int				rd_size;
	char			*ptr;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((ptr = ft_strchr(strs[fd], '\n')) == 0
			&& (rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = 0;
		strs[fd] = ft_strappend(strs[fd], buf);
	}
	if (rd_size < 0)
		return (-1);
	return (get_line(strs, line, ptr, fd));
}
