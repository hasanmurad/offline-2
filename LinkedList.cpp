#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Element {
private:
    Element * next;
	Element * prev;
	int value;
public:
	void setNext(Element *n) {
		next = n;
	}
	Element * getNext() {
		return next;
	}
	void setPrev(Element *p) {
		prev  = p;
	}
	Element * getPrev() {
		return prev;
	}
	void setValue(int v) {
		value = v;
	}
	int getValue() {
		return value;
	}
};

class LinkedListBase {
protected:
	Element * head;
	Element * tail;
	int size;
public:
	LinkedListBase() {
        head=new Element;
        tail=new Element;
		head->setNext(tail);
		tail->setPrev(head);
		size = 0;
    }
	int getSize() {
		return size;
	}
	~LinkedListBase() {
		delete head;
		delete tail;
	}
};

class LinkedList: public LinkedListBase {

public:

    void add(Element *e)
    {
        if(size==0)
        {
            e->setNext(0);
            e->setPrev(0);
            head->setNext(e);
            tail->setPrev(e);
        }
        else{
            e->setNext(head->getNext());
            (head->getNext())->setPrev(e);
            e->setPrev(0);
            head->setNext(e);
        }
        size++;
    }


    void addFirst(Element *e)
    {
        if(size==0)
        {
            e->setNext(0);
            e->setPrev(0);
            head->setNext(e);
            tail->setPrev(e);
        }
        else{
            e->setNext(head->getNext());
            (head->getNext())->setPrev(e);
            e->setPrev(0);
            head->setNext(e);
        }
        size++;
    }


    void addLast(Element *e)
    {
        if(size==0)
        {
            e->setNext(0);
            e->setPrev(0);
            head->setNext(e);
            tail->setPrev(e);
        }
        else{
            e->setNext(0);
            (tail->getPrev())->setNext(e);
            e->setPrev(tail->getPrev());
            tail->setPrev(e);
        }
        size++;
    }


    void add(int index,Element *element)
    {
        if(index>size){cout<<"out of present range"<<endl;return;}
        if(index==0)addFirst(element);
        else if(index==size)addLast(element);
        else{
            int i=0;
            Element *e=head->getNext();
            while(e!=0)
            {
                if(i==index-1)break;
                e=e->getNext();
                i++;
            }
            element->setPrev(e);
            element->setNext(e->getNext());
            e->setNext(element);
            (element->getNext())->setPrev(element);
            size++;
        }
    }


    bool contains(Element e)
    {
        Element *e1=head->getNext();
        while(e1!=0)
        {
            if(e1->getValue()==e.getValue())return true;
            e1=e1->getNext();
        }
        return false;
    }


    Element	get(int	index){
        int i=0;
        Element *e=head->getNext();
        while(e!=0)
        {
            if(i==index)return *e;
            e=e->getNext();
            i++;
        }
    }


    Element getFirst()
    {
        return *(head->getNext());
    }


    Element	getLast()
    {
        return *(tail->getPrev());
    }


    int	indexOf(Element	e)
    {
        Element *e1=head->getNext();
        int i=0;
        while(e1!=0)
        {
            if(e1->getValue()==e.getValue())return i;
            e1=e1->getNext();
            i++;
        }
        return -1;
    }


    int	 lastIndexOf(Element e)
    {
        Element *e1=head->getNext();
        int i=0,index=-1;
        while(e1!=0)
        {
            if(e1->getValue()==e.getValue()){index=i;}
            e1=e1->getNext();
            i++;
        }
        if(index!=-1)return index;
        return -1;
    }


    Element removeLast()
    {
        if(size==1){
            Element *e=tail->getPrev();
            head->setNext(0);
            tail->setPrev(0);
            size--;
            return *e;
        }
        Element *e=tail->getPrev();
        (e->getPrev())->setNext(0);
        tail->setPrev(e->getPrev());
        size--;
        return *e;
    }


    Element	removeFirst()
    {
        if(size==1){
            Element *e=head->getNext();
            head->setNext(0);
            tail->setPrev(0);
            size--;
            return *e;
        }
        Element *e=head->getNext();
        (e->getNext())->setPrev(0);
        head->setNext(e->getNext());
        size--;
        return *e;
    }


    Element remove(int index)
    {
        if(index==0)return removeFirst();
        if(index==size-1)return removeLast();
        else{
            int i=0;
            Element *e=head->getNext();
            while(e!=0)
            {
                if(i==index)break;
                e=e->getNext();
                i++;
            }
            (e->getPrev())->setNext(e->getNext());
            (e->getNext())->setPrev(e->getPrev());
            size--;
            return *e;
        }
    }


    void clear()
    {
        int len=size;
        for(int i=1;i<=len;i++)removeLast();
    }


    bool remove(Element e)
    {
        int index=indexOf(e);
        if(index==-1)return false;
        else{
            remove(index);
            return true;
        }
    }


    bool removeFirstOccurrence(Element e)
    {
        int index=indexOf(e);
        if(index==-1)return false;
        else{
            remove(index);
            return true;
        }
    }


    bool removeLastOccurrence(Element e)
    {
        int index=lastIndexOf(e);
        if(index==-1)return false;
        else{
            remove(index);
            return true;
        }
    }


