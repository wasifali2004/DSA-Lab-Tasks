#include<iostream>
using namespace std;

class item
{
    public:
           string data;

           item(string d)
           {
            data=d;
           }
        
};
class hashtable
{
    private:
            item* array[11];
            int size=11;
            int hsize;
   
    public:
            
            hashtable()
            {
                for (int i = 0; i < size; i++)
                {
                    array[i]= new item("-1");
                }
                hsize=0;
            }
            int hashfunction(string hashdata,int s)
            {
                int d=0;
                for (int i = 1; i <= hashdata.length();i++)
                {
                 d=d+hashdata[i]*(i+1);
                }
                return d % s;
            }
            
            void insert(string strin)
            {
                item* i=new item(strin);
                int hashvalue=hashfunction(strin,size);

                while (array[hashvalue]->data!="-1")
                {
                    hashvalue++;
                    hashvalue=hashvalue % size;
                }
                array[hashvalue]=i;
                hsize++;
                cout<<i->data<<" inserted  at Array["<<hashvalue<<"]"<<endl;
                float lf=(float)hsize/size;
                cout<<"The number of elements is "<<hsize;
                cout<<". The Load Factor is  "<<lf<<endl;
                if(lf>=0.5)
                {
                    cout<<"Reaching Load factor "<<lf<<"! Refactoring Required! "<<endl;
                    cout<<"~~~~Moving Data to Another Location~~~~~"<<endl;
                    rehash();
                }
            }
            void rehash()
            {
                int rhsize=getPrime(size);
                item* hlist[rhsize];
                int index;

                cout<<"The size of New Array is "<<rhsize<<endl;
                for (int  i = 0; i < rhsize; i++)
                {
                    hlist[i]=new item("-1");
                }
                
                for (int i = 0; i < size; i++)
                {
                    if (array[i]->data!="-1"){
                    {
                        index=hashfunction(hlist[i]->data,rhsize);
                    }
                    while (hlist[index]->data!="-1")
                    {
                      index=(index+1) % rhsize;
                    }
                    hlist[index]=new item (array[i]->data);
                }
                }
                cout<<"Data in New Array: "<<endl;
                 for (int  i = 0; i < rhsize; i++)
                 {
                   cout<<"Data at "<<i<<" is "<<hlist[i]->data<<endl;                          
                 }
            }

            int  getPrime(int gp)
            {
              for (int  i = gp+1; true ; i++)
              if(Prime(i))
              return i; 
            }

            bool Prime(int p)
            {
                for (int  i = 2; i*i <= p; i++)
                if(p%i == 0)
                {
                   return false;
                }
                else{
                return true;
                }
            }
};
int main()
{
  hashtable* hashing=new hashtable();
 
  hashing->insert("Islamabad");
  hashing->insert("Mardan");
  hashing->insert("Lahore");
  hashing->insert("Karachi");
  hashing->insert("kpk");
  hashing->insert("Swat");
  hashing->insert("katapa");  
 
}

