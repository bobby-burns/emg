GLFW=`pkg-config --cflags glfw3` `pkg-config --libs glfw3`
main:
	gcc src/*.c libs/*.c  src/modules/*.c $(GLFW) -g -ldl -Wall -o test