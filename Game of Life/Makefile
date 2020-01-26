SRC:=$(wildcard *.c)
OBJ:=$(SRC:.c=.o)

gameoflife: $(OBJ)
	gcc -o $@ $^

%.o: %.c
	gcc -o $@ -c $< -g

clean:
	rm -f gameoflife $(OBJ)
