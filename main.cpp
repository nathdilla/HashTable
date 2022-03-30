#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct node // simple sll node
{
    int data = NULL;
    node *next;
};

class HashTable // just an array of pointers to linked lists
{
private:
    const int SIZE = 53;
    const int HASH = 53;
    node *buckets[53] = {}; // array of pointers

public:
    HashTable(){};
    int hash(string str) // turns string into hashable value
    {
        int data = 0;
        for (int i = 0; i < str.length(); i++)
        {
            data = data + str[i];
        }
        return data;
    };
    void insert(string str) // o(1)
    {
        node *newNode = new node;
        int data = hash(str);
        // cout << data << endl;
        newNode->data = data;
        newNode->next = buckets[data % HASH]; // hash function is value % size of the bucket, collision
        buckets[data % HASH] = newNode;
    };
    bool find(string str) // worst case o(n)
    {
        node *temp;
        bool res = false;
        int hashVal = hash(str);
        int inspt = 0;

        temp = buckets[hashVal % HASH];
        if (temp != NULL)
        {
            if (temp->data == hashVal)
            {
                cout << "inspected 1 element" << endl;
                return true;
            }
            else
            {
                int elem = 0;
                while (temp != NULL) // if the first value isnt what we are looking for, loop through list
                {
                    elem++;
                    if (temp->data == hashVal)
                    {
                        cout << "inspected " + to_string(elem) + " elements" << endl;
                        return true;
                    }
                    temp = temp->next;
                }
            }
        }
        return res;
    };
    void display()
    {
        node *temp;
        for (int i = 0; i < SIZE; i++)
        {
            cout << "#";
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
    cout << "nathan's hash table" << endl;
    HashTable myHashTable;

    ifstream fin("input.txt"); // read from file
    string txt;

    if (!fin)
    {
        cout << "File not found\n";
        exit(2);
    }

    while (getline(fin, txt))
    {
        cout << "inserting " + txt << endl;
        myHashTable.insert(txt);
    }
    myHashTable.display();
    cout << "******************" << endl;
    string input = "";
    while (input != "-1")
    {
        cout << "enter a word to search for:" << endl;
        cin >> input;
        if (myHashTable.find(input))
        {
            cout << "found " + input << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
    }
    cout << "Goodbye! :]" << endl;
    return 0;
}