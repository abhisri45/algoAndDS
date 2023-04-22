'''
We have some clickstream data that we gathered on our client's website. We collected snippets of users' anonymized URL histories while they browsed the site. The histories are in chronological order, and no URL was visited more than once per person.

Write a function that takes two users' browsing histories as input and returns the longest contiguous sequence of URLs that appears in both.

Sample input:

user0 = ["/start", "/green", "/blue", "/pink", "/register", "/orange", "/one/two"]
user1 = ["/start", "/pink", "/register", "/orange", "/red", "a"]
user2 = ["a", "/one", "/two"]
user3 = ["/pink", "/orange", "/yellow", "/plum", "/blue", "/tan", "/red", "/amber", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow", "/BritishRacingGreen"]
user4 = ["/pink", "/orange", "/amber", "/BritishRacingGreen", "/plum", "/blue", "/tan", "/red", "/lavender", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow"]
user5 = ["a"]
user6 = ["/pink","/orange","/six","/plum","/seven","/tan","/red", "/amber"]

Sample output:

findContiguousHistory(user0, user1) => ["/pink", "/register", "/orange"]
findContiguousHistory(user0, user2) => [] (empty)
findContiguousHistory(user0, user0) => ["/start", "/green", "/blue", "/pink", "/register", "/orange", "/one/two"]
findContiguousHistory(user2, user1) => ["a"] 
findContiguousHistory(user5, user2) => ["a"]
findContiguousHistory(user3, user4) => ["/plum", "/blue", "/tan", "/red"]
findContiguousHistory(user4, user3) => ["/plum", "/blue", "/tan", "/red"]
findContiguousHistory(user3, user6) => ["/tan", "/red", "/amber"]

n: length of the first user's browsing history
m: length of the second user's browsing history

'''

user0 = ["/start", "/green", "/blue", "/pink", "/register", "/orange", "/one/two"]
user1 = ["/start", "/pink", "/register", "/orange", "/red", "a"]
user2 = ["a", "/one", "/two"]
user3 = ["/pink", "/orange", "/yellow", "/plum", "/blue", "/tan", "/red", "/amber", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow", "/BritishRacingGreen"]
user4 = ["/pink", "/orange", "/amber", "/BritishRacingGreen", "/plum", "/blue", "/tan", "/red", "/lavender", "/HotRodPink", "/CornflowerBlue", "/LightGoldenRodYellow"]
user5 = ["a"]
user6 = ["/pink","/orange","/six","/plum","/seven","/tan","/red", "/amber"]

# Note: built-in functions like the Python difflib module should not be used as solutions to this problem

class A:
   def __init__(self):
      self.a = 0
      self.b = [[]]

   def findMaxCorr(self):
      return max(self.b, key = len)


def contHistory(user0, idx1, user1, idx2, res):
   """
   Recurssive solution
   """
    
    if (idx1 < len(user0)) and (idx2 < len(user1)):
        ans = 0
        local = []
        if(user0[idx1] == user1[idx2]):
            #print(user0[idx1])
            res.b[-1].append(user0[idx1])
            #local.append(user0[idx1])
            
            ans = 1 + contHistory(user0, idx1+1, user1, idx2+1, res)
            #res.b.append(user0[idx1])

            if(ans > res.a):
                #print("----------------------------")
                #print("ans: %s"%ans)
                #print("res: %s"%res.a)
                #print("----------------------------")
                res.a = ans
            return ans
        else:
            ans = 0
            res.b.append([])
            contHistory(user0, idx1+1, user1, idx2, res)
            contHistory(user0, idx1, user1, idx2+1, res)
        return ans        
            
            #return max(contHistory(user0, idx1+1, user1, idx2),  contHistory(user0, idx1, user1, idx2+1))
    else:
        return 0
        

def findContiguousHistory(user0, user1):
    finalCount = 0
    a1 = A()
    
    finalCount = []
    contHistory(user0, 0, user1, 0, a1)
    print(a1.a)
    print(a1.findMaxCorr())
    '''
    if finalCount:
      print(max(finalCount))
      return max(finalCount)
    print(0)
    '''
    return 0
    

findContiguousHistory(user0, user1)

findContiguousHistory(user0, user2)
findContiguousHistory(user0, user0)
findContiguousHistory(user2, user1)
findContiguousHistory(user5, user2)
findContiguousHistory(user3, user4)
findContiguousHistory(user4, user3)
findContiguousHistory(user3, user6)
#findContiguousHistory(user3, user4)
#findContiguousHistory(user3, user4)
#findContiguousHistory(user3, user4)
    
