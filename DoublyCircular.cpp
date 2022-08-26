#include<iostream>

using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
	struct node *prev;
	
};

template<class T>
class DoublyCLL
{
	public:
	  struct node<T> *Head;
	  struct node<T> *Tail;
	  int Count;
	  
	  DoublyCLL();
	  
	  void InsertFirst(T);
	  void InsertLast(T);
	  void InsertAtPos(T,int);
	  
	  void DeleteFirst();
	  void DeleteLast();
	  void DeleteAtPos(int);
	  
	  void Display();
	  int CountNode();
	
	
};

template<class T>
 DoublyCLL<T>::DoublyCLL()
{
	Head =NULL;
	Tail =NULL;
	Count =0;
	
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
	struct node<T> *newn = NULL;
	newn = new node<T>;
	
	newn->data = no;
	newn->next =NULL;
	newn->prev =NULL;
	
	if(Count==0)
	{
		Head =newn;
		Tail =newn;
	}
	else
	{
		newn->next =Head;
		Head->prev =newn;
		Head = newn;
	}
	Head->prev =Tail;
	Tail->next =Head;
	
	Count++;	
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
	struct node<T> *newn = NULL;
	newn = new node<T>;
	
	newn->data =no;
	newn->next =NULL;
	newn->prev =NULL;
	
	if(Count==0)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->next =newn;
		newn->prev =Tail;
		
		Tail =newn;
	}
	Head->prev =Tail;
	Tail->next =Head;
	
	Count++;
	
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T no,int pos)
{
	if((pos<1)||(pos>Count+1))
	{
		cout<<"Invalid position";
		return;
	}
	
	if(pos==1)
	{
		InsertFirst(no);
	}
	else if(pos == Count+1)
	{
		InsertLast(no);
	}
	else
	{
		struct node<T> *newn =NULL;
		newn = new node<T>;
		
		newn->data =no;
		newn->next =NULL;
		newn->prev =NULL;
		
		struct node<T> *temp =Head;
		
		
		for(int i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		 newn->next = temp->next;
         temp->next->prev = newn;
         temp->next = newn;
         newn->prev = temp;

         Count++;
	}	
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
	if(Count==0)
	{
		return;
	}
	else if(Count==1)
	{
		delete Head;
		Head =NULL;
		Tail =NULL;
		
	}
	else
	{
		Head =Head->next;
		delete Tail->next;
	}
	Tail->next =Head;
	Head->prev =Tail;
	
	Count--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
	if(Count==0)
	{
		return;
	}
	else if(Count==1)
	{
		delete Tail;
		Head =NULL;
		Tail =NULL;
		
	}
	else
	{
		Tail =Tail->prev;
		delete Tail->next;
	}
	Tail->next =Head;
	Head->prev =Tail;
	
	Count--;

	
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
	if((pos<1)||(pos>Count))
	{
		cout<<"Invalid position";
		return;
	}
	
	if(pos==1)
	{
		DeleteFirst();
	}
	else if(pos == Count)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp = Head;
		
		for(int i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		 temp->next = temp->next->next;
         delete temp->next->prev;
         temp->next->prev = temp;

         Count--;
	}
	
}

template<class T>
void DoublyCLL<T>::Display()
{
	int i=0;
	struct node<T> *temp =Head;
	
	for(i=1;i<=Count;i++)
	{
		cout<<"|"<<temp->data<<"|-> ";
		temp = temp->next;
	}
	cout<<"\n";
	
}

template<class T>
int DoublyCLL<T>::CountNode()
{
	return Count;
}





int main()
{
	 DoublyCLL<int>obj1;
	  DoublyCLL<float>obj2;
	 
	 
	 obj1.InsertFirst(51);
	 obj1.InsertFirst(21);
	 obj1.InsertFirst(11);
	 obj1.InsertLast(101);
	 obj1.InsertAtPos(151,5);
	 
	 obj1.Display();
	 cout<<"Number of nodes are"<<obj1.CountNode()<<" "<<endl;
	 
	 obj1.DeleteFirst();
     obj1.DeleteLast();
     obj1.DeleteAtPos(2);
	 
	 obj1.Display();
	 cout<<"Number of nodes are"<<obj1.CountNode()<<" "<<endl;
	 
	 obj2.InsertFirst(51);
	 obj2.InsertFirst(21);
	 obj2.InsertFirst(11);
	 obj2.InsertLast(101);
	 obj2.InsertAtPos(151,5);
	 
	 obj2.Display();
	 cout<<"Number of nodes are"<<obj2.CountNode()<<" "<<endl;
	 
	 obj2.DeleteFirst();
     obj2.DeleteLast();
     obj2.DeleteAtPos(2);
	 
	 obj2.Display();
	 cout<<"Number of nodes are"<<obj2.CountNode()<<" "<<endl;
	 
	
	return 0;
}