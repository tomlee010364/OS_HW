#include<stdio.h>
#include<time.h>

int Partition(int arr[], int p, int r){
	int x = arr[r];
	int i = p - 1;
	int tmp;
	for (int j = p; j < r; j++){
		if (arr[j] <= x){
			i += 1;
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
	tmp = arr[r];
	arr[r] = arr[i + 1];
	arr[i + 1] = tmp;
	return (i + 1);
}

void Quicksort(int arr[], int p, int r){
	if (p < r){
		int q = Partition(arr, p, r);
		Quicksort(arr, p, q - 1);
		Quicksort(arr, q + 1, r);
	}
	return;
}

int main(void){
	FILE *fPtr;
	fPtr = fopen("test.txt", "r"); // read file from "test.txt"

	int numberOfKeys;

	fscanf(fPtr, "%d", &numberOfKeys); // get the number of keys

	int *tmp = malloc(numberOfKeys * sizeof(int));

	if (tmp == NULL){
		printf("Error: unable to allocate required memory\n");
		return 1;
	}

	for (int i = 0; i < numberOfKeys; i++){
		fscanf(fPtr, "%d", &tmp[i]);
	} // read keys into tmp array
	clock_t t;
	t = clock();
	Quicksort(tmp, 0, numberOfKeys - 1);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("%f", time_taken);
	/*---------------print into output.txt---------------------*/
	fPtr = fopen("output.txt", "w");

	fprintf(fPtr, "%d ", numberOfKeys);
	
	fprintf(fPtr, "\n");
	for (int i = 0; i < numberOfKeys; i++){
		fprintf(fPtr, "%d\n", tmp[i]);
	}

	fclose(fPtr);
	free(tmp);

	while (getchar() != EOF);
	return 0;
}