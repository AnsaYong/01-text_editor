# Define the compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Define the source and target files
SRC = *.c
TARGET = e

# The default target, which builds the e executable
all: $(TARGET)

# Compile the source code and create the executable
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

# Clean up generated files
clean:
	rm -f $(TARGET)

# .PHONY rule to prevent conflicts with files of the same name
.PHONY: all clean
