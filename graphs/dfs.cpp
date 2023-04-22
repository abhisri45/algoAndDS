#include<iostream>
#include<stack>
#include<vector>
#include<map>
/* 

   Implement DfS using stack and recursion

   edges: [
            [i,j], [k, i], [i, a], [m, k], [k, l], [o, n]
   ]


 */

void dfsUsingStack(char node, std::map<char, std::vector<char>> adjMap)
/*
   Traversing deep without exploring all the neighbours of the nodes and thus
   we need to have stack so that we comeback to non processed neighbours.
*/
{

   // -1 not visited, 0 in stack, 1 visited -> 3 states of keys in adjMap. They
   // can either be never visited, or may be on stack or may be already visited and
   // removed from stack. The main purpose of state is to make sure that we dont
   // visit a particular node twice.
   std::map<char, int> state;
   for(std::map<char, std::vector<char>>::iterator it = adjMap.begin(); it != adjMap.end(); it++)
   {
      state.insert(std::pair<char, int>(it->first, -1));
   }

   std::stack<char> s;
   
   s.push(node);
   std::map<char, int>::iterator mapIt = state.find(node);
   if(mapIt != state.end())
   {
      mapIt->second = 0;
   }
   while(!s.empty())
   {
      char a = s.top();
      s.pop();
      std::map<char, int>::iterator mapIt1 = state.find(a);
      if(mapIt1 != state.end())
      {
         mapIt1->second = 1;
       }

      std::cout<< "DFS Order: "<< a << std::endl;
      std::vector<char> adjVec = adjMap[a];
      for(std::vector<char>::iterator it = adjVec.begin(); it!=adjVec.end(); it++)
      {
         
         if(state[*it] == -1)
         {
            //std::cout<< "To be pushed: "<< *it << std::endl;
            s.push(*it);
            std::map<char, int>::iterator mapIt2 = state.find(*it);
            if(mapIt2 != state.end())
            {
               mapIt2->second = 0;
            }
         }
      }
      
   }

}

bool dfsUsingRecursionInternal(char node, std::map<char, std::vector<char>> adjMap, std::map<char, int> state)
{
 

   // -1 not visited, 0 in stack, 1 visited
  
   std::map<char, int>::iterator mapIt = state.find(node);
   if(mapIt->second != -1)
   {
      //std::cout << "return" << std::endl;
      return false;
   }
   if(mapIt != state.end())
   {
         mapIt->second = 1;
   }

   
   std::cout<< "DFS Order: "<< node << std::endl;
   
   std::vector<char> adjVec = adjMap[node];
   for(std::vector<char>::iterator it = adjVec.begin(); it!=adjVec.end(); it++)
   {
      
      if(state[*it] == -1)
      {
         //std::cout<< "To be pushed on recursive stack: "<< *it << std::endl;
         dfsUsingRecursionInternal(*it, adjMap, state);
      }
   }

  return true; 
}

void dfsUsingRecursion(char node, std::map<char, std::vector<char>> adjMap)
{
  
    std::map<char, int> stateVar;
   for(std::map<char, std::vector<char>>::iterator it = adjMap.begin(); it != adjMap.end(); it++)
   {
      stateVar.insert(std::pair<char, int>(it->first, -1));
   }
   bool b = dfsUsingRecursionInternal(node, adjMap, stateVar);
 
}


void printAdjacencyList(std::map<char, std::vector<char>> adjmap)
/*
   function to print adjanceyList
*/

{

   std::map<char, std::vector<char>>::iterator it = adjmap.begin();
   for( ; it!=adjmap.end(); it++)
   {
      std::cout << "Map: " << it->first << " : ";
      std::cout << " [ ";
      for(std::vector<char>::iterator itVec = it->second.begin(); itVec != it->second.end(); itVec++)
      {
         std::cout << ", " << *itVec;
      }   
      std::cout << " ]  " << std::endl;
}
}

std::map<char, std::vector<char> > buildAdjacencyList(std::vector<std::vector<char>> vec)
/*
   What does this funtions does?

   function converts below output into Adjaceny list; 
  [
            [i,j], [k, i], [m, k], [k, l], [o, n]
   ]

   to

   {
      'i': ['j', 'k']
      'j': [i],
      'k': ['i', 'm', 'l'],
      'l': ['k'],
      'm': ['k'],
      'n': ['o'],
      'o': ['n']

   }

*/
{
   std::map<char, std::vector<char>> adjmap;

   for(std::vector<std::vector<char>>::iterator it = vec.begin(); it!=vec.end(); it++)
   {
      int i = 0;
      for(std::vector<char>::iterator itInt = it->begin(); itInt != it->end(); itInt++)
      {
         //std::cout << *itInt << std::endl;
         if(adjmap.find(*itInt) != adjmap.end())
         {
            if(i == 0)
            {
              adjmap[*itInt].push_back(*(itInt+1)); 
            }
            else
            {
              adjmap[*itInt].push_back(*(itInt-1)); 
            } 
         }

         else
         {
            adjmap.insert(std::pair<char, std::vector<char>>(*itInt, std::vector<char>()));
            if(i==0)
            {
               adjmap[*itInt].push_back(*(itInt+1));
            }
            else if(i==1)
            {
               adjmap[*itInt].push_back(*(itInt-1));
            }
         }
         
         i++;
      }
   }
   return adjmap;
}


int main()
{

   std::vector<std::vector<char>> v {{'i', 'j'}, {'k', 'i'}, {'i', 'a'}, {'m', 'k'}, {'k', 'l'}, {'o', 'n'}};
   
   std::map<char, std::vector<char>> finalAdjMap = buildAdjacencyList(v);
   printAdjacencyList(finalAdjMap);
   dfsUsingStack('k', finalAdjMap);
   std::cout << "-----------------------------------------------------------" << std::endl;
   dfsUsingRecursion('k', finalAdjMap);

}
