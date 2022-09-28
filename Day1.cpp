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
		while (getline(input_file, line))
		{
			lines.push_back(std::stoi(line));
			current_lines_size = lines.size();
			if (current_lines_size > 1 && lines[current_lines_size-2] < lines[current_lines_size-1]) {
				increased++;
			}
		};
	}
	std::cout << "Answer: " << increased << "\n";
	return increased;
}