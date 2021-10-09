#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include <functional>
#include <utility>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "CountingSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include <cassert>
#include <cmath>

const double EPS = 0.00000001;

bool compare(Sequence<int>* s1, Sequence<int>* s2)
{
    if (s1->GetLength() != s2->GetLength())
    {
        return false;
    }
    for(int i = 0; i < s1->GetLength(); i++)
    {
        if (s1->Get(i) != s2->Get(i))
        {
            return false;
        }
    }
    return true;
}

void testInt (function<bool(int, int)> compInt)
{
    Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>();
    s1->Append(10);
    s1->Append(3);
    s1->Append(6);
    s1->Append(2);
    s1->Append(5);
    s1->Append(11);
    s1->Append(5);

    Sequence<int>* correctSequence = (Sequence<int>*)new ArraySequence<int>();
    correctSequence->Append(2);
    correctSequence->Append(3);
    correctSequence->Append(5);
    correctSequence->Append(5);
    correctSequence->Append(6);
    correctSequence->Append(10);
    correctSequence->Append(11);

    Sequence<int>* sSort1 = (Sequence<int>*)new ArraySequence<int>(7);
    sSort1 = BubbleSort(s1, compInt);

    /*
    for (int i = 0; i < sSort1->GetLength(); i++)
    {
        cout << sSort1->Get(i) << endl;
    }
    */

    Sequence<int>* sSort2 = (Sequence<int>*)new ArraySequence<int>(7);
    sSort2 = InsertionSort(s1, compInt);

    Sequence<int>* sSort3 = (Sequence<int>*)new ArraySequence<int>(7);
    sSort3 = MergeSort(s1, compInt);

    Sequence<int>* sSort4 = (Sequence<int>*)new ArraySequence<int>(7);
    sSort4 = QuickSort(s1, compInt);

    Sequence<pair<int, int>>* s5 = (Sequence<pair<int, int>>*)new ArraySequence<pair<int, int>>();
    pair<int, int> p1, p2, p3, p4, p5, p6, p7;
    p1.first = 10;
    p1.second = 6;

    p2.first = 3;
    p2.second = 2;

    p3.first = 6;
    p3.second = 5;

    p4.first = 2;
    p4.second = 1;

    p5.first = 5;
    p5.second = 3;

    p6.first = 11;
    p6.second = 7;

    p7.first = 5;
    p7.second = 4;

    s5->Append(p1);
    s5->Append(p2);
    s5->Append(p3);
    s5->Append(p4);
    s5->Append(p5);
    s5->Append(p6);
    s5->Append(p7);

    Sequence<int>* sSort5 = (Sequence<int>*)new ArraySequence<int>(7);
    sSort5 = CountingSort(s5, 8);

    if(compare(sSort1, correctSequence) && compare(sSort2, correctSequence) && compare(sSort3, correctSequence) && compare(sSort4, correctSequence)
       && compare(sSort5, correctSequence))
    {
        cout << "Tests for integer sequences are successful" << endl;
    }
    else cout << "Error in testing integer" << endl;
}

bool compareDouble(Sequence<double>* s1, Sequence<double>* s2)
{
    if (s1->GetLength() != s2->GetLength())
    {
        return false;
    }
    for(int i = 0; i < s1->GetLength(); i++)
    {
        if (fabs(s1->Get(i) - s2->Get(i)) > EPS)
        {
            return false;
        }
    }
    return true;
}

