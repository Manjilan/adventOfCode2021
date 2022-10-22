#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int day2Part1(ifstream& input) {
	int horizontal = 0;
	int depth = 0;
	std::string direction;
	int steps;
	while (!input.eof()) {
		input >> direction >> steps;
		if (direction == "forward") {
			horizontal += steps;
		}
		else if (direction == "down") {
			depth += steps;
		}
		else {
			depth -= steps;
		}
	}
	return horizontal * depth;
}


int day2Part2(ifstream& input) {
	int horizontal = 0;
	int depth = 0;
	int aim = 0;
	std::string direction;
	int steps;
	while (!input.eof()) {
		input >> direction >> steps;
		if (direction == "down") {
			aim += steps;
		}
		else if (direction == "up") {
			aim -= steps;
		}
		else {
			horizontal += steps;
			depth += aim * steps;
		}
	}
	return horizontal * depth;
}

int main2() {
	fstream input;
	input.open("Day2.txt");
	ifstream input_file("Day2.txt");
	int answer = 0;
	if (input_file.is_open()) {
		answer = day2Part2(input_file);
	}
	std::cout << "Answer: " << answer <<  "\n";
	return 0;
}
