#include <iostream>
#include <sstream>
#include <fstream>


int main(){

    using namespace std;


    ostringstream strbuf;

    int lucky = 7;
    float pi = 3.14;
    double e = 2.71;


    cout << "An in memory stream " << endl;
    strbuf << "luckynumber: " << lucky << endl;
    string strval = strbuf.str();
    cout << strval;

    ofstream outf;
    outf.open("outdata");
    if (outf.is_open()){
        cout << "done\n";
    }
    outf << strval;

    outf.close();

}