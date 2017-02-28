#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

//FIXME: free не правильно работате
//FIXME: разобраться с удаление элементов
//TODO: надо уходить от void** иначе некоторые данные могут не влезть...

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

  void Push(TYPE data){ // добавить элемент в конец массива
    element=(void**)realloc(element,(count+1)*sizeof(void*));
    element[count]= new TYPE;
    memcpy(element[count],&data,sizeof(TYPE));
    count++;

  }
  void Push(TYPE data, int position){ // добавить элемент в массив на nю позицию
    if (position > count){
      element=(void**)realloc(element,(position+1)*sizeof(void*));
      count+=position-count+1;
    }
    element[position]=malloc(sizeof(TYPE));
    cout << "mem bef->" << element[position] << "\n";
    memcpy(element[position],&data,sizeof(TYPE));
  }

  TYPE Pull(){ // вытянуть последний элемент
    TYPE tmp;
    if ((element[count-1]) != 0){
      tmp = *((TYPE*)element[count-1]);
      element[count-1] = new(void*);
      return tmp;
    }
    return 0;
  }

  TYPE Pull(int position){ //вытянуть nй элемент
      TYPE tmp;
      if (position < count){
        if ((element[position]) != 0){
          tmp = *((TYPE*)element[position]);
          delete[] (element[position]);
          cout << "mem aft->" << element[position] << "\n";
          return tmp;
        }
      }
      throw string("No Data");
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

  TYPE Reset(){ // очистить массив
    for (int i=0;i<count;i++){
      if (element[i]){
        cout << "bef " << element[i] << " ! " << *((TYPE*)element[i]) << "\n";
        free(element[i]);
        cout << "aft " << element[i] << " ! " << *((TYPE*)element[i]) << "\n";
      }
    }
    free(element);
    element=(void**)malloc(sizeof(void*));
    count=0;
    return 0;
  }
  TYPE Swap(int i, int j){ // Поменять местми iй и jй элемент
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

  struct test{
    int i;
    int j;
  };

typedef struct test test;

int main()
{
        Array<int> array;
        Array<test> array2;
        test to_push;
        array2.Push(to_push);
        int test=1;

        //array.Create();

        array.Push(test,0);
        test=2;
        array.Push(test,1);


      //  cout << "test01\n" << array.Pull(0)<<"\n";
        //cout << "test02\n" << array.Pull(0)<<"\n";
        //array.Swap(0,1);
        //cout << "test04\n" << array.Pull(4)<<"\n";
        array.Reset();
        try
     {
       cout << "test03\n" << array.Pull(5)<<"\n";
     }
     catch(string std)
     {
          cout << std << "\n";
     }

        return 0;
}
