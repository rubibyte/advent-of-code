#include "../include/get_next_line.h"
#include "../include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
(Every block of numbers in input.txt represents what an Elf is carrying)
1st part:
Find the Elf carrying the most Calories. How many total Calories is that Elf carrying?

2nd part:
Find the top three Elves carrying the most Calories. How many Calories are those Elves carrying in total?
*/

int	ft_total_elves(char	*file_name)
{
	int		fd;
	int		total_elves;
	char	*line;

	fd = open(file_name, O_RDONLY);
	total_elves = 1;
	line = "1";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			if (line[0] == '\n')
				total_elves++;
		free(line);
	}
	close(fd);
	return (total_elves);
}

int	*ft_sort(int *arr, size_t len)
{
	int	temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len - 1)
	{
		j = i;
		temp = 0;
		while (j < len - 1)
		{
			if (arr[i] < arr[j + 1])
			{
				temp = arr[i];
				arr[i] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	main(void)
{
	int		fd;
	int		ranking[ft_total_elves("input.txt")];
	int		temp;
	int		current_elf;
	char	*line;

	fd = open("input.txt", O_RDONLY);
	line = "1";
	temp = 0;
	current_elf = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (line[0] == '\n')
			{
				ranking[current_elf] = temp;
				current_elf++;
				temp = 0;
			}
			else
			{
				temp += ft_atoi(line);
			}
		}
		else
		{
			ranking[current_elf] = temp;
		}
		free(line);
	}
	ft_sort(ranking, sizeof(ranking)/sizeof(int));
	printf("1. How many total Calories is that Elf carrying?\n2. Find the top three Elves carrying the most Calories. How many \
Calories are those Elves carrying in total?\n\nRanking:");
	for (size_t i = 0; i < sizeof(ranking)/sizeof(int); i++)
	{
		printf(" %i", ranking[i]);
	}
	printf("\n\n1. Answer: %i\n2. Answer: %i\n", ranking[0], ranking[0] + ranking[1] + ranking[2]);		
	close(fd);
	return (0);
}

