#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class HashTable
{
private:
    const int SIZE = 8;
    node *buckets[8];

public:
    HashTable(){};
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}