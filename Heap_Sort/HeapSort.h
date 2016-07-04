class HeapSort {

private:

	int* pArray; // dynamic array
	int size; // array size
	char* inFile; // pointer to argv[1]
	char* outFile; // pointer to argv[2]

public:

	HeapSort(int a, char* i, char* o); // constructor

	void buildHeap();

	void insertOneDataItem(int a);

	void DeleteHeap();
	
	void DeleteRoot();
	
	void bubbleUp();
	
	void bubbleDown();
	
	bool isHeapEmpty();
	
	bool isHeapFull();
	
	std::string printHeap(int a); // int a: how may items you have to print starting from [1]

};
