# ANOTAÇÕES

## Teste do Parseador

```c
void	printmap(t_mdata *ms)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < ms->col)
	{
		j = 0;
		{
			while (j < ms->row)
			{
				//if (ms->coord[i][j].color)
					printf("Col: %.0f | Row: %.0f | Z: %.0f | Color: %i\n", ms->coord[i][j].coord[0], ms->coord[i][j].coord[1], ms->coord[i][j].coord[2], ms->coord[i][j].color);
				j++;
			}
		}
		i++;
	}
}
```

## Função para desenhar direto na janela

* NÃO PERMITIDO NESSE PROJETO

```c
void	paint(t_mdata *m)
{
	int	x;
	int	y;
	int	color;

	x = 150;
	color = 0xFF0000;

	while (x < 156)
	{
		y = 0;
		
		while (y < 200)
		{
			putpixel(m, x, y, color);
			y++;
		}
		x++;
	}
}
```

## MENU

```
+-----------------------------+
|             MENU            |
+-----------------------------+
| Zoom:        Mouse scroll   |
| Movement:    Arrow Keyboard |
| Z axis:      +/- Keyboard   |
+-----------------------------+
|   Click on axis to rotate   |
+-----------------------------+
|    X    |    Y    |    Z    |
+---------+---------+---------+
```

## Norminette

`norminette fdf_bresenham.c fdf_draw.c fdf_exit.c fdf_features.c fdf_makers.c fdf_matrix_utils.c fdf_matrix.c fdf_parser.c fdf_utils.c fdf_window.c get_next_line.c get_next_line_utils.c main.c`

## Valgrind

`@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./fdf ./maps/pyramide.fdf`