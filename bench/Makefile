INC_DIR := ../include
SRCS	:=	vector_bench.cpp\
			Stopwatch.cpp \
			vector_bench_cases.cpp
OBJS	:= $(SRCS:.cpp=.o)
DEPS	:= $(OBJS:.o=.d)
CXX		:= c++
CXXFLAGS:= 

all: vector

vector: vector_bench.o vector_bench_cases.o Stopwatch.o
	$(CXX) $(CXXFLAGS) $^ -o $@ -I $(INC_DIR)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -I $(INC_DIR)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f vector

re: fclean all

-include: $(DEPS)

.PHONY: all clean fclean re