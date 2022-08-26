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
class DoublyLL
{
	public:
	   struct node<T> *Head;
	   struct node<T> *Tail;
	   
	   
	   DoublyLL();
	   
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
DoublyLL<T>::DoublyLL()
{
	Head = NULL;
	Tail = NULL;
	
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
	struct node<T> *newn = NULL;
	newn = new node<T>;
	
	newn->data = no;
	newn->next =NULL;
	newn->next =NULL;
	
	if(Head==NULL)
	{
		Head =newn;
		
	}
	else
	{
		newn->next =Head;
		Head->prev =newn;
		Head = newn;
	}
	
		
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
	int Size=0;
	Size = CountNode();
	
	struct node<T> *newn = NULL;
	
	newn = new node<T>;
	
	newn->data = no;
	newn->next =NULL;
	newn->prev =NULL;
	
	if(Size==0)
	{
		Head =newn;
		Tail =newn;
	}
	else
	{ 
        struct node<T> *temp = Head;
		
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next =newn;
		newn->prev =temp;
	}		
		

}

template<class T>
void DoublyLL<T>::InsertAtPos(T no,int pos)
{
	
	
	if((Head ==NULL)||(pos>CountNode()+1)||(pos<=0))
	{
		cout<<"position is Invalid"<<endl;
		return;
	}
	
	if(pos ==1)
	{
		InsertFirst(no);
	}
	else if(pos ==(CountNode())+1)
	{
		InsertLast(no);
	}
	else
	{
		struct node<T> *newn =NULL;
		struct node<T> *temp =NULL;
		
		newn = new node<T>;
		
		if(newn == NULL)
		{
			return;
		}
		newn->next =NULL;
		newn->prev =NULL;
		newn->data =no;
		
		temp =Head;
		for(int iCnt=1;iCnt<= (pos-1);iCnt++)
		{
			temp =temp->next;
		}
		newn->next =temp->next;
		temp->next->prev =newn;
		newn->prev =temp;
		temp->next =newn;
		}	
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
	struct node<T> *temp = NULL;
	
	if(Head ==NULL)
	{
		return;
	}
	else
	{
		temp =Head;
		Head =Head->next;
		Head->prev=NULL;
		
		delete temp;
	}
	
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
	struct node<T> *temp =NULL;
	
	if(Head == NULL)
	{
		return;
	}
	else if(Head->next ==NULL)
	{
		delete Head;
		Head =NULL;
	}
	else
	{
		temp = Head;
		
		while((temp->next)!=NULL)
		{
			temp = temp->next;
		}
		temp->prev->next =NULL;
		delete temp;
	}
	
	
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
	int Size=0;
	Size = CountNode();
	
	if((Head ==NULL)||(pos>Size)||(pos<=0))
	{
		cout<<"position is Invalid"<<endl;
		return;
	}
	
	if(pos ==1)
	{
		DeleteFirst();
	}
	else if(pos ==Size)
	{
		DeleteLast();
	}
	else
	{
		
		struct node<T> *temp =NULL;		
		
		temp =Head;
		
		for(int iCnt=1;iCnt<= pos-2;iCnt++)
		{
			temp =temp->next;
		}
		temp->next =temp->next->next;
		delete temp->next->prev;
		temp->next->prev =temp;
		}
	
}

template<class T>
void DoublyLL<T>::Display()
{
      cout<<"Elements from linked list are :"<<endl;
	  
	  struct node<T>*temp =Head;
	  
	  while(temp!=NULL)
	   {
		cout<<temp->data<<" ";
		temp = temp ->next;
	   }
	cout<<endl;
		
}

template<class T>
int DoublyLL<T>::CountNode()
{
	struct node<T> *temp =Head;
	int iCnt=0;
	
	while(temp!=NULL)
	{
		iCnt++;
		temp = temp->next;
	}
	return iCnt;
}


int main()
{
	DoublyLL<int> obj1;
	DoublyLL<float>obj2;
	
	obj1.InsertFirst(51);
	obj1.InsertFirst(21);
	obj1.InsertFirst(11);
	obj1.InsertLast(101);
	obj1.InsertAtPos(151,1);
	
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj1.DeleteFirst();
	obj1.DeleteLast();
	
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj1.DeleteAtPos(2);
	
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj2.InsertFirst(51.11);
	obj2.InsertFirst(21.12);
	obj2.InsertFirst(11.13);
	obj2.InsertLast(101.14);
	obj2.InsertAtPos(151.15,1);
	
	obj2.Display();
	cout<<"number of nodes are:"<<obj2.CountNode()<<endl;
	
	obj2.DeleteFirst();
	obj2.DeleteLast();
	
	obj2.Display();
	cout<<"number of nodes are:"<<obj2.CountNode()<<endl;
	
	obj2.DeleteAtPos(2);
	
	obj2.Display();
	cout<<"number of nodes are:"<<obj2.CountNode()<<endl;
	
	
	return 0;
}