#include "../../cub3D.h"

void init_render_data(t_game *game, t_render_data *render_data)
{
	set_starting_pos(game, render_data);
	printf("starting x: %f\nstarting y: %f\n", render_data->pos_x, render_data->pos_y);
}