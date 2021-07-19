#include <iostream>

using namespace std;

class Temp
{
	int TEMP;
public:                    
	Temp() { TEMP = 25; } //конструктор
	void TempFunction() {
		cout << "TEMP = " << TEMP << "\n\n"; //функция показа на экран
	}
	
	void TempSet(int T) //функция установки значения
	{        
		TEMP = T;
	}
};

class SmartPointer
{
	
	Temp* ptr;
	int count_copy; //счётчик

public:
	
		SmartPointer(Temp * p = NULL)//конструктор
		{
			count_copy = 0; //записываем 0 при создании копий нет
			ptr = p;
		}


	SmartPointer(const SmartPointer& obj) 
	{
		                                                        //создается копия - увеличиваем счётчик
		ptr = obj.ptr;
		count_copy++;
	}
	                                                             //перегрузка оператора равно
	SmartPointer operator=(const SmartPointer& obj)
	{
		                                                         //создается копия - увеличиваем счётчик
		ptr = obj.ptr;
		ptr = obj.ptr;
		count_copy++;
		                                                        //возвращаем сам объект для ситуации a=b=c
		return *this;
	}
	                       
	~SmartPointer() {
		                                                          //если объект есть и копий нет
		if (ptr != NULL && count_copy == 0) 
		{
			cout << "\n~Delete Object\n";
			                                                                //уничтожаем объект
			delete[]ptr;
		}
		                                                             //в противном случае(уничтожается копия)
		else 
		{
			                                                               //уменьшаем счётчик
			count_copy--;
			cout << "\n~Delete Copy\n";
		}
	}
	                                       
	Temp* operator->() {
		return ptr;
	}
};

void main() {
	  
	Temp* main_ptr = new Temp;
	                                                            //инициализируем этим объектом умный указатель
	SmartPointer PTR(main_ptr);
	
	PTR->TempSet(100);
	PTR->TempFunction();
	
	SmartPointer PTR2 = PTR;
}
