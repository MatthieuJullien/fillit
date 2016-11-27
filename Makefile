NAME		:=	fillit
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

SRCDIR		:=	sources
SRCFILES	:=	main.c
SRC			:=	$(addprefix $(SRCDIR)/, $(SRCFILES))

OBJDIR		:=	objects
OBJ			:=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

LIBFTDIR	:=	libft
LIBFTFILE	:=	$(LIBFTDIR)/libft.a
LIBFT		:=	-L $(LIBFTDIR) -lft

INCDIR		:=	includes

all: obj $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(NAME): $(LIBFTFILE) $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@ -I $(INCDIR) $(LIBFT)
	@echo "Compiling" $(NAME)

$(LIBFTFILE):
	@echo "Making libft.a"
	@make -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling" $@
	@$(CC) $(CFLAGS) -c -o $@ $< -I $(INCDIR) -I $(LIBFTDIR) $(LIBFT)

clean:
	@echo "Cleaning" $(NAME)
	@/bin/rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean


fclean:
	@echo "Deleting objects"
	@/bin/rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) fclean
	@echo "Deleting" $(NAME)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all obj clean fclean re
