#sorting techniques

#------heap sort--------
def reheapUp(arr, indx):
 p = 0
 temp = 0
 if indx != 0:
  p = (indx-1)//2
  if arr[indx] > arr[p]:
   temp = arr[indx]
   arr[indx] = arr[p]
   arr[p] = temp   
   reheapUp(arr, p)

def reheapDown(arr, r, last):
 lchild = r*2+1
 if lchild > last:
  lchild = -1

 rchild = r*2+2
 if rchild > last:
  rchild = -1 

 if lchild != -1 and rchild == -1:
  child = lchild
 elif lchild != -1 and rchild != -1:
  if arr[lchild] > arr[rchild]:
   child = lchild
  else:
   child = rchild
 else:
  child = -1

 if child != -1:
  if arr[r] < arr[child]:
   temp = arr[r]
   arr[r] = arr[child]
   arr[child] = temp
   reheapDown(arr,child, last)  
 
def makeHeap(arr, n):
 for i in range(0, n):
  reheapUp(arr, i)

def heapSort(arr, n):
 makeHeap(arr,n)

 i = n-1
 while i > 0:
   temp = arr[0]
   arr[0] = arr[i]
   arr[i] = temp
   reheapDown(arr,0,i-1)
   i = i-1
 

#--------radix sort------
def getDigit(val, x):
 for i in range(0,x):
  val = val//10

 return val%10
  
def radixSort(arr, s):
 myarr = []
 for j in range(0,s):
  myarr.append(arr[0])
  arr.pop(0)

 for flag in range(0,4):
  arr1= []
  for i in range(0,10): # all possible digits
   for j in range(0,s): # for the entire array
    digit = getDigit(myarr[j],flag)
    if digit == i:
     arr1.append(myarr[j])
  myarr = arr1

 for j in range(0,s):
  arr.append(myarr[j])

#--------shell sort------

def shellSort(arr, s):
 i=0
 temp=0
 curr=0
 incr = (s-1)//2

 while incr != 0:
  for curr in range (incr,s):
   temp = arr[curr]
   i = curr-incr
   while i >=0:
    if temp < arr[i]:
     arr[i+incr] = arr[i]
     i = i - incr
    else:
     break  
   
   arr[i+incr] = temp #insertion

  incr = incr//2

#--------merge sort------

def mergeSort(arr, s):
 arr1=[]
 arr2=[]
 s1 = 0
 s2 = 0
 i =0 
 j =0 
 k =0

 if s % 2 == 0:
  s1 = s//2
  s2 = s//2
 else:
  s1 = s//2 +1
  s2 = s//2

#copy s1 elements of arr into arr1
 for i in range(0,s1):
  arr1.append(arr[i])

#copy s1 onward elements of arr into arr2
 for i in range(0,s2):
  arr2.append(arr[i + s1])

 if s1 > 2:
  mergeSort(arr1,s1)
 elif s1 == 2:
  if arr1[0] > arr1[1]:
   temp = arr1[0]
   arr1[0] = arr1[1]
   arr1[1] = temp

 if s2 > 2:
  mergeSort(arr2,s2)
 elif s2 == 2:
  if arr2[0] > arr2[1]:
   temp = arr2[0]
   arr2[0] = arr2[1]
   arr2[1] = temp

#merge
 i = 0;
 j = 0;
 k = 0;

 while i < s1 and j < s2:
  if arr1[i] < arr2[j]:
   arr[k] = arr1[i]
   i= i+1
   k= k+1
  else:
   arr[k] = arr2[j]
   j= j+1
   k= k+1

#for remaining elements of arr1
 while i < s1:
  arr[k] = arr1[i]
  i = i+1
  k = k+1

#for remaining elements of arr2
 while j < s2:
  arr[k] = arr2[j]
  j = j+1
  k = k+1


#--------quick sort------

def quickSort(arr,x,y):
 if x <y:
  i=x
  j=y
  key=arr[x]
  while i<j:
   while key >= arr[i] and i<y:
    i = i+1
   while key < arr[j] and j>x:
    j = j-1
   if i<j:
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

  #j is the final pos of key in sorted array
  #j is the pivot point

  temp = arr[x]
  arr[x] = arr[j]
  arr[j] = temp
  
  #sort the left of pivot
  quickSort(arr, x,j-1)
  quickSort(arr,j+1, y)

#--------scan array------

def scanArr(arr, n):
 for i in range(0,n):
  x = int(input("enter a number"))
  arr.append(x)
  
#--------menu------
  
def menu():
 print("1. scan array ")
 print("2. display array ")
 print("3. quick sort ")
 print("4. merge sort ")
 print("5. radix sort ")
 print("6. shell sort ")
 print("7. heap sort ")
 print("8. exit ")
 x= int(input("enter choice"))
 return x
 
#--------sorting------

def sorting():
 arr=[]
 ch = 0
 n = 0

 while ch != 8:
  ch = menu()

  if ch == 1:
   n = int(input("enter array size"))
   arr=[]
   scanArr(arr,n)

  elif ch == 2:
   print(arr)

  elif ch == 3:
   quickSort(arr, 0, n-1)
   print("array sorted using quick sort")

  elif ch == 4:
   mergeSort(arr, n)
   print("array sorted using merge sort")

  elif ch == 5:
   radixSort(arr, n)
   print("array sorted using radix sort")

  elif ch == 6:
   shellSort(arr, n)
   print("array sorted using shell sort")  
  
  elif ch == 7:
   heapSort(arr, n)
   print("array sorted using heap sort")  
 
