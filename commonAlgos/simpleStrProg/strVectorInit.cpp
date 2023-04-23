#include<iostream>
#include<vector>
#include<string>

int main()
{
   int n=5;
   //using namespace std;;

   std::vector<std::string> strVec(n, std::string(10, '.'));

   std::cout<< strVec.size() <<std::endl;

   for(std::vector<std::string>::iterator it = strVec.begin(); it!=strVec.end(); it++)
   {
      std::cout<< *it <<std::endl;
   }

}
