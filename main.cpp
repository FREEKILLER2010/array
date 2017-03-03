#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
class Structura {
public:
int i;
int j;
};


template< typename TYPE>
class Array {
private:
int count;
int out_size;
//  int pushingposition;
//int error = -1;
int ResizeArray(int newsize){
        CatchError* temparray = new CatchError[newsize];
        int b;
        if(newsize>count) {
                b=count;
        }
        else b= newsize;
        //cout <<"Resizing array from " << count << " to " << newsize << endl;
        for(int i =0; i<=b; i++) {
                temparray[i]= element[i];
        }
        if(newsize>=count) {
                for(int i =count; i<=newsize; i++) {
                         temparray[i].info=(TYPE)0;   // set all new cells to NULL
                         temparray[i].Error = -1;
                }
        }
        delete[] element;
        //count=newsize;
        element = temparray;
        return 0;
}
struct CatchError {
        TYPE info;
        int Error;
};


public:

CatchError *element;
Array<TYPE>(int size){

        element = new CatchError  [size];
        for(int i=0; i<size; i++) {
                element[i].info=(TYPE)0;
                element[i].Error = -1;
        }
        count=size;

}
Array<TYPE>(){
        //  element= (void**)malloc(sizeof(void*));
        element = new CatchError[0];
        element[0].info=(TYPE)0;
        element[0].Error = -1;
        count=1;
}
~Array(){
  cout << "DESTRUCTED ARRAY" << endl;
  cout << "Size of elemet: "<<sizeof(element)<< endl;
  delete[] element;
}

int Length(){   // размер масива
        return count;
}

void Push(TYPE data){   // добавить элемент в конец массива
        //element=(void**)realloc(element,(count+1)*sizeof(void*));
        //element[count]=(void*)malloc(sizeof(TYPE));
        //memcpy(element[count],&data,sizeof(TYPE));
        //  cout << "Trying to push" << endl;
        //cout << "Data = "<< data << endl;

                ResizeArray(count);
                element[count-1].info= data;
                element[count-1].Error = 0;


        //  cout << "Data in element = "<< element[count] << endl;
        count++;


}
void Push(TYPE data, int position){   // добавить элемент в массив на nю позицию
        CatchError temp;
        if (position > count) {
                //element=(void**)realloc(element,(position+1)*sizeof(void*));

                ResizeArray(position);
                count = position;
        }
        temp.info = data;
        temp.Error = 0;
        element[position]=temp;
        //  memcpy(element[position],&data,sizeof(TYPE));
        count++;
}





TYPE Pull(){   // вытянуть последний элемент
        TYPE tmp;
        //if ((element[count-1]) != (TYPE)NULL){
        if(!(count-1)) {
          if(!element[count-1].Error){
                tmp = element[count-1].info;
                cout << "111"<<endl;
                //free (element[count-1]);
                CatchError* temparray = new CatchError[count-1];
                cout << "222"<<endl;
                for(int i=0; i<count-2; i++) {
                        cout << "111"<<i <<"!!!"<<endl;
                        temparray[i] = element[i];
                }
                cout << "333"<<endl;
                delete[] element;
                cout << "444"<<endl;
                count--;
                cout << "555"<<endl;
                element=temparray;
                //  cout << "temparray= "<<*temparray<<endl;
                delete[] temparray;
                cout << "777`"<<endl;
                return tmp;
              }
              else {

              }
        }
        //}
        cout << "Did not PULL" << endl;
          return 0;
}
//commits for master branch
TYPE Pull(int position){   //вытянуть nй элемент
        TYPE tmp;

        if (position <= count) {

                if (!element[position].Error) {
                        tmp = element[position].info;
                        //free (element[position]);
                        element[position].Error= -2;
                        return tmp;
                }
                else {
                        cout << "Position is NULL" << endl;

                }
        }
        cout << "Did not PULL" << endl;

        return 0;
}


TYPE Get(){   // получить данные последнего элемента (не вытягивая его)
        CatchError tempstruct;
        TYPE outp;
        if(count>=2)tempstruct = element[count-2];
        else tempstruct = element[count-1];
        if(tempstruct.Error) return tempstruct.Error;
        else {
                outp = tempstruct.info;
                return outp;
        }
        //}
        //return -2;
}


TYPE Get(int position){   // получить данные nго элемента (не вытягивая его)
        CatchError tempstruct;
        TYPE outp;
        if(position<count){
        tempstruct = element[position];
        cout << "Error code: "<<tempstruct.Error << endl;
        if (!tempstruct.Error) {
                outp = tempstruct.info;
                return outp;
        }

        cout << "No such element" << endl;
        if(tempstruct.Error) return tempstruct.Error;
}
        return 0;
}

void Delete(){
        // удалить массив
        //  for (int i=0;i<count;i++){
        //  delete element[i];
        //}
        delete[] element;

}


TYPE Reset(){   // очистить массив (возможно это дублирует Delete())

        cout << "Count before deletting = " << count << "\n";
        /*for (int i=0; i<count; i++) {
                cout << "Deleting " << i+1 <<"-i element \n";
                try {
                        cout <<element[i].info<< endl;
                        //delete &element[i].Error;
                      //  delete &element[i].info;
                        delete[] element;
                }
                catch(int a) {
                        cout <<"Error number: "<< a<< endl;

                }
        }*/
        cout << "Done deleting array's cells\n";
        delete[] element;

        // Delete не стоит использовать вместе с malloc
        // Либо malloc/free
        // Либо New/Delete
        cout << "Done deleting array\n";
        element=new CatchError[0];
        element[0].info = (TYPE)0;
        element[0].Error = -1;
        count=0;
        return 0;
}

void Swap(int i, int j){
        if ((!element[i].Error) && (!element[j].Error)) {
                CatchError* tmp=new CatchError;
                tmp[1]= element[j];
                element[j]=element[i];
                element[i]=tmp[1];
                delete tmp;
        }
}


TYPE &operator[](int subscript){
        if(subscript>(count-1)) {
                cout <<"Resizing throwed from overloaded" << endl;
                ResizeArray(subscript);
                count = subscript+1;
                element[subscript].Error=0;
                //cout<< "Count after resizing from overloaded = " << count << endl;
        }
        return element[subscript].info;

}


};



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


        int test;
        test=11;

