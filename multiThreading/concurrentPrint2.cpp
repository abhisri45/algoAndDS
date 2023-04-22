/*

Expected output:

Ping: 1
Pong: 1
Ping: 2
Pong: 2
Ping: 3
Pong: 3
Ping: 4
Pong: 4
Ping: 5
Pong: 5
Ping: 6
Pong: 6
Ping: 7
Pong: 7
Ping: 8
Pong: 8
Ping: 9
Pong: 9
Ping: 10
Pong: 10

*/ 



#include<iostream>
#include<pthread.h>
#include<unistd.h>

int counter = 1;
int thread1Count1 = 3;
int thread2Count2 = 3;

int thread1Active = 1;

pthread_mutex_t mutex1;
pthread_cond_t cond;
int num=0;
bool waitSec = true;

using namespace std;
    
    void* func1(void * arg)
    {
        while(num<5)
        {
        pthread_mutex_lock(&mutex1);
         while(waitSec==false)
         {
             pthread_cond_wait(&cond, &mutex1);
         }
         num++;
        
        cout << "Ping: " << num << endl;
         waitSec=false;
         pthread_cond_signal(&cond);
         pthread_mutex_unlock(&mutex1);
       }
        return NULL;
        
    }
    
    
    
    void* func2(void *arg)
    {
      while(num<=5)
      {
         pthread_mutex_lock(&mutex1);
        while(waitSec==true)
        {
            pthread_cond_wait(&cond, &mutex1);
        }
        cout << "Pong: " << num << endl;
        
        waitSec=true;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex1);
        if(num==5)
         {
            return NULL;
         }
      }
        return NULL;
    }
    
    



int main()
{
   pthread_t thread1, thread2; 
   int err1 = pthread_create(&thread1, NULL, &func1, NULL);
   int err2 = pthread_create(&thread2, NULL, &func2, NULL);

   //int err1 = pthread_create(&thread1, NULL, &evenThread, NULL);
   //int err2 = pthread_create(&thread2, NULL, &oddThread, NULL);
   
   pthread_join(thread1, NULL);
   pthread_join(thread2, NULL);

}

