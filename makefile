CC = clang
LD =
CFLAGS = -Wall -Wextra -O2 -nostdlib -Isrc/include -Iinclude --target=wasm32-unknown-unknown -DHAVE_MMAP=0 -Isrc/internal
SRC_DIR = src
OBJ_DIR = obj
TARGET = libc.wasm
DEPFLAGS = -MMD -MP

SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

$(TARGET): $(OBJS)
	@echo "Archiving object files into $(TARGET)"
	llvm-ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: clean