#include <stdio.h>

void print_array(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	
	return;
}

int find_min(int arr[], int low, int high, int min_index) // inner loop
{
	if(low > high)
	{
		return min_index;
	} 
	if(arr[low] < arr[min_index])
	{
		min_index = low;
	}
	return find_min(arr, low + 1, high, min_index);
}

void selection_sort(int arr[], int low, int high) // outer loop
{
	if(low >= high)
	{
		return;
	}
	int min_index = find_min(arr, low, high, low);
	swap(&arr[min_index], &arr[low]);
	selection_sort(arr, low + 1, high);
	
	return;
}

int main()
{
	int n;
	printf("Enter number of elements to be sorted: ");
	scanf("%d", &n);
	
	int arr[n];
	printf("Enter elements in an array:\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	selection_sort(arr, 0, n - 1);
	printf("Elements after sorting:\n");
	print_array(arr, n);
	
	return 0;
}
