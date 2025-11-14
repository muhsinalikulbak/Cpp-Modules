NAME = phonebook

CXX = c++
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98

SRCS = Contact.cpp \
	   PhoneBook.cpp \
	   main.cpp

OBJS_DIR = obj
OBJS = $(OBJS_DIR)/Contact.o $(OBJS_DIR)/PhoneBook.o $(OBJS_DIR)/main.o

HEADERS = Contact.hpp PhoneBook.hpp

# Make silent
MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@echo "✅ Compiling $(NAME).."
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "✅ $(NAME) Ready!"

$(OBJS_DIR)/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	@echo "🧹 Cleaning objects..."
	rm -rf $(OBJS_DIR)
	@echo "✅ Objects cleaned!"

fclean: clean
	@echo "🧹 Removing executable..."
	rm -f $(NAME)
	@echo "✅ Full clean done!"

re: fclean all

.PHONY: all clean fclean re
