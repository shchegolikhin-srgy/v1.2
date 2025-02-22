#include <string>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;
vector <string> toBinaryNums(string s) {
	vector<string> nums;
	int pos = 0, count = 0;
	while (pos < s.size()) {
		string num;
		while (s[pos] != '1') {
			count++;
			pos++;
		}
		for (int i = 0; i <= count; ++i) {
			num.push_back(s[pos]);
			pos++;
		}
		cout << num << ' ';
		nums.push_back(num);
		count = 0;
	}
	return nums;
}
string toBinary(vector<int> nums, bool bin) {
	string binary = "";
	for (int i : nums) {
		for (int j = 0; j < i; ++j) {
			binary += to_string(int(bin));
		}
		bin = !bin;
	}
	return binary;
}
int toDecimal(const string& binary) {
	int decimal = 0;
	int length = binary.length();

	for (int i = 0; i < length; ++i) {
		if (binary[i] == '1') {
			decimal += (1 << (length - i - 1));
		}
	}
	return decimal;
}
vector<int> toLetters(string binary) {
	vector<string> binary_words;
	for (int i = 0; i < binary.size(); i += 8) {
		string s = "";
		for (int j = 0; j < 8; ++j) {
			s.push_back(binary[i + j]);
		}
		binary_words.push_back(s);
	}
	vector<int> words;
	for (string i : binary_words) {
		words.push_back(toDecimal(i));
	}
	return words;
}
void getWord(vector<int> words) {
    SetConsoleOutputCP(1251);
	for (int i : words) {
		cout << char(i);
	}
}
void deleteSpaces(string& str) {
	for (int i = 0; i < str.size(); ++i) {
		if (isspace(str[i])) {
			str.erase(i, 1);
		}
	}
}
int main() {
	string s;
	vector<string> binary_nums;
	vector<int> nums;
	bool bin = true;
	getline(cin, s);	
	if (s[0] == '0')
		bin = false;
	cout << endl<<s[0]<<':';
	s.erase(0, 1);
	deleteSpaces(s);
	binary_nums = toBinaryNums(s);
	for (string& i : binary_nums) {
		nums.push_back(toDecimal(i));
	}
	cout << endl<<endl<<int(bin)<<':';
	for (int i : nums) {
		cout << i << ' ';
	}
	cout << endl<<endl;
	vector<int> words = toLetters(toBinary(nums, bin));
	for (int i : words) {
		cout << i << ' ';
	}
	cout << endl<<endl;
	getWord(words);
	cout<<endl;
	system("pause");
}