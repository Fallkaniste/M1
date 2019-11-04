#include <stdlib.h>
#include <stdio.h>

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
	if ((l <= size) && (array[i-1] < array[r-1])) {
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

int pop(int *array, int *size) {
	int m = array[0];
	array[0] = array[*size-1];
 	*size = *size -1;
	percolate_down(array, *size, 1);
	return m;
}

void build_heap(int *array, int size) {
	if (size>0) {
		for (int i = size/2; i > 0; i--) {
			percolate_down(array, size, i);
		}
	}
}

/* Write your functions there*/


/* Main Program*/
int main( int argc, char **argv ) {
	int *data;
	int n, k;
	FILE *f_in;

	if ( argc > 1 )
		f_in = fopen(argv[1], "r");
	else
		f_in = stdin;

	/* read the data from the file given in arg or from stdin */
	read_data( f_in, &data, &n, &k );
	//bubble_sort(data,n,k);
	build_heap(data,n);

	pop(data,&n);

	/* print the array */
	print_data(data,n);
	printf("K : %d\n", k);
	printf("D : %d\n", n);


	/* use your functions there*/

	/* output result */


	/* end of the program*/
	 free(data);
	return 0;
}
