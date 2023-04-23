#include<iostream>
#include<map>
#include <unordered_map>
#include<set>

int main()
{
   std::unordered_map<int, std::set<std::pair<int, int>>> testMap;

   testMap.insert(std::pair<int, std::set<std::pair<int, int>>>(0, {{0,1}, {0,-1}}));
   testMap.insert(std::pair<int, std::set<std::pair<int, int>>>(1, {{2,0}, {3,-1}}));
   testMap.insert(std::pair<int, std::set<std::pair<int, int>>>(2, {{1,1}, {1,-1}}));

   std::set<std::pair<int, int>>::iterator it = testMap[2].find(std::pair<int, int>(1,-1));
  
   if(it != testMap[2].end())
   {
      std::cout << it->first << std::endl;
      std::cout << it->second << std::endl;
   }
   else
   {
      std::cout << "Not found" << std::endl;
   } 
   
   std::set<std::pair<int, int>>::iterator it1 = testMap[2].find(std::pair<int, int>(10,-1));

   if(it1 != testMap[2].end())
   {
      std::cout << it1->first << std::endl;
      std::cout << it1->second << std::endl;
   }
   else
   {
      std::cout << "Not found" << std::endl;
   } 


}
