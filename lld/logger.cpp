#include<iostream>
#include<string>
#include<set>
#include<unordered_map>

class Logger { 
	/**
	* When a process starts, it calls 'start' with processId and startTime.
	*/
	void virtual start(std::string processId, long startTime)=0;
	
	/**
	* When the same process ends, it calls 'end' with processId and endTime.
	*/
	void virtual end(std::string processId, long endTime)=0;

	/**
	* Prints the logs of this system sorted by the start time of processes in the below format
	* {processId} started at {startTime} and ended at {endTime}
	*/
	void virtual print()=0;
};

class Process
{
   public:
   Process(std::string processId, long startTime):processId(processId),startTime(startTime),endTime(-1)
   {

   }
   bool operator <(const Process * obj)
   {
      std::cout << "Comparator called for: " <<  this->startTime <<  " and " << obj->startTime << std::endl;
      return this->startTime < obj->startTime;
   }
   
   std::string processId;
   long startTime;
   long endTime;

};

class ProcessComp
{
   public:
   ProcessComp()
   {
   }

   bool operator ()(const Process *lft, const Process *rt) const
   {
      std::cout << "Comparator called for: " <<  lft->startTime <<  " and " << rt->startTime << std::endl;
      return lft->startTime < rt->startTime;
   }


};

/*
struct openlist_compare
{
    bool operator()(const astar_node &node1, const astar_node &node2 ){
           return node1.f < node2.f ;
    }
};
std::set<astar_node, openlist_compare> Openlist;

*/



class LoggerImpl: public Logger
{
   public:
   LoggerImpl():Logger()
   {
      this->ptr = NULL;
   }

   void start(std::string processId, long startTime)
   {
      Process *ptr = new Process(processId, startTime);
     

      pidMap.insert(std::pair<std::string, Process*>(processId, ptr));
      startTimeSet.insert(ptr);
      //this->ptr = ptr;

   }


   void end(std::string processId, long endTime)
   {
      if(this->pidMap.find(processId) != pidMap.end())
      {
            std::unordered_map<std::string, Process*>::iterator it = pidMap.find(processId);
            it->second->endTime = endTime;
      }
   }

   void print()
   {
      std::cout<< "Want to print Processes which are finished" << std::endl;
      if(startTimeSet.empty())
      {
         std::cout<< "No process added so far" << std::endl;
         return;
      }
      while(1)
      {
         Process* ptr1 = *startTimeSet.begin();
         if(ptr1->endTime != -1)
         {
            std::cout<<"Process with id: "<< ptr1->processId << " and startTime: " << ptr1->startTime << " and endTime: " << ptr1->endTime << " is finished"<< std::endl;
            startTimeSet.erase(ptr1);
            pidMap.erase(ptr1->processId);
            delete ptr1;
         }

         else
         {
            std::cout<<"Process with id: "<< ptr1->processId << " and startTime: " << ptr1->startTime << " is still not finished"<< std::endl;
            break;
         }

         if(startTimeSet.empty())
         {
            std::cout << "All elements are processed successfully " << std::endl;
            break;
         }
      }
      
   }

   private:
      Process *ptr;
      std::unordered_map<std::string, Process*> pidMap;
      std::set<Process*, ProcessComp> startTimeSet;

   
};

int main()
{
   LoggerImpl* impl = new LoggerImpl();

   impl->print();
   impl->start("S1", 101);
   impl->start("S2", 100);
   impl->start("S3", 102);
   impl->print();
   impl->end("S1", 102);
   impl->print();
   impl->end("S2", 103);
   impl->end("S3", 105);
   impl->print();
   

   return 0;
}
