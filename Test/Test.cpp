// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch2\catch.hpp>
#include "Lab5Str/MyList.h"
unsigned int Factorial(unsigned int number) {
	return number <= 1 ? number : Factorial(number - 1) * number;
}
/*
TEST_CASE("Factorials are computed", "[factorial]") {
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
}*/
TEST_CASE("MyList AddFront", "[MyList]") {
	MyList<char> s;
	s.AddFront('c');
	CHECK(s.beginning == s.end);
	s.AddFront('d');
	CHECK(s.GetValue(0) == 'd');
}

TEST_CASE("MyList conctructor", "[MyList]") {
	MyList<char> s;
	CHECK(s.Size() == 0);
	CHECK(s.beginning == nullptr);
	CHECK(s.end == nullptr);

}
//pushfront=AddFront
//push_back=Add

TEST_CASE("MyList Add", "[MyList]") {
	MyList<char> s;
	s.Add('c');
	CHECK(s.beginning == s.end);
	s.Add('d');
	CHECK(s.GetValue(1) == 'd');
}

TEST_CASE("MyList Insert", "[MyList]") {
	MyList<char> d;
	d.Insert('b', 0);
	CHECK(d.count == 1);
	d.AddFront('c');
	d.AddFront('c');
	d.AddFront('c');
	d.Insert('v', 2);
	CHECK(d.count == 5);

	d.Insert('z', 4);
	CHECK(d.count == 6);
	//CHECK(s.front() == s.GetValue(0));
	//CHECK(s.back() == s.end->data);
}

TEST_CASE("MyList pop_front", "[MyList]") {
	MyList<char> s;
	s.AddFront('a');
	s.AddFront('b');
	s.AddFront('c');
	s.Delete(0);
	s.Delete(0);
	CHECK(s.beginning == s.end);
	s.Delete(0);
	CHECK(s.Back()->data == s.end->data);

}

TEST_CASE("MyList pop_back", "[MyList]") {
	MyList<char> s;
	s.AddFront('a');
	s.AddFront('b');
	s.AddFront('c');
	s.DeleteBack();
	s.DeleteBack();
	s.DeleteBack();
	CHECK(s.beginning == s.end);
	//CHECK(s.front() == s.GetValue(0));
	//CHECK(s.back() == s.end->data);


}


TEST_CASE("MyList remove", "[MyList]") {
	MyList<char> s;
	s.AddFront('a');
	s.AddFront('b');
	s.AddFront('k');
	s.AddFront('c');
	s.AddFront('c');
	s.AddFront('d');
	s.AddFront('e');
	s.AddFront('f');
	s.DeletebyValue('a');
	s.DeletebyValue('f');
	s.DeletebyValue('c');
	CHECK(s.Front()->data == s.GetValue(0));
	CHECK(s.Back()->data == s.end->data);
}


TEST_CASE("MyList front", "[MyList]") {
	MyList<char> s;
	s.AddFront('a');
	s.AddFront('a');
	s.AddFront('a');
	s.AddFront('a');
	CHECK(s.Front()->data == s.GetValue(0));
}


TEST_CASE("MyList back", "[MyList]") {
	MyList<char> s;
	s.AddFront('a');
	s.AddFront('b');
	s.AddFront('c');
	s.AddFront('d');
	CHECK(s.Back()->data == s.GetValue(3));
	CHECK(s.Front()->data == s.GetValue(0));
	CHECK(s.Back()->data == s.end->data);
}

TEST_CASE("MyList size", "[MyList]") {
	MyList<char> s;
	CHECK(s.Size() == 0);
	s.AddFront('a');
	s.AddFront('a');
	s.AddFront('a');
	s.AddFront('a');
	CHECK(s.Size() == 4);
}

TEST_CASE("MyList GetValue", "[MyList]") {
	MyList<char> s;
	s.AddFront('a');
	s.AddFront('a');
	s.AddFront('a');
	s.AddFront('a');
	CHECK(s.GetValue(3));
}



TEST_CASE("MyList mnojestvo++", "[MyList]") {
	MyList<char> s;
	for (int i = 1; i < 10; i++) {
		s.AddFront('a');
		s.Add('b');
		CHECK(s.Size() == i * 2);
		CHECK(sizeof(s.Back()->data) == sizeof(char));

	}

}

TEST_CASE("MyList mnojestvo--", "[MyList]") {
	MyList<char> s;
	for (int i = 1; i < 10; i++) {
		s.AddFront('a');
		s.Add('b');
		CHECK(s.Size() == i * 2);
		CHECK(sizeof(s.Back()->data) == sizeof(char));
	}
	//s.remove('a');
	for (int i = 10000; i >= 0; i--) {
		s.DeleteFront();
		s.DeleteBack();
		//CHECK(sizeof(s.back()) == sizeof(char));
	}
	CHECK(s.Size() == 0);
}

TEST_CASE("MyList complex", "[MyList]") {
	MyList<char> s;
	s.AddFront('a');
	CHECK(s.Size() == 1);
	s.AddFront('b');
	CHECK(s.Size() == 2);
	s.Add('c');
	CHECK(s.Size() == 3);
	s.Add('d');
	CHECK(s.Size() == 4);


	CHECK(s.GetValue(0) == 'b');
	CHECK(s.GetValue(1) == 'a');
	CHECK(s.GetValue(2) == 'c');
	CHECK(s.GetValue(3) == 'd');

} /**/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
