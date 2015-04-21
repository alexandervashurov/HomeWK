#include "interfaces.h"
#include <stddef.h>
template <class T> struct SetElement{
    T data;
    SetElement<T>* next;
};


template <class T> class MySet: public ISet<T>{
public:
    MySet(){
        set_size=0;
        head=NULL;
    }

    ~MySet(){
        SetElement<T>* simba=head;
        while(head!=NULL)
        {
            head=simba->next;
            delete simba;
            simba=head;
        }
        delete head;
        delete simba;
    }

    void add(const T &elem){
        SetElement<T>* simba;
        unsigned int res=findplace(simba,elem);
        if(!res){
            return;
        }
        SetElement<T>* new_element=new SetElement<T>;
        new_element->data=elem;
        new_element->next=NULL;
        if(res==1)
        {
            new_element->next=simba->next;
            simba->next=new_element;

            set_size+=1;
            return;
        }
        new_element->next=head;
        head=new_element;
        set_size+=1;
    }

    void remove(const T &elem){
        SetElement<T>* simba;
        SetElement<T>* previous;
        if(findplace(simba,elem))
            return;
		if (simba == head)
		{
			head = simba->next;
		}
		else{
			previous = findprevious(simba);
			if (previous == head)
			{
				head->next = simba->next;
			}
			else{
				previous->next = simba->next;
			}
		}
        set_size-=1;
        delete simba;
    }

    bool contains(const T &elem) {
        SetElement<T>* transit;
         if(findplace(transit,elem))
             return false;
         return true;
    }

    int size() const{
        return set_size;
    }

  private:

    SetElement<T>* findprevious(SetElement<T> *place){
        SetElement<T>* transit=head;
        while(transit->next!=place)
            transit=transit->next;
        return transit;
    }

   unsigned int findplace(SetElement<T>* &place,const T& elem ){
   place=head;
   if(head==NULL)
       return 2;
  if(place->data==elem)
      return 0;
  if(place->data>elem)
      return 2;
  while((place->next!=NULL)&&(place->next->data<=elem))
    place=place->next;
  if(place->data==elem)
      return 0;
  return 1;
   }
    SetElement<T>* head;
    unsigned int set_size;
};
