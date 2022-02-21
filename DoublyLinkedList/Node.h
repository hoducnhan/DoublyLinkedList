#pragma once
#include<iostream>
template<typename T>
class Node
{
public:
	Node* prev;
	Node* next;
	T data;
	Node(T value)
	{
		data = value;
		prev = NULL;
		next = NULL;
	}
	Node(){}
};



