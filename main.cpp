using namespace std;
#include <iostream>

class DynamicIntegerArray{
 private:
     int *data;
     int size;
 public:
    DynamicIntegerArray(){
        this->size =0;
        this->data =new int[0];
    }
    DynamicIntegerArray(const int arr[], int size){
        this->size=size;
        data = new int [size];
        for(int i=0;i<size;i++)
            data[i] =arr[i];
    }
    DynamicIntegerArray(const DynamicIntegerArray &o){
    this->size =o.size;
    this->data= new int[o.size];
    for(int i=0;i<o.size;i++)
        data[i]=o.data[i];
    }
    int GetSize() const{
    return size;
    }
    ~DynamicIntegerArray(){
    delete[]data;
    }

    void print() const {
    std:: cout<<"[";
    for(int i =0;i<size;i++)
        std::cout<<data[i]<<" ";
    std::cout<<"]";
    }
    void set (int value,int pos)const {
    data[pos]=value;
    }


    void pushback(int value){
        int *aux=new int [size];


        for(int i=0;i<size;i++){
                aux[i]=data[i];
        }

        size=size+1;

        delete[] data;


        data = new int [size];


        for(int i=0;i<size-2;i++){
            data[i]=aux[i];
        }

        data[size-1]=value;



    }




    void insert(int value,int pos){

        int *aux=new int [size];


        for(int i=0;i<size;i++){
                aux[i]=data[i];
        }

        size=size+1;

        delete[] data;
        data = new int [size];

        for(int i=0;i<pos;i++){
             data[i]=aux[i];

        }



        for(int i = size-1; i >= pos; i--){
             data[i]=aux[i-1];
        }
        data[pos]=value;

    }



    void remove(int pos){

        int *aux=new int [size];


        for(int i=0;i<size;i++){
                aux[i]=data[i];
        }

        size=size-1;

        delete[] data;
        data = new int [size];

        for (int i=0;i<size+1;i++)
        {
            if(i<pos)
                data[i]=aux[i];

            else if(i>pos)
                data[i-1]=aux[i];

        }


    }

};
int main()

{
    DynamicIntegerArray da;
    DynamicIntegerArray *ptr;
    ptr=&da;
    cout<<ptr->GetSize()<<endl;
    cout<< da.GetSize()<<endl;
    int arr[]= {1,2,3,44,5,6};
    DynamicIntegerArray da2(arr,6);
    da2.set(15,0);
    da2.print();
    cout<<endl;

    da2.pushback(3);
    da2.pushback(1);
    da2.print();
    cout<<endl;


    da2.insert( 99, 4);
    da2.print();
    cout<<endl;
    da2.insert( 20, 2);
    da2.print();
    cout<<endl;

    da2.remove(5);
    da2.print();

    return 0;
}
