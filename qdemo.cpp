#include <QTextStream>
#include <QString>
#include <QFile>

QTextStream cout (stdout);
QTextStream cin (stdin);
QTextStream cerr (stderr);


int main(){
    QString str, newstr;
    QTextStream strbuf(&str);

    int lucky = 7;
    float pi = 3.14;
    double e = 2.71;


    cout << "An in-memory stream" << endl;
    strbuf << "lukynumber: " << lucky << endl
            << "pi: " << pi << endl
            << "e: " << e << endl;

    cout << str;

    QFile data("outdata");
    data.open(QIODevice::WriteOnly);
    QTextStream out(&data);

    out << str;
    data.close();

    // end of part one ...

    cout << "Read data from the file - watch for errors. " << endl;
    if (data.open(QIODevice::ReadOnly)){
        QTextStream in(&data);
        int lucky2;
        in >> newstr >> lucky2;
        if(lucky != lucky2)
            cerr << "ERROR! wrong " << newstr << lucky2 << endl;
        else
            cout << newstr << " OK" << endl;
        
        float pi2;

        in >> newstr >> pi2;
        if(pi2 != pi)
            cerr << "ERROR! wrong " << newstr << pi2 << endl;
        else
            cout << newstr << " OK" << endl;
        data.close();
    }
    
    // Second Method 

    cout << "Read from file line-by-line" << endl;

    if(data.open(QIODevice::ReadOnly)){

        QTextStream in(&data);
        while(not in.atEnd()){
            newstr = in.readLine();
            cout << newstr << endl;
        }

        data.close();
    }

    return 0;

}