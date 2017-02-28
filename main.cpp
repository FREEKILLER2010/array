#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

//FIXME: free не правильно работате

template< typename TYPE>
class Array {
public:
  void **element;

  Array(){
   element=(void**)malloc(sizeof(void*));
   count=0;

 }

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

  TYPE Pull(){ // вытянуть последний элемент
    TYPE tmp;
    if ((element[count-1]) != 0){
      tmp = *((TYPE*)element[count-1]);
      free (element[count-1]);
      return tmp;
    }
    return 0;
  }

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

/*
  TYPE Create(){ // заполнить поля начльными данными (по возможности исключить эту функцию)
    element=(void**)malloc(sizeof(void*));
    count=0;
    return 0;
  }
  */

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
      if (element[i]){
        free(element[i]);
      }
    }
    free(element);
    element=(void**)malloc(sizeof(void*));
    count=0;
    return 0;
  }
  TYPE Swap(int i, int j){ // Поменять местми nй и kй элемент
    if ((element[i]) && (element[j])){
      void *tmp=malloc(sizeof(TYPE));
      memcpy(tmp,element[j],sizeof(TYPE));
      memcpy(element[j],element[i],sizeof(TYPE));
      memcpy(element[i],tmp,sizeof(TYPE));
    }
    return 0;
  }




  private:
    int count;
    int out_size;

  };

int main()
{
        Array<int> array;
        int test=1;

        //array.Create();

        array.Push(&test);
        test =2;
        array.Push(&test);


        cout << "test01\n" << array.Pull(0)<<"\n";
        cout << "test02\n" << array.Pull(1)<<"\n";
        array.Swap(0,1);
        cout << "test03\n" << array.Pull(0)<<"\n";
        cout << "test04\n" << array.Pull(1)<<"\n";
        array.Reset();

        return 0;
}
