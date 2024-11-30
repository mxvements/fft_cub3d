#include "includes/cub3d.h"

static void *init_cub(char *filepath)
{
	t_cub		*cub;

	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	if (!cub)
		return (NULL); //print message 
	cub->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!cub->map)
		return (NULL); //print message in case of error & free
	cub->textures = (t_texture *) ft_calloc(1, sizeof(t_texture));
	if (!cub->textures)
		return (NULL); //print message in case of error & free
	
	cub = parse_map(cub, filepath);
	if (!cub)
		return (NULL);
	return (cub);
}

/**
 * CUB3D
 * 
 * Execution
 * 		./cub3d <path/to/map.cub>
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		print_error(ERR_USE);
	init_cub(argv[1]);
		
	
	return (0);
}