#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int day3Part1(vector<string> list) {
	string gamma_rate;
	string epsilon_rate;
	int ones;
	int zeros;
	for (int i = 0; i < list[0].size(); i++) {
		ones = 0;
		zeros = 0;
		for (int j = 0; j < list.size(); j++) {
			list[j][i] == '0' ? zeros++ : ones++;
		}
		if (ones > zeros) {
			gamma_rate += "1";
			epsilon_rate += "0";
		}
		else {
			gamma_rate += "0";
			epsilon_rate += "1";
		}
	}
	int gamma_rate_int = stoi(gamma_rate, 0, 2);
	int epsilon_rate_int = stoi(epsilon_rate, 0, 2);
	return gamma_rate_int * epsilon_rate_int;
}

char getMostCommonAtIndex(vector<string> list, int index) {
	// Get occurences of 1s and 0s
		int ones = 0;
		int zeros = 0;
		for (int j = 0; j < list.size(); j++) {
			list[j].at(index) == '0' ? zeros++ : ones++;
		}
		/*cout << ones << " " << zeros << "\n";*/
	return ones >= zeros ? '1' : '0';
}

vector<string> Filter(vector<string> list, char bit, int index) {
	vector<string> new_list;
	for (string it : list)
	{
		if (!it.empty()) {
			if (it.at(index) == bit) {
				new_list.push_back(it);
			}
		}
	}
	return new_list;
}

int day3Part2(vector<string> list) {
	vector<string> oxygen_generator_rating(list);
	vector<string> co2_scrubber_rating(list);
	char most_common;
	char least_common;
	string oxygen_rating;
	string co2_rating;
	for (int i = 0; i < oxygen_generator_rating[0].size(); i++) { 
		if (oxygen_generator_rating.size() > 1) {
			most_common = getMostCommonAtIndex(oxygen_generator_rating, i);
			oxygen_rating += most_common;
			cout << "most common: " << most_common << '\n';
			oxygen_generator_rating = Filter(oxygen_generator_rating, most_common, i);
		}
		if (co2_scrubber_rating.size() > 1) {
			least_common = getMostCommonAtIndex(co2_scrubber_rating, i) == '1' ? '0' : '1';
			co2_rating += least_common;
			cout << "least common: " << least_common << '\n';
			co2_scrubber_rating = Filter(co2_scrubber_rating, least_common, i);
		}
		else {
			co2_rating = co2_scrubber_rating[0];
		}
	}
	int oxygen_rating_int = stoi(oxygen_rating, 0, 2);
	int co2_rating_int = stoi(co2_rating, 0, 2);
	return oxygen_rating_int * co2_rating_int;
}


std::vector<std::string> GetListOfBits(ifstream& input) {
	std::string line;
	std::vector<std::string> numbers;
	if (input.is_open()) {
		while (!input.eof()) {
			input >> line;
			numbers.push_back(line);
		}
	}
	return numbers;
}

int main() {
	fstream input;
	input.open("Day3.txt");
	ifstream input_file("Day3.txt");
	int answer1 = 0;
	int answer2;
	vector<string> list = GetListOfBits(input_file);
	answer1 = day3Part1(list);
	answer2 = day3Part2(list);
	std::cout << "\n Answer1: " << answer1 ;
	std::cout << "\n Answer2: " << answer2 ;
	return 0;
}

