#include "../../cub3D.h"

void init_render_data(t_game *game, t_render_data *render_data)
{
	set_starting_position(game, render_data);
	printf("starting x: %f\nstarting y: %f\n", render_data->pos_x, render_data->pos_y);
	set_starting_direction(game, render_data);
	printf("starting dir_x: %f\nstarting dir_y: %f\n", render_data->dir_x, render_data->dir_y);
	set_camera_plane(render_data);
	printf("starting plane_x: %f\nstarting plane_y: %f\n", render_data->plane_x, render_data->plane_y);
	init_time(render_data);
	printf("starting time: %f\nstarting old_time: %f\n", render_data->time, render_data->old_time);
}