#include <iostream>
#include "SocketServer.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include <sstream>
#include<fstream>
#include<sstream>
//#include"data_import_file.cpp"
//using namespace std;
using namespace exploringRPi;

int main(int argc, char *argv[]){

/*
SocketServer server(54321);
server.listen();
string msg = server.receive(1024);


int rec_msg_size = msg.size();
char msg_char_array[rec_msg_size + 1];

strcpy(msg_char_array, msg.c_str());


string msg_to_str[20];
string temp_str="";
int msg_str_counter = 0;

for(int i=0;i<rec_msg_size;i++)
{
	if(msg_char_array[i]=='#')
	{
		msg_to_str[msg_str_counter]=temp_str;
		msg_str_counter++;
		temp_str="";
	}
	else
		temp_str += msg_char_array[i];
}


string  user_input_code[20];
string user_input_weight[20];

int code_counter=0,weight_counter=0;

   for (int i = 0; i < msg_str_counter; i++)
     {
    	if(i%2 == 0)
    	{
    		user_input_code[code_counter] = msg_to_str[i];
    		code_counter++;
    	}
    	else
    	{
    		user_input_weight[weight_counter] = msg_to_str[i];
    		weight_counter++;
    	}
     }

cout<<"Input Code:"<<endl;
for(int i=0;i<code_counter;i++)
{
cout<<user_input_code[i];
cout<<endl;
}
cout<<"Input Weight:"<<endl;
for(int i=0;i<weight_counter;i++)
{
cout<<user_input_weight[i];
cout<<endl;
}
*/

std:: string data[306][6];
    std:: ifstream file("data.csv");

    for (int row = 0; row < 306; ++row)
    {
    	std:: string line;
    	std:: getline(file,line);
    	if(!file.good())
    	break;

    	std::stringstream iss(line);

		for (int col = 0; col < 6; ++col)
		{
			std:: string val;
			std:: getline(iss,val,',');
			if(!iss.good())
			break;

		std:: stringstream convertor(val);
		convertor >> data[row][col];
		}
	}

    for (int i = 0; i < 306; ++i)
    {
		for (int j = 0; j < 6; ++j)
		{
			std:: cout<<data[i][j]<<" ";
		}
	std:: cout<<"\n";
    }


   return 0;
}
