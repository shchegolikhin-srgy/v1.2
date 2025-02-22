#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

int toDecimal(string binary) {
	int decimal = 0;
	int length = binary.length();

	for (int i = 0; i < length; ++i) {
		if (binary[i] == '1') {
			decimal += (1 << (length - i - 1));
		}
	}
	return decimal;
}
int toDecimal(vector<bool> vec) {
	int decimal = 0;
	int length = vec.size();

	for (int i = 0; i < length; ++i) {
		if (vec[i]) {
			decimal += (1 << (length - i - 1));
		}
	}
	return decimal;
}
void getWord(vector<int> words) {
    SetConsoleOutputCP(1251);
	for (int i : words) {
		cout << char(i);
	}
}
void hammingAlgorithm(vector<bool>& codes) {
	string index_fall = "";
	int sum_1 = 0, sum_2 = 0, sum_4 = 0, sum_8 = 0;
	for (int i = 0; i < 15; ++i) {
		if ((i + 1) % 2 == 1)
			sum_1 += int(codes[i]);
		if ((i + 1) % 4 > 1)
			sum_2 += int(codes[i]);
		if ((i + 1) % 8 > 3)
			sum_4 += int(codes[i]);
		if ((i + 1) % 16 > 7)
			sum_8 += int(codes[i]);
	}
	cout << sum_1 << ' ' << sum_2 << ' ' << sum_4 << ' ' << sum_8 << ' ' << endl;
	index_fall += to_string(sum_1 % 2) + to_string(sum_2 % 2) + to_string(sum_4 % 2) + to_string(sum_8 % 2);
	cout << index_fall << ' ' << toDecimal(index_fall) << endl;
	if (toDecimal(index_fall) != 0) {
		codes[toDecimal(index_fall) - 1] = 1 ^ codes[toDecimal(index_fall) - 1];
	}
	for (int i = 0; i < codes.size(); ++i) {
		cout << codes[i];
	}
	cout << endl;
}
void binarytoASCII(vector<vector<bool>>& codes_binary) {
	const int index_data[11] = {3, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15};
	vector<int> codes_decimal;
	string code = "";
	for (int i = 0; i < codes_binary.size(); ++i){
		vector<bool> tmp;
		for (int j = 0; j < 11; ++j) {
		 	code.push_back(codes_binary[i][index_data[j]-1]);
		}
	}
	code.erase(code.size()-(code.size()%8));
	
	for(long long i=0; i<code.size(); i+=8){
		string tmp = "";
		for(int j =0; j<8; ++j){
			tmp+=to_string(code[i+j]);
		}
		cout<<tmp<<endl;
		codes_decimal.push_back(toDecimal(tmp));
	}
	cout << endl;
	for (int i : codes_decimal) {
		cout << i << ' ';
	}
	cout << endl;
	getWord(codes_decimal);
}
vector <bool> stringToBool(string code) {
	vector<bool> result;
	for (char i : code) {
		if (i == '0')
			result.push_back(0);
		else
			result.push_back(1);
	}
	for (bool i : result) {
		cout << i << ' ';
	}
	cout << endl;
	return result;
}
void readCodes(vector<string>& vec) {
	string code;
	while (code != "start")
	{
		vec.push_back(code);
		cin >> code;
	}
}

int main() {
    SetConsoleOutputCP(1251);
    cout<<"������� ����� ����� ������, ��� ������� ��������: 'start'"<<endl;
	vector <string> codes_string;
	readCodes(codes_string);
	vector<vector<bool>> codes_binary;
	for (int i = 1; i < codes_string.size(); ++i) {
		codes_binary.push_back(stringToBool(codes_string[i]));
		hammingAlgorithm(codes_binary.back());
	}
	binarytoASCII(codes_binary);
	cout<<endl;
	system("pause");
}
