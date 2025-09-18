// Name: TAN YI JIE
// Matric No: 191020976
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

int intNumber[100];

//function which generate the random numbers and return those numbers
int* generateNumbers(){
int *ptr=(int*)malloc(sizeof(int)*100); //creating block to store 100 numbers
srand(191020976);           //setting seed
for(int i=0;i<100;i++)      //loop to generate numbers
*(ptr+i)=rand();
return ptr;
}

// Merges two sub-array of arr[].
// First sub-array is arr[l..m]. Second sub-array is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{   // m: middle, l: left, r: right
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // create temp arrays
    int L[n1], R[n2];
    // Copy the data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = l; // Initial index of merged sub-array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;        // increments for index of first sub-array
        }
        else {
            arr[k] = R[j];
            j++;        // increments for index of second sub-array
        }
        k++;    // increments for index of merged sub-array
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;    // increments for index of first sub-array
        k++;    // increments for index of merged sub-array
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;    // increments for index of second sub-array
        k++;    // increments for index of merged sub-array
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//UTILITY FUNCTIONS. Function to print an array for merge sort
void printArrayMerge(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);    // print the array
    printf("\n");
}

//Function and driver program for Merge Sort
void MergeSort()
{
    int *ptr=(int*)malloc(sizeof(int)*100); //Block for storing 100 numbers
    ptr = generateNumbers();                //store numbers in block
    FILE *fptr;
    fptr = fopen("100data.txt", "w");
    if (fptr == NULL) {                   //handling error condition
        printf("Error!");
        exit(1);
        }
    for(int i=0;i<100;i++){              //writing data to file
        fprintf(fptr, "%d\n", *(ptr+i));
        intNumber[i] =*(ptr+i);
        }
    fclose(fptr);

    int arr_size = sizeof(intNumber) / sizeof(intNumber[0]);
    printf("Given array is \n");  //print the given array which from the random number generator
    printArrayMerge(intNumber, arr_size);

    mergeSort(intNumber, 0, arr_size - 1);
    printf("\nSorted array is \n");  // print the sorted array
    printArrayMerge(intNumber, arr_size);
}

// A utility function to swap two elements for quick sort
void swapQuick(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes LAST element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller element(smaller than pivot)
   to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];  // pivot
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] < pivot)     // If current element is smaller than the pivot
        {
            i++;    // increment index of smaller element
            swapQuick(&arr[i], &arr[j]);
        }
    }
    swapQuick(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort, arr[] --> Array to be sorted,
   low  --> Starting index, high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array for quick sort
void printArrayQuick(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]); // print the array
    printf("\n");
}

//Function and driver program for Quick Sort
void QuickSort()
{
    int *ptr=(int*)malloc(sizeof(int)*100); //Block for storing 100 numbers
    ptr = generateNumbers();                //store numbers in block
    FILE *fptr;
    fptr = fopen("100data.txt", "w");
    if (fptr == NULL) {                   //handling error condition
        printf("Error!");
        exit(1);
        }
    for(int i=0;i<100;i++){              //writing data to file
        fprintf(fptr, "%d\n", *(ptr+i));
        intNumber[i] =*(ptr+i);
        }
    fclose(fptr);

    int n = sizeof(intNumber) / sizeof(intNumber[0]);
    printf("Given array is \n");   //print the given array which from the random number generator
    printArrayQuick(intNumber, n);

    mergeSort(intNumber, 0, n - 1);
    printf("\nSorted array is \n");  // print the sorted array
    printArrayQuick(intNumber, n);
}

// A utility function to swap two elements for bubble sort
void swapBubble(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++){
     // Last i elements are already in place
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
              swapBubble(&arr[j], &arr[j+1]);
           }
       }
    }
}

// Function to print an array for bubble sort
void printArrayBubble(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);  // print the array
    printf("\n");
}

