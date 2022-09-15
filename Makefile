NAME	:= a.out
SRCS	:= main.cpp vector.cpp
SRC_DIR := ./src
INC_DIR := ./include
OBJ_DIR := ./objs
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS 	:= $(OBJS:.o=.d)
VPATH	:= $(SRC_DIR)
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD -MP

ifdef DEBUG
	FLAGS += -fsanitize=address -g3
endif

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	make DEBUG=1

-include $(DEPS)

.PHONY: all clean fclean re debug