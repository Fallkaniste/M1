#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
	Reading and writing data
 */
void read_data( FILE *datain, int **dataout, int *n, int *k ) {
	int *data;

	fscanf(datain, "%d", n);
	*dataout = (int *)malloc( (*n) * sizeof(int) );
	data=*dataout;
	fscanf(datain, "%d", k);

	for ( int i=0; i< *n; ++i, ++data )
		fscanf( datain, "%d", data );
}

void print_data(int *array, int size) {
        for( int i=0; i<size; ++i)
		printf( "%d ", array[i] );
	printf("\n");
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

static int compare (void const *a, void const *b)
{
   int const *pa = a;
   int const *pb = b;
   return *pa - *pb;
}
/**
	Bubble sort
	*/
void bubble_sort(int *array, int size, int k) {
	k=size-k;
   for (int i = size-1; i > k; i--) {
		 for (int j = 0; j < i; j++) {
			 if (array[j+1] < array[j]) {
				 swap(&array[j+1], &array[j]);
			 }
		 }
	 }
}

/* Main Program*/
int main( int argc, char **argv ) {
	int *data_bubble;
	int n, k;
	FILE *f_in;

	clock_t bubble_start, bubble_end, qsort_start, qsort_end;
	double bubble_time, qsort_time;

	if ( argc > 1 )
		f_in = fopen(argv[1], "r");
	else
		f_in = stdin;

	/* read the data from the file given in arg or from stdin */
	read_data( f_in, &data_bubble, &n, &k );


	printf("D : %d\n", n);
	k=1;
	printf("K = 1 (arbitrary choice, needed for the time comparison)\n");

	int data_sort[n];
	for (size_t i = 0; i < n; i++) {
		data_sort[i]=data_bubble[i];
	}

	qsort_start=clock();
	qsort(&data_sort,n,sizeof(int),compare);
	qsort_end=clock();

	bubble_start=clock();
	bubble_sort(data_bubble,n,k);
	bubble_end=clock();

	qsort_time = ((double) (qsort_end - qsort_start)) / CLOCKS_PER_SEC;
	bubble_time = ((double) (bubble_end) - bubble_start) / CLOCKS_PER_SEC;

	while(k<n&&bubble_time<=qsort_time)
	{
		k++;
		bubble_start=clock();
		bubble_sort(data_bubble,n,k);
		bubble_end=clock();
		bubble_time = ((double) (bubble_end) - bubble_start) / CLOCKS_PER_SEC;
	}

	printf("\n\n you will need to extract %d numbers for the qsort to be more effecient than the optimized bubble sort\n",k );
	printf("\n Qsort TIME : %.7fms \n", qsort_time);
	printf("\n Bubble TIME : %.7fms \n\n", bubble_time);

	printf("Numbers extracted by the quick sort are :\n");
	for (size_t i = n-1; i > n-k; i--) {
		printf("%d ", data_sort[i]);
	}
	printf("\n\nNumbers extracted by the bubble sort are :\n");
	for (size_t i = n-1; i > n-k; i--) {
		printf("%d ", data_bubble[i]);
	}
	printf("\n");
	 free(data_bubble);
	return 0;
}
