NAME		:=	fillit
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

SRCDIR		:=	sources
SRCFILES	:=	main.c \
				grid.c \
				parse.c \
				check.c \
				solve.c \
				print.c
SRC			:=	$(addprefix $(SRCDIR)/, $(SRCFILES))

OBJDIR		:=	objects
OBJ			:=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

LIBFTDIR	:=	libft
LIBFTINCDIR	:=	$(LIBFTDIR)/includes
LIBFTFILE	:=	$(LIBFTDIR)/libft.a
LIBFT		:=	-L $(LIBFTDIR) -lft

INCDIR		:=	includes

all: $(NAME)

$(NAME): $(LIBFTFILE) $(OBJ)
	@echo "Compiling" $(NAME)
	@$(CC) $(CFLAGS) $^ -o $@ -I $(INCDIR) $(LIBFT)

$(LIBFTFILE):
	@echo "Making libft.a"
	@make -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	@echo "Compiling" $@
	@$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR) -I $(LIBFTINCDIR)

clean:
	@make -C $(LIBFTDIR) clean
	@echo "Cleaning" $(NAME)
	@/bin/rm -rf $(OBJDIR)


fclean:
	@echo "Deleting objects"
	@/bin/rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) fclean
	@echo "Deleting" $(NAME)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
