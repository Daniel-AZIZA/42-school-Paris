#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*dst;
	int	i;

	dst = NULL;
	if (!str)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = str[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char 	*ft_strdup(char *str)
{
	char 	*dst;
	int 	i;

	dst = NULL;
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])	
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	*ft_memmove(void *dst, void *src, int len)
{
	int i;

	if (!dst || !src)
		return (NULL);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((char *)dst)[i] = ((char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

char 	*join_and_free(char *str, char *buf)
{
	int len1;
	int len2;
	char *dst;
	int i;

	if (!str)
		return (ft_strdup(buf));
	if (!buf)
		return (NULL);
	len1 = ft_strlen(str);
	len2 = ft_strlen(buf);
	dst = NULL;
	if (!(dst = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	free(str);
	str = NULL;
	i = 0;
	while (buf[i])
	{
		dst[len1 + i] = buf[i];
		i++;
	}
	dst[len1 + i] = '\0';
	return (dst);
}	

int	find_index(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != c)
		return (-1);
	return (i);
}

int	get_line(char *str, char **line, int i)
{
	int len;

	*line = ft_substr(str, 0, i);
	i++;
	len = ft_strlen(str + i) + 1;
	ft_memmove(str, str + i, len);
	return (1);
}

int	get_next_line(char **line)
{
	int i;
	int ret;
	static char *str = NULL;
	char buf[128];

	if (!line || read(0, buf, 0) < 0)
		return (-1);
	if (str && ((i = find_index(str, '\n')) != -1))
		return (get_line(str, line, i));
	while ((ret = read(0, buf, 128)) > 0)
	{
		buf[ret] = '\0';
		str = join_and_free(str, buf);
		if (((i = find_index(str, '\n')) != -1))
			return (get_line(str, line, i));
	}
	if (str)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (ret);
	}
	*line = ft_strdup("");
	return (ret);
}

int main (void)
{
	char *line;
	line = NULL;

	while (get_next_line(&line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	free(line);
}
