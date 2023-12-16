// strukturka.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
//#include <list.h>
#include "MyList.h"


int main()
{
    MyList<char> s;
    MyList<char> somelist;
    s.Scanner("sakdalsdk");
    if (s.Front()->data == s.GetValue(1))
        printf("aboba");
    else
        printf("Kuks");
    // printf("%c", somelist.GetValue(0));
   /*  MyList<char> somelist;
   //  printf("Mesto: %d", tochka1());
     //printf("\n");
     somelist.Scanner("987654dbca");
    somelist.CountSort();
     somelist.BrushSort();
    somelist.BubbleSort();
   somelist.ChoiceSort();
     somelist.ExchangeSort();
    somelist.InserSort();
     somelist.ShakerSort();
     somelist.PrinterViaCurrent();
     int b = somelist.Size();
     char selm = 'a';
    // somelist.QuickSort(0,b-1);
  //   somelist.Printer();
    printf("\n");
    if (somelist.SearchWhile(selm, 0, b) >= 0)
         printf("searched el in list");
     else printf("this el not in list");*/
     // somelist.Scanner("lbuigiuguoguoguooi8h8ipuipuogivgiohuvuohgiikhiv");
      //somelist.ChoiceSort();
      //somelist.PrinterViaCurrent();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
