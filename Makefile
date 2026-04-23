CC := gcc
CFLAGS := -Wall -Wextra -o3

TARGET := example
SOURCES := dd_matrix_static.c dd_matrix_operations.c example.c 
HEADERS := dd_matrix.h dd_matrix_operations.h dd_matrix_static.h dd_matrix_error.h
OBJECTS := $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking files..."
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)