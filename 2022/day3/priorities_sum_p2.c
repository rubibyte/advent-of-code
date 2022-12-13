#include "../include/my_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*

Part 2:

(common item in each three-Elf group corresponds to the badge, item pritoritie
as in part 1)

Find the item type that corresponds to the badges of each three-Elf group. What is the sum of the priorities of those item types?

*/

int	main(void)
{
	int		fd;
	char	*line1;
	char	*line2;
	char	*line3;
	int		i;
	int		j;
	int		k;
	int		badge;
	int		priorities_sum;

	fd = open("input.txt", O_RDONLY);
	line1 = "1";
	priorities_sum = 0;
	while (line1)
	{
		line1 = get_next_line(fd);
		if (line1)
		{
			line2 = get_next_line(fd);
			line3 = get_next_line(fd);
			i = 0;
			badge = 0;
			while (line1[i])
			{
				j = 0;
				while (line2[j])
				{
					if (line1[i] == line2[j])
					{
						k = 0;
						while (line3[k])
						{
							if (line3[k] == line2[j])
							{
								badge = line3[k];
								if (badge > 64 && badge < 91)
									priorities_sum += badge - 38;
								else if (badge > 96 && badge < 123)
									priorities_sum += badge - 96;
								break;
							}
							k++;
						}
						break;
					}
					j++;
				}
				if (badge)
					break;
				i++;
			}
		}
		free(line1);
		free(line2);
		line2 = NULL;
		free(line3);
		line3 = NULL;
	}
	close(fd);
	printf("\nFind the item type that corresponds to the badges of \
each three-Elf group. What is the sum of the priorities of those \
item types?\n\nAnswer: %i\n", priorities_sum);
	return (0);
}
