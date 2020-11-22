DEPS=  zad5_main.o zad5_dziekanat.o  zad5_studenci.o


# zad5: clean $(DEPS)
zad5_main: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f zad5_main
	rm -f *.o

test: zad5_main
	./zad5_main 1 2 3
