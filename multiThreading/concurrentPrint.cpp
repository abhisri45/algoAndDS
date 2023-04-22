#include<iostream>
#include<pthread.h>
#include<unistd.h>

int counter = 1;
int thread1Count1 = 3;
int thread2Count2 = 3;

int thread1Active = 1;

pthread_mutex_t mutex;
pthread_cond_t cond;


void* evenThread(void * even)
{
   for(int i=0; i<=10;i++)
   {
      pthread_mutex_lock(&mutex);
      while(counter%2 == 1)
      {
         pthread_cond_wait(&cond, &mutex);
      }
      std::cout << "evenThread: " << counter << std::endl;
      counter++;
      pthread_cond_signal(&cond);
      pthread_mutex_unlock(&mutex);
   }
   return NULL;
}

void* oddThread(void *odd)
{
   for(int i=0; i<=10;i++)
   {
   pthread_mutex_lock(&mutex);
   while(counter%2 == 0)
   {
      pthread_cond_wait(&cond, &mutex);
   }
   std::cout << "oddThread: " << counter << std::endl;
   counter++;
   pthread_cond_signal(&cond);
   pthread_mutex_unlock(&mutex);
   }

   return NULL;
}


void* threadFunc1(void *arg1)
{
   {
   pthread_mutex_lock(&mutex);
   for(int i=thread1Count1; i>0; i--)
   {
         std::cout << "thread1: " << counter << std::endl;
         counter++;
   }
   thread1Active = 0;
   thread1Count1++;
   pthread_cond_signal(&cond);
   pthread_mutex_unlock(&mutex);
   }

   
   {
   pthread_mutex_lock(&mutex);

   while(thread1Active==0)
   {
      pthread_cond_wait(&cond, &mutex);
   }
   for(int i=thread1Count1; i>0; i--)
   {
         std::cout << "thread1: " << counter << std::endl;
         counter++;
   }
   thread1Active = 0;
   pthread_cond_signal(&cond);
   pthread_mutex_unlock(&mutex);
   }
   return NULL;
}

void* threadFunc2(void *arg2)
{
   {
   pthread_mutex_lock(&mutex);
   while(thread1Active==1)
   {
      pthread_cond_wait(&cond, &mutex);
   }
   for(int i=thread2Count2; i>0; i--)
   {
         std::cout << "thread2: " << counter << std::endl;
         counter++;
   }
   thread2Count2--;
   thread1Active = 1;
   pthread_cond_signal(&cond);
   pthread_mutex_unlock(&mutex);
   }

   pthread_mutex_lock(&mutex);
   while(thread1Active==1)
   {
      pthread_cond_wait(&cond, &mutex);
   }

   for(int i=thread2Count2; i>0; i--)
   {
         std::cout << "thread2: " << counter << std::endl;
         counter++;
   }

   pthread_cond_signal(&cond);
   pthread_mutex_unlock(&mutex);

     
   return NULL;
}


int main()
{
   pthread_t thread1, thread2; 
   int err1 = pthread_create(&thread1, NULL, &threadFunc1, NULL);
   int err2 = pthread_create(&thread2, NULL, &threadFunc2, NULL);

   //int err1 = pthread_create(&thread1, NULL, &evenThread, NULL);
   //int err2 = pthread_create(&thread2, NULL, &oddThread, NULL);
   
   pthread_join(thread1, NULL);
   pthread_join(thread2, NULL);

}

