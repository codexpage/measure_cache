CC=gcc
CFLAGS=-g -O0 -fPIC -std=gnu99
TESTS=ram cache


%: %.c
	$(CC) $(CFLAGS) $< -o $@ 

%.o: %.c ${HEADERS}
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf *.o $(TESTS)

checkmem: ram
	./ram
checkcache: cache 
	./cache

dist: clean
	dir=`basename $$PWD`; cd ..; tar cvf $$dir.tar ./$$dir; gzip $$dir.tar