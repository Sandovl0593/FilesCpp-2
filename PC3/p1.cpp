#include <iostream>
#include <vector>
using namespace std;

class Singleton {
    private:
        int _data;
        // static Singleton* _inst;
        Singleton(): _data(rand()%100) {}
        // Singleton(int data): _data(data) {}
    public:
        static vector<Singleton*> limit;
        static int pos;
        static Singleton* getInstance();
        int getData(){  return _data; }
};

// Singleton* Singleton::_inst = NULL;
vector<Singleton*> Singleton::limit = {NULL, NULL, NULL, NULL};
int Singleton::pos = 0;
Singleton* Singleton::getInstance(){
    if (pos == 4)   pos = 0;
    else {
        if (limit[pos] == NULL)
            limit[pos] = new Singleton();
        pos++;
    }
    return limit[pos];
}

int main () {
    Singleton * ptr1 = Singleton :: getInstance ();
    cout << " prt1 :  data  = " << ptr1 -> getData () << endl ;
    Singleton * ptr2 = Singleton :: getInstance ();
    cout << " ptr2 :  data  = " << ptr2 -> getData () << endl ;
    Singleton * ptr3 = Singleton :: getInstance ();
    cout << " ptr3 :  data  = " << ptr3 -> getData () << endl ;
    Singleton * ptr4 = Singleton :: getInstance ();
    cout << " ptr4 :  data  = " << ptr4 -> getData () << endl ;
    Singleton * ptr5 = Singleton :: getInstance ();
    cout << " ptr5 :  data  = " << ptr5 -> getData () << endl ;
    return 0;
}