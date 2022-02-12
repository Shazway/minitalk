SRCS_MEM	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c
SRCS_STR	=	ft_strchr.c ft_strdup.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strlen.c ft_error.c
SRCS_PUTFD	=	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_IS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c
SRCS_TO		=	ft_atoi.c ft_itoa.c 
SRCS_MALLOC	=	ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_malloc.c ft_free_tab.c
SRCS_PRINTF =	ft_printf/ft_printf.c ft_printf/ft_parsing.c ft_printf/ft_putnbr_base.c ft_printf/ft_putnbr_base_2.c ft_printf/ft_hex.c ft_printf/ft_u.c ft_printf/ft_d_i.c ft_printf/ft_utils.c ft_printf/ft_p.c ft_printf/ft_s.c
SRCS		=	${SRCS_MEM} ${SRCS_STR} ${SRCS_PUTFD} ${SRCS_IS} ${SRCS_TO} ${SRCS_MALLOC} ${SRCS_PRINTF} ${SRCS_LST}
SRCS_LST	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc
RM			=	rm -f
NAME		=	libft.a

FLAGS		=	-Wall -Werror -Wextra -Ift_printf -I./

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re