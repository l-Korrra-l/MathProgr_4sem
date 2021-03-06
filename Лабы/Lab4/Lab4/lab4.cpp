#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenshtein.h"
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	clock_t t1 = 0, t2 = 0, t3, t4;
	char x[] = "darhwwwpgmbmguuazcqmrxhtsstojiuqjvjlovgoozmxiyummgyqreaudwmfepeurfgjuligratnssmtjnokviqjgrzaoiprvxddmxmgxttizjyutoornicpavhhzhvlthnuolmdfriernvwuloqauwbqtkljbuymcixrlxsiuizhuvmindabfectaqdgjdjgqxztjokuzbbnsdrgojutbxjrumjpgztizongjtpfirzawglgpjpaezmqbyewdxdltdyuylwonnfyczybbtkqtvtkzgrnvbmmzwznqyxhkja",
		y[] = "djlzveaiwkulyybsuaioafnekwanencvxqskrxhnqrczxaqzorxgjpphhztyreszdtveoqxvwtllxfhkotmvpwljryjdtsbxkvhjydtzuzzjdexltuvdxjpcoirukbksmhlsohsmkuqvbrnnohptvinykppmsuhadtdxswxbmchuamwcemigvilfsjlhboooonfzdxbyancabawwphdafzcsdfsudoqldpgyjmxerznpapviymgwhvijmt";
	int  lx = sizeof(x) - 1, ly = sizeof(y) - 1;
	std::cout << "str1   " << x << std::endl;
	std::cout << "str2   " << y << std::endl;
	std::cout << std::endl;
	std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;

	std::cout << std::endl << "-- расстояние Левенштейна -----" << std::endl;
	std::cout << "ЛОМ" << std::endl;
	std::cout << "ГОМОН" << std::endl;
	std::cout << levenshtein(3, "ЛОМ", 5, "ГОМОН");

	std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;
	std::cout << std::endl << "-- расстояние Левенштейна -----" << std::endl;
	std::cout << std::endl << "--длина --- рекурсия -- дин.програм. ---"
		<< std::endl;
	double arr[]={1/25,1/20,1/15,1/10,1/5,1/2,1};
	for (int i = 8; i < std::min(lx, ly); i++)
	{

		t1 = clock(); levenshtein_r(i, x, i - 2, y); t2 = clock();
		t3 = clock(); levenshtein(i, x, i - 2, y); t4 = clock();
		std::cout << std::right << std::setw(2) << i - 2 << "/" << std::setw(2) << i
			<< "        " << std::left << std::setw(10) << (t2 - t1)
			<< "   " << std::setw(10) << (t4 - t3) << std::endl;
	}
	system("pause");
	return 0;
}
