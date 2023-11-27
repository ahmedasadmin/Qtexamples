#include <QTextStream>
#include <QString>
using namespace std;

QTextStream cout (stdout);
QTextStream cin (stdin);

// Let's do real code HERE...
int main(){


	QString s1("This "), s2("is a "), s3("string.");


	s1 += s2;
	QString s4 = s1 + s3;
	cout << s4 << endl;

	cout <<"The length of that string is " << s4.length() << endl;
	cout << "Enter a sentence with whitespaces: "<< endl;
	s2 = cin.readLine();

	cout << "Here is your sentence is: " << s2.length() << endl;
	
	

	return 0;
}