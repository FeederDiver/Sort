#include <ctime>
template <class arrayType>
class Sorts
{
private:
	arrayType * myArray;
	int lenght;
	void swap(int first, int second);
	void mergeSort(int start, int end);
	void quickSort(int start, int end);
	template <typename myArrayType> void heapSort(int start, int end);
	template <typename myArrayType> void heapify(int size, int position, arrayType* tempTable);
	void introSort(int start, int end, int count);
public:
	Sorts() { myArray = new arrayType; }
	Sorts(int size) { myArray = new arrayType[size]; lenght = size; }
	Sorts(int size, bool ordered)
	{
		lenght = size;
		myArray = new arrayType[size]; 
		if (ordered) { for (int i = 0; i < size; i++) myArray[i] = arrayType(i); }
		else
		{
			srand(time(NULL));
			for (int i = 0; i < size; i++) myArray[i] = arrayType(rand());
		}

	}
	void display();
	void mergeSort();
	void quickSort();
	void heapSort();
	void introSort();

};
