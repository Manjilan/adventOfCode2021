#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
int main() {
	fstream input;
	input.open("Day1Part1Input.txt");
	std::vector<int> lines;
	string line;
	ifstream input_file("Day1Part1Input.txt");
	int increased = 0;
	int current_lines_size;
	if (input.is_open()) {
		int sum1 = 0;
		int sum2 = 0;
		while (getline(input_file, line))
		{
			lines.push_back(std::stoi(line));
			current_lines_size = lines.size();
			if (lines.size() >= 1) {
				sum2 += lines[current_lines_size - 1];
				if (lines.size() > 3) {
					sum1 = sum2 - lines[current_lines_size - 1];
					sum2 -= lines[current_lines_size - 4];
				}
			}
			if (sum1 != 0 && sum2 != 0) {
				if (sum2 > sum1) {
					increased++;
				}
			}
		};
	}
	std::cout << "Answer: " << increased << "\n";
	return increased;
}
