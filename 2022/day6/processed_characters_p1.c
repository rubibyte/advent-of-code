#include "../include/get_next_line.h"
#include "../include/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/*

Part 1:

(packet starts after four unique characters)

How many characters need to be processed before the 
first start-of-packet marker is detected?

*/

static int	ft_four_unique(char *line, size_t i)
{
	if (line[i] == line[i + 1] || line[i] == line[i + 2] || line[i] == line[i + 3])
		return (0);
	else if (line[i + 1] == line[i + 2] || line[i + 1] == line[i + 3])
		return (0);
	else if (line[i + 2] == line[i + 3])
		return (0);
	return (1);
}

int	main(void)
{
	int		fd;
	char	*line;
	size_t	i;
	int		start_of_packet;

	fd = open("input.txt", O_RDONLY);
	line = "1";
	i = 0;
	start_of_packet = 0;
	while (line && !start_of_packet)
	{
		line = get_next_line(fd);
		if (line)
		{
			while (i < ft_strlen(line))
			{
				if (ft_four_unique(line, i))
				{
					start_of_packet = (int)i + 4;
					break;
				}
				i++;
			}
		}
		free(line);
	}
	close(fd);
	printf("How many characters need to be processed before \
the first start-of-packet marker is detected?\n\nAnswer: %i\n", start_of_packet);
	return (0);
}
