#include <iostream>
#include <ctime> 
#include <locale>
#include <iomanip> 
#include "Combi.h"
#include"Boat.h"
#include "Auxil.h"
#include <iomanip> 
#include <string>
#include <conio.h>
#define N 10
#define INF   0x7fffffff 
#define H (sizeof(AA)/2)
#define M 3
#define NN (sizeof(v)/sizeof(int))
#define MM 6
#define COUNT 35
int main()
{
	setlocale(LC_ALL, "rus");
	
	int v[COUNT]; //Вес клнтейнеров
	int c[COUNT]; //Доход от перевзки каждого
	auxil::start();
	for (int i = 0; i < COUNT; i++)
	{
		v[i] = auxil::iget(100, 900);
		c[i] = auxil::iget(10, 150);
	}

	int V = 1500;
	short  r[MM];
	clock_t t1 = clock();
	int cc = boat(
		V,   // [in]  максимальный вес груза
		MM,  // [in]  количество мест для контейнеров     
		NN,  // [in]  всего контейнеров  
		v,   // [in]  вес каждого контейнера  
		c,   // [in]  доход от перевозки каждого контейнера     
		r    // [out] результат: индексы выбранных контейнеров  
	);
	clock_t t2 = clock();

	std::cout << std::endl << "Задача о размещении контейнеров на судне \n --------------------------------";
	std::cout << std::endl << "Общее количество контейнеров : " << NN;
	std::cout << std::endl << "количество мест для контейнеров : " << MM;
	std::cout << std::endl << "ограничение по суммарному весу  : " << V;
	std::cout << std::endl << "вес контейнеров : ";
	for (int i = 0; i < NN; i++) std::cout << std::setw(3) << v[i] << " ";
	std::cout << std::endl << "доход от перевозки : ";
	for (int i = 0; i < NN; i++) std::cout << std::setw(3) << c[i] << " ";
	std::cout << std::endl << "выбраны контейнеры (0,1,...,m-1): ";
	for (int i = 0; i < MM; i++) std::cout << r[i] << " ";
	std::cout << std::endl << "доход от перевозки : " << cc;
	std::cout << std::endl << "общий вес выбранных контейнеров : ";
	int k = 0; for (int i = 0; i < MM; i++) k += v[r[i]]; std::cout << k;
	std::cout << std::endl << std::endl;
	std::cout << "Время: " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC) << std::endl;
	system("pause");

	std::cout << std::endl << "Задача об оптимальной загрузке судна \n ----------------------------------- ";
	std::cout << std::endl << "ограничение по весу : " << V;
	std::cout << std::endl << "количество мест : " << MM;
	std::cout << std::endl << "количество контейнеров / продолжительность вычисления";
	for (int i = 25; i <= NN; i++)
	{
		t1 = clock();
		int maxcc = boat(V, MM, i, v, c, r);
		t2 = clock();
		std::cout << std::endl << "          " << std::setw(2) << i
			<< "                     " << std::setw(5) << (t2 - t1);
	}
	std::cout << std::endl << std::endl;
	system("pause");
}