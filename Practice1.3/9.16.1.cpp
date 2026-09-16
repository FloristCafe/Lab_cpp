#include <iostream>
using namespace std;
template <class T>
class Sort {
private:
    T* data;   //
    int n;

public:
    Sort(int a):n(a){
        data=new T[n];
    }
    ~Sort(){
        delete[] data;
    }

    void input() {
        for (int i=0; i<n; i++) {
            cin >> data[i];
        }
    }
    void sel() {
        for (int i=0; i<n-1; i++) {
            int min1=i;
            bool ordered=true;
            for (int j=i+1; j<n; j++) {
                if (data[j] < data[min1]) {
                    min1=j;
                }
                if (data[j] < data[j-1]) {
                    ordered=false;
                }
            }
            if (ordered && i>0) break; 
            if (min1!=i) {
                T tem=data[i];
                data[i]=data[min1];
                data[min1]=tem;
            }
        }
    }
    void bub() {
        for (int i=0; i<n-1; i++) {
            bool swapped=false;
            for (int j=0; j<n-1-i; j++) {
                if (data[j] > data[j+1]) {
                    T tmp=data[j];
                    data[j]=data[j+1];
                    data[j+1]=tmp;
                    swapped=true;
                }
            }
            if (!swapped) break; 
        }
    }

    void insert() {
        for (int i=1; i<n; i++) {
            T ch=data[i];
            int j=i-1;
            while (j>=0 &&data[j] > ch) {
                data[j+1]=data[j];
                j--;
            }
            data[j+1]=ch;
        }
    }

    void rank(int* rank1) {
        for (int i=0; i<n; i++) {
            int r=1;
            for (int j=0; j<n; j++) {
                if (j!=i && data[j] < data[i]) r++;
            }
            rank1[i]=r;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (data[i]==data[j] && rank1[i] > rank1[j]) {
                    rank1[i]=rank1[j];
                }
            }
        }
    }
    void output() {
        for (int i=0; i<n; i++) {
            if (i > 0) cout<<" ";
            cout<<data[i];
        }
        cout<<endl;
    }
    void typerank(int* rank) {
        for (int i=0; i<n; i++) {
            if (i > 0) cout<<" ";
            cout<<rank[i];
        }
        cout<<endl;
    }

    void copy1(Sort<T>& other) {
        for (int i=0; i<n; i++) {
            other.data[i]=data[i];
        }
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Sort<int> a(n);
    a.input();

    //选择排序
    Sort<int> s1(n);
    a.copy1(s1);
    s1.sel();
    s1.output();

    //冒泡排序
    Sort<int> s2(n);
    a.copy1(s2);
    s2.bub();
    s2.output();

    //插入排序
    Sort<int> s3(n);
    a.copy1(s3);
    s3.insert();
    s3.output();

    //名次排序
    int* rank=new int[n];
    a.rank(rank);
    a.typerank(rank);

    return 0;
}