#include <unordered_map>
#include <vector>
#include <string>




bool hasPath(std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst) {
  // todo
  
  bool connectedPath = false;
  
  if(src == dst)
  {
    return true;
  }
  
  std::unordered_map<std::string, std::vector<std::string>>::iterator mapIt = graph.find(src);
  
  std::vector<std::string>::iterator it;
  if(mapIt != graph.end())
  {
    it = mapIt->second.begin();
  }
  else
  {
    return false;  
  }
  
  
  for(;it!=mapIt->second.end();it++)
  {
    connectedPath = hasPath(graph, *it, dst);
    if(connectedPath)
    {
      return connectedPath;
    }
  }
  
  
  return connectedPath;
}


int main()
{

   std::unordered_map<std::string, std::vector<std::string>> graph1 {
     { "f", {"g", "i"} },
     { "g", {"h"} },
     { "h", {} },
     { "i", {"g", "k"} },
     { "j", {"i"} },
     { "k", {} }
   };

   bool res1 = hasPath(graph1, "f", "k"); // 1 (true)
   assert(res1);

   std::unordered_map<std::string, std::vector<std::string>> graph2 {
     { "f", { "g", "i" } },
     { "g", {"h"} },
     { "h", {} },
     { "i", {"g", "k"} },
     { "j", {"i"} },
     { "k", {} }
   };

   bool res2 = hasPath(graph2, "f", "j"); // 0 (false)
   assert(!res2);


   std::unordered_map<std::string, std::vector<std::string>> graph3 {
     { "f", {"g", "i"} },
     { "g", {"h"} },
     { "h", {} },
     { "i", {"g", "k"} },
     { "j", {"i"} },
     { "k", {} }
   };

   bool res3 = hasPath(graph3, "i", "h"); // 1 (true)
   assert(res3);


   std::unordered_map<std::string, std::vector<std::string>> graph4 {
     { "v", {"x", "w"} },
     { "w", {} },
     { "x", {} },
     { "y", {"z"} },
     { "z", {} } 
   };

   bool res4 = hasPath(graph4, "v", "w"); // 1 (true)
   assert(res4);


   std::unordered_map<std::string, std::vector<std::string>> graph5 {
     { "v", {"x", "w"} },
     { "w", {} },
     { "x", {} },
     { "y", {"z"} },
     { "z", {} } 
   };

   bool res5 = hasPath(graph5, "v", "z"); // 0 (false)
   assert(!res5);


}
