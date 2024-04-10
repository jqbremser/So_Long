# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 12:39:28 by jbremser          #+#    #+#              #
#    Updated: 2024/04/04 12:37:26 by jbremser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = 		so_long

FLAGS = 	-Wall -Werror -Wextra

FILES = 	so_long.c 

SRCDIR =	srcs
OBJDIR =	objs

LIBFT_DIR =	libft
LIBFT =		$(LIBFT_DIR)/libft.a

LIBS = 		$(LIBFT) 

SRCS =		$(addprefix $(SRCDIR)/, $(FILES))
OBJS =		$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

ANSI_BLUE := \033[0;34m
ANSI_RED := \033[31m
ANSI_RESET := \033[0m

all:		$(NAME)

$(NAME):	$(LIBS) $(OBJS)
			@cc $(FLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
			@echo "$(ANSI_BLUE) Compilation Complete: $(NAME) $(ANSI_RESET)"

$(LIBFT):
			@$(MAKE) -C $(LIBFT_DIR)
			@echo "$(ANSI_BLUE) Library Compiled$(ANSI_RESET)"

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
			@mkdir -p $(OBJDIR)
			@cc $(FLAGS) -c $< -o $@

clean:		
			@rm -rf $(OBJDIR) 
			@make -C $(LIBFT_DIR) clean
			@echo "$(ANSI_RED) Objects and Libraries:$(LIBFT_DIR) Cleaned$(ANSI_RESET)"
			

fclean:		clean
			@rm -f $(NAME)
			@echo "$(ANSI_RED) Executable $(NAME) removed$(ANSI_RESET)"

re:		fclean	all

.PHONY:		all	clean fclean re