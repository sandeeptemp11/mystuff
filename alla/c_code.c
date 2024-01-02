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

void selection_sort(int n, int arr[])
{
	int min_ind;
	for(int i = 0; i < n - 1; i++)
	{
		min_ind = i;
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[min_ind])
			{
				min_ind = j;
			}
		}
		swap(&arr[i], &arr[min_ind]);
		printf("iteration = %d, ", i);
		print_array(arr, n);
		
	}
}

int main()
{
	int n;
	printf("Enter number of elements to be sorted: ");
	scanf("%d", &n);
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

void selection_sort(int n, int arr[])
{
	int min_ind;
	for(int i = 0; i < n - 1; i++)
	{
		min_ind = i;
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[min_ind])
			{
				min_ind = j;
			}
		}
		swap(&arr[i], &arr[min_ind]);
		printf("iteration = %d, ", i);
		print_array(arr, n);
		
	}
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
	
	selection_sort(n, arr);
	printf("Elements after sorting:\n");
	print_array(arr, n);
	
	return 0;
}

	int arr[n];
	printf("Enter elements in an array:\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	selection_sort(n, arr);
	printf("Elements after sorting:\n");
	print_array(arr, n);
	
	return 0;
}
