#include<iostream>
#include<cstdlib>
using namespace std;
template<class eType>
class Heap
{
	private:
		int capacity;
		eType* array;
		int currentSize;
		void percolateDown(int hole)
		{
			eType tmp=array[hole];
			int child;
			for(;2*hole<=currentSize;hole=child)
			{
				child=hole*2;
				if(child<=currentSize && array[child+1]<array[child])
					child++;
				if(array[child]<tmp)
					array[hole]=array[child];
				else
					break;
			}
			array[hole]=tmp;
		}
	public:
		Heap(int capacity=100)
		{
			array=new eType[capacity+1];
			currentSize=0;
		}
		int isEmpty()
		{
			return currentSize==0;
		}
		int isFull()
		{
			return currentSize==capacity;
		}
		void insert(const eType &x)
		{
			if(isFull())
				cout<<"Heap is full...Cant insert exiting\n";
			else
			{
				int hole=++currentSize;
				for(;hole>1 && x<array[hole/2];hole=hole/2)
					array[hole]=array[hole/2];
				array[hole]=x;
			}
		}
		void deleteMin()
		{
			if(isEmpty())
				cout<<"Heap is empty......cant delete exiting\n";
			else
			{
				eType minTerm=array[1];
				array[1]=array[currentSize--];
				percolateDown(1);
			}
		}
		eType getMin()
		{
			if(!isEmpty())
				return array[1];
		}
		void buildHeap(eType* anArray,int n)
		{
			for(int i=1;i<=n;i++)
				array[i]=anArray[i-1];
			currentSize=n;
			for(int i=currentSize/2;i>0;i--)
				percolateDown(i);
		}
		int getSize()
		{
			return currentSize;
		}
};
			
			
