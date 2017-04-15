#Operations on Max Heap

class Heap:
 def __init__(self):
  self.arr=[]

 def scanArr(self, n):
  self.arr= []
  for i in range(0, n):
   self.arr.append( int( input("enter a number") ) )

 def dispArr(self):
  print(self.arr)

 def reheapUp(self, indx):
  p = 0
  temp = 0
  if indx != 0:
   p = (indx-1)//2
   if self.arr[indx] > self.arr[p]:
    temp = self.arr[indx]
    self.arr[indx] = self.arr[p]
    self.arr[p] = temp   
    self.reheapUp(p)

 def reheapDown(self, r, last):
  lchild = r*2+1
  if lchild > last:
   lchild = -1

  rchild = r*2+2
  if rchild > last:
   rchild = -1 

  if lchild != -1 and rchild == -1:
   child = lchild
  elif lchild != -1 and rchild != -1:
   if self.arr[lchild] > self.arr[rchild]:
    child = lchild
   else:
    child = rchild
  else:
   child = -1

  if child != -1:
   if self.arr[r] < self.arr[child]:
    temp = self.arr[r]
    self.arr[r] = self.arr[child]
    self.arr[child] = temp
    self.reheapDown(child, last)  
 
 def makeHeap(self):
  for i in range(0, len(self.arr)):
   self.reheapUp(i)

 def heapSort(self):
  self.makeHeap()

  i = len(self.arr)-1
  while i > 0:
   temp = self.arr[0]
   self.arr[0] = self.arr[i]
   self.arr[i] = temp
   self.reheapDown(0,i-1)
   i = i-1


def heapDemo():
 h = Heap()
 x = int(input("enter number of elements in heap "))
 h.scanArr(x)
 h.dispArr()
 h.heapSort()
 h.dispArr() 
  
 