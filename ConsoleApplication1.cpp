// RabbitHole.cpp: определяет точку входа для консольного приложения.
//

#include"stdafx.h"
#include<iostream>
#include<math.h>
#include<fstream>


int num, sym;
fstream myfile;


bool number(int a, int n) //Функция проверки цифр
{
	bool d = 1;
	for (int i = 0; i < a; i++) //Проверяются цифры, от первого разряда и до разряда a
	{
		if ((n % pow(10, i + 1) / pow(10, i)) < a) //По умолчанию в d хранится "Да"...
		{
		}
		else //Но если какая-то из цифр не проходит условие - значение меняется на нет и мы выходим из цикла
		{
			d = 0;
			break;
		}
	}
	return d;
}

double equation(int n)
{
	if (n >= 2 * num)
		return sqrt(1 + 2 * n); //Если параметр равен/больше предела, возвращает значение
	else
		return sqrt(1 + (n + 1) * equation(n + 1)); //Если параметр меньше предела - вызов функции sqrt со вложенным вызовом этой функции (рекурсия)
}

double equation(int n, int m)
{
	if (m == 0 || m == n)
		return 1; //Если бином С(х, 0) или С(х, х) - возвращает 1
	else
		return (equation(n - 1, m) + equation(n - 1, m - 1)); //Иначе - вызывает эту функцию с измененными параметрами (рекурсия)
}

void output(int sym, int n) //Доп. задание
{
	if (n < pow(10, sym)) //Проверка, содержит ли число sym значащих цифр
	{
		output(sym, n + 1); //Если да - вызывается функция для следующего числа...
		if (number(sym, n)) //...И вызывается функция проверки цифр
		{
			myfile << n << "\n"; //Если возвращается "Да" - число сохраняется в файл
		}
	}
}




int main()
{
	myfile.open("Save.txt"); //Открытие файла для доп. задания
	double res;
	std::cout << "Please, enter a integral number: "; //Задание 1
	std::cin >> num;

	res = equation(num);

	std::cout << "\nResult is: " << res << "\n";


	std::cout << "\nPlease, enter 2 integral numbers: "; //Задание 2, бином Ньютона

	std::cin >> num;
	std::cin >> sym;
	if (num > sym)
		res = equation(num, sym);
	else
		res = equation(sym, num);

	std::cout << "\nResult is: " << res << "\n";

	std::cout << "\nPlease, enter integral number from 1 to 9: "; /*Дополнительно задание - прием цифры,
																  и сохранение чисел, которые имеют это кол-во знаков и 
																  все знаки меньше введенной цифры*/
	std::cin >> sym;
	output(sym, pow(10, sym - 1));
	std::cout << "\nResult numbers are saved in file\n";

	system("pause");
	myfile.close();
	return 0;
}


