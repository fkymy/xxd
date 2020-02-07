OUT = xxd
SRC_PATH = src/
INCLUDE_PATH = include/
HEADERS = include/
CC = gcc
# CCFLAGS = -g -Wall -Werror -Wextra -fsanitize=address -fsanitize=undefined
CCFLAGS = -I $(HEADERS) -g -Wall -Werror -Wextra
SRCS = $(addprefix $(SRC_PATH), main.c utility.c error.c memdup.c memcat.c datadump.c puts.c)
OBJS = $(SRCS:.c=.o)

all: $(OUT)

$(OUT) : $(OBJS)
	$(CC) -o $(OUT) $(OBJS) $(CCFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean:
	rm -f $(OUT)

.PHONY: re
re: fclean all
