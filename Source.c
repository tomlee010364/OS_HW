#include<stdio.h>

void merge(int arr[], int head, int mid, int tail){
	int a_length = mid - head + 1;
	int b_length = tail - (mid + 1) + 1;
	int *a = malloc(a_length * sizeof(int));
	int *b = malloc(b_length * sizeof(int));

	for (int i = 0; i < a_length; i++){
		a[i] = arr[head + i];
	}
	for (int j = 0; j < b_length; j++){
		b[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = head;
	
	while (i < a_length && j < b_length){
		if (a[i] < b[j]){
			arr[k] = a[i];
			i++;
		}
		else{
			arr[k] = b[j];
			j++;
		}
		k++;
	}

	while (i < a_length){
		arr[k] = a[i];
		i++;
		k++;
	}

	while (j < b_length){
		arr[k] = b[j];
		j++;
		k++;
	}

	free(a);
	free(b);
}

void merge_sort(int arr[], int head, int tail){
	if (head < tail){
		int mid = (head + tail) / 2;
		merge_sort(arr, head, mid);
		merge_sort(arr, mid + 1, tail);
		merge(arr, head, mid, tail);
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
	
	merge_sort(tmp, 0, numberOfKeys - 1);

	for (int i = 0; i < numberOfKeys; i++){
		printf("%d ", tmp[i]);
	}

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