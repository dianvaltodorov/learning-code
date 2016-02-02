/******************************************************/
/* Примерен код към курса ООП, ФМИ (2016)
* Пример за структури - структура представяща адрес
* Съставен от няколко статични полета.
* Функции за четене и извеждане на стандартния изход  */
/******************************************************/


#ifndef _ADDRESS_HEADER_INCLUDED_
#define _ADDRESS_HEADER_INCLUDED_

struct Address
{
    char city[32];
    char street[64];
    unsigned short number;
    unsigned long ZIP;
};

// Извежда подаден адрес на стандартния изход
void printAddress(const Address& address);

// Чете данни за адрес от стандартния вход
void readAddress(Address& address);

#endif //_ADDRESS_HEADER_INCLUDED_
