#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data = NULL;
    node *next;
};

class HashTable
{
private:
    const int SIZE = 8;
    const int HASH = 8;
    node *buckets[8] = {};

public:
    HashTable(){};
    void insert(int data)
    {
        node *newNode = new node;
        newNode->data = data;
        newNode->next = buckets[data % HASH];
        buckets[data % HASH] = newNode;
    };
    void search(){};
    void display()
    {
        node *temp;
        for (int i = 0; i < SIZE; i++)
        {
            int x = i % HASH;
            temp = buckets[x];
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    };
};

int main()
{
    srand(time(0));
    cout << "nathan's hash table" << endl;
    HashTable myHashTable;
    myHashTable.insert(3);
    myHashTable.insert(8);
    myHashTable.insert(1);
    myHashTable.insert(10);
    myHashTable.insert(15);
    myHashTable.insert(18);
    myHashTable.insert(21);
    myHashTable.insert(42);
    myHashTable.insert(64);
    myHashTable.insert(12);
    myHashTable.insert(11);
    myHashTable.display();
    return 0;
}