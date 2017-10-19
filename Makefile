output: main.o dataStructure.o executers.o fileHandler.o memoryManagement.o threadMaker.o timeCalculator.o
		gcc main.o dataStructure.o executers.o fileHandler.o memoryManagement.o threadMaker.o timeCalculator.o -o matmult.out -lpthread

main.o: main.c
		gcc -c main.c

dataStructure.o: dataStructures/dataStructure.c
		gcc -c dataStructures/dataStructure.c

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

clean:
		rm *.o matmult.out
