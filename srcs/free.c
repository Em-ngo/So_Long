#include "so_long.h"

void    free_map(char *map)
{
    int    i;

    i = 0;
    if (map != NULL)
    {
        while (map[i] != NULL)
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
}

void    destruction(t_all *all)
{
    mlx_destroy_image(all->data.mlx_ptr, all->image[0].img);
    mlx_destroy_image(all->data.mlx_ptr, all->image[1].img);
    mlx_destroy_image(all->data.mlx_ptr, all->image[2].img);
    mlx_destroy_image(all->data.mlx_ptr, all->image[3].img);
    mlx_destroy_image(all->data.mlx_ptr, all->image[4].img);
}

void    hakai(t_all *all)
{
    free_map(all->map);
    destruction(all);
    mlx_destroy_window(all->data.mlx_ptr, all->data.mlx_win);
    mlx_destroy_display(all->data.mlx_ptr);
    free(all->data.mlx_ptr);
}