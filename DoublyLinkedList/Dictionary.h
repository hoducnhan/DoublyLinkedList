#pragma once
#include<iostream>
#include"LinkedList.h"
#include<string>
using namespace Algorithm;
using HASH = long long int;
using UCHAR = unsigned char;
template<class TKey,class TValue>
class Dictionary
{
private:
	struct TVALUE
	{
		TValue value;
		HASH keyHashCode;
		TVALUE(){}
		
	};
	int lengthArray;
	LinkedList<TVALUE>** jaggArray;
	HASH HashTest(TKey* data, int byteSize)
	{
		HASH hv = 0x0030507;    // an initial value, could be anything
		UCHAR* pd = (UCHAR*)data;
		for (int n = 0; n < byteSize; ++n)
		{
			hv << 4;
			hv += pd[n];
		}
		return hv;
	}
	int GetIndex(TKey* key)
	{
		return HashTest(key, sizeof(TKey)) % lengthArray;
	}
	
public:
	Dictionary()
	{
		lengthArray = 7;
		jaggArray = new LinkedList<TVALUE>*[lengthArray];
	}
	void Add(TKey* key, TValue value)
	{
		HASH hashCode = HashTest(key, sizeof(TKey));
		int index = hashCode % lengthArray;
		if (index >= lengthArray) {
			std::cout << "Array index out of bound, exiting";
			return;
		}
		TVALUE* structValue = new TVALUE();
		structValue->value = value;
		structValue->keyHashCode = hashCode;
		jaggArray[index] = new LinkedList<TVALUE>();
		jaggArray[index]->AddLast(*structValue);
	}
	void Add(TKey key, TValue value)
	{
		TKey* refKey = key;
		HASH hashCode = HashTest(refKey, sizeof(TKey));
		int index = hashCode % lengthArray;
		if (index >= lengthArray) {
			std::cout << "Array index out of bound, exiting";
			return;
		}
		TVALUE *structValue = new TVALUE();
		structValue->value = value;
		structValue->keyHashCode = hashCode;
		jaggArray[index] = new LinkedList<TVALUE>();
		jaggArray[index]->AddLast(*structValue);
	}
	bool TryGetValue(TKey* key, TValue* value)
	{
		HASH hashCode = HashTest(key,sizeof(TKey));
		int index = GetIndex(key);
		Node<TVALUE>* p = jaggArray[index]->First();
		if (p == NULL)
		{
			return false;
		}
		while (p)
		{
			if (p->data.keyHashCode == hashCode)
			{
				*value = p->data.value;
				return true;
			}
			p = p->next;
		}
		//value = 
		return false;	
	}
	bool TryGetValue(TKey key, TValue *value)
	{
		TKey* refKey = key;
		HASH hashCode = HashTest(refKey, sizeof(TKey));
		int index = GetIndex(&key);
		Node<TVALUE>* p = jaggArray[index]->First();
		if (p == NULL)
		{
			return false;
		}
		while (p)
		{
			if (p->data.keyHashCode == hashCode)
			{
				*value = p->data.value;
				return true;
			}
			p = p->next;
		}
		//value = 
		return false;	
	}
	/*int& operator = (const int& i) { return value = i; }*/
	/*TValue& operator[](TKey* key)
	{
		int index = GetIndex(key);
		if (index >= lengthArray) {
			cout << "Array index out of bound, exiting";
			return NULL;
			exit(0);
		}
		if (jaggArray[index].First() == NULL)
		{
			jaggArray[index].AddLast()
		}
		for (int i = 0; i < jaggArray[index].Length(); ++i)
		{
			
		}
	}*/
};


