# incluir reglas para compilar la libreria libft

CC= gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT_DIR = .

# incluir el header para que sea accesible por el compilador
CFLAGS += -I.

# todos los sourcefiles que queraos añadir
SRCS = push_swap.c

REMOVE = rm -rf

# convertimos todos los source files a object files
OBJS = $(SRCS:.c=.o)

# compilamos la libreria junto a todos los otros archivos
LDFLAGS = -L$(LIBFT_DIR) -lftb

all: $(NAME)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME) $(OBJS)

#Hacemos el ejecutable
$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
