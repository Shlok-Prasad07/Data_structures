//Write a program to implement Binary Search. 

#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    //int mid = low + (high - low) / 2;
    int mid = ((low + high) / 2);
    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }
  return -1;
}


void main()
{

  int array[100], search, i, n;

  printf("\nEnter the Length of Array:=> ");
  scanf("%d",&n);

  printf("\nEnter Elements of Array in sorted order:\n");
      for(i=0;i<n;i++)
      {
	    printf("\nA[%d]= ",i);
	    scanf("%d",&array[i]);
      }

  printf("\nEnter a number to search:=> ");
  scanf("%d", &search);

  int result = binarySearch(array, search, 0, n - 1);

  if (result == -1)
    printf("\nElement is not found\n");
  else
    printf("\nElement is found at index %d\n", result);
  return 0;
}
