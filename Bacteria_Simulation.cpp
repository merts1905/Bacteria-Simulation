#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {






	ifstream in;
	in.open("data.txt");
	string read;
	vector<char> bacteria;
	vector<string> rules;
	vector<string> start;
	int row, col;



	// READING part ...................................................................................

	// reading ----> " bacteria: "
	getline(in, read, '\n');


	// reading ----> " A B C D "    
	getline(in, read, '\n');
	
	// storing the name of bacteria "A B C D"  it can be of any length you want eg. "A B C D E F G..."
	for (int i = 0; i < read.length(); i+=2)
	{
		bacteria.push_back(read[i]);
	}

	

	//reading ----> " rules: "
	getline(in, read, '\n');
	

	// reading all the rules and string them
	while (1)
	{
		getline(in, read, '\n');
		if (read == "size:")
		{
			break;
		}
		
		rules.push_back(read);
	}



	//reading the size eg." 10 * 10 "

	// reading ----> "10"
	getline(in, read, ' ');
	row = stoi(read);


	// readming ----> " * "
	getline(in, read, ' ');
	
	// reading -----> " 10 "
	getline(in, read, '\n');
	col = stoi(read);


	// the variables row and col contains the size of matrix






	//reading ---->" start: "
	getline(in, read, '\n');

	// reading start rules ----> eg. "A 0 0     A 1 2 ..."
	while (!in.eof())
	{
		getline(in, read, '\n');
		start.push_back(read);
	}


	

	// END of READNING part.......................................................................


	




	// RULES and STARTING POSITION.................................................................

	up1:
	char a;
	cout << "Enter the name of bacteria : ";
	cin >> a;
	int found = 0;

	for (int i = 0; i < bacteria.size(); i++)
	{
		if (bacteria[i] == a)
		{
			found = 1;
		}
	}

	if (found == 0)
	{
		cout << "No such bacteria found. Try Again: " << endl;
		goto up1;
	}


	system("cls");

	
	cout << "The Rules for Bacteria "<< a <<" are : " << endl;
	for (int i = 0; i < rules.size(); i++)
	{

		if (rules[i][0] == a)
		{
			cout << rules[i]<<endl;
		}
	}




	cout << "The Starting position for Bacteria " << a << " are : " << endl;
	for (int i = 0; i < start.size(); i++)
	{

		if (start[i][0] == a)
		{
			cout << start[i] << endl;
		}
	}

	// END of SHOWING RULES AND STARTING POSITION......................................................







	system("pause");
	return 0;
}
