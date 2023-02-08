#include <iostream>
#include <thread>
using namespace std;

/*
    Hilos para una concurrencia
*/

void foo(){
   cout << "funcion 'foo'\n";
   
}  

int main(){
   thread t(&foo); 
   cout << "funcion ‘main’\n";  
   t.join();
   return 0;
}