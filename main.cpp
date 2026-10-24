#include<iostream>
#include<string>
#include<unistd.h>
#include<sys/wait.h>
#include<vector>
#include<sstream>
using namespace std ;

int main(){
	string buff ;

	cout << "$ " << flush ;	
	getline(cin , buff);

	vector<string> args;
	stringstream ss(buff);
	string arg;
	while(ss >> arg){
		args.push_back(arg);
	}

	vector<char*> args_c;
	for(int i = 0; i < args.size(); i++){
		args_c.push_back(&args[i][0]);
	}
	args_c.push_back(NULL);

	pid_t pid = fork();

	if(pid > 0){
		wait(NULL);
	}
	else{
		execvp(args_c[0] , args_c.data());
		cerr << "Couldn't exec the " << buff << endl ;
		_exit(1);
	}	
}
