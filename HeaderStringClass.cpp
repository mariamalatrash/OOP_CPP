#pragma once
#include <iostream>
using namespace std;

class String
{
public:
	String();
	String(const char* s);
	String(int i);
	~String();

	void    set(const char* s);
	void    set(const String& s);
	void    set(int i);
	int     cmp(const char* s) const;
	int     cmp(const String& other) const;
	char* get();
	//...
private:
	//...
	void   setData(const char* s);
	int m_size;
	char* m_data;
};
