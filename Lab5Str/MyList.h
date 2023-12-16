#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Element {
    T data;
    Element* next;
};
template <class T>
class MyList {
public:
    Element<T>* current = nullptr;
    Element<T>* beginning = nullptr;
    Element<T>* end = nullptr;
    int count = 0;
public:
    Element<T>* Move(int index) {
        current = beginning;
        for (int i = 0; i < index; i++) {
            ++(*this);
        }
        return current;
    }
    void Add(T data) {
        Element<T>* elem = new Element <T>;
        elem->data = data;
        elem->next = nullptr;
        //если список пуст (как я)
        if (Empty()) {
            beginning = elem;
            end = elem;
            count++;

        }
        //если че-то в нем водится
        else {
            end->next = elem;
            end = elem;
            count++;
        }
    }
    void AddFront(T data)
    {
        Element<T>* elem = new Element <T>;
        elem->data = data;
        elem->next = nullptr;
        //если список пуст (как я)
        if (Empty()) {
            beginning = elem;
            end = elem;
            count++;
            return;
        }
        //если че-то в нем водится
        else {
            count++;
            elem->next = beginning;
            beginning = elem;
        }
    }
    void Insert(T data, int index) {
        if (index <= count) {
            Element<T>* elem = new Element <T>;
            elem->data = data;
            if (index == 0) {
                elem->next = beginning;
                beginning = elem;
            }
            else {
                Element<T>* previous = Move(index - 1);
                elem->next = previous->next;
                previous->next = elem;
                end = index == count ? elem : end;
            }
            count++;
        }
    }
    int FirstEnter(T value) {
        current = beginning;
        for (int i = 0; i < count; i++) {
            if (current->data == value)
                return i;
            ++(*this);
        }
        return NULL;
    }
    void Delete(int position) {
        Element<T>* delElem;
        if (position == 0) {
            delElem = beginning;
            beginning = beginning->next;
        }
        else {
            delElem = Move(position);
            Element<T>* PrevElem = Move(position - 1);
            Element<T>* NextElem = Move(position + 1);
            PrevElem->next = NextElem;
            end = position == count - 1 ? PrevElem : end;
        }
        delete delElem;
        count--;
    }
    void DeleteFront()
    {
        if (Empty())
            return;
        Element<T>* delElem = beginning;
        beginning = delElem->next;
        delete delElem;
        count--;
    }
    void DeleteBack() {
        if (Empty())
            return;
        if (beginning == end)
        {
            DeleteFront();
            end = nullptr;
            return;
        }
        Element<T>* delElem = beginning;
        while (delElem->next != end)
            delElem = delElem->next;
        delElem->next = nullptr;
        delete end;
        end = delElem;
        end->next = nullptr;
        count--;
    }
    void DeletebyValue(T value) {
        int position = FirstEnter(value);
        Element<T>* delElem;
        if (position == 0) {
            delElem = beginning;
            beginning = beginning->next;
        }
        else {
            delElem = Move(position);
            Element<T>* PrevElem = Move(position - 1);
            Element<T>* NextElem = Move(position + 1);
            PrevElem->next = NextElem;
            end = position == count - 1 ? PrevElem : end;
        }
        delete delElem;
        count--;
    }
    void operator++() {
        current = current->next;
    }
    void  operator--() {
        Element<T>* ptr = beginning;
        for (int i = 0; i < count; i++) {
            ptr = ptr->next;
            if (ptr->next == current) {
                current == ptr;
                return;
            }
        }
    }
    void Printer() {
        Element<T>* ptr = beginning;
        for (int i = 0; i < count; i++) {
            printf("%c", ptr->data);
            ptr = ptr->next;
        }
    }
    void Scanner(const char* s) {
        if (Empty()) {
            for (int i = 0; s[i] != 0; i++) {
                Add(s[i]);
            }
        }
    }
    void PrinterViaCurrent() {
        current = beginning;
        for (int i = 0; i < count; i++) {
            printf("%c", current->data);
            ++(*this);
        }
    }
    T Max() {
        T max = beginning->data;
        int index = 0;
        int i = 1;
        for (i = 1; i < count; i++) {
            if (GetValue(i) > max) {
                max = GetValue(i);
                index = i;
            }
        }
        return max;
    }
    void Switch(int index1, int index2) {
        T switcher = GetValue(index1);
        Move(index1)->data = GetValue(index2);
        Move(index2)->data = switcher;
    }
    void BubbleSort() {
        for (int j = 1; j < count; j++) {
            for (int i = 0; i < count - j; i++) {
                if (GetValue(i) > GetValue(i + 1))
                    Switch(i, i + 1);
            }
        }
    }
    void ShakerSort() {
        for (int j = 0; j < count; j++) {
            for (int i = 0 + j; i < count - 1 - j; i++) {
                if (GetValue(i) > GetValue(i + 1))
                    Switch(i, i + 1);
            }
            for (int i = count - 1 - j; i > 0 + j; i--) {
                if (GetValue(i) < GetValue(i - 1))
                    Switch(i, i - 1);
            }
        }
    }
    void ChoiceSort() {
        Element<T>* mindata;
        int i = 0, minindex;
        while (i < count)
        {
            mindata = Move(i);
            minindex = (i);
            for (int j = i; j < count; j++)
            {
                if (GetValue(minindex) > GetValue(j))
                {
                    mindata = Move(j);
                    minindex = j;
                }

            }
            Switch(i, minindex);
            i++;
        }
    }
    /* MyList<T>* Split() {
         MyList<T>* parts = (MyList<T>*)calloc(2, sizeof(MyList<T>));
         int i;
         for(i = 0;i < count / 2;i++)
             parts[0].Add(GetValue(i));
         for (i = count / 2; i < count; i++)
             parts[1].Add(GetValue(i));
         return parts;
     }*/
    void Clear() {
        int c = count;
        for (int i = 1; i <= c; i++) {
            Delete(0);
        }
        count = 0;
        beginning = nullptr;
        end = nullptr;
    }
    T GetValue(int index) {
        if (Move(index) != nullptr)
            return Move(index)->data;
        else return NULL;
    }
    Element<T>* Front() { return beginning; }
    Element<T>* Back() { return end; }
    bool Empty() { return beginning == nullptr || end == nullptr; }
    int Size() { return count; }
    void InserSort()
    {
        T elementik;
        int location;
        for (int i = 1; i < Size(); i++)
        {
            elementik = GetValue(i);
            location = i - 1;
            int j = i;
            while ((location >= 0) && (GetValue(location) > GetValue(j)))
            {
                Switch(location, j);
                location = location - 1;
                j--;
            }
        }
    }
    void ExchangeSort()
    {
        int chng = 0;
        do {
            chng = 0;
            for (int i = 0; i < Size() - 1; i++)
            {
                if (GetValue(i + 1) < GetValue(i))
                {
                    Switch(i + 1, i);
                    chng += 1;
                }
            }
        } while (chng);
    }
    void BrushSort() {
        int space = count - 1;
        while (space) {
            for (int i = 0; GetValue(i + space) != NULL; i++) {
                if (GetValue(i) > GetValue(i + space))
                    Switch(i, i + space);
            }
            space--;
        }
    }
    /*  /// <summary>
       /// Рекурсивно делит список по частям, пока может.
       /// </summary>
       /// <param name="pair">пара нужна, чтобы потом обратно сшить</param>
       void SplitterPart(MyList<T> pair) {
           if (count > 1) {
               MyList<T>* parts = Split(); //Split() возвращает указатель на массив из двух частей спиика
               parts[0].SplitterPart(parts[1]);
               parts[1].SplitterPart(parts[0]);
           }
           else {
               MergerPart(pair);
           }
       }
       /// <summary>
       /// По аналогии должно рекурсивно все сшивать, но я не знаю, как заставить это работать.
       /// </summary>
       /// <param name="pair"></param>
       /// <returns></returns>
       MyList<T> MergerPart(MyList<T> pair) {
           MyList<T> merged;
           merged.Add(GetValue(0));//объединение работает только с единичными массивами, да
           merged.Add(pair.GetValue(0));
           if (GetValue(0) > pair.GetValue(0)) {
               merged.Switch(0, 1);
           }
           return merged;
       }
       void MergeSort() {

       }*/
    void CountSort() {
        int max = (int)Max();
        int* a = (int*)calloc(max + 1, sizeof(int));
        for (int i = 0; i <= max; i++) {
            a[i] = 0;
        }
        current = beginning;
        while (current != nullptr) {
            a[(int)(current->data)]++;
            ++(*this);
        }
        Clear();
        for (int i = 0; i <= max; i++) {
            if (i == 97) {
                ;
            }
            for (int j = 0; j < a[i]; j++) {
                Add((T)i);
            }
        }
        free(a);
    }
    void QuickSort(int i, int j)
    {
        T pivot;
        int lh = i;
        int rh = j;
        pivot = GetValue(i);
        while (i <= j)
        {
            while ((GetValue(i) < pivot))
                i++;
            while ((GetValue(j) > pivot))
                j--;
            if (i <= j)
            {
                if (GetValue(i) >= GetValue(j))
                    Switch(i, j);
                i++;
                j--;
            }
        }
        if (lh < j) QuickSort(lh, j);
        if (i < rh) QuickSort(i, rh);
    }
    int Search(T selm, int l, int r) //лучше использовать SearchWhile (тот же поиск, но лучше)
    {
        // printf("borders - %d %d", l, r);
       //  printf("\n");
        T midel = Move((l + r) / 2)->data;
        printf("elem = %c", midel);
        //  printf("\n");
        if (selm > midel)
        {
            int i = (l + r) / 2 + 1;
            Search(selm, i, count);
        }
        else if (selm < midel)
        {
            int i = (l + r) / 2 - 1;
            Search(selm, 0, i);
        }
        else return midel;
    }
    int SearchWhile(T selm, int l, int r)
    {
        while (l <= r)
        {
            //  printf("borders - %d %d", l, r);
            //  printf("\n");
            T midel = Move((l + r) / 2)->data;
            //  printf("elem = %c", midel);
            //  printf("\n");
            if (selm < midel)
                r = (l + r) / 2 - 1;
            else if (selm > midel)
                l = (l + r) / 2 + 1;
            else
            {
                return midel;
            }
        }return -9;
    }
};