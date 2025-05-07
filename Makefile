
NAME = cub3D

# Répertoires
DIR_SRC = src/
DIR_OBJ = obj/
DIR_MLX = ./ress/minilibx-linux/
DIR_INC = includes/

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(DIR_INC) -I$(DIR_MLX)

# Librairies à linker
MLX_FLAGS = -L$(DIR_MLX) -lmlx -lm -lXext -lX11

# Outils
RM = rm -f
MKDIR = mkdir -p

# Sources
SRCS = $(wildcard $(DIR_SRC)*.c) \
       $(wildcard $(DIR_SRC)/parsing/*.c) \
       $(wildcard $(DIR_SRC)/utils/*.c) \
	   $(wildcard $(DIR_SRC)/minilibx/*.c)

# Objets
OBJS = $(SRCS:$(DIR_SRC)%.c=$(DIR_OBJ)%.o)

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

# Compilation des objets
$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	$(RM) -r $(DIR_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
