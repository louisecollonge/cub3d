/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:19 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/17 22:02:21 by amonfret         ###   ########.fr       */
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

# define WIDTH 640
# define HEIGHT 480
# define GREY "\033[90m"
# define BOLDRED "\033[1;31m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[38;2;255;165;0m"
# define RED "\033[31m"
# define RESET "\033[0m"

# define BUFFER_SIZE 1 //gnl

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
	char			*floor;
	char			*ceiling;
	int				floor_rgb;
	int				ceiling_rgb;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	int				fd_map;
	int				character_nb;
	char			*map_string;
	char			**map_tab;
	int				in_map;
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
	mlx_texture_t	**textures; // tableau de textures
	char			**map; //carte du jeu en 2D
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

// Parsing
t_data	*parse_args(int ac, char **av);
t_data	*parse_file(char *file);
void	parse_texture(char *line, t_data *data, t_option option, int *count);
void	parse_color(char *line, t_data *data, t_option, int *count);
void	parse_map_line(char *line, t_data *data, int *count);
bool	wall_outline(t_data *data);
bool	empty_space(t_data *data);

// Parsing utils
bool	is_orientation(char *line);

// Init
void	init_game();

// Drawing
void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, uint32_t color);
void	draw_line(mlx_image_t *img, t_coord coord, uint32_t color);
void	draw_line_loop_helper(t_line_vars *l_vars, t_coord *coord);
void	clear_image(mlx_image_t *img);

// Rendering
int render_loop(t_game *game);

// Input
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	my_closehook(void *param);
// Textures

// Utils
void	error(char *s, t_data *data, void *p1, void *p2);
void	cleanup(t_data *data);
int		tab_line_nb(char **tab);
void	print_tab(char **tab); //debug


// Get Next Line
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*add_buff(char *big, char *small);
char	*ft_strchr(const char *s, int c);
char	*read_file(char	*str, int fd);
char	*ft_get_line(char *str);
char	*get_next_line(int fd);
char	*remain(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);


#endif
