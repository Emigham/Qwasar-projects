SRC = my_mastermind.c
OBJ = $(SRC:.c=.o)
TARGET = my_mastermind
CFLAGS = -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)

clean:
	 rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all