void testDouble (function<bool(double, double)> compDouble)
{
    Sequence<double>* s1 = (Sequence<double>*)new ArraySequence<double>();
    s1->Append(9.3);
    s1->Append(14.2);
    s1->Append(15.0);
    s1->Append(2.7);
    s1->Append(3.9);
    s1->Append(37.4);
    s1->Append(55.1);
    s1->Append(6.2);
    s1->Append(37.4);

    Sequence<double>* correctSequence = (Sequence<double>*)new ArraySequence<double>();
    correctSequence->Append(2.7);
    correctSequence->Append(3.9);
    correctSequence->Append(6.2);
    correctSequence->Append(9.3);
    correctSequence->Append(14.2);
    correctSequence->Append(15.0);
    correctSequence->Append(37.4);
    correctSequence->Append(37.4);
    correctSequence->Append(55.1);

    Sequence<double>* sSort1 = (Sequence<double>*)new ArraySequence<double>(9);
    sSort1 = BubbleSort(s1, compDouble);

    /*
    for (int i = 0; i < sSort1->GetLength(); i++)
    {
        cout << sSort1->Get(i) << endl;
    }
    */

    Sequence<double>* sSort2 = (Sequence<double>*)new ArraySequence<double>(9);
    sSort2 = InsertionSort(s1, compDouble);

    Sequence<double>* sSort3 = (Sequence<double>*)new ArraySequence<double>(9);
    sSort3 = MergeSort(s1, compDouble);

    Sequence<double>* sSort4 = (Sequence<double>*)new ArraySequence<double>(9);
    sSort4 = QuickSort(s1, compDouble);

    Sequence<pair<double, int>>* s5 = (Sequence<pair<double, int>>*)new ArraySequence<pair<double, int>>();
    pair<double, int> p1, p2, p3, p4, p5, p6, p7, p8, p9;
    p1.first = 9.3;
    p1.second = 4;

    p2.first = 14.2;
    p2.second = 5;

    p3.first = 15.0;
    p3.second = 6;

    p4.first = 2.7;
    p4.second = 1;

    p5.first = 3.9;
    p5.second = 2;

    p6.first = 37.4;
    p6.second = 7;

    p7.first = 55.1;
    p7.second = 9;

    p8.first = 6.2;
    p8.second = 3;

    p9.first = 37.4;
    p9.second = 8;

    s5->Append(p1);
    s5->Append(p2);
    s5->Append(p3);
    s5->Append(p4);
    s5->Append(p5);
    s5->Append(p6);
    s5->Append(p7);
    s5->Append(p8);
    s5->Append(p9);

    Sequence<double>* sSort5 = (Sequence<double>*)new ArraySequence<double>(9);
    sSort5 = CountingSort(s5, 9);

    if(compareDouble(sSort1, correctSequence) && compareDouble(sSort2, correctSequence) && compareDouble(sSort3, correctSequence) && compareDouble(sSort4, correctSequence)
       && compareDouble(sSort5, correctSequence))
    {
        cout << "Tests for double sequences are successful" << endl;
    }
    else cout << "Error in testing double" << endl;
}

bool compareChar(Sequence<char>* s1, Sequence<char>* s2)
{
    if (s1->GetLength() != s2->GetLength())
    {
        return false;
    }
    for(int i = 0; i < s1->GetLength(); i++)
    {
        if (s1->Get(i) != s2->Get(i))
        {
            return false;
        }
    }
    return true;
}

void testChar (function<bool(char, char)> compChar)
{
    Sequence<char>* s1 = (Sequence<char>*)new ArraySequence<char>();
    s1->Append('d');
    s1->Append('f');
    s1->Append('j');
    s1->Append('z');
    s1->Append('p');
    s1->Append('b');
    s1->Append('s');
    s1->Append('x');

    Sequence<char>* correctSequence = (Sequence<char>*)new ArraySequence<char>();
    correctSequence->Append('b');
    correctSequence->Append('d');
    correctSequence->Append('f');
    correctSequence->Append('j');
    correctSequence->Append('p');
    correctSequence->Append('s');
    correctSequence->Append('x');
    correctSequence->Append('z');

    Sequence<char>* sSort1 = (Sequence<char>*)new ArraySequence<char>(8);
    sSort1 = BubbleSort(s1, compChar);

    /*
    for (int i = 0; i < sSort1->GetLength(); i++)
    {
        cout << sSort1->Get(i) << endl;
    }
    */

    Sequence<char>* sSort2 = (Sequence<char>*)new ArraySequence<char>(8);
    sSort2 = InsertionSort(s1, compChar);

    Sequence<char>* sSort3 = (Sequence<char>*)new ArraySequence<char>(8);
    sSort3 = MergeSort(s1, compChar);

    Sequence<char>* sSort4 = (Sequence<char>*)new ArraySequence<char>(8);
    sSort4 = QuickSort(s1, compChar);

    Sequence<pair<char, int>>* s5 = (Sequence<pair<char, int>>*)new ArraySequence<pair<char, int>>();
    pair<char, int> p1, p2, p3, p4, p5, p6, p7, p8;
    p1.first = 'd';
    p1.second = 2;

    p2.first = 'f';
    p2.second = 3;

    p3.first = 'j';
    p3.second = 4;

    p4.first = 'z';
    p4.second = 8;

    p5.first = 'p';
    p5.second = 5;

    p6.first = 'b';
    p6.second = 1;

    p7.first = 's';
    p7.second = 6;

    p8.first = 'x';
    p8.second = 7;

    s5->Append(p1);
    s5->Append(p2);
    s5->Append(p3);
    s5->Append(p4);
    s5->Append(p5);
    s5->Append(p6);
    s5->Append(p7);
    s5->Append(p8);

    Sequence<char>* sSort5 = (Sequence<char>*)new ArraySequence<char>(8);
    sSort5 = CountingSort(s5, 8);


    if(compareChar(sSort1, correctSequence) && compareChar(sSort2, correctSequence) && compareChar(sSort3, correctSequence) && compareChar(sSort4, correctSequence)
       && compareChar(sSort5, correctSequence))
    {
        cout << "Tests for char sequences are successful" << endl;
    }
    else cout << "Error in testing char" << endl;
}
#endif // TESTS_H_INCLUDED
