pl: main.c accr.c
	gcc main.c accr.c -o pl -lm -lraylib

clean:
	rm -f pl
