//Recursive algorithm code using general-purpose list

//list copy: recursive algorithm
//driver
template <class T>
void GenList<T>::Copy(const GenList<T>& l) const{
    first = Copy(l.first);
}
//operate function
template <class T>
GenListNode<T>* GenList<T>::Copy(GenListNode<T> *p)
//copies an non-recursive list witha non-public sublist p
{
    GenListNode<T> *q = 0;
    if(p)
    {
        q = nwe GenListNode<T>;
        q->tag = p->tag; //check whether there is a down link by tag
        if(p->tag
        {
            q->down = Copy(p->down); // if there is a down link, copy down link to q
        })
        else
        {
            q->data = p->data; // if not, just copy data
        }
        q->next = Copy(p->next); // and also copy next until there is no recursion
    }
    return q;
}


// equality comparison function - recursive algorithm
//driver
template <class T>
int GenList<T>::Depth()
// Measuring non-recursive list depth
{
    return Depth(first);
}
//operate function
tmeplate <class T>
int GenList<T>::Depth(GenlistNode<T> *s)
{
    if(!s)
    {
        return(); // empty list
    }

    GenListNode<T> *current = s;
    int m = 0;
    while(current)
    {
        if(current->tag)
        {
            m = max(m, Depth(current->down));
            current = current->next;
        }
    }
    return m+1;
}

// Recursive deletion of a list
//driver
template <class T>
Genlist<T>::~GenList()
// Header node has reference coefficient
{
    if(first)
    {
        Delete(first);
        first = 0;
    }
}
//operation function
void GenList<T>::Delete(GenListNode<T> *x)
{
    x->ref--; // decrease the reference coef of header node
    if(!x->ref)
    {
        GenListNode<T> *y = x; // y traverse the top level of x;
        while(y->next)
        {
            y = y->nest;
            if(y->tag == 1)
            {
                Delete(y->down);
            }
            
        }
        y->next = av; // add top level nodes in av list
        av = x;
    }
}