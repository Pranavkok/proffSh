#include<iostream>
#include<string>
#include<unistd.h>
#include<sys/wait.h>
using namespace std ;

int main(){
	string buff ;

	cout << "$ " << flush ;	
	getline(cin , buff);

	pid_t pid = fork();

	if(pid > 0){
		wait(NULL);
	}
	else{
		execlp(buff.c_str() , buff.c_str() , NULL );
		cerr << "Couldn't exec the " << buff << endl ;
		_exit(1);
	}	
}
