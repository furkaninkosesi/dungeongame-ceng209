CC = gcc
CFLAGS = -Wall -Wextra -std=c99


SRC_DIR = src
BUILD_DIR = build
ASSETS_DIR = assets

SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/game.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

EXEC = $(BUILD_DIR)/dungeon

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*

run: $(EXEC)
	./$(EXEC)

save: $(EXEC)
	./$(EXEC) save

load: $(EXEC)
	./$(EXEC) load

.PHONY: all clean run save load
