#include "libft/libft.h"
#include "get_next_line.h"

int main(int argc, char **argv)
{
	char **line;
	char *lu;
	int fd;

	// lu = NULL;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = &lu;
	while (get_next_line(fd, line) == 1)
	{
		ft_putendl(lu);
	}
	return (0);
}
