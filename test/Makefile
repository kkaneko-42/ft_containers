SRCS	:=	enable_if_test.cpp \
			is_integral_test.cpp \
			equal_test.cpp \
			lexicographical_compare_test.cpp \
			pair_test.cpp
INC_DIR := ../include
OBJ_DIR := ./objs
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS 	:= $(OBJS:.o=.d)
CXX		:= c++
CXXFLAGS:= -Wall -Wextra -Werror -MMD -MP -fsanitize=address -fsanitize=undefined -g3

all: enable_if is_integral equal lexicographical_compare pair

enable_if: enable_if_test.cpp $(OBJ_DIR) 
	$(CXX) $(CXXFLAGS) -c $< -o $(OBJ_DIR)/enable_if_test.o -I $(INC_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/enable_if_test.o -o $@ -I $(INC_DIR)

is_integral: is_integral_test.cpp $(OBJ_DIR) 
	$(CXX) $(CXXFLAGS) -c $< -o $(OBJ_DIR)/is_integral_test.o -I $(INC_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/is_integral_test.o -o $@ -I $(INC_DIR)

equal: equal_test.cpp $(OBJ_DIR) 
	$(CXX) $(CXXFLAGS) -std=c++98 -c $< -o $(OBJ_DIR)/equal_test.o -I $(INC_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/equal_test.o -o $@ -I $(INC_DIR) -I $(INC_DIR)

lexicographical_compare: lexicographical_compare_test.cpp $(OBJ_DIR) 
	$(CXX) $(CXXFLAGS) -std=c++98 -c $< -o $(OBJ_DIR)/lexicographical_compare_test.o -I $(INC_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/lexicographical_compare_test.o -o $@ -I $(INC_DIR)

pair: pair_test.cpp $(OBJ_DIR) 
	$(CXX) $(CXXFLAGS) -std=c++98 -c $< -o $(OBJ_DIR)/pair_test.o -I $(INC_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/pair_test.o -o $@ -I $(INC_DIR)

iterator: iterator_test.cpp $(OBJ_DIR) 
	$(CXX) $(CXXFLAGS) -c $< -o $(OBJ_DIR)/iterator_test.o -I $(INC_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/iterator_test.o -o $@ -I $(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f enable_if is_integral equal lexicographical_compare pair iterator

re: fclean all

$(OBJ_DIR):
	mkdir -p $@

-include $(DEPS)

.PHONY: all clean fclean re debug