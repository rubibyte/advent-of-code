#include "../include/my_lib.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/*

Part 2:

(message starts after fourteen unique characters)

How many characters need to be processed before the 
first start-of-message marker is detected?

*/

static int	ft_fourteen_unique(char *line, size_t i)
{
	size_t	j;
	size_t	k;
	
	j = 0;
	while (j < 14)
	{
		k = j + 1;
		while (k < 14)
		{
			if (line[i + j] == line[i + k])
				return (0);
			k++;
		}
		j++;
	}
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
				if (ft_fourteen_unique(line, i))
				{
					start_of_packet = (int)i + 14;
					break;
				}
				i++;
			}
		}
		free(line);
	}
	close(fd);
	printf("How many characters need to be processed before \
the first start-of-message marker is detected?\n\nAnswer: %i\n", start_of_packet);
	return (0);
}
