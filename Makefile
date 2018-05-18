# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malberte <malberte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 22:08:39 by acoulomb          #+#    #+#              #
#    Updated: 2018/05/17 22:49:38 by malberte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

#BINARIES:
CC          = /usr/bin/clang
RM          = /bin/rm
MAKE        = /usr/bin/make

#LIBFT:
LFTPATH     = libft
LIBFT       = $(LFTPATH)/libft.a

#FLAGS:
CC = clang
FLAGS = -Wall -Wextra -Werror
LDFLAGS = -L $(LFTPATH) -lft

#EXECUTABLE:
NAME = printf

#SRCS:
SRCS =	flags.c \
		ft_printf.c \
		main.c

#OBJ:
OBJS = $(SRCS:.c=.o)

#HEADERS:
HEADS =	



all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c $(HEADS)
	@$(CC) -c $(FLAGS) -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LFTPATH)

clean:
	@$(MAKE) -C $(LFTPATH) clean
	@$(RM) -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LFTPATH) fclean
	@$(RM) -rf $(NAME)

cleanlib:
	$(MAKE) clean -C $(LFTPATH)

re: fclean all

g: re $(OBJS)
	$(CC) $(FLAGS) -g $(SRCS) $(LIBFT) -o $(NAME)

.PHONY = re all clean fclean g