#include<vector>
#include<list>
#include<iostream>

using namespace std;


int main()
{
   //std::list<int> li1 = {1, 2, 3};
   std::list<int> li1;
   

   list<int>::iterator it = li1.begin();

   list<int> li2 = {9, 8};

   cout << "begin(): " << *li1.begin() << endl;
   cout << "end(): " << *li1.end() << endl;
   
   li1.insert(li1.end(), li2.begin(), li2.end());

   cout << "============================" << endl;
   cout << "begin(): " << *li1.begin() << endl;
   cout << "end(): " << *li1.end() << endl;
      
   for(auto it=li1.begin(); it!=li1.end(); it++)
   {
      
         cout << "element: "<< *it << endl;
      
   }
   
   cout << "============================" << endl;
   cout << "begin(): " << *li1.begin() << endl;
   cout << "end(): " << *li1.end() << endl;

   li1.push_front(11); 
   
   cout << "============================" << endl;
   cout << "begin(): " << *li1.begin() << endl;
   cout << "end(): " << *li1.end() << endl;
   
}
