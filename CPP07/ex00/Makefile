NAME = templates

CXX = c++
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \



HEADERS = whatever.hpp



OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))


# Make silent
# MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJS) 
	@echo "Compiling $(NAME).."
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(NAME) ready!"

$(OBJS_DIR)/%.o: %.cpp $(HEADERS) | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	@echo "Cleaning objects..."
	rm -rf $(OBJS_DIR)
	@echo "Objects cleaned!"

fclean: clean
	@echo "Removing executable..."
	rm -f $(NAME)
	@echo "Full clean done!"

re: fclean all

.PHONY: all clean fclean re
