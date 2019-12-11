#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "HString.h"
#include <iostream>
#include <cstring>
using namespace std;
String::String()
{
	setData("");
}

String::String(const char *s)
{
	setData(s);
}

String::String(int i)
{
	char    buffer[10];
	sprintf(buffer, "%d", i);
	setData(buffer);
}

void String::setData(const char* s) {
	if (s != NULL) {
		m_size = strlen(s);
		m_data = new char[m_size + 1];
		strcpy(m_data, s);
	}
	else {
		// Sets an empty string
		m_size = 0;
		m_data = new char[1];
		m_data[0] = '\0';
	}
}

void String::set(const char *s)
{
	delete[] m_data;
	setData(s);
}

void String::set(const String& s)
{
	set(s.m_data);
}

void String::set(int i)
{
	char buffer[10];
	sprintf(buffer, "%d", i);
	set(buffer);
}

int String::cmp(const char *s) const
{
	return(strcmp(m_data, s));
}

int String::cmp(const String& other) const
{
	return(cmp(other.m_data));
}
char* String::get() {
	return m_data;
}
// string3Main.cpp
String::~String() {
	delete[] m_data;
}
void main()
{
	String  s1;
	String  s2("Hello");
	String  s3(100);
	s1.set(s2);
	s2.set("Good Bye");
	s3.set(200);

	cout << "Our Strings Are: " << s1.get() << " " << s2.get()
		<< " " << s3.get() << endl;
	String s4(201);
	if (s3.cmp(s4) == 0)
		cout << "s3 == s4, Something is wrong here..." << endl;
	else
		cout << "s3 != s4, OK!" << endl;
	getchar();
}