//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int middle=partition(arr,low,high);
            quickSort(arr,low,middle-1);
            quickSort(arr,middle+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int pivot=arr[low];
       int i=low;
       int j=high;
       while(i<j){
           while(arr[i]<=pivot&&i<high){
               i++;
           }
           while(arr[j]>pivot&&j>low){
               j--;
           }
           if(i<j){
              int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
           }
       }
      int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends