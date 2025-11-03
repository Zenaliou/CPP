CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP

SRCS = main.cpp \
    Amateria.cpp \
    Ice.cpp \
    Cure.cpp \
    Character.cpp \
    MateriaSource.cpp
OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(OBJS:.o=.d)
NAME = materia

GREEN   = \033[1;32m
RED     = \033[1;31m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
CYAN    = \033[1;36m
NC      = \033[0m

all: $(NAME)
    @echo "$(CYAN)Tout est pret !$(NC)"

$(NAME): $(OBJ_DIR) $(OBJS)
    @echo "$(YELLOW)Compilation de $(NAME)...$(NC)"
    @$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
    @echo "$(GREEN)Compilation de $(NAME) reussie!$(NC)"

$(OBJ_DIR):
    @mkdir -p $(OBJ_DIR)
    @echo "$(BLUE)Dossier obj cree.$(NC)"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
    @$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
    @rm -rf $(OBJ_DIR)
    @echo "$(RED)Fichiers objets supprimes.$(NC)"

fclean: clean
    @rm -f $(NAME)
    @echo "$(RED)Executable $(NAME) supprime.$(NC)"

re: fclean all
    @echo "$(CYAN)Recompilation terminee.$(NC)"

.PHONY: all clean fclean re