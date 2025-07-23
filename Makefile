# target to build and run src/roguelike.c

run: src/roguelike.c
	gcc -o roguelike src/roguelike.c
	./roguelike

clean:
	rm -f roguelike