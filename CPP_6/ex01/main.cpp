/* **************************************************************************** */
/*                                                                      .       */
/*   main.cpp                                                        / V\     */
/*                                                                   / `  /     */
/*   By: tilda      <tilda@student.21-school.ru.fr>                 <<   |      */
/*                                                                  /    |      */
/*   Created: 5/20/21 by tilda                                    /      |      */
/*                                                              /        |      */
/*                                                            /    \  \ /       */
/*                                                           (      ) | |       */
/*                                                   ________|   _/_  | |       */
/*                                                 <__________\______)\__)      */
/* **************************************************************************** */

#include "Include/SerializationHeader.hpp"

void serializeStr(char *dataSerialize, int sizeStr){
	int randSymbol;
	for (int i = 0; i <  + sizeStr; i++){
		randSymbol = 65 + rand() % 15;
		std::cout << static_cast <char> (randSymbol);
		*dataSerialize = static_cast <char> (randSymbol);
		dataSerialize++;
	}
	std::cout << std::endl;
}

void serializeInt(char *dataSerialize, int nbr, int sizeInt){
	dataSerialize = reinterpret_cast <char *> (nbr);
	dataSerialize += sizeInt;
}

void* serialize(void){
	void* ptr;
	int sizeInt = sizeof(int);
	int sizeFirstStr = 24;
	int sizeSecondStr = 32;
	int randomInt = rand() % 1000;
	char* dataSerialize = new char[(sizeInt * 3) + sizeFirstStr + sizeSecondStr];

	ptr = static_cast <void *> (dataSerialize);
	serializeInt(dataSerialize, sizeFirstStr, sizeInt);
	std::cout << "Sould serilalize " << sizeFirstStr << std::endl;
	serializeStr(dataSerialize,sizeFirstStr);
	serializeInt(dataSerialize, randomInt, sizeInt);
	std::cout << "Sould serilalize " << randomInt << std::endl;
	serializeInt(dataSerialize, sizeSecondStr, sizeInt);
	std::cout << "Sould serilalize " << sizeSecondStr << std::endl;
	serializeStr(dataSerialize,sizeSecondStr);

	return ptr;
}

int deserializeInt(char* raw, int intSize){
	void* copy = static_cast <void *> (raw);
	int* integer = reinterpret_cast<int*>(copy);
	raw += intSize;
	return *integer;
}

std::string deserializeStr(char* raw, int sizeInt){
	int sizeStr;
	char* literalStr;
	std::string objStr;

	sizeStr = deserializeInt(raw, sizeInt);
	literalStr = new char[sizeStr];
	std::memcpy(literalStr, raw, sizeStr);
	objStr = strdup(literalStr);
	raw += sizeStr;
	delete literalStr;
	return objStr;
}


Data* deserialize(void* raw){
	char* charRaw;
	int sizeInt = sizeof(int);
	Data *data = new Data();

	charRaw = static_cast <char *> (raw);
	data->str1 = deserializeStr(charRaw, sizeInt);
	data->integer = deserializeInt(charRaw, sizeInt);
	data->str2 = deserializeStr(charRaw, sizeInt);
	return data;
}

int main(){
	std::srand(std::time(NULL));
	void* dataSerialize1 = serialize();
	void* dataSerialize2 = serialize();
	void* dataSerialize3 = serialize();

	Data* data1 = deserialize(dataSerialize1);
	Data* data2 = deserialize(dataSerialize2);
	Data* data3 = deserialize(dataSerialize3);

	std::cout << data1->str1 << "|" << data1->str2 << "|" << data1->integer << std::endl;
	std::cout << data2->str1 << "|" << data2->str2 << "|" << data2->integer << std::endl;
	std::cout << data3->str1 << "|" << data3->str2 << "|" << data3->integer << std::endl;
	std::cout << sizeof(data3->str1) << std::endl;
	std::cout << sizeof(data3->integer) << std::endl;
	std::cout << sizeof(data3->str2) << std::endl;


	delete data1;
	delete data2;
	delete data3;
	return (0);
}