#include "../include/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/*
Part 1:

(3 for draw, 6 for win, 0 for losing, 1 for rock, 2 for paper, 3 for scissors)

What would your total score be if everything goes exactly according to your strategy guide?
*/
static int	ft_shape_score(char shape)
{
	if (shape == 'X')
		return (1);
	else if (shape == 'Y')
		return (2);
	else if (shape == 'Z')
		return (3);
	return (0);
}

static int	ft_round_score(char *line)
{
	if ((line[0] == 'A' && line[2] == 'X') || (line[0] == 'B' && line[2] == 'Y')\
 || (line[0] == 'C' && line[2] == 'Z'))
		return (3);
	else if (line[0] == 'A' && line[2] == 'Y')
		return (6);
	else if (line[0] == 'B' && line[2] == 'Z')
		return (6);
	else if (line[0] == 'C' && line[2] == 'X')
		return (6);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char 	*line;
	int		total_score;
	
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		total_score = 0;
		while (line)
		{
			line = get_next_line(fd);
			if (line)
			{
				total_score += ft_shape_score(line[2]);
				total_score += ft_round_score(line);
			}
			free(line);
		}
		close(fd);
		printf("What would your total score be if everything goes exactly \
according to your strategy guide?\n\nAnswer: %i\n", total_score);
	}
	return (0);
}
