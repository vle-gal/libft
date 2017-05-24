#include "libft/libft.h"
#include "get_next_line.h"


static char		*ft_draw_line(char *static_str, int read_return)
{
	int			i;
	char		*line;
	char		end_line;

	end_line = (read_return > 0 ? '\n' : '\0');
	i = 0;
	while (static_str[i] != end_line)
		i++;
	line = ft_strnew(i);
	i = 0;
	while (static_str[i] != end_line)
	{
		line[i] = static_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int				get_next_line(int const fd, char **line)
{
	static	char				*static_str;
	int							read_return;
	char						buffer[BUFF_SIZE + 1];
	char						*tmp;


	if (!line)
		return (-1);

	static_str = (static_str == NULL ? ft_strdup("") : static_str);
	read_return = 9;
	tmp = ft_strdup(static_str);
	while (!(ft_strchr(tmp, '\n')))
	{
		if ((read_return = read(fd, buffer, BUFF_SIZE)) == -1 || BUFF_SIZE <= 0)
			return (-1);
		buffer[read_return] = '\0';
		tmp = ft_strdup(static_str);
		if (read_return == 0 && *static_str == '\0')
		{
			return (0);
		}
	}
	*line = ft_draw_line(static_str, read_return);
	static_str = ft_strchr(static_str, '\n');
	static_str = static_str != NULL ? static_str + 1 : static_str;
	return (1);
}
