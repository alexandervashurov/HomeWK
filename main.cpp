#include <iostream>
#include"myset.h"
using namespace std;
int main (void){

MySet<int> dog;
for(int i=0;i<100;i++)
dog.add(i);
cout<<dog.size()<<endl;
for (int i = 0; i < 100; i++)
{
	if (i % 2 == 0){
		dog.remove(i);
	}
}
cout<<dog.size()<<endl;
dog.add(4);
cout << dog.size() << endl;
for(int i=0;i<100;i++)
    cout<<dog.contains(i);
cout << endl;
    return 0;
}
