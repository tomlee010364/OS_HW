#include<stdio.h>

void merge(int arr[], int a[], int b[], int length){
	int length_a = length / 2;
	int length_b = length - length_a;
	int i = 0, j = 0, k = 0;
	while (i < length_a && j < length_b){
		if (a[i] < b[j]){
			arr[k] = a[i];
			i++;
		}
		else{
			arr[k] = b[j];
			j++;
		}
		k++;
	} // choose the smaller key from the first index of a and b  
	while (i < length_a){
		arr[k] = a[i];
		k++;
		i++;
	}
	while (j < length_b){
		arr[k] = b[j];
		k++;
		j++;
	}
}

void merge_sort(int arr[], int length){
	int mid = length / 2;
	int *a;
	int *b;

	if (length < 2){
		return;
	} // stop recursion
	else{
		a = malloc(mid * sizeof(int));
		b = malloc((length - mid) * sizeof(int));
		for (int i = 0; i < mid; i++){
			a[i] = arr[i];
		}
		for (int i = mid; i < length; i++){
			b[i - mid] = arr[i];
		} // seperate arr into two part
		merge_sort(a, mid);
		merge_sort(b, length - mid); // go into recursion
		merge(arr, a, b, length);
	}
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
	
	merge_sort(tmp, numberOfKeys);

	fPtr = fopen("output.txt", "w");
	
	for (int i = 0; i < numberOfKeys; i++){
		fprintf(fPtr, "%d ", tmp[i]);
	}
	fprintf(fPtr, "\n");
	for (int i = 0; i < numberOfKeys; i++){
		fprintf(fPtr, "%d : %d\n", i + 1, tmp[i]);
	}

	fclose(fPtr);
	free(tmp);
	

	while (getchar() != EOF);

	return 0;
}