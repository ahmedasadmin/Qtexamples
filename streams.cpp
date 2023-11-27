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
    strbuf << "luckynumber: " << lucky << endl
            << "PI: " << pi << endl 
             << "e: " << e << endl;

    string strval = strbuf.str();
    cout << strval;

    ofstream outf;
    outf.open("outdata");
    if (outf.is_open()){
        cout << "done\n";
    }
    outf << strval;

    outf.close();

    cout << "Read data from file - watch for errors." << endl;
    string newstr;
    ifstream inf;
    inf.open("outdata");


    if(inf){
        int lucky2;
        inf >> newstr >> lucky2;

        if(lucky != lucky2){

            cerr << "ERROR! wrong " << newstr << lucky2 << endl; 
        }else{

            cout << newstr << " OK" << endl;
        }

        float pi2;
        inf >>newstr >> pi2;

        if(pi != pi2)
            cerr << "ERROR! wrong "<< newstr << pi2 << endl;
        else
            cout << newstr << " OK" << endl;
   
        double e2;

        inf >> newstr >> e2;

        if(e2 != e)
            cerr << "ERROR! wrong " << newstr << e << endl;
        else
            cout << newstr << " OK" << endl;
    }// end of IF 



}