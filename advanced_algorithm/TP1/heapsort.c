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
	Binary heap
	*/

int left(int i) {
	return (2*i);
}

int right(int i) {
	return (2*i+1);
}

int parent(int i) {
	return (i/2);
}

void percolate_down(int *array, int size, int i) {
	int m;
	int l = left(i);
	int r = right(i);
	if ((l <= size) && (array[i-1] < array[l-1])) {
		m = l;
	}
	else {
		m = i;
	}
	if ((r <= size) && (array[m-1] < array[r-1])) {
		m = r;
	}
	if (m != i) {
		swap(&array[i-1], &array[m-1]);
		percolate_down(array, size, m);
	}
}

void percolate_up(int *array, int i) {
	int j = parent(i);
	while ((j > 0) && (array[j-1] < array[i-1])) {
		swap(&array[i-1], &array[j-1]);
		i = j ;
		j =parent(i);
	}

}

int pop(int *array, int *size) {
	int m = array[0];
	array[0] = array[*size-1];
 	*size = *size -1;
	percolate_down(array, *size, 1);
	return m;
}

void add(int *array, int *size, int elem){
	*size=*size+1;
	array[*size-1]=elem;
	percolate_up(array, *size);
}

void build_heap(int *array, int size) {
	if (size>0) {
		for (int i = size/2; i > 0; i--) {
			percolate_down(array, size, i);
		}
	}
}

/* Write your functions there*/
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
	int *data_heap;
	int n, k;
	FILE *f_in;

	clock_t add_start, add_end, heap_start, heap_end;
	double add_time, heap_time;

	if ( argc > 1 )
		f_in = fopen(argv[1], "r");
	else
		f_in = stdin;

	read_data( f_in, &data_heap, &n, &k );

	printf("K : %d\n", k);
	printf("D : %d\n", n);

	int add_greatest[k];
	int heap_greatest[k];

	add_start=clock();
	int size=0;
	int data_add[n+5];
	for (size_t i = 0; i < n; i++) {
		add(data_add,&size,data_heap[i]);
	}
	for (size_t i = 0; i < k; i++) {
		add_greatest[i]=pop(data_add,&size);
	}
	add_end=clock();

	heap_start=clock();
	build_heap(data_heap,n);
	for (size_t i = 0; i < k; i++) {
		heap_greatest[i]=pop(data_heap,&n);
	}
	heap_end=clock();

	add_time = ((double) (add_end - add_start)) / CLOCKS_PER_SEC;
	heap_time = ((double) (heap_end) - heap_start) / CLOCKS_PER_SEC;


	/*printf("\nHEAP :\n");
	print_data(data_heap,30);
	printf("\nADD :\n");
	print_data(data_add,30);*/

	printf("\n HEAP TIME : %.7fms \n", heap_time*1000);
	printf("\n ADD TIME : %.7fms \n\n", add_time*1000);
printf("Numbers extracted from the add sort: \n");
	print_data(add_greatest,15);
	printf("\n");
	printf("Numbers extracted from the heap sort: \n");
	print_data(heap_greatest,15);
	printf("\n");

	free(data_heap);

	return 0;
}
