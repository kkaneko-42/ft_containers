SRCS	:=	enable_if_test.cpp \
			is_integral_test.cpp \
			equal_test.cpp \
			lexicographical_compare_test.cpp \
			pair_test.cpp \
			vector_test.cpp \
			vector_test_cases.cpp
INC_DIR := ../include
OBJ_DIR := ./objs
OBJS	:= $(SRCS:.cpp=.o)
DEPS 	:= $(OBJS:.o=.d)
CXX		:= c++
CXXFLAGS:= -Wall -Wextra -Werror -MMD -MP -fsanitize=address -fsanitize=undefined -g3

all: enable_if is_integral equal lexicographical_compare pair

enable_if: enable_if_test.o 
	$(CXX) $(CXXFLAGS) $^ -o $@ -I $(INC_DIR)

is_integral: is_integral_test.o 
	$(CXX) $(CXXFLAGS) $^ -o $@ -I $(INC_DIR)

equal: equal_test.o 
	$(CXX) $(CXXFLAGS) $^ -o $@ -I $(INC_DIR)

lexicographical_compare: lexicographical_compare_test.o 
	$(CXX) $(CXXFLAGS) $^ -o $@ -I $(INC_DIR)

pair: pair_test.o 
	$(CXX) $(CXXFLAGS) $^ -o $@ -I $(INC_DIR)

iterator: iterator_test.o 
	$(CXX) $(CXXFLAGS) $^ -o $@ -I $(INC_DIR)

vector: vector_test.o vector_test_cases.o
	$(CXX) $(CXXFLAGS) $^ -o $@ -I $(INC_DIR)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -I $(INC_DIR)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -f enable_if is_integral equal lexicographical_compare pair iterator vector

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re debug