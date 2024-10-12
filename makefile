NAME = 2048

CC = g++
RM = rm -rf
FLAGS = 

# Définir les fichiers source et les objets
SRC_FILES = ./src/2048.cpp ./src/main.cpp

OBJS = $(patsubst ./src/%.cpp, $(OBJS_F)%.o, $(SRC_FILES))
OBJS_F = _objFiles/

# Règle principale pour créer l'exécutable
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(FLAGS) -o $(NAME)
	@echo -ne '\033[32m                            (0%)\r'
	@sleep 0.2
	@echo -ne '#####                      (33%)\r'
	@sleep 0.2
	@echo -ne '#############              (66%)\r'
	@sleep 0.2
	@echo -ne '#######################   (100%)\r'
	@echo -ne '\n'
	@echo "\033[33mC'est compilé !"

# Compilation des fichiers objets
$(OBJS_F)%.o: ./src/%.cpp
	@mkdir -p $(OBJS_F)
	@$(CC) $(FLAGS) -c $< -o $@

# Cible pour tout compiler
all: $(NAME)

# Nettoyage des objets
clean:
	@$(RM) $(OBJS_F)
	@echo -ne '\033[36m#######################   (100%)\r'
	@sleep 0.2
	@echo -ne '#############              (66%)\r'
	@sleep 0.2
	@echo -ne '#####                      (33%)\r'
	@sleep 0.2
	@echo -ne '                            (0%)\r'
	@echo -ne '\n'
	@echo "\033[33mC'est clean !"

# Nettoyage complet
fclean: clean
	@$(RM) $(NAME)
	@echo -ne '\033[34m#######################   (100%)\r'
	@sleep 0.2
	@echo -ne '#############              (66%)\r'
	@sleep 0.2
	@echo -ne '#####                      (33%)\r'
	@sleep 0.2
	@echo -ne '                            (0%)\r'
	@echo -ne '\n'
	@echo "\033[33mC'est fclean !"

# Recompiler tout
re: fclean all
