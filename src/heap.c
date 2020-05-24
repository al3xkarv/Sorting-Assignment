/* C implementation QuickSort */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>    /*signals*/
#include <sys/times.h>  /* times() */
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>


#define SIZEofBUFF 20
#define SSizeofBUFF 6

typedef struct{
	long  	custid;
	char 	FirstName[SIZEofBUFF];
	char 	LastName[SIZEofBUFF];
	char	Street[SIZEofBUFF];
	int 	HouseID;
	char	City[SIZEofBUFF];
	char	postcode[SSizeofBUFF];
	float  	amount;
} MyRecord;

//initial code before changes from
//https://www.geeksforgeeks.org/quick-sort/

// A utility function to swap two elements
void swap(MyRecord* a, MyRecord* b)
{
								MyRecord rec = *a;
								*a = *b;
								*b = rec;
}


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify_custid(MyRecord arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l].custid > arr[largest].custid)
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r].custid > arr[largest].custid)
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify_custid(arr, n, largest);
	}
}

void heapify_FirstName(MyRecord arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && strcmp(arr[l].FirstName , arr[largest].FirstName)>0)
		largest = l;

	// If right child is larger than largest so far
	if (r < n && strcmp(arr[r].FirstName , arr[largest].FirstName)>0)
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify_FirstName(arr, n, largest);
	}
}

void heapify_LastName(MyRecord arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && strcmp(arr[l].LastName , arr[largest].LastName)>0)
		largest = l;

	// If right child is larger than largest so far
	if (r < n && strcmp(arr[r].LastName , arr[largest].LastName)>0)
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify_LastName(arr, n, largest);
	}
}

void heapify_Street(MyRecord arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && strcmp(arr[l].Street , arr[largest].Street)>0)
		largest = l;

	// If right child is larger than largest so far
	if (r < n && strcmp(arr[r].Street , arr[largest].Street)>0)
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify_Street(arr, n, largest);
	}
}

void heapify_HouseID(MyRecord arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l].HouseID > arr[largest].HouseID)
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r].HouseID > arr[largest].HouseID)
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify_HouseID(arr, n, largest);
	}
}

void heapify_City(MyRecord arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && strcmp(arr[l].City , arr[largest].City)>0)
		largest = l;

	// If right child is larger than largest so far
	if (r < n && strcmp(arr[r].City , arr[largest].City)>0)
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify_City(arr, n, largest);
	}
}

void heapify_postcode(MyRecord arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && strcmp(arr[l].postcode, arr[largest].postcode)>0)
		largest = l;

	// If right child is larger than largest so far
	if (r < n && strcmp(arr[r].postcode, arr[largest].postcode)>0)
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify_postcode(arr, n, largest);
	}
}

void heapify_amount(MyRecord arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l].amount > arr[largest].amount)
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r].amount > arr[largest].amount)
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify_amount(arr, n, largest);
	}
}

// main function to do heap sort


void heapSort_custid(MyRecord arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_custid(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify_custid(arr, i, 0);
	}
}


void heapSort_FirstName(MyRecord arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_FirstName(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify_FirstName(arr, i, 0);
	}
}


void heapSort_LastName(MyRecord arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_LastName(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify_LastName(arr, i, 0);
	}
}


void heapSort_Street(MyRecord arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_Street(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify_Street(arr, i, 0);
	}
}

void heapSort_HouseID(MyRecord arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_HouseID(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify_HouseID(arr, i, 0);
	}
}


void heapSort_City(MyRecord arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_City(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify_City(arr, i, 0);
	}
}


void heapSort_postcode(MyRecord arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_postcode(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify_postcode(arr, i, 0);
	}
}

void heapSort_amount(MyRecord arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_amount(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify_amount(arr, i, 0);
	}
}


/* A utility function to print array of size n */
void printArray_custid(MyRecord arr[], int n)
{
	for (int i=0; i<n; ++i){
		printf("%ld ",arr[i].custid );
	}
	printf("\n");
}

void printArray_FirstName(MyRecord arr[], int n)
{
	for (int i=0; i<n; ++i){
		printf("%s ",arr[i].FirstName );
	}
	printf("\n");
}

void printArray_LastName(MyRecord arr[], int n)
{
	for (int i=0; i<n; ++i){
		printf("%s ",arr[i].LastName );
	}
	printf("\n");
}

void printArray_Street(MyRecord arr[], int n)
{
	for (int i=0; i<n; ++i){
		printf("%s ",arr[i].Street );
	}
	printf("\n");
}

