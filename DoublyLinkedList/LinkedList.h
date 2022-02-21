#pragma once
#include<iostream>
#include"Node.h"
#include<string>
template<typename T>
class LinkedList
{
private:
	Node<T>* first;
	Node<T>* last;
	int length;
	void InitialLinkedList(T value)
	{
		first = new Node<T>();
		first->data = value;
		first->prev = first->next = NULL;
		last = first;
	}
	void InitialLinkedList(Node<T>* node)
	{
		first = node;
		first->prev = first->next = NULL;
		last = first;
	}
	bool HasInLinkedList(Node<T>* node)
	{
		Node<T>* p = first;
		if (p == NULL) { return false; }
		while (p)
		{
			if (p == node)
			{
				return true;
			}
			p = p->next;
		}
		return false;
	}
	
	~LinkedList()
	{
		Clear();
	}
public:
	LinkedList()
	{
		first = NULL;
		last = first;
		length = 0;
	}
	
	Node<T>* First()
	{
		return first;
	}
	Node<T>* Last()
	{
		return last;
	}
	int Length()
	{
		return length;
	}
	void AddLast(T value)
	{
		if (first == last && first == NULL)
		{
			InitialLinkedList(value);
		}
		else
		{
			Node<T>* t = new Node<T>();
			t->data = value;
			t->prev = last;
			t->next = NULL;
			last->next = t;
			last = t;
		}
		length++;
	}
	void AddLast(Node<T>* node)
	{
		if (HasInLinkedList(node)) { return; }
		if (node == NULL) { return; }
		if (first == last && first == NULL)
		{
			InitialLinkedList(node);
		}
		else
		{						
			node->prev = last;
			node->next = NULL;
			last->next = node;
			last = node;
		}
		length++;
	}
	void AddFirst(T value)
	{

		if (first == last && last == NULL)
		{
			InitialLinkedList(value);
		}
		else
		{
			Node<T>* t = new Node<T>();
			t->data = value;
			t->next = first;
			t->prev = NULL;
			first->prev = t;
			first = t;
		}
		length++;
	}
	void AddFirst(Node<T>* node)
	{
		if (HasInLinkedList(node)) { return; }
		if (node == NULL) { return; }
		if (first == last && last == NULL)
		{
			InitialLinkedList(node);
		}
		else
		{
			node->next = first;
			node->prev = NULL;
			first->prev = node;
			first = node;
		}
		length++;
	}
	void AddBefore(Node<T>* node, T value)
	{
		if (!HasInLinkedList(node)) { return; }
		if (node == first||node==NULL)
		{
			length++;
			AddFirst(value);
			return;
		}
		Node<T>* t = new Node<T>();
		t->data = value;
		t->next = node;
		t->prev = node->prev;
		if(node->prev){ node->prev->next = t; }		
		node->prev = t;
		length++;
	}
	void AddBefore(Node<T>* node, Node<T>* nodeValue)
	{
		if (HasInLinkedList(nodeValue)) { return; }
		if (nodeValue == NULL) { return; }
		if (!HasInLinkedList(node)) { return; }
		if (node == first || node == NULL)
		{
			length++;
			AddFirst(nodeValue);
			return;
		}
		nodeValue->next = node;
		nodeValue->prev = node->prev;
		if (node->prev) { node->prev->next = nodeValue; }
		node->prev = nodeValue;
		length++;
	}
	void AddAfter(Node<T>* node, T value)
	{
		if (!HasInLinkedList(node)) { return; }
		if (last == node || node == NULL)
		{
			length++;
			AddLast(value);
			return;
		}
		Node<T>* t = new Node<T>();
		t->data = value;
		t->next = node->next;
		t->prev = node;
		if(node->next){ node->next->prev = t; }		
		node->next = t;
		length++;
	}
	void AddAfter(Node<T>* node, Node<T>* nodeValue)
	{
		if (HasInLinkedList(nodeValue)) { return; }
		if (nodeValue == NULL) { return; }
		if (!HasInLinkedList(node)) { return; }
		if (last == node || node == NULL)
		{
			length++;
			AddLast(nodeValue);
			return;
		}		
		nodeValue->next = node->next;
		nodeValue->prev = node;
		if (node->next) { node->next->prev = nodeValue; }
		node->next = nodeValue;
		length++;
	}
	void Clear()
	{	
		length = 0;
		while (first)
		{
			Node<T>* p = first;
			first = first->next;			
			delete p;
			p = NULL;						
		}
		last = NULL;
	}
	Node<T>* Find(T value)
	{
		Node<T>* p = first;
		while (p)
		{
			if (p->data == value)
			{
				return p;
			}
			p = p->next;
		}
		return NULL;
	}
	Node<T>* FindLast(T value)
	{
		Node<T>* p = first;
		Node<T>* result = NULL;
		while (p)
		{
			if (p->data == value)
			{
				result = p;
			}
			p = p->next;
		}
		return result;
	}
	void RemoveFirst()
	{
		if (first == NULL) { return; }
		Node<T>* p = first;
		first = first->next;
		delete p;
		p = NULL;
		first->prev = NULL;
		length--;
	}
	void RemoveLast()
	{
		if (last == NULL) { return; }
		Node<T>* p = last;
		last = last->prev;
		delete p;
		p = NULL;
		last->next = NULL;
		length--;
	}
	bool Remove(T value)
	{
		if (value == first->data)
		{			
			RemoveFirst();
			return true;
		}
		Node<T>* p = first;
		while (p)
		{
			if (p->data == value)
			{
				if (p == last)
				{
					RemoveLast();
					return true;
				}
				Node<T>* t = p;
				if(p->prev){ p->prev->next = p->next; }
				if(p->next){ p->next->prev = p->prev; }
				delete t;
				t = NULL;
				length--;
				return true;
			}
			p = p->next;
		}
		return false;
	}
	void Remove(Node<T>* node)
	{
		if (node == NULL) { return; }
		if (!HasInLinkedList(node)) { return; }
		if (node==first)
		{			
			first = first->next;
			first->prev = NULL;
			node->next = NULL;
			node->prev = NULL;
			length--;
			return;
		}
		Node<T>* p = first;
		while (p)
		{
			if (p==node)
			{
				Node<T>* t = p;
				if (p->prev) { p->prev->next = p->next; }
				if (p->next) { p->next->prev = p->prev; }
				t->next = NULL;
				t->prev = NULL;
				length--;
				return;
			}
			p = p->next;
		}	
	}
	void Reverse()
	{
		if (first == NULL) { return; }
		last = first;
		Node<T>* p = first;
		while (p)
		{
			Node<T>* t = p->next;
			p->next = p->prev;
			p->prev = t;			
			p = p->prev;
			if (p != NULL && p->next == NULL )
			{
				first = p;
				
			}
		}
	}
	bool Contains(T value)
	{
		if (first == NULL) { return false; }
		Node<T>* p = first;
		while (p)
		{
			if (value == p->data)
			{
				return true;
			}
			p = p->next;
		}
		return false;
	}
	bool Contains(Node<T>* node)
	{
		if (first == NULL) { return false; }
		Node<T>* p = first;
		while (p)
		{
			if (node==p)
			{
				return true;
			}
			p = p->next;
		}
		return false;
	}
	void Display()
	{
		Node<T>* p = first;
		if (p == NULL) 
		{
			std::cout << "Linked list is empty" << std::endl;
			return;
		}
		while (p)
		{
			std::cout << p->data << std::endl;
			p = p->next;
		}
	}
};