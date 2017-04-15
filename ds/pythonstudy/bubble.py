#--------bubble sort------

def bubbleSort(arr, n):
 i = n-1
 while i > 0:
  for j in range(0,i):
   if arr[j] > arr[j+1]:
    temp = arr[j]
    arr[j] = arr[j+1]
    arr[j+1] = temp
  i = i-1

def scanArr(arr, n):
 for i in range(0,n):
  x = int(input("enter a number"))
  arr.append(x)
  
def sorting():
 arr=[]
 n = int(input("enter array size"))
 scanArr(arr,n)
 print(arr)
 bubbleSort(arr, n)
 print(arr)
