#include<iostream>

using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
	
};


template<class T>
class SinglyCLL
{
	public:

	   struct node<T> *Head;
	   struct node<T> *Tail;
	   int Count;
	   
	   SinglyCLL();
	   
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
SinglyCLL<T>::SinglyCLL()
{
	Head =NULL;
	Tail =NULL;
	Count=0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
   struct node<T> *newn =NULL;
   newn = new node<T>;

   newn ->data = no;
   newn ->next =NULL;

   if((Head ==NULL)&&(Tail ==NULL))
   {
	Head =newn;
	Tail =newn;
   }
   else
   {
     newn -> next = Head;
	 Head = newn;
   }
   Tail ->next = Head;
   Count++;
}



template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
	struct node<T> *newn = NULL;
    newn = new node<T>;

	newn -> data = no;
	newn ->next =NULL;

	if((Head == NULL)&&(Tail == NULL))
	{
		Head = newn;
		Tail = newn;

	}
	else
	{
      Tail ->next = newn;
	  Tail = newn;
	}
	Tail -> next = Head;
    Count++;
}

template<class T>
void SinglyCLL<T>::InsertAtPos(T no,int iPos)
{
	int iSize = CountNode();
	if((iPos<1)||(iPos>iSize+1))
	{
		cout<<"Invalid position\n";
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == iSize+1)
	{
		InsertLast(no);
	}
	else
	{
		struct node<T> *newn =NULL;
		
		newn = new  node<T>;
		
		newn ->data = no;
		newn ->next = NULL;
		
		struct node<T> *temp = Head;
		int iCnt =0;
		
		for(iCnt=1;iCnt<iPos-1;iCnt++)
		{
			temp = temp ->next;
		}
		newn->next = temp->next;
		temp->next = newn;
	}
	Count++;
}

template<class T>
 void SinglyCLL<T>::DeleteFirst()
 {
   if((Head == NULL)&&(Tail == NULL))
   {
	return;
   }
   else if(Head ==Tail)
   {
     delete Head;
	 Head = NULL;
	 Tail = NULL;
   }
   else
   {
	Head = Head -> next;
	delete Tail ->next;

	Tail ->next = Head;
   }
   Count--;
 }

 template<class T>
 void SinglyCLL<T>::DeleteLast()
 {
	if((Head == NULL)&&(Tail == NULL))
   {
	return;
   }
   else if(Head ==Tail)
   {
     delete Tail;
	 Head = NULL;
	 Tail = NULL;
   }
   else
   {
	struct node<T> *temp = Head;

	while(temp->next !=Tail)
	{
		temp = temp ->next;
	}
	delete Tail;
	Tail = temp;

	Tail ->next = Head;
   }
   Count--;
 }
 
 template<class T>
 void SinglyCLL<T>::DeleteAtPos(int iPos)
 {
	int iSize = CountNode();
    
    if((iPos<1)||(iPos>iSize))
	{
		cout<<"Invalid position\n";
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp1 = Head;
        int iCnt=0;
        
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
			temp1 = temp1->next;
		}
		
        struct node<T> *temp2 = temp1->next;
       
        temp1->next = temp2->next;
        delete temp2;		
	}
	Count--;
 }

template<class T>
void SinglyCLL<T>::Display()
{
    struct node<T> *temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }

    do
    {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }while(temp != Head);

    cout<<endl;
}

 template<class T>
int SinglyCLL<T>::CountNode()
{
	return Count;
}






int main()
{
	SinglyCLL<int>obj1;

	SinglyCLL<float>obj2;

	obj1.InsertFirst(101);
	obj1.InsertFirst(51);
	obj1.InsertFirst(21);
	obj1.InsertFirst(11);
	obj1.InsertLast(151);

	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
    obj1.InsertAtPos(81,4);
	
	
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj1.DeleteFirst();
	obj1.DeleteLast();
	
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	obj1.DeleteAtPos(2);
	obj1.Display();
	cout<<"number of nodes are:"<<obj1.CountNode()<<endl;
	
	

	obj2.InsertFirst(101.15);
	obj2.InsertFirst(51.14);
	obj2.InsertFirst(21.13);
	obj2.InsertFirst(11.12);
	obj2.InsertLast(151.11);

	obj2.Display();
	cout<<"number of nodes are:"<<obj2.CountNode()<<endl;
	
    obj2.InsertAtPos(81.21,4);
	
	
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