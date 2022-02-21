#include<iostream>
#include<string>
#include <chrono>
#include"LinkedList.h"
#include"IntroSort.h"
#include"SortAlgorithm.h"
#include"Dictionary.h"
#include<map>
using namespace std;
using namespace std::chrono;
int main()
{
	
	/*Node<int>* va = new Node<int>();
	Node<int>* va2 = new Node<int>();
	va2->data = 7;
	va->data = 5;
	LinkedList<int>* newList = new LinkedList<int>();
	newList->AddFirst(1);
	newList->AddFirst(2);
	newList->AddFirst(3);
	newList->AddFirst(2);
	newList->AddFirst(4);
	newList->AddLast(va);
	newList->AddFirst(va2);
	newList->AddFirst(va2);
	newList->AddFirst(va2);
	newList->Remove(va);
	newList->Remove(va);
	newList->Display();*/
	//int a[100] = {5, 10, 12, 33, -5, 4, 1,11,12,43,12,11,56,78,90,45,23,65,23,11,-10,12};
	///*IntroSort sort;
	//sort.heapSort(a, 7);
	//for (int i = 0; i < 7; ++i)
	//{
	//	cout << a[i] << " ";
	//}*/
	//SortAlgorithm<int> sort;
	//auto start = high_resolution_clock::now();
	////sort.HeapSort(a, 22);
	////sort.InsertionSort(a, 22);
	//sort.IntroSort(a, 0, 22);
	///*IntroSort sort;
	//sort.heapSort(a, 22);
	//sort.InsertionSort(a, a, a + 22 - 1);
	//sort.Introsort(a, a, a + 22 - 1);*/

	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);
	//cout << "Time taken by function: "
	//	<< duration.count() << " microseconds" << endl;
	//for (int i = 0; i < 22; ++i)
	//{
	//	cout << a[i] << " ";
	//}
	Dictionary<string,string>* dictionary = new Dictionary<string, string>();
	string name = "Nguyen";
	string anotherName = "Nguyen";
	dictionary->Add(&name, "Huu Dung");
	string value = "";
	if (dictionary->TryGetValue(&anotherName, &value))
	{
		cout << value << endl;
	}
	//string name = "Nguyen";
	/*dictionary->Add("Nguyen", "Huu Dung");
	string value = "";
	if (dictionary->TryGetValue("Nguyen", &value))
	{
		cout << value << endl;
	}*/
	return 0;
}