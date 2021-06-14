#include<iostream>

using namespace std;

class ENode
{
    friend void Equivalence();
public:
    Enode(int d = 0)
    {
        data = d;
        link = 0;
    }
private:
    int data;
    ENode *link;
}

void Equivalence()
{
    ifstream inFile("equiv.in", ios::in); // input file: equiv.in
    if(!inFile)
    {
        throw "Cannot open input file!";
    }

    int i, j, n;
    inFile >> n; // read number of object

    // init first and out
    ENode ** first = new ENode * [n];
    bool *out new bool[n];

    // use STL func: fill for init
    fill(first, first+n, 0);
    fill(out, out+n, false);

    //step 1: iput couple of equivalent
    inFile >> i >> j;
    while(inFile.good())
    // search end of the file
    {
        first[i] = new ENode(j, first[i];
        first[j] = new ENode(i, first[j]);
        inFile >> i >> j;
    }

    //step 2: print equivalent class
    for(int i = 0; i < n; i++)
    {
        if(!out[i])
        // if you need to print
        {
            cout << endl << "A new class; " << i;
            out[i] = True;
            ENode *x = first[i];
            ENode *top = 0; // init the stack
            while(1)
            // search rest of class
            {
                while(x)
                // process thr list
                {
                    j = x->data;
                    if(!out[j])
                    {
                        cout << "," << j;
                        out[j] = True;
                        ENode *y = x->link;
                        x->link = top;
                        top = x;
                        x = y;
                    }
                    else
                    {
                        x = x->link;
                    }
                }
                if(!top)
                {
                    break;
                }
                x = first[top->data];
                top = top->link // delete from the stack
            }
        }
        for(i = 0; i < n; i++)
        {
            while(first[i])
            {
                ENode *delNode = first[i];
                first[i] = delNode->link;
                delete delNode;
            }
            delete[] first;
            delete[] out;
        }
    }
}