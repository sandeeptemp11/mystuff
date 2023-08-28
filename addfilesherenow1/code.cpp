#include <bits/stdc++.h>
using namespace std;

class parent{
    public:
    int data1 = 2;

    protected:
    int data2 = 7;

    private:
    int data3 = 10;
// here data1, data2, data3 are accesible
};

class child: protected parent{
    public:
    int data4 = 20;

    protected:
    int data5 = 20;

    private:
    int data6 = 20;


    void modify(){
        data1 = 30;
    }
// accesiible:
// here data1, data2, data5 are protected
// here data4 is public
// data6 is private

// data 3 is not accesiible here
};

int main(){
    child obj;
    // here only data4 is accessible.
}
