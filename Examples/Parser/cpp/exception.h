/******************************************************
Copyright (c/c++) 2013-doomsday by Alexey Slovesnov 
homepage http://slovesnov.narod.ru/indexe.htm
email slovesnov@yandex.ru
All rights reserved.
******************************************************/

#ifndef _exception_h_
#define _exception_h_

class Exception: std::exception{//this class is created for g++ compiler
	std::string message;
public:
	Exception(const char* _message):std::exception(){
		message=_message;
	};

	const char* what() const throw(){
		return message.c_str();
	};

	~Exception () throw (){
	};
};

class IllegalArgumentException: Exception{
public:
	IllegalArgumentException():Exception("IllegalArgumentException"){
	};
};

#endif
