CC = gcc
CFLAGS = -W -Wall
LDFLAGS = -lallegro -lallegro_image -lallegro_font -lallegro_ttf

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include

EXE = Galaga
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

all: $(EXE)
 
$(EXE): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) -I$(INC_DIR) -o $(BIN_DIR)/$@ $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@
 
clean:
	$(RM) $(OBJ)

.PHONY: all clean