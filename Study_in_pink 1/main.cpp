/*
* Author: Võ Tiến
* Date: 20.02.2023
* FB: https://www.facebook.com/profile.php?id=100056605580171
* FB nhóm: https://www.facebook.com/groups/211867931379013
* khóa học KTLT1: https://www.facebook.com/photo/?fbid=845258184037693&set=gm.404500422115762&idorvanity=211867931379013
*/
/*
* cách dùng hàm main.cpp
* b1: mở folder BTL1 lên vscode
* b2: mở Terminal trên thanh công cụ mở new Terminal
* b3: chạy lệnh g++ -o main main.cpp study_in_pink1.cpp nếu không gì hiện ra thì không bị lỗi code
* b4: chạy ./main KEYWORDS (./main task1, ./main task2)
* b5: nếu hiện Success: test 1 to 200 thì đã đúng hết

! KEYWORDS có thể là
* ./main task1 này chạy phần task1
* ./main 2 này chạy phần input2
* ./main 1 5 này sẽ chạy phần input1 -> input5
* ./main hiện tại cũng chạy hết task 1 
*/


#include "study_in_pink1.h"
void copyFile(const std::string& sourcePath, const std::string& destinationPath);
void printTestFail(int i);
void comparefile(int start, int end);
bool isNumber(string str);
ofstream OUTPUT;
void run(string input_file)
{
    


    int test = stoi(input_file);
    if(test <= 200)
    {
        int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
        if (!readFile(folder_input + input_file + ".txt", HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
            return;
        }
        OUTPUT << "BEFORE firstMeet EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
        int result = firstMeet(EXP1, EXP2, E1);
        OUTPUT << "AFTER firstMeet  EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result << endl;
    }
    else if(test <= 400)
    {
        int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
        if (!readFile(folder_input + input_file + ".txt", HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
            return;
        }
        OUTPUT << "BEFORE traceLuggage HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1  << ", E2: " << E2 << endl;
        int result = traceLuggage(HP1, EXP1, M1, E2);
        OUTPUT << "AFTER traceLuggage  HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1  << ", result: " << result << endl;
    }
    else if (test <= 600)
    {
        string s1, s2, s3, s4, s5, s6;
        ifstream ifs(folder_input + input_file + ".txt");
        ifs.is_open();
        for(int i = 0; i < 100 && !ifs.eof(); i++) {
            ifs >> s1 >> s2
                >> s3 >> s4 
                >> s5 >> s6;
            OUTPUT << s1 << s2 << s3 << ", " << s4 << s5 << s6 << endl;
            const char *email =  s3.c_str();
            const char *se = s6.data();
            OUTPUT << "result : " <<  checkPassword(se, email) << endl;
        }      

    }
    else if(test <= 800)
    {
        ifstream ifs(folder_input + input_file + ".txt");
        ifs.is_open();   
        int number;
        string s1, s2;
        for(int i = 0; i < 100 && !ifs.eof(); i++) {
            ifs >> s1 >> s2 >> number;
            string s[200];
            for (int j = 0; j < number; j++) ifs >> s[j];
            const char * arr_pwds[200];

            for (int i = 0; i < number; ++i) {
                arr_pwds[i] = s[i].c_str(); // Get a const char* pointer to the string
            }


            OUTPUT << "result line " << i * 2 + 1 <<" : " <<  findCorrectPassword(arr_pwds, number) << endl;
        }          
    }
    else if(test <= 910)
    {
        int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
        if (!readFile(folder_input + input_file + ".txt", HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
            return;
        }
        OUTPUT << "BEFORE chaseTaxi HP1: " << HP1 << ", EXP1: " << EXP1 
                              << ", HP2: " << HP2 << ", EXP2: " << EXP2  << ", E3: "  << E3 << endl;
        int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
        OUTPUT << "AFTER chaseTaxi  HP1: " << HP1 << ", EXP1: " << EXP1 
                              << ", HP2: " << HP2 << ", EXP2: " << EXP2  << ", result: " << result << endl;
    }
    else
    {
        int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
        if (!readFile(folder_input + input_file + ".txt", HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
            return;
        }
        OUTPUT << "BEFORE firstMeet EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
        int result = firstMeet(EXP1, EXP2, E1);
        OUTPUT << "AFTER firstMeet  EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result << endl;

        OUTPUT << "BEFORE traceLuggage HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1  << ", E2: " << E2 << endl;
        result = traceLuggage(HP1, EXP1, M1, E2);
        OUTPUT << "AFTER traceLuggage  HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1  << ", result: " << result << endl;

        OUTPUT << "BEFORE chaseTaxi HP1: " << HP1 << ", EXP1: " << EXP1 
                              << ", HP2: " << HP2 << ", EXP2: " << EXP2  << ", E3: "  << E3 << endl;
        result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
        OUTPUT << "AFTER chaseTaxi  HP1: " << HP1 << ", EXP1: " << EXP1 
                              << ", HP2: " << HP2 << ", EXP2: " << EXP2  << ", result: " << result << endl;
    }
}


//* ./main task1; ./main task2; ./main task3; ./main task4; ./main task5
int main(int argc, char *argv[])
{
	cout << "Start program assignments 1" << endl;


    int START = 0, END = 0;
    int fullTask = 200;
    //* check all test cases

    if (argc == 1)
    {
        cout << "checking test : ";
        START = 1;
        END = 1000;
        for (int i = START; i <= END; i++)
        {
            cout << i << " ";
            OUTPUT.open(folder_output + to_string(i) + ".txt");
            run(to_string(i));
            OUTPUT.close();
        }
    }

    else if(argc == 2)
    {
        string stringTask = argv[1];
        if (isNumber(stringTask))
        {
            cout << "checking test : " << argv[1];
            START = stoi(stringTask);
            END = stoi(stringTask);
            OUTPUT.open(folder_output + stringTask + ".txt");
            run(stringTask);
            OUTPUT.close();            
        }
        else if(stringTask == "me")
        {
            cout << "checking test : ";
            for (int i = 1; i <= 1000; i++)
            {
                cout << i << " ";
                OUTPUT.open(folder_expect + to_string(i) + ".txt");
                run(to_string(i));
                OUTPUT.close();
            }            
        }
        else if(stringTask.substr(0,4) != "task" || stringTask[4] <= '0' || stringTask[4] > '5')
        {
            cout << "Please re-enter the correct command" << endl;
            cout << "./main task1\n./main task2\n./main task3\n./main task4\n./main task5\n./main number" << endl;
            return 0;
        }
        else
        {
            cout << "checking test : ";

            START = fullTask * (stringTask[4] - '0' - 1) + 1;
            END = fullTask * (stringTask[4] - '0');
            if(stringTask[4] - '0' == 4){
                START = 401;
                END = 600;
            }
            else if (stringTask[4] - '0' == 3){
                START = 801;
                END = 1000;
            }
            else if(stringTask[4] - '0' == 5){
                START = 601;
                END = 800;
            }
            for (int i = START; i <= END; i++)
            {
                cout << i << " ";
                OUTPUT.open(folder_output + to_string(i) + ".txt");
                run(to_string(i));
                OUTPUT.close();
            }     
        }
    }
    else if (argc == 3 && isNumber(argv[1]) && isNumber(argv[2]))
    {
        cout << "checking test : ";
        START = stoi(argv[1]);
        END = stoi(argv[2]);
        for (int i = stoi(argv[1]); i <= stoi(argv[2]); i++)
        {
            cout << i << " ";
            OUTPUT.open(folder_output + to_string(i) + ".txt");
            run(to_string(i));
            OUTPUT.close();
        }           
    }
    else 
    {
        cout << "Please re-enter the correct command" << endl;
        cout << "./main task1\n./main task2\n./main task3\n./main task4\n./main task5\n./main number" << endl;
        return 0;
    }

	cout << "\nOK: runs without errors\n" << endl;
    comparefile(START, END);
    return 1;
}




bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (!isdigit(c)) return false;
    }
    return true;
}

void comparefile(int start, int end)
{
	vector<int> result;
	for (int i = start; i <= end; i++)
	{
		ifstream read_output(folder_output + to_string(i) + ".txt");
		ifstream read_expect(folder_expect + to_string(i) + ".txt");
		if (read_output.fail() || read_expect.fail())
		{
			cout << "Error reading file"<< end;
			return;
		}
		string s1, s2;
		while (read_output >> s1 && read_expect >> s2)
		{
			if (s1 != s2)
			{
				result.push_back(i);
				break;
			}
		}
		if (read_output >> s1 || read_expect >> s2)
		{
			if (result.size() == 0 || result.size() > 0 && result[result.size() - 1] != i)
				result.push_back(i);
		}
	}

	if (result.size() == 0)
	{
		cout << "Success: test " << start << " to " << end << endl;
	}
	else
	{
		cout << "percent success : " << (1 - result.size() * 1.0 / (end - start + 1)) * 100 << "%" << endl;
		cout << "Fail : test [";
		for (int i = 0; i < result.size() - 1; i++)
		{
			cout << result[i] << ", ";
		}
		cout << result[result.size() - 1] << "]\n";
        cout << "link check comparefile: https://www.diffchecker.com/text-compare/" << endl;
		printTestFail(result[0]);
	}
}

void printTestFail(int i)
{
    //copy
    // copyFile(folder_input + to_string(i) + ".txt",  "test_fail/input.txt");
    // copyFile(folder_output + to_string(i) + ".txt", "test_fail/output.txt");
    // copyFile(folder_expect + to_string(i) + ".txt", "test_fail/expect.txt");

	// string file_output = "testCase/output/output" + to_string(i) + ".txt";
	// string file_expect = "testCase/expect/output" + to_string(i) + ".txt";
	// ifstream read_output(file_output);
	// ifstream read_expect(file_expect);
	// string s1, s2;
	// int k = 1;
	// while (read_output >> s1 && read_expect >> s2)
	// {
	// 	if (s1 != s2)
	// 	{
	// 		cout << "fail test " << i << " line " << k << endl;
	// 		return;
	// 	}
	// 	k++;
	// }
	// if (read_output >> s1 || read_expect >> s2)
	// {
	// 	cout << "fail test " << i << " line " << k << endl;
	// }
}

void copyFile(const std::string& sourcePath, const std::string& destinationPath) {
    std::ifstream sourceFile(sourcePath, std::ios::binary);
    std::ofstream destinationFile(destinationPath, std::ios::binary);

    if (!sourceFile) {
        std::cerr << "Error opening source file: " << sourcePath << std::endl;
        return;
    }


    if (!destinationFile) {
        std::cerr << "Error opening destination file: " << destinationPath << std::endl;
        return;
    }

    destinationFile << sourceFile.rdbuf();

    if (!destinationFile) {
        std::cerr << "Error copying data from " << sourcePath << " to " << destinationPath << std::endl;
    }
}