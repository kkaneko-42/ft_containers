NAME	:= is_integral
SRCS	:= main.cpp vector.cpp
SRC_DIR := ../src
INC_DIR := ../include
OBJ_DIR := ./objs
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS 	:= $(OBJS:.o=.d)
VPATH	:= $(SRC_DIR)
CXX		:= c++
CXXFLAGS:= -Wall -Wextra -Werror -MMD -MP -fsanitize=address -fsanitize=undefined -g3

is_integral: is_integral_test.cpp $(OBJ_DIR) 
	$(CXX) $(CXXFLAGS) -c $< -o $(OBJ_DIR)/is_integral_test.o -I $(INC_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/is_integral_test.o -o $@ -I $(INC_DIR)

all: is_integral

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	mkdir -p $@

-include $(DEPS)

.PHONY: all clean fclean re debug