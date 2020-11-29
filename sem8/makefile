DEPS = main.o liczydlo.o wczytajpliki.o

main: $(DEPS)
cc $(DEPS) -o $@ -Wall --pedantic

%.o : %.c
	cc -c $^ -o $@

clean:
	rm -f zad6
	rm -f *.o
