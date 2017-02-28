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

  void Push(void *data){ // добавить элемент в конец массива
    element=(void**)realloc(element,(count+1)*sizeof(void*));
    element[count]=(void*)malloc(sizeof(TYPE));
    memcpy(element[count],data,sizeof(TYPE));
    count++;

  }
  void Push(void *data, int position){ // добавить элемент в массив на nю позицию
    if (position > count){
      element=(void**)realloc(element,(position+1)*sizeof(void*));
      count+=position-count+1;
    }
    element[position]=(void*)malloc(sizeof(TYPE));
    memcpy(element[position],data,sizeof(TYPE));
  }

//sfsffdsgfdgdfsd
//reee

  TYPE Pull(){ // вытянуть последний элемент
    TYPE tmp;
    if ((element[count-1]) != 0){
      tmp = *((TYPE*)element[count-1]);
      free (element[count-1]);
      return tmp;
    }
    return 0;
  }
//commits for master branch
  TYPE Pull(int position){ //вытянуть nй элемент
    TYPE tmp;
    if (position < count){
      if ((element[position]) != 0){
        tmp = *((TYPE*)element[position]);
        free (element[position]);
        return tmp;
      }
    }
    return 0;
  }


  TYPE Create(){ // заполнить поля нучальными данными (по возможности исключить эту функцию)
    element=(void**)malloc(sizeof(void*));
    count=0;
    return 0;
  }


  TYPE Get(){ // получить данные последнего элемента (не вытягивая его)
    if ((element[count-1]) != 0){
      return *((TYPE*)element[count-1]);
    }
    return 0;
  }

  TYPE Get(int position){ // получить данные nго элемента (не вытягивая его)
    TYPE tmp;
    if (position < count){
      if ((element[position]) != 0){
        return *((TYPE*)element[position]);
      }
    }
    return 0;
  }

  void Delete(){ // удалить массив
    for (int i=0;i<count;i++){
      free(element[i]);
    }
    free(element);
  }

  TYPE Reset(){ // очистить массив (возможно это дублирует Delete())
    for (int i=0;i<count;i++){
      free(element[i]);
    }
    free(element);
    element=(void**)malloc(sizeof(void*));
    count=0;
    return 0;
  }
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
        Array<char> len;


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
        cout << "test04\n" << array3.Pull(3)<<"\n";

        len.Create();
        char a='a';
        len.Push(&a);
        len.Push(&a);
        cout << "test05\n" << len.Length()<<"\n";
        len.Delete();



        //float b=array.Pull(); // возврящает типа float
        //st c=array.Pull(); // возврящает типа st





        return 0;
}
