#include "stdafx.h"
#include"Auxil.h"
#include<iostream>
#include<ctime>
#include<locale>

#define  CYCLE  10000000                 

namespace auxil
{
	void start()                          // старт  генератора сл. чисел
	{
		srand((unsigned)time(NULL));
	};

	double dget(double rmin, double rmax) // получить случайное число
	{
		return ((double)rand() / (double)RAND_MAX)*(rmax - rmin) + rmin;
	};

	int iget(int rmin, int rmax)         // получить случайное число
	{
		return (int)dget((double)rmin, (double)rmax);
	};

}

int _tmain(int argc, char* argv[])
{

	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;
	int buf = 1000000;
	setlocale(LC_ALL, "rus");

	auxil::start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
		if (i == buf)
		{
			t2 = clock();  
			std::cout << std::endl << "количество циклов:         " << buf;
			std::cout << std::endl << "среднее значение (int):    " << av1 / buf;
			std::cout << std::endl << "среднее значение (double): " << av2 / buf;
			std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
			std::cout << std::endl << "                  (сек):   "
				<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
			std::cout << std::endl;
			buf += 1000000;
		}
	}
	        
	system("pause");

	return 0;
}

