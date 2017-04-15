//Program to implement :
//Generic Functions
//refer : about generic functions and classes

#include <iostream>
using namespace std;

template <class X> void interchange(X &a, X &b)
{
    X temp;
    temp = a;
    a = b;
    b = temp;
}

template<class X> void bubbleSort(X arr[], int s)
{
    int i, j;
    
    for(i = s-1; i> 0; i--)
    {
        for(j =0; j< i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                interchange(arr[j], arr[j+1]);
            }
        }//for(j
    }//for(i
}//bubbleSort

template <class X> void display(X arr[], int s )
{
    int i;
    cout<<"\n";
    for(i =0; i< s; i++)
        cout<<" "<<arr[i];
}

//no ambiguity, instead this would serve
//for calls to display with int array
void display(int arr[], int s )
{
    int i;
    cout<<"\n";
    for(i =0; i< s; i++)
        cout<<" "<<arr[i];
}

int main()
{
    int iarr[] = {4,8,1,9,5};
    char carr[] = {'q', 'a', 'z', 'w', 's', 'x'};
    double darr[] = { 1.23, 1.09, 1.093, 1.3, 1.03 };

    display(iarr, 5);
    bubbleSort(iarr, 5);
    display(iarr, 5);
    
    display(carr, 6);
    bubbleSort(carr, 6);
    display(carr, 6);
    
    display(darr, 5);
    bubbleSort(darr, 5);
    display(darr, 5);
    return 0;
}

