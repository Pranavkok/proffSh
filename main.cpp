#include<iostream>
#include<string>
#include<unistd.h>
#include<sys/wait.h>
#include<vector>
#include<sstream>
using namespace std ;

int main(){

	while(true){
		string buff ;

		cout << "$ " << flush ;	
		if(!getline(cin , buff)) break;

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

		if(args.size() == 0 || args_c[0] == NULL){
			continue;
		}

		if(args[0] == "exit"){
			_exit(0);
		}

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
	return 0;
}
