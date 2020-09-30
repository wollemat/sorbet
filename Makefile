
bin/sorbet:
	mkdir bin
	gcc src/main.c -o bin/sorbet
	chmod a+x bin/sorbet

clean:
	rm -rf bin

