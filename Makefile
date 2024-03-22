CC = gcc

CFLAGS =  -O3
CFLAGS += -D _DEBUG -ggdb3 -Wall -Wextra  -Waggressive-loop-optimizations -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wopenmp-simd -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-varargs -Wstack-protector -fcheck-new -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

OBJ_DIR = obj

SRCS  = testing.c
SRCS += src/memswap/memswap.c
SRCS += src/do_tests/tester.c
SRCS += src/dirs/dirs.c
SRCS += src/graphs_generator/gen_graph.c

OBJS = $(SRCS:.c=.o)
%.o: %.c
	@mkdir -p $(dir $(OBJ_DIR)/$@)
	@$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

swaps.out: $(OBJS)
	@$(CC) $(CFLAGS) $(patsubst %,obj/%,$(OBJS)) -o $@

clean:
	@rm -rf $(OBJ_DIR) swaps.out