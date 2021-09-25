#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> word = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	int index;
	string input;
	cin >> input;
	for (int i = 0; i < word.size(); i++) {
		while (1) {
			index = input.find(word[i]);
			if (index == string::npos)
				break;
			input.replace(index,word[i].length(), "#");
		}
	}
	cout << input.length();
}