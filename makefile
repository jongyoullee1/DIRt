 dirt: dirt.c
	clang dirt.c -o dirt

clean:
	rm *~

run: dirt
	./dirt
