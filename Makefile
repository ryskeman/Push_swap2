# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernafer <fernafer@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 21:40:38 by fernafer          #+#    #+#              #
#    Updated: 2025/11/26 00:35:13 by fernafer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# --- PROJECT INFO ---
NAME = push_swap
CC = cc
OBJ_DIR = obj

# --- LIBRARIES ---
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# --- SOURCES ---
SRCS =  main.c \
		args_validation.c \
		args_valida_aux.c \
		movements.c \
		put_moves.c \
		rotate_moves.c \
		sort_stacks.c \
		swap_moves.c \
	# sort_process_utils.c \
	# sort_utils.c \
	# target_in_a_finder.c \


SRC= $(addprefix src/, $(SRCS))

OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# --- FLAGS ---
CFLAGS = -Wall -Wextra -Werror
INCLUDES =  -Iincludes/ -I$(LIBFT_DIR)/

# FLAG FOR DEBUGGING ---
FSANITIZE = -fsanitize=address -g3


# --- RULES ---
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@echo "🔗	Linking $(NAME)..."
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(FSANITIZE) -o $(NAME)
	@echo "✅ $(NAME) compiled succesfully!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# LIBFT COMPILING RULE
$(LIBFT):
	@echo "🛠️	Compiling Libft..."
	@make -C $(LIBFT_DIR)

# RULE TO CREATE OBJECTS
$(OBJ_DIR)/%.o: src/%.c $(OBJ_DIR)
	@echo "⚙️	Compiling $< into $@ (in $(OBJ_DIR)/)"
	$(CC) $(CFLAGS) $(FSANITIZE) $(INCLUDES) -c $< -o $@

# CLEANING OBJECTS RULE
clean:
	@echo "🧹	Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@rm -rf *.o
	@make -C $(LIBFT_DIR) clean
	@echo "Clean complete."

# CLEANING FILES RULE
fclean: clean
	@echo "🔥	Deep cleaning executable..."
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Deep clean complete."

re: fclean all
	@echo "Rebuilding project..."


.PHONY: all clean fclean re
