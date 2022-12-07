#include "../include/get_next_line.h"
#include "../include/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/*

Part 2:

In how many assignment pairs do the ranges overlap?

*/

int	main(void)
{
	int		fd;
	char	*line;
	int		pair1[2];
	int		pair2[2];
	int		i;
	int		total_overlapping_pairs;

	fd = open("input.txt", O_RDONLY);
	line = "1";
	total_overlapping_pairs = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			i = -1;
			pair1[0] = 0;
			pair1[1] = 0;
			pair2[0] = 0;
			pair2[1] = 0;
			printf("%s", line);
			while (ft_isdigit(line[++i]))
				pair1[0] = pair1[0] * 10 + (line[i] - 48);
			while (ft_isdigit(line[++i]))
				pair1[1] = pair1[1] * 10 + (line[i] - 48);
			while (ft_isdigit(line[++i]))
				pair2[0] = pair2[0] * 10 + (line[i] - 48);
			while (ft_isdigit(line[++i]))
				pair2[1] = pair2[1] * 10 + (line[i] - 48);
			if (!(pair1[1] < pair2[0] || pair2[1] < pair1[0]))
				total_overlapping_pairs++;		
		}
		free(line);
	}
	close(fd);
	printf("In how many assignment pairs do the ranges \
overlap?\n\nAnswer: %i\n", total_overlapping_pairs);
	return (0);
}
