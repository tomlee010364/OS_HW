#include<stdio.h>
#include<time.h>
int main(void){
	FILE *fPtr;
	fPtr = fopen("test.txt", "r");

	int numberOfKeys;

	fscanf(fPtr, "%d", &numberOfKeys); // get the number of keys

	int *tmp = malloc(numberOfKeys * sizeof(int));

	if (tmp == NULL){
		printf("Error : unable to allocate required memory\n");
		return 1;
	}

	for (int i = 0; i < numberOfKeys; i++){
		fscanf(fPtr, "%d", &tmp[i]);
	} // read keys into tmp array


	int key = 0;
	int i = 0;

	clock_t t;
	t = clock();

	for (int j = 1; j < numberOfKeys; j++){
		key = tmp[j];
		i = j - 1;
		while ((i > -1) && (tmp[i] > key)){
			tmp[i + 1] = tmp[i];
			i = i - 1;
		}
		tmp[i + 1] = key;
	}
	
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("%f", time_taken);
	
	/*------------print into output.txt-------------*/
	fPtr = fopen("output.txt", "w");

	fprintf(fPtr, "%d\n", numberOfKeys);

	for (int i = 0; i < numberOfKeys; i++){
		fprintf(fPtr, "%d\n", tmp[i]);
	}

	fclose(fPtr);
	free(tmp);


	while (getchar() != EOF);
	return 0;
}