//Function and driver program for Bubble Sort
void BubbleSort()
{
    int *ptr=(int*)malloc(sizeof(int)*100); //Block for storing 100 numbers
    ptr = generateNumbers();                //store numbers in block
    FILE *fptr;
    fptr = fopen("100data.txt", "w");
    if (fptr == NULL) {                   //handling error condition
        printf("Error!");
        exit(1);
        }
    for(int i=0;i<100;i++){              //writing data to file
        fprintf(fptr, "%d\n", *(ptr+i));
        intNumber[i] =*(ptr+i);
        }
    fclose(fptr);

    int n = sizeof(intNumber) / sizeof(intNumber[0]);
    printf("Given array is \n");   //print the given array which from the random number generator
    printArrayBubble(intNumber, n);

    bubbleSort(intNumber, n);
    printf("\nSorted array is \n");  // print the sorted array
    printArrayBubble(intNumber, n);
}

// Function to sort the array using shell sort
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for the gap size.
        // The first gap elements a[0..gap-1] are already in gapped order then
        // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add arr[i] to the elements that have been gap sorted and
            // save arr[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier the gap-sorted elements up until the correct
            // location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

// Function to print an array for shell sort
void printArrayShell(int arr[], int n)
{
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);      // print the array
    printf("\n");
}

//Function and driver program for Shell Sort
void ShellSort()
{
    int *ptr=(int*)malloc(sizeof(int)*100); //Block for storing 100 numbers
    ptr = generateNumbers();                //store numbers in block
    FILE *fptr;
    fptr = fopen("100data.txt", "w");
    if (fptr == NULL) {                   //handling error condition
        printf("Error!");
        exit(1);
        }
    for(int i=0;i<100;i++){              //writing data to file
        fprintf(fptr, "%d\n", *(ptr+i));
        intNumber[i] =*(ptr+i);
        }
    fclose(fptr);

    int n = sizeof(intNumber) / sizeof(intNumber[0]);
    printf("Given array is \n");  //print the given array which from the random number generator
    printArrayShell(intNumber, n);

    shellSort(intNumber, n);
    printf("\nSorted array is \n");   // print the sorted array
    printArrayShell(intNumber, n);
}

int main()
{
    int intUserChoice;
    clock_t start, end;
    double cpu_time_used;
    while(1){
        rewind(stdin);
        printf("-------------------\n");
        printf("SORTING MENU:\n");      // Menu for sorting
        printf("-------------------\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Shell Sort\n");
        printf("5. Exit\n");
        printf("Choose from the options of 1,2,3,4,5: ");
        rewind(stdin);
        scanf("%d", &intUserChoice);
        switch(intUserChoice){
        case 1:
            start = clock();    // Execution time for the following function
            MergeSort();        // Function for merge sort
            end = clock();
            cpu_time_used = (((double) (end - start))/ CLOCKS_PER_SEC);
            printf("Merge Sort took %f milliseconds to execute \n\n", cpu_time_used);
            break;

        case 2:
            start = clock();    // Execution time for the following function
            QuickSort();        // Function for quick sort
            end = clock();
            cpu_time_used = (((double) (end - start))/ CLOCKS_PER_SEC);
            printf("Quick Sort took %f milliseconds to execute \n\n", cpu_time_used);
            break;

        case 3:
            start = clock();    // Execution time for the following function
            BubbleSort();       // Function for bubble sort
            end = clock();
            cpu_time_used = (((double) (end - start))/ CLOCKS_PER_SEC);
            printf("Bubble Sort took %f milliseconds to execute \n\n", cpu_time_used);
            break;

        case 4:
            start = clock();    // Execution time for the following function
            ShellSort();        // Function for shell sort
            end = clock();
            cpu_time_used = (((double) (end - start))/ CLOCKS_PER_SEC);
            printf("Shell Sort took %f milliseconds to execute \n\n", cpu_time_used);
            break;

        case 5:
            printf("Exiting menu...\n");
            printf("End of processing.\n");
            exit(0);
            break;

        default: printf("\nInvalid Choice, please key in again.\n\n");
        }
    }
    return 0;
 }
// End of the program, thanks.
