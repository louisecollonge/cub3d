/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:19 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/21 16:14:01 by amonfret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h" //sur conseil de Baptiste : MLX42 et non minilibX
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>

# define WIDTH 1024
# define HEIGHT 720
# define GREY "\033[90m"
# define BOLDRED "\033[1;31m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[38;2;255;165;0m"
# define RED "\033[31m"
# define RESET "\033[0m"

# define BUFFER_SIZE 1 //gnl
# define tex mlx_texture_t //for lisibility
# define COLLISION_RADIUS 0.1

typedef enum	s_option
{
	FLOOR,
	CEILING,
	NO,
	SO,
	WE,
	EA,
} t_option;

typedef struct s_data
{
	char	*floor;
	char	*ceiling;
	int		floor_rgb;
	int		ceiling_rgb;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		fd_map;
	int		character_nb;
	char	*line;
	char	*map_string;
	char	**map_tab;
	int		in_map;
}	t_data;

typedef struct s_player
{
	float	x; //float pour la precision apres la virgule
	float	y;
	float	dir;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx; //pointeur instance MLX42
	mlx_image_t		*img; //image affichee par render
	t_player		player;
	tex				**textures; // tableau de textures
	char			**map; //carte du jeu en 2D
	t_data			*data; //pointer to data for cleanup
}	t_game;

//struct for bresenhams algo
typedef struct s_line_vars
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	err2;
	int	x_start;
	int	y_start;
}	t_line_vars;

// used to pass coords in functions
typedef struct s_coord
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}	t_coord;

//struct for vertical line drawing
typedef struct s_vertical
{
	int	draw_start;
	int	draw_end;
}	t_vertical;

typedef enum e_wall_direction
{
	EAST,
	WEST,
	SOUTH,
	NORTH
} t_direction;

typedef struct s_texture_data
{
	double	wall_x; //where on x the wall was hit by the ray;
	int		texture_index;
	int		tex_width;
	int		tex_height;
	int		tex_x; // x coordinate on the texture;
	int		tex_y;
	double	step; // increment of tex coord per screen pixel
	double	tex_pos; //starting texture coordinate

}	t_texture_data;

typedef struct s_render_data
{
	double			pos_x; //x and y starting position
	double			pos_y;
	double			dir_x;// direction vector of player
	double			dir_y;
	double			plane_x; //perpendicular camera plane vector
	double			plane_y;
	double			camera_x; // x in camera space
	double			ray_direction_x;
	double			ray_direction_y;
	double			ray_length;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x; //distance the ray must travel along the X-axis to reach the next vertical grid line.
	double			delta_dist_y; //distance the ray must travel along the Y-axis to reach the next horizontal grid line.
	double			perp_wall_dist;
	double			step_x;
	double			step_y;
	int				hit;
	int				side;
	int				draw_start;
	int				draw_end;
	uint32_t		color;
	double			time;
	double			old_time;
	double			current_time;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
	t_direction		wall_dir;
	double	wall_x; //where on x the wall was hit by the ray;
	int		texture_index;
	int		tex_width;
	int		tex_height;
	int		tex_x; // x coordinate on the texture;
	int		tex_y;
	double	step; // increment of tex coord per screen pixel
	double	tex_pos; //starting texture coordinate
}	t_render_data;

typedef struct s_ray_data
{
	t_game			*game;
	t_render_data	*render_data;
} t_ray_data;


typedef struct s_tripe_data
{
	t_render_data	*render_data;
	t_texture_data	*tex_data;
}	t_stripe_data;

//!debug
void		print_data(t_render_data *data);

// Drawing
void		my_mlx_pixel_put(mlx_image_t *img, int x, int y, uint32_t color);
void		draw_line(mlx_image_t *img, t_coord coord, uint32_t color);
void		draw_line_loop_helper(t_line_vars *l_vars, t_coord *coord);
void		vertical_line(mlx_image_t *img, int x,
				t_vertical vert, uint32_t color);
void	draw_texture_stripe(mlx_image_t *img, int x, t_game *game, t_render_data *data);
void		clear_image(mlx_image_t *img);

// Rendering
void		render_loop(void *param);
void		raycast(t_game *game, t_render_data *data);

// Parsing
t_data		*parse_args(int ac, char **av);
t_data		*parse_file(char *file);
void		parse_texture(char *line, t_data *data, t_option option, int *count);
void		parse_color(char *line, t_data *data, t_option, int *count);
void		parse_map_line(t_data *data, int *count);
bool		wall_outline(t_data *data);
bool		empty_space(t_data *data);
bool		is_orientation(char *line);
t_option	get_option(char *line);
bool		acceptable_char(char c);
bool		space(char **tab, size_t x, size_t y);
bool		zero(char **tab, size_t x, size_t y);
bool		end_of_map(t_data *data);

// Init game and render data
void		init_game(t_game *game, t_data *data);
void		init_render_data(t_game *game, t_render_data *render_data);
void		set_starting_position(t_game *game, t_render_data *render_data);
void		set_starting_direction(t_game *game, t_render_data *render_data);
void		set_camera_plane(t_render_data *render_data);
void		init_time(t_render_data *render_data);

// Input
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		my_closehook(void *param);
void 		update_keys(t_game *game, t_render_data *data, double move_speed, double rot_speed);
void		move_forward(t_game *game, t_render_data *data, double move_speed);
void		move_backward(t_game *game, t_render_data *data, double move_speed);
void		move_left(t_game *game, t_render_data *data, double move_speed);
void		move_right(t_game *game, t_render_data *data, double move_speed);
void		rotate_right(t_game *game, t_render_data *data, double rot_speed);
void		rotate_left(t_game *game, t_render_data *data, double rot_speed);
void		push_player(t_game *game, t_render_data *data);
// Textures
tex			**load_textures(t_game *game, t_data *data);

// Utils
size_t		tab_line_nb(char **tab);
void		print_tab(char **tab); //debug
int			get_map_height(char **map);
int			get_map_width(char **map);

// Clean-up
void		error(char *s, t_data *data, void *p1, void *p2);
void		delete_texture_tab(tex **textures);
void		cleanup(t_data *data);

// Close window and cleanup
void		my_mlx_close(void *param);

// Get Next Line
char		*get_next_line(int fd);
size_t		ft_strlen2(const char *s);
size_t		ft_strlcpy2(char *dst, const char *src, size_t size);
void		*free_mem(char **remainder, char **buffer);
char		*ft_strjoin_gnl(char *s1, char *s2);

#endif