void printArray_HouseID(MyRecord arr[], int n)
{
	for (int i=0; i<n; ++i){
		printf("%d ",arr[i].HouseID );
	}
	printf("\n");
}

void printArray_City(MyRecord arr[], int n)
{
	for (int i=0; i<n; ++i){
		printf("%s ",arr[i].City );
	}
	printf("\n");
}

void printArray_postcode(MyRecord arr[], int n)
{
	for (int i=0; i<n; ++i){
		printf("%s ",arr[i].postcode );
	}
	printf("\n");
}

void printArray_amount(MyRecord arr[], int n)
{
	for (int i=0; i<n; ++i){
		printf("%.2f ",arr[i].amount );
	}
	printf("\n");
}

// Driver program
int main (int argc, char** argv)
{
	double t1, t2;
	struct tms tb1, tb2;
	double ticspersec;
	double time;
	ticspersec = (double) sysconf(_SC_CLK_TCK);
	t1 = (double) times(&tb1);


	FILE* fpb;
	MyRecord rec;
	MyRecord* ptr;
	char myfifo[10];
	strcpy(myfifo, argv[5]);
	int i, start, end;
	fpb = fopen (argv[1],"rb");

	if (fpb==NULL) {
		printf("Cannot open binary file\n");
		return 1;
	}
	start=atoi(argv[2]);
	end=atoi(argv[3]);
	ptr = (MyRecord*)malloc((end-start) * sizeof(MyRecord));

	// Check if the memory has been successfully
	// allocated by malloc or not
	if (ptr == NULL) {
	   printf("Memory not allocated.\n");
	   exit(0);
	}
	// else {
	//
	//    // Memory has been successfully allocated
	//    // printf("Memory successfully allocated using malloc for %d records.\n", end-start);
	// }

	fseek(fpb, start * sizeof(MyRecord), SEEK_SET);


	for (i=0; i<end-start ; i++) {
		fread(&rec, sizeof(rec), 1, fpb);
		ptr[i]=rec;

		//Code for Testing

		// printf("%ld %s %s  %s %d %s %s %-9.2f\n",ptr[i].custid,
		// ptr[i].LastName, ptr[i].FirstName, \
		// ptr[i].Street, ptr[i].HouseID, ptr[i].City, ptr[i].postcode, \
		// ptr[i].amount);
	}



	if (strcmp(argv[4],"1")==0){
		heapSort_custid(ptr, end-start);
		// printf("Sorted array based on custid: \n");
		// printArray_custid(ptr, (end-start) );
	}

	if (strcmp(argv[4],"2")==0){
		heapSort_LastName(ptr, end-start);
				// printf("Sorted array based on LastName: \n");
				// printArray_LastName(ptr, (end-start) );
	}

	if (strcmp(argv[4],"3")==0){
		heapSort_FirstName(ptr, end-start);
		// printf("Sorted array based on FirstName: \n");
		// printArray_FirstName(ptr, (end-start) );
	}

	if (strcmp(argv[4],"4")==0){
		heapSort_Street(ptr, end-start);
		// printf("Sorted array based on Street: \n");
		// printArray_Street(ptr, (end-start) );
	}

	if (strcmp(argv[4],"5")==0){
		heapSort_HouseID(ptr, end-start);
		// printf("Sorted array based on HouseID: \n");
		// printArray_HouseID(ptr, end-start );
	}

	if (strcmp(argv[4],"6")==0){
		heapSort_City(ptr, end-start);
		// printf("Sorted array based on City: \n");
		// printArray_City(ptr, (end-start) );
	}

	if (strcmp(argv[4],"7")==0){
		heapSort_postcode(ptr, end-start);
		// printf("Sorted array based on postcode: \n");
		// printArray_postcode(ptr, (end-start) );
	}

	if (strcmp(argv[4],"8")==0){
		heapSort_amount(ptr, end-start);
		// printf("Sorted array based on amount: \n");
		// printArray_amount(ptr, (end-start) );
	}



	int fd;
    i=0;
	MyRecord arr[50];
	int j=0;


	mkfifo(myfifo, 0666);
	fd = open(myfifo, O_WRONLY);
	while (j<end-start) {


		for ( i = 0; i < 50 && j<end-start; i++,j++) {
			arr[i]=ptr[j];
		}
		write(fd, &arr,50*sizeof(MyRecord));


	}
	t2 = (double) times(&tb2);
	// printf("Run time for child was %lf sec (REAL time) .\n",(t2 - t1) / ticspersec);
	time=(t2 - t1) / ticspersec;
	write(fd, &time, sizeof(time));
	unlink(myfifo);
	close(fd);
	free(fpb);
	free(ptr);
	kill(getppid(),SIGUSR2);
	exit(10);
	return 0;

}
