

#include <iostream>

long factorial(long n){
	
	long ans = 1;
	for (long i = 2; i <=n; i++){
		ans = ans * i;
		if (ans < 0){
			return -1;
		}
	}

	return ans;
}


int main(){
	
	using namespace std;

	cout << "Please enter n: " << flush;
	long n;
	cout << endl;
	cin >>n;
	long nfact; 
	if(n >= 0){ // check if n is negative...
		
		nfact = factorial(n);

		if(nfact < 0){
			cerr << "overflow error: "
			     << n << " is too long " << endl;
		}else{	
		cout << " factorial (" << n << ") = " << nfact << endl;
	}
	}else{
		cerr << "undefined: " << " factorial of negative number: "	<< nfact << endl;
	} // end of else ...


	
	

	return 0;

}
