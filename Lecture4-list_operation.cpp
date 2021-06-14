#include<iostream>

using nmaespace std;

// list insert, connect, reverse code

template <class T>
void Chain<T>::InsertBack(const T& e)
{
    if(first)
    // if not empty
    {
        last->link = new ChainNode<T>(e);
        last = last->link;
    }
    else
    {
        first = last = new ChainNode<T>(e);
    }
}

template <class T>
void Chain<T>::Concatenate(Chain<T>& b)
// connect b after *this
{
    if(first)
    {
        last->link = b.first;
        last = b.last;
    }
    else
    {
        first = b.first;
        last = b.last;
    }
    b.first = b.last = 0;
}

template <class T>
vois Chain<T>::Reverse()
// reverse the chain
{
    ChainNode<T> *current = first;
    ChainNode<T> *previous = 0;

    while(current)
    {
        ChainNode<T> *r = previous;
        previous = current;
        current = current->link;
        previous->link = r;
    }
    first = previous;
}