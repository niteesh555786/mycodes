#BFS DFS on Binary Tree

class Node:
 def __init__(self, d):
  self.left = None 
  self.data = d
  self.right = None


class BinTree:
 def __init__(self):
  self.root = None

 def create(self):
  ch1 = "y"
  while ch1 == "y":
   val = int(input("enter value for new node ")) 
   n = Node(val)
   if self.root== None:
    self.root = n
   else:
    p = self.root
    flag = 1
    while(flag == 1):
     print("l : add to left of ", p.data)
     print("r : add to right of ", p.data)
     ch2 = input("enter choice ")

     if ch2 == "l":
      if p.left == None:
       p.left = n #connect
       flag = 0
      else:
       p = p.left #travserse
     elif ch2 == "r":
      if p.right == None:
       p.right = n #connect
       flag = 0
      else:
       p = p.right #travserse
   
   ch1 = input("add more nodes ")
 
 def DFS(self):
  print("DFS")
  self.rDFS(self.root)

 def rDFS(self, r):
  if r != None:
   print(r.data, end=" ") #data
   self.rDFS(r.left) #left
   self.rDFS(r.right) #right

 def BFS(self):
  print(" ")
  print("BFS")

  arr=[]
  arr.append(self.root)

  p = self.root

  while p != None:
   print(p.data, end=" ")
   if p.left != None:
    arr.append(p.left)   
   if p.right != None:
    arr.append(p.right)
   
   if len(arr) != 0:
    p = arr.pop(0)
   
    if p == self.root:
     print(" ")
     if len(arr) != 0:
      p = arr.pop(0)
      arr.append(self.root) 
     else:
      p = None
     
   else:
    p = None  

def useBinTree():
 bt = BinTree()
 bt.create()
 bt.DFS()
 bt.BFS()  
 
