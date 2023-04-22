"""
1. Given a positive integer number N. The task is to generate all the binary strings of N bits. These binary strings should be in ascending order.
[0]
tempList = [0, 0]
tempList = [0, 1]
tempList = [1, 0]

finalList=[[0, 0]]
finalList=[[0, 0], [0, 1], [1, 0]]]

"""
import copy

def func(N, finalList, tempList):
   if (len(tempList) == N):
      #print(tempList)
      #print("new\n")
      finalList.append(copy.copy(tempList))
      #print(finalList)
      return

   tempList.append(0)
   func(N, finalList, tempList)
   tempList.pop()
   tempList.append(1)
   func(N, finalList, tempList)
   tempList.pop()
  

   

finalList = list()
tempList = []
#func(3, finalList, tempList)

#print(finalList)


def func2(N, finalList, tempList):
   if (len(tempList) == N):
      #print(tempList)
      #print("new\n")
      finalList.append(copy.copy(tempList))
      #print(finalList)
      return

   for i in [1, 2, 3]:
      tempList.append(i)
      func2(N, finalList, tempList)
      tempList.pop()
     

#func2(2, finalList, tempList)
#print(finalList) 

def func3(N, finalList, tempList):
   if (len(tempList) == N):
      #print(tempList)
      #print("new\n")
      finalList.append(copy.copy(tempList))
      #print(finalList)
      return

   tempList.append(1)
   func3(N, finalList, tempList)
   tempList.pop()
   tempList.append(2)
   func3(N, finalList, tempList)
   tempList.pop()
   tempList.append(3)
   func3(N, finalList, tempList)
   tempList.pop()

#func3(3, finalList, tempList)
#print(finalList) 


def func4(finalList, tempList, offset, array):
   if (len(array) == offset):
      #print(tempList)
      #print("new\n")
      finalList.append(copy.copy(tempList))
      #print(finalList)
      return

   tempList.append(array[offset])
   func4(finalList, tempList, offset+1, array)
   tempList.pop()
   func4(finalList, tempList, offset+1, array)
    


func4(finalList, tempList, 0, [1, 2, 3])
print(finalList) 
