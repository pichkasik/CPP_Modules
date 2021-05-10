/* **************************************************************************** */
/*                                                                      .       */
/*   Search.cpp.cc                                                     / V\     */
/*                                                                   / `  /     */
/*   By: tilda      <tilda@student.21-school.ru.fr>                 <<   |      */
/*                                                                  /    |      */
/*   Created: 5/10/21 by tilda                                    /      |      */
/*                                                              /        |      */
/*                                                            /    \  \ /       */
/*                                                           (      ) | |       */
/*                                                   ________|   _/_  | |       */
/*                                                 <__________\______)\__)      */
/* **************************************************************************** */


#include "Search.hpp"

std::string Search::getCorrectString(std::string str)
{
	std::string	spaceString;
	int			numberSpaces;
	int			width = 10;

	if (str.length() > width){
		return str.substr(0, width - 1) + ".";
	}
	else{
		numberSpaces = width - static_cast <int> (str.length());
		spaceString = std::string(numberSpaces, ' ');
		return str + spaceString;
	}
}

void Search::printShortContactByIndex(Contact *contact, int index){
	std::string rowToPrint;
	rowToPrint = std::to_string(index);
	rowToPrint += "|" + getCorrectString(contact[index].firstName)
				+ "|" + getCorrectString(contact[index].lastName)
				+ "|" + getCorrectString(contact[index].nickName)
				+ "|";
	std::cout << rowToPrint;
}

void Search::printFullContactByIndex(Contact *contact, int index){
	std::string rowToPrint;
	rowToPrint = std::to_string(index + 1);
	rowToPrint += "|" + getCorrectString(contact[index].firstName)
				+ "|" + getCorrectString(contact[index].lastName)
				+ "|" + getCorrectString(contact[index].nickName)
				+ "|" + getCorrectString(contact[index].login)
				+ "|" + getCorrectString(contact[index].postalAddress)
				+ "|" + getCorrectString(contact[index].email)
				+ "|" + getCorrectString(contact[index].birthdayDate)
				+ "|" + getCorrectString(contact[index].favoriteMeal)
				+ "|" + getCorrectString(contact[index].underwearColor)
				+ "|" + getCorrectString(contact[index].darkestSecret)
				+ "|" + getCorrectString(std::to_string(contact[index].phoneNumbrer));
	std::cout << rowToPrint;
}

