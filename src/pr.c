#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
typedef struct s_point
{
  int row;
  int column;
} t_point;*/

typedef struct s_point
{
  int x;
  int y;
} t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

char** create_zone_copy(char *zone[], t_point size) {
    char **copy = malloc(size.y * sizeof(char*));
    for (int i = 0; i < size.y; i++) {
        copy[i] = strdup(zone[i]);
    }
    return copy;
}

void free_zone_copy(char **zone, t_point size) {
    for (int i = 0; i < size.y; i++) {
        free(zone[i]);
    }
    free(zone);
}

int main(void)
{
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	t_point size;
	t_point	begin;
	size.x = 8;
	size.y = 5;
	begin.x = 7;
	begin.y = 4;

    char **area = create_zone_copy(zone, size);
    flood_fill(area, size, begin);

    int i = 0;
    while (i < size.y) {
        printf("%s\n", area[i]);
        i++;
    }
    free_zone_copy(area, size);
    return 0;
}