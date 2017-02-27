#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

template< typename TYPE>
class Array {
public:
  void **element;

  int Length(){ // размер масива
    return count;
  }
  //inprogress bu

  void Push(void *data){ // добавить элемент в массив
    element=(void**)realloc(element,(count+1)*sizeof(void*));
    cout << "here\n";
    element[count]=(void*)malloc(sizeof(TYPE));
    cout << "here2\n";
    memcpy(element[count],data,sizeof(TYPE));
    cout << "here3\n";
    count++;
    cout << "count -> " << count << "\n";

  }
  void Push(void *data, int position){ // добавить элемент в массив
    if (position>>count){ // остановился тут КИРИЛЛ
      element=(void**)realloc(element,(position+1)*sizeof(void*));
    }
    cout << "here\n";
    cout << "here2\n";
    memcpy(element[position],data,sizeof(TYPE));
    cout << "here3\n";
    count+=position-count+1;
    cout << "count -> " << count << "\n";
  }



  TYPE Pull(){

    return *((TYPE*)element[count-1]);

  }
  TYPE Pull(int position){

    return *((TYPE*)element[position]);

  }


  TYPE Create(){ // заполнить поля нучальными данными (по возможности исключить эту функцию)
    element=(void**)malloc(sizeof(void*));
    count=0;
    return 0;
  }


  void Get(){} // получить данные nго элемента (не вытягивая его)
  void Delete(){} // удалить массив
  void Reset(){} // очистить массив (возможно это дублирует Delete())
  void Swap(){} // Поменять местми nй и kй элемент




  private:
    int count;
    int out_size;

  };

int main()
{
        Array<int> array;
        Array<float> array2;
        Array<char> array3;

        int test=1;
        float test2 = 3.5;
        char test3 = 'h';
        array.Create();
        array2.Create();

        array3.Create();

        array.Push(&test);
        array2.Push(&test2,0);
        array3.Push(&test3);
        test=2;
        array.Push(&test,5);
        array.Push(&test,4);



        cout << "test01\n" << array.Pull()<<"\n";
        cout << "test02\n" << array2.Pull(0)<<"\n";
        cout << "test03\n" << array3.Pull()<<"\n";
        test=2;
        array.Push(&test,2);
        cout << "test04\n" << array.Pull(4)<<"\n";


        //float b=array.Pull(); // возврящает типа float
        //st c=array.Pull(); // возврящает типа st





        return 0;
}
