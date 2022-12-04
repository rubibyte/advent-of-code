#include "../include/get_next_line.h"
#include "../include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*

Part 1:

(a to z priorities 1 through 26, A to Z priorities 27 through 52)

Find the item type that appears in both compartments of each rucksack. What is the sum of the priorities of those item types?

*/

int	main(void)
{
	int		fd;
	char	*line;
	int		len;
	char	common_item;
	int		priorities_sum;
	int		i;
	char	*second_half;

	fd = open("input.txt", O_RDONLY);
	line = "1";
	priorities_sum = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			len = ft_strlen(line) - 1;
			second_half = ft_substr(line, len / 2, len / 2);
			i = 0;
			while (i < len / 2)
			{
				if (ft_strchr(second_half, line[i]))
				{
					common_item = line[i];
					if (common_item > 64 && common_item < 91)
						priorities_sum += common_item - 38;
					else if (common_item > 96 && common_item < 123)
						priorities_sum += common_item - 96;
					break;
				}
				i++;
			}
		}
		free(line);
	}
	printf("\nFind the item type that appears in both compartments \
of each rucksack. What is the sum of the priorities of those item \
types?\n\nAnswer: %i\n", priorities_sum);
	return (0);
}
