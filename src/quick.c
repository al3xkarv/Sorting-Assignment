/* C implementation QuickSort */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>			 /*signals*/
#include <sys/times.h> 		/*times*/
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

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition_HouseID (MyRecord arr[], int low, int high)
{
	MyRecord pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
// If current element is smaller than the pivot
		if (arr[j].HouseID < pivot.HouseID)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
						}
							}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
int partition_custid (MyRecord arr[], int low, int high)
{
	MyRecord pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
// If current element is smaller than the pivot
		if (arr[j].custid < pivot.custid)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
						}
							}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int partition_amount (MyRecord arr[], int low, int high)
{
	MyRecord pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
// If current element is smaller than the pivot
		if (arr[j].amount < pivot.amount)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
						}
							}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int partition_FirstName (MyRecord arr[], int low, int high)
{
	MyRecord pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
// If current element is smaller than the pivot
		if (strcmp(arr[j].FirstName,pivot.FirstName) < 0)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
						}
							}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


int partition_LastName (MyRecord arr[], int low, int high)
{
	MyRecord pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
// If current element is smaller than the pivot
		if (strcmp(arr[j].LastName,pivot.LastName) < 0)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
						}
							}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int partition_Street (MyRecord arr[], int low, int high)
{
	MyRecord pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
// If current element is smaller than the pivot
		if (strcmp(arr[j].Street,pivot.Street) < 0)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
						}
							}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int partition_City (MyRecord arr[], int low, int high)
{
	MyRecord pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
// If current element is smaller than the pivot
		if (strcmp(arr[j].City,pivot.City) < 0)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
						}
							}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int partition_postcode (MyRecord arr[], int low, int high)
{
	MyRecord pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
// If current element is smaller than the pivot
		if (strcmp(arr[j].postcode,pivot.postcode) < 0)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
						}
							}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


/* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low --> Starting index,
   high --> Ending index */
void quickSort_HouseID(MyRecord arr[], int low, int high)
{
	if (low < high)
	{
	/* pi is partitioning index, arr[p] is now
	at right place */
		int pi = partition_HouseID(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort_HouseID(arr, low, pi - 1);
		quickSort_HouseID(arr, pi + 1, high);
					}
}


void quickSort_custid(MyRecord arr[], int low, int high)
{
	if (low < high)
	{
	/* pi is partitioning index, arr[p] is now
	at right place */
		int pi = partition_custid(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort_custid(arr, low, pi - 1);
		quickSort_custid(arr, pi + 1, high);
					}
}


void quickSort_amount(MyRecord arr[], int low, int high)
{
	if (low < high)
	{
	/* pi is partitioning index, arr[p] is now
	at right place */
		int pi = partition_amount(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort_amount(arr, low, pi - 1);
		quickSort_amount(arr, pi + 1, high);
					}
}

void quickSort_FirstName(MyRecord arr[], int low, int high)
{
	if (low < high)
	{
	/* pi is partitioning index, arr[p] is now
	at right place */
		int pi = partition_FirstName(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort_FirstName(arr, low, pi - 1);
		quickSort_FirstName(arr, pi + 1, high);
					}
}

void quickSort_LastName(MyRecord arr[], int low, int high)
{
	if (low < high)
	{
	/* pi is partitioning index, arr[p] is now
	at right place */
		int pi = partition_LastName(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort_LastName(arr, low, pi - 1);
		quickSort_LastName(arr, pi + 1, high);
					}
}

void quickSort_Street(MyRecord arr[], int low, int high)
{
	if (low < high)
	{
	/* pi is partitioning index, arr[p] is now
	at right place */
		int pi = partition_Street(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort_Street(arr, low, pi - 1);
		quickSort_Street(arr, pi + 1, high);
					}
}

void quickSort_City(MyRecord arr[], int low, int high)
{
	if (low < high)
	{
	/* pi is partitioning index, arr[p] is now
	at right place */
		int pi = partition_City(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort_City(arr, low, pi - 1);
		quickSort_City(arr, pi + 1, high);
					}
}

void quickSort_postcode(MyRecord arr[], int low, int high)
{
	if (low < high)
	{
	/* pi is partitioning index, arr[p] is now
	at right place */
		int pi = partition_postcode(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort_postcode(arr, low, pi - 1);
		quickSort_postcode(arr, pi + 1, high);
					}
}

/* Function to print an array */
void printArray_HouseID(MyRecord arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i].HouseID);
	printf("\n");
}

void printArray_custid(MyRecord arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%ld ", arr[i].custid);
	printf("\n");
}


void printArray_FirstName(MyRecord arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%s ", arr[i].FirstName);
	printf("\n");
}

void printArray_LastName(MyRecord arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%s ", arr[i].LastName);
	printf("\n");
}

void printArray_Street(MyRecord arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%s ", arr[i].Street);
	printf("\n");
}

void printArray_City(MyRecord arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%s ", arr[i].City);
	printf("\n");
}

void printArray_postcode(MyRecord arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%s ", arr[i].postcode);
	printf("\n");
}

void printArray_amount(MyRecord arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%.2f ", arr[i].amount);
	printf("\n");
}

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
	char myfifo[7];
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
	//    printf("Memory successfully allocated using malloc.\n");
	// }

	fseek(fpb, start * sizeof(MyRecord), SEEK_SET);


	for (i=0; i<end-start ; i++) {
		fread(&rec, sizeof(rec), 1, fpb);
		ptr[i]=rec;
	// Code for Testing Purposes

	// 	printf("%ld %s %s  %s %d %s %s %-9.2f\n",ptr[i].custid,
	// 	ptr[i].LastName, ptr[i].FirstName, \
	// 	ptr[i].Street, ptr[i].HouseID, ptr[i].City, ptr[i].postcode, \
	// 	ptr[i].amount);
	}

	if (strcmp(argv[4],"1")==0){
		quickSort_custid(ptr, 0, (end-start-1));
		// printf("Sorted array based on custid: \n");
		// printArray_custid(ptr, (end-start) );
	}

	if (strcmp(argv[4],"2")==0){
		quickSort_LastName(ptr, 0, (end-start-1));
		// printf("Sorted array based on LastName: \n");
		// printArray_LastName(ptr, (end-start) );
	}
	if (strcmp(argv[4],"3")==0){
		quickSort_FirstName(ptr, 0, (end-start-1));
		// printf("Sorted array based on FirstName: \n");
		// printArray_FirstName(ptr, (end-start) );
	}
	if (strcmp(argv[4],"4")==0){
		quickSort_Street(ptr, 0, (end-start-1));
		// printf("Sorted array based on Street: \n");
		// printArray_Street(ptr, (end-start) );
	}

	if (strcmp(argv[4],"5")==0){
		quickSort_HouseID(ptr, 0, (end-start-1));
		// printf("Sorted array based on HouseID: \n");
		// printArray_HouseID(ptr, (end-start) );

	}

	if (strcmp(argv[4],"6")==0){
		quickSort_City(ptr, 0, (end-start-1));
		// printf("Sorted array based on City: \n");
		// printArray_City(ptr, (end-start) );
	}

	if (strcmp(argv[4],"7")==0){
		quickSort_postcode(ptr, 0, (end-start-1));
		// printf("Sorted array based on postcode: \n");
		// printArray_postcode(ptr, (end-start) );
	}

	if (strcmp(argv[4],"8")==0){
		quickSort_amount(ptr, 0, (end-start-1));
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
