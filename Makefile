# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 23:27:53 by tmoragli          #+#    #+#              #
#    Updated: 2022/02/10 16:18:37 by tmoragli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	= 	client
SERVER	= 	server
SRCS_C	=	srcs/client.c
SRCS_S =	srcs/server.c

INCLUDES	=	-Iincludes

OBJS_C		=	$(SRCS_C:.c=.o)
OBJS_S		=	$(SRCS_S:.c=.o)
CC			=	gcc
RM			=	@rm -f

LD_FLAGS	=	 libft/libft.a -fsanitize=address
FLAGS		=	-Wall -Werror -Wextra $(INCLUDES) -g
LIBFT		=	libft/libft.a
.c.o:
				$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

all:			start_message $(CLIENT) $(SERVER)

$(SERVER):		$(LIBFT) $(OBJS_S) start_link
				$(CC) $(OBJS_S) $(FLAGS) -o $(SERVER) $(LD_FLAGS)
				@echo "\033[1;31mminitalk\033[0m is ready to use!"

$(CLIENT):		$(LIBFT) $(OBJS_C)
				$(CC) $(OBJS_C) $(FLAGS) -o $(CLIENT) $(LD_FLAGS)
$(LIBFT):
				@make  -C libft -f Makefile


add_flag:
			$(eval FLAGS := -D BONUS=1)

clean:
#					@clear
					@make -s -C libft -f Makefile clean
					@echo "\033[0;33mCleaning \033[1;31mminitalk\033[0;33m's objects\033[0m"
					$(RM) $(OBJS_C) $(OBJS_S)

fclean:
					@make -s -C libft -f Makefile fclean
					@echo "\033[0;33mRemoving \033[1;31mminitalk\033[0;33m.\033[0m"
					$(RM) $(CLIENT) $(SERVER) $(OBJS_S) $(OBJS_C)
					$(RM) $(OBJS_S)$(OBJS_S)
start_message:
#				@clear
				@echo "\033[0;31mMaking \033[1;31mminitalk"
				@echo "\033[1;32mCompiling objects\033[0;32m"

start_link:
				@echo "\033[1;32mLinking all objects\033[0;32m"

re:				fclean all

.PHONY:			all clean fclean re