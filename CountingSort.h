#ifndef COUNTINGSORT_H_INCLUDED
#define COUNTINGSORT_H_INCLUDED
#include <utility>
#include "SEQUENCE.H"
#include "LinkedList.h"
#include "LinkedListSequence.h"
#include "ArraySequence.h"
#include <functional>
#include <set>

template<typename T>
Sequence<T>* CountingSort(Sequence<pair<T, int>>* s, int maxKey)
{
    Sequence<LinkedList<T>*>* countingList = (Sequence<LinkedList<T>*>*)new LinkedListSequence<T>(maxKey + 1);
    set<int> keys;
    for (int i = 0; i < s->GetLength(); i++)
    {
        countingList->GetP((s->Get(i)).second) = (LinkedList<T>*)new LinkedList<T>();
        keys.insert((s->Get(i)).second);
    }
    for (int i = 0; i < s->GetLength(); i++)
    {
        (countingList->GetP((s->Get(i)).second))->Append((s->Get(i)).first);
    }
    int sequenceIndex = 0;
    Sequence<T>* sortedSequence = (Sequence<T>*) new LinkedListSequence<T>(s->GetLength());
    for (set<int>::const_iterator it = keys.begin(); it != keys.end(); ++it)
    {
        //LinkedList<T>* pointer = new LinkedList<T>((countingList->GetP(*it))->GetLength());
        //pointer = countingList->GetP(*it);
        for (int j = 0; j < (countingList->GetP(*it))->GetLength(); j++)
        {
            sortedSequence->Set(sequenceIndex, (countingList->GetP(*it))->Get(j));
            sequenceIndex++;
        }
    }
    delete[] countingList;
    return sortedSequence;
}


#endif // COUNTINGSORT_H_INCLUDED