    string	toString()
    {
        string str("");
        Element *e=head->getNext();
        while(e!=0)
        {
            int n=e->getValue();
            string a;
            ostringstream b;
            b<<n;
            a=b.str();
            str=str+a;
            if(e->getNext()!=0)str=str+",";
            e=e->getNext();
        }
        return str;
    }


    bool isEmpty()
    {
        if(size==0)return true;
        return false;
    }


    int	sizeoflist()
    {
        return size;
    }


    void print()
    {
        Element *e=head->getNext();
        while(e!=0)
        {
            cout<<e->getValue()<<endl;
            e=e->getNext();
        }
    }
};

// a very simple main
int main() {

	LinkedList ll;

	while(1){

    cout<<" 1. void add(Element e).\n";
    cout<<" 2. void add(int index,Element element).\n";
    cout<<" 3. void addFirst(Element e).\n";
    cout<<" 4. void addLast(Element e).\n";
    cout<<" 5. void clear().\n";
    cout<<" 6. boolean contains(Element e).\n";
    cout<<" 7. Element get(int index).\n";
    cout<<" 8. Element getFirst().\n";
    cout<<" 9. Element getLast().\n";
    cout<<"10. int indexOf(Element e).\n";
    cout<<"11. int lastIndexOf(Element e).\n";
    cout<<"12. Element remove(int index).\n";
    cout<<"13. boolean remove(Element e).\n";
    cout<<"14. Element removeFirst().\n";
    cout<<"15. boolean removeFirstOccurrence(Element e).\n";
    cout<<"16. Element removeLast().\n";
    cout<<"17. boolean removeLastOccurrence(Element e).\n";
    cout<<"18. int size().\n";
    cout<<"19. boolean isEmpty().\n";
    cout<<"20. String toString().\n";
    cout<<"21. print().\n";
    cout<<"22. exit.\n";
	int ch;

	cin>>ch;


	if(ch==1)
    {
        Element *e;
        e=new Element;
        int value;
        cin>>value;
        e->setValue(value);
        ll.add(e);
    }


    else if(ch==2)
    {
        int index;
        cin>>index;
        Element *e;
        e=new Element;
        int value;
        cin>>value;
        e->setValue(value);
        ll.add(index,e);
    }


    else if(ch==3)
    {
        Element *e;
        e=new Element;
        int value;
        cin>>value;
        e->setValue(value);
        ll.addFirst(e);
    }


    else if(ch==4)
    {
        Element *e;
        e=new Element;
        int value;
        cin>>value;
        e->setValue(value);
        ll.addLast(e);
    }


    else if(ch==5)ll.clear();


    else if(ch==6)
    {
        Element e;
        int value;
        cin>>value;
        e.setValue(value);
        if(ll.contains(e))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }


    else if(ch==7)
    {
        int index;
        cin>>index;
        if(index>=ll.sizeoflist()||index<0)cout<<"out of range.\n";
        else{
        Element e=ll.get(index);
        cout<<e.getValue()<<endl;
        }
    }


    else if(ch==8)
    {
        Element e=ll.getFirst();
        cout<<e.getValue()<<endl;
    }


    else if(ch==9)
    {
        Element e=ll.getLast();
        cout<<e.getValue()<<endl;
    }


    else if(ch==10)
    {
        Element e;
        int value;
        cin>>value;
        e.setValue(value);
        cout<<ll.indexOf(e)<<endl;
    }


    else if(ch==11)
    {
        Element e;
        int value;
        cin>>value;
        e.setValue(value);
        cout<<ll.lastIndexOf(e)<<endl;
    }


    else if(ch==12)
    {
        int index;
        cin>>index;
        if(index<0||index>=ll.sizeoflist())cout<<"out of range\n";
        else{
            Element e=ll.remove(index);
            cout<<e.getValue()<<endl;
        }
    }


    else if(ch==13)
    {
        Element e;
        int value;
        cin>>value;
        e.setValue(value);
        ll.remove(e);
    }


    else if(ch==14)
    {
        if(ll.sizeoflist()==0)cout<<"No element to delete.\n";
        else{
            Element e=ll.removeFirst();
            cout<<e.getValue()<<endl;
        }
    }


    else if(ch==15)
    {
        Element e;
        int value;
        cin>>value;
        e.setValue(value);
        ll.removeFirstOccurrence(e);
    }


    else if(ch==16){
        if(ll.sizeoflist()==0)cout<<"No element to delete.\n";
        else{
            Element e=ll.removeLast();
            cout<<e.getValue()<<endl;
        }
    }


    else if(ch==17)
    {
        Element e;
        int value;
        cin>>value;
        e.setValue(value);
        ll.removeLastOccurrence(e);
    }


    else if(ch==18)
    {
        cout<<"size: "<<ll.sizeoflist()<<endl;
    }


    else if(ch==19)
    {
        if(ll.isEmpty())cout<<"Empty\n";
        else cout<<"Not Empty\n";
    }


    else if(ch==20)
    {
        cout<<ll.toString()<<endl;;
    }


    else if(ch==21)
    {
        cout<<endl;
        if(ll.sizeoflist()!=0)ll.print();
        cout<<endl;
    }
    else if(ch==22)break;

    else
    {
        cout<<"Enter a valid number.\n";
    }


	}
	return 0;
}
