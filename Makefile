output: main.o executers.o fileHandler.o memoryManagement.o threadMaker.o timeCalculator.o debug.o
		gcc main.o executers.o fileHandler.o memoryManagement.o threadMaker.o timeCalculator.o debug.o -o matmult.out -lpthread

main.o: main.c
		gcc -c main.c

executers.o: executers/executers.c
		gcc -c executers/executers.c

memoryManagement.o: memoryManagement/memoryManagement.c
		gcc -c memoryManagement/memoryManagement.c

fileHandler.o: fileHandler/fileHandler.c
		gcc -c fileHandler/fileHandler.c

threadMaker.o: threadMaker/threadMaker.c
		gcc -c threadMaker/threadMaker.c

timeCalculator.o: timeCalculator/timeCalculator.c
		gcc -c timeCalculator/timeCalculator.c

debug.o: debug/debug.c
	gcc -c debug/debug.c

clean:
		rm *.o matmult.out
