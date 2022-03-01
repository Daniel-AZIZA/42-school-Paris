NAME=vectlib.a
TEST_NAME=vectest

CC = clang
SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, utils.c vector.c vector_utils.c)
TEST_SRC = test.c

OBJDIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c= $(OBJDIR)/%.o)
OBJ_PATHS = $(shell ls -R $(SRC_DIR) | grep / | sed 's/://g' | sed 's/src/$(OBJDIR)/g')

HEADERS_PATH = ./includes/
INCLUDE = -I./includes
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDE)
LDFLAGS = 


HEADERS = $(addprefix $(HEADERS_PATH), \
				vector.h \
			)

all: $(NAME) $(HEADERS)


$(NAME): $(OBJDIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $< 

test:$(TEST_NAME)

$(TEST_NAME): $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) $(TEST_SRC) $(NAME) -o $(TEST_NAME)

clean:
	$(RM) -rf $(OBJDIR)
	$(RM) $(TEST_NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all	

.PHONY: all clean fclean re