#include <iostream>
#include <fstream>
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
    const int SIZE = 53;
    const int HASH = 53;
    node *buckets[53] = {};

public:
    HashTable(){};
    int hash(string str)
    {
        int data = 0;
        for (int i = 0; i < str.length(); i++)
        {
            data = data + str[i];
        }
        return data;
    };
    void insert(string str)
    {
        node *newNode = new node;
        int data = hash(str);
        // cout << data << endl;
        newNode->data = data;
        newNode->next = buckets[data % HASH];
        buckets[data % HASH] = newNode;
    };
    bool find(string str)
    {
        node *temp;
        bool res = false;
        int data = hash(str);
        int inspt = 0;
        for (int i = 0; i < SIZE; i++)
        {
            int x = i % HASH;
            temp = buckets[x];
            while (temp != NULL)
            {
                inspt++;
                if (temp->data == data)
                {
                    res = true;
                }
                temp = temp->next;
            }
        }
        cout << "inspected " + to_string(inspt) + " elements.." << endl;
        ;
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
    srand(time(0));
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