//array.Create();
//cout << "Count after initialization array2 = " << array2.Length() << "\n";
cout << "Size of elemet: "<<sizeof(array)<< endl;
        cout << "Count before pushing = " << array.Length() << "\n";
        array.Push(test);
        cout <<"Done pushing 1 element\n";
        cout << "Count after pushing = " << array.Length() << "\n";
        cout << "Array[0] GET last= "<<array.Get() << endl;
        cout << "Array[0]GET = "<<array.Get(0) << endl;
        test =10;
        array.Push(test);
        cout << "Array[0] GET= "<<array.Get(0) << endl;
        cout << "Array[1] GET= "<<array.Get(1) << endl;
        cout << "Array[1]GET last= "<<array.Get() << endl;
        cout <<"Done pushing 2 element\n";
        cout << "Count before pushing = " << array.Length() << "\n";
        array.Push(110,2);
        cout <<"Done pushing 3 element\n";
        cout << "Count before pushing = " << array.Length() << "\n";
array[4] = 90;
cout<< "Array[2] by get last = "<< array.Get() << endl;
cout<< "Array[4] by get 4 = "<< array.Get(4) << endl;
        cout <<"Done pushing 4 element\n";
        cout << "Count before pushing = " << array.Length() << "\n";
array[3]= array[4];
cout << "Trying to get array[0] :   " << array[0] <<endl;
cout << "Trying to get array[1] :   " << array[1] <<endl;
cout << "Trying to get array[3] :   " << array[3] <<endl;
cout << "Trying to get array[4] :   " << array[4] <<endl;
cout << "Trying to get array[2] :   " << array[2] <<endl;
        cout << "Count before operations = " << array.Length() << "\n";
//cout << "Count array2 before operations = " << array2.Length() << "\n";
//cout << "Array2[3] = " << array2[3] <<endl;
cout << "test01\n" << array.Pull(0)<<"\n";
cout << "test02\n" << array.Pull(1)<<"\n";
array.Swap(0,1);
//cout << "test03 = " << array.Get(0)<<"\n";
        cout << "Count after pull 1 = " << array.Length() << "\n";
//cout << "test04 = " << array.Pull(1)<<"\n";
        cout << "Count after pull 2 = " << array.Length() << "\n";
cout << "test04 pull last= " << array.Pull()<<"\n";
        cout << "Count after pull 1 = " << array.Length() << "\n";
        cout << "Before Resetting \n";
        cout << "Size of elemet: "<<sizeof(array)<< endl;
        array.Reset();
        return 0;
}
