# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:43:11 by eviscont          #+#    #+#              #
#    Updated: 2024/01/25 15:40:11 by eviscont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Comandos
CFLAGS = -Wall -Wextra -Werror

# Nombre ejecutable
CLIENT_NAME = client
SERVER_NAME = server

# Ficheros
SRCS_CLIENT = client.c
SRCS_SERVER = server.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
HEADER = minitalk.h

LIBS = ft_printf/libftprintf.a

# Reglas
all: libs $(SERVER_NAME) $(CLIENT_NAME)

# Compilar
libs:
	@make -C ft_printf

$(CLIENT_NAME): $(OBJS_CLIENT)
	gcc $(CFLAGS) -o $(CLIENT_NAME) $(OBJS_CLIENT) $(LIBS)

$(SERVER_NAME): $(OBJS_SERVER)
	gcc $(CFLAGS) -o $(SERVER_NAME) $(OBJS_SERVER) $(LIBS)

%.o: %.c
		gcc $(CFLAGS) -c -o $@ $<

# Eliminar temporales

clean:
	@make clean -C ft_printf
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME) $(LIBS)

re: fclean all