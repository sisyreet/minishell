NAME			= minishell

SRCS_M			= main.c utils.c \
				includes/ft_strlcpy.c includes/ft_strlen.c includes/ft_strncmp.c \
				includes/minishell_split.c \
				builtins/ft_cd.c builtins/ft_echo.c builtins/ft_env.c builtins/ft_exit.c \
				builtins/ft_export.c builtins/ft_pwd.c builtins/unset.c
				

SRCS_B			= main.c utils.c \
				includes/ft_strlcpy.c includes/ft_strlen.c includes/ft_strncmp.c \
				includes/minishell_split.c \
				builtins/ft_cd.c builtins/ft_echo.c builtins/ft_env.c builtins/ft_exit.c \
				builtins/ft_export.c builtins/ft_pwd.c builtins/unset.c

HEADER			= includes/minishell.h

OBJS_M			= $(SRCS_M:.c=.o)
OBJS_B			= $(SRCS_B:.c=.o)

GCC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g
RLFLAGS			= -lreadline

.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):		$(if $(findstring bonus, $(MAKECMDGOALS)), $(OBJS_B), $(OBJS))
				$(CC) $^ $(RLFLAGS) -o $(NAME)

%.o:			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@ 

clean:			
				$(RM) $(OBJS_M) $(OBJS_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all