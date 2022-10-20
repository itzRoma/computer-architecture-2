CC = gcc

utils: main.o utils.o
	@echo ""
	@echo "making default goal..."
	$(CC) main.c utils.c -o utils
	@echo "default goal making finished"
	@echo ""

main.o: main.c utils.h
	@echo ""
	@echo "making dependency goal 1..."
	$(CC) -c main.c
	@echo "dependency goal 1 making finished"
	@echo ""

utils.o: utils.c utils.h
	@echo ""
	@echo "making dependency goal 2..."
	$(CC) -c utils.c
	@echo "dependency goal 2 making finished"
	@echo ""

clean:
	@echo ""
	@echo "cleaning started..."
	rm *.o utils
	@echo "cleaning finished"
	@echo ""
