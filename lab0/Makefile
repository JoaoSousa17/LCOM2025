CC = cc
CFLAGS = -Wall -Wextra -g
TARGET = my_program
SRC = main.c helper.c
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)