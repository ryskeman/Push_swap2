# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 18:28:59 by fernafer          #+#    #+#              #
#    Updated: 2025/11/19 21:44:39 by fernafer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIBRARY NAME
NAME = libft.a
OBJ_DIR = obj

# COMPILATOR
CC = cc

# COMPILATION FLAGS
CFLAGS = -Wall -Wextra -Werror -c

# ARCHIVER
AR = ar rcs

# HEADER FILES
HEADERS = libft.h

# SOURCES FILES LIST
SOURCES = ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_memset.c ft_memcpy.c ft_strlcpy.c ft_bzero.c ft_memmove.c \
	  ft_toupper.c ft_tolower.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strlcat.c \
	  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_calloc.c \
	  ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c ft_itoa.c \
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_formats_chars.c \
	  ft_formats_ints.c ft_formats_hex.c ft_get_next_line.c ft_atoi_base.c \
	  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_strspn.c \

# OBJECTS LIST CREATOR
OBJS	= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))


# RULE TO CREATE THE LIBRARY
$(NAME): $(OBJS)
	@echo "📚 Making the static library $(NAME) from the objects..."
	@$(AR) $@ $^
	@echo "-----------------------------------------"
	@echo "✅ Compilation $(NAME) completed."
	@echo "-----------------------------------------"


# MAIN RULE: LIBFT.A CREATOR.
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# CREATOR OBJS RULE
$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@echo "⚙️ Compiling $< in $@"
	$(CC) $(CFLAGS) $< -o $@

# CLEAN RULE: DELETE OBJECT FILES
clean:
	@echo "🧹 Cleaning: Deleting objects files (*.o)..."
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Cleaning completed."

# FCLEAN RULE: DELETE OBJECT FILES AND LIBRARY
fclean: clean
	@echo "🗑️ Deep cleaning: Deleting objects files and library ($(NAME))..."
	@rm -rf $(NAME)
	@echo "🗑️ Deep cleaning completed."

# RE RULE: RECOMPILES ALL
re: fclean all
	@echo "🔄 Recompiling project..."

# PHONY TARGETS
.PHONY: all clean fclean re
