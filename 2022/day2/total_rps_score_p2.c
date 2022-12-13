#include "../include/my_lib.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/*
Part 2:

(x means lose, y meas draw and z means win, shape points as in part 1)
Following the Elf's instructions for the second column, what would \
your total scorebe if everything goes exactly according to your strategy guide?

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
	int	score;

	score = 0;
	if (line[0] == 'A' && line[2] == 'X')
		score += ft_shape_score('Z');
	else if (line[0] == 'A' && line[2] == 'Y')
		score += ft_shape_score('X') + 3;
	else if (line[0] == 'A' && line[2] == 'Z')
		score += ft_shape_score('Y') + 6;
	else if (line[0] == 'B' && line[2] == 'X')
		score += ft_shape_score('X');
	else if (line[0] == 'B' && line[2] == 'Y')
		score += ft_shape_score('Y') + 3;
	else if (line[0] == 'B' && line[2] == 'Z')
		score += ft_shape_score('Z') + 6;
	else if (line[0] == 'C' && line[2] == 'X')
		score += ft_shape_score('Y');
	else if (line[0] == 'C' && line[2] == 'Y')
		score += ft_shape_score('Z') + 3;
	else
		score += ft_shape_score('X') + 6;
	return (score);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		total_score;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		line = "1";
		total_score = 0;
		while (line)
		{
			line = get_next_line(fd);
			if (line)
				total_score += ft_round_score(line);
			free(line);
		}
		close(fd);
		printf("What would your total score be if everything goes exactly \
according to your strategy guide?\n\nAnswer: %i\n", total_score);
	}
	return (0);
}
