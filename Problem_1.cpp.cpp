using namespace std;
#include <iostream>
#include <bits/stdc++.h>

int Total_no_of_swap(int arr[], int left,int mid, int right)                 // Function to count total number of swaps of array
{

     int place[100000];               //storing elements of array

    int no_of_swap = 0;

    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j <= right)
    {

        if (arr[i] <= arr[j])
        {
            place[k] = arr[i];
            k++, i++;
        }
        else
        {
            place[k] = arr[j];
            k++, j++;
            no_of_swap = no_of_swap + (mid - i);
        }
    }
    while (i < mid)
    {
        place[k] = arr[i];
        k++, i++;
    }

    while (j <= right)
    {
        place[k] = arr[j];
        k++, j++;
    }

    while (left <= right)
    {
        arr[left] = place[left];
        left++;
    }

    return no_of_swap;
}

// Function to count the total number of swaps required to sort the array
int InsertionSwap(int arr[],int left, int right)
{

    int no_of_swap = 0;
    if (left < right)
    {

        // Find the middle index
        int mid =  (right + left) / 2;

        // number of swaps  to sort the left subarray
        no_of_swap = no_of_swap +  InsertionSwap(arr, left, mid);    //mid->right of left subarray

        // number of swaps to sort the right subarray
        no_of_swap = no_of_swap + InsertionSwap(arr, mid + 1, right);   //mid+1->left of right subarray

        //total number of swaps of array
        no_of_swap = no_of_swap + Total_no_of_swap(arr, left, mid + 1, right);
    }
    return no_of_swap;
}


int main()
{
    //int arr[] = {2};                             // 0
//    int arr[] = {2,3,6,5,0};                       //5
    //int arr[] = {2,3,4};                             //0
    int arr[] = {2,1,3,1,2};                             //4
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<"Number Of Swaps  Of this Array is "<< InsertionSwap(arr, 0, n - 1);
    return 0;
}
