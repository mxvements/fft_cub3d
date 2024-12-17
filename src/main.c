#include "includes/cub3d.h"

static int	init_map(t_map *map)
{
	map->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!map->player)
		return (print_error("init_map", NULL));
	map->player->x = -1;
	map->player->y = -1;
	return (0);
}

static void init_texture(t_texture *tx)
{
	tx->floor = -1;
	tx->ceiling = -1;
}

static int init_cub(t_cub *cub, char *filepath)
{
	cub->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!cub->map)
		return (print_error("init_cub", NULL));
	if (init_map(cub->map) < 0)
		return (-1);
	cub->textures = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!cub->textures)
	{
		free_cub(cub);
		return (print_error("init_cub", NULL));
	}
	init_texture(cub->textures);
	if (parse_input(cub, filepath) < 0)
	{
		free_cub(cub);
		return (-1);
	}
	print_cub(cub); //LOG
	return (0);
}


/**
 * CUB3D
 * 
 * Execution
 * 		./cub3d <path/to/map.cub>
 */
int main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		print_error("main", ERR_USE);
	// parsing test multiple maps
	if (ft_strncmp(argv[1],"test\0",5) == 0)
		return (parse_test());
	
	if (is_file_extension(argv[1], ".cub") < 0)
	{
		print_error("main", ERR_CUB);
		return (1);
	}
	ft_memset(&cub, 0, sizeof(t_cub));
	if (init_cub(&cub, argv[1]) < 0)
		return (1);
	//edu deberia continuar su codigo aqui
	free_cub(&cub);
	return (0);
}
