/*
 * data_import_file.cpp
 *
 *  Created on: Apr. 10, 2020
 *      Author: devil
 *//*
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
//using namespace std;
void read_record()
{
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
			std:: cout<<data[i][j];
		}
	std:: cout<<"\n";
    }

}
*/
