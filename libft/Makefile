NAME	= libft.a
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC	=	ft_memset.c	\
		ft_bzero.c	\
		ft_memcpy.c	\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_strlen.c	\
		ft_strdup.c	\
		ft_strcpy.c	\
		ft_strncpy.c	\
		ft_strcat.c	\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strchr.c	\
		ft_strrchr.c	\
		ft_strstr.c	\
		ft_strnstr.c	\
		ft_strcmp.c	\
		ft_atoi.c	\
		ft_strncmp.c	\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_isblank.c \
		ft_iscntrl.c \
		ft_isgraph.c \
		ft_ispunct.c \
		ft_isspace.c \
		ft_isxdigit.c \
		ft_memalloc.c	\
		ft_memdel.c	\
		ft_realloc.c \
		ft_strnew.c	\
		ft_strdel.c	\
		ft_strclr.c	\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c	\
		ft_strmapi.c	\
		ft_strequ.c	\
		ft_strnequ.c	\
		ft_strsub.c	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strsplit.c	\
		ft_itoa.c	\
		ft_putchar.c	\
		ft_putstr.c	\
		ft_putendl.c	\
		ft_putnbr.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_lstnew.c	\
		ft_lstdelone.c	\
		ft_lstdel.c	\
		ft_lstadd.c	\
		ft_lstiter.c \
		ft_lstmap.c \
		ft_islower.c	\
		ft_isupper.c	\
		ft_llist_create.c		\
		ft_llist_create_node.c	\
		ft_llist_add_first.c	\
		ft_llist_add_nodup.c \
		ft_llist_rm_first.c	\
		ft_llist_add_last.c	\
		ft_llist_rm_last.c		\
		ft_llist_destroy_node.c	\
		ft_llist_destroy.c		\
		ft_llist_contains.c	\
		ft_llist_indexof.c		\
		ft_llist_last_indexof.c	\
		ft_llist_copy.c		\
		ft_llist_merge.c		\
		ft_llist_add_at.c		\
		ft_llist_get_at.c		\
		ft_llist_rm_at.c		\
		ft_llist_set_at.c		\
		ft_llist_foreach.c		\
		ft_llist_inverse.c		\
		ft_llist_map.c		\
		ft_llist_sort.c		\
		ft_llist_sorted_insert.c	\
		ft_llist_sorted_merge.c	\
		ft_llist_to_array.c	\
		ft_llist_to_set.c \
		ft_array_to_llist.c	

HEADERS	= libft.h
OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating" $(NAME)
	@ar rc $@ $^
	@echo "Generate index to" $(NAME)
	@ranlib $@ 

%.o: %.c
	@$(CC) $(CFLAGS) -c $<
	@echo "Compiling" $@

clean: 
	@/bin/rm -f $(OBJ) 
	@echo "Cleaning" $(NAME)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Deleting" $(NAME)

re: fclean all

.PHONY: all clean fclean re
