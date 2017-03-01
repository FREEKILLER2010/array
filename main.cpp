#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

template< typename TYPE>
class Array {

public:
  TYPE *element;
  Array<TYPE>(int size){
    //element= (void**)malloc(size*sizeof(void*));
    element = new TYPE[size];
    for(int i=0;i<size;i++){

    //  element[i]=(void*)malloc(sizeof(TYPE));
    element[i]=(TYPE)0;
  //    memcpy(element[i],&tmp,sizeof(TYPE));
    }
    count=size;

  }
  Array(){
  //  element= (void**)malloc(sizeof(void*));
  element = new TYPE[0];
    count=0;
  }

  void Swap(int i,int j);
  int Length(){ // размер масива
    return count;
  }

  void Push(TYPE data){ // добавить элемент в конец массива
    //element=(void**)realloc(element,(count+1)*sizeof(void*));
    //element[count]=(void*)malloc(sizeof(TYPE));
    //memcpy(element[count],&data,sizeof(TYPE));
    count++;
    ResizeArray(count);
    element[count]= data;


  }
  void Push(TYPE data, int position){ // добавить элемент в массив на nю позицию
    if (position >= count){
      //element=(void**)realloc(element,(position+1)*sizeof(void*));
      count+=position-count+1;
      ResizeArray(count);
    }
    element[position]=data;
  //  memcpy(element[position],&data,sizeof(TYPE));
    //count++;
  }





  TYPE Pull(){ // вытянуть последний элемент
    TYPE tmp;
    if ((element[count-1]) != 0){
      tmp = *((TYPE*)element[count-1]);
      //free (element[count-1]);
      delete[] (TYPE*)element[count-1];
      count--;
      return tmp;
    }
    return 0;
  }
//commits for master branch
  TYPE Pull(int position){ //вытянуть nй элемент
    TYPE tmp;
    if (position <= count){
      if ((element[position]) != (TYPE)NULL){
        tmp = element[position];
        //free (element[position]);
        element[position]= (TYPE)NULL;
        return tmp;
      }
      else {
        cout << "Position is NULL" << endl;

      }
    }
    return 0;
  }


  TYPE Get(){ // получить данные последнего элемента (не вытягивая его)
    if ((element[count]) != (TYPE)0){
      return element[count];
    }
    return 0;
  }

  TYPE Get(int position){ // получить данные nго элемента (не вытягивая его)
    //TYPE tmp;
    if (position < count){
      if ((element[position]) != 0){
        return element[position];
      }
    }
    return 0;
  }

  void Delete();

  TYPE Reset(){ // очистить массив (возможно это дублирует Delete())

        cout << "Count before deletting = " << count << "\n";
    for (int i=0;i<count;i++){
      cout << "Deleting " << i+1 <<"-i element \n";
      delete &element[i];
    }
    cout << "Done deleting array's cells\n";
    delete[] element;

    // Delete не стоит использовать вместе с malloc
    // Либо malloc/free
    // Либо New/Delete
    cout << "Done deleting array\n";
    element=new TYPE[1];
    count=0;
    return 0;
  }

  /*TYPE void Swap(int i, int j){ // Поменять местми nй и kй элемент
   if ((element[i]) && (element[j])){
      void *tmp=malloc(sizeof(TYPE));
      memcpy(tmp,element[j],sizeof(TYPE));
      memcpy(element[j],element[i],sizeof(TYPE));
      memcpy(element[i],tmp,sizeof(TYPE));
    }
    //return 0;
  } */


 TYPE &operator[](int subscript){
  cout << "[] overloaded func" << endl;
  //pushingposition = subscript;
  if(subscript>count){
    ResizeArray(subscript);
  }
  return element[subscript];

}

  private:
    int count;
    int out_size;
  //  int pushingposition;
    //int error = -1;
    int ResizeArray(int newsize){
      TYPE* temparray = new TYPE[newsize];
      int b;
      if(newsize>count){
        b=count;
      }
      else b= newsize;
      for(int i =0;i<b;i++){
        temparray[i]= element[i];
      }
      delete[] element;
      element = temparray;
      return 0;
    }

  };
template <typename TYPE>
 void Array<TYPE>::Swap(int i, int j){
    if ((element[i]) && (element[j])){
      TYPE* tmp=new TYPE[1];
      tmp[1]= element[j];
      element[j]=element[i];
      element[i]=tmp[1];
      delete[] tmp;
    }
  }
template <typename TYPE>
void Array<TYPE>::Delete(){
  // удалить массив
    for (int i=0;i<count;i++){
      free(element[i]);
    }
    free(element);

}
int main()
{
  /*      Array<int> array;
        Array<int> array2;
        Array<char> array3;
        Array<char> len;


        int test=1;
        int test2 = 3;
        char test3 = 'h';


        array.Push(test);
        cout << "array2.Count before push " << array2.Length() << "\n";
        array2.Push(test2,0);
        array3.Push(test3);
        test=2;
        array.Push(test,5);
        array.Push(test,4);



        cout << "test01\n" << array.Pull()<<"\n";
        cout << "array2.Count before pull " << array2.Length() << "\n";
        cout << "test02\n" << array2.Pull()<<"\n";
        cout << "test03\n" << array3.Pull()<<"\n";
        test=2;
        array.Push(test,2);
        cout << "test04\n" << array2.Pull(3)<<"\n";
        cout << "test08\n" << array2.Pull(3)<<"\n";

        char a='a';
        len.Push(a);
        len.Push(a);
        cout << "test05\n" << len.Length()<<"\n";
        len.Delete();



        //float b=array.Pull(); // возврящает типа float
        //st c=array.Pull(); // возврящает типа st


*/

Array<int> array;
Array<float> array2(10);

int test=0;
//array.Create();
cout << "Count after initialization array2 = " << array2.Length() << "\n";
cout << "Count before pushing = " << array.Length() << "\n";
array.Push(test);
test =10;
array.Push(test);
array.Push(110);
array[4] = 90;
//array[3]= array[4];
cout << "Trying to get array[0] :   " << array[0] <<endl;
cout << "Trying to get array[1] :   " << array[1] <<endl;
cout << "Trying to get array[4] :   " << array[4] <<endl;
cout << "Trying to get array[2] :   " << array[2] <<endl;
cout << "Count before operations = " << array.Length() << "\n";
cout << "Count array2 before operations = " << array2.Length() << "\n";
cout << "Array2[3] = " << array2[3] <<endl;
//cout << "test01\n" << array.Pull(0)<<"\n";
//cout << "test02\n" << array.Pull(1)<<"\n";
array.Swap(0,1);
cout << "test03 = " << array.Get(0)<<"\n";
cout << "Count after pull 1 = " << array.Length() << "\n";
cout << "test04 = " << array.Pull(1)<<"\n";
cout << "Count after pull 2 = " << array.Length() << "\n";
cout << "test04 = " << array.Pull(1)<<"\n";
cout << "Before Resetting \n";
array.Reset();
        return 0;
}
