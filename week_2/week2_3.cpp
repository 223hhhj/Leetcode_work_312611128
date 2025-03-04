#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Record {
    std::string name;
    int english;
    int math;
    int science;
};

void writeToCSV(const std::string& filename, const std::vector<Record>& records) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    file << "Name,English,Math,Science\n";

    for (const auto& record : records) {
        file << record.name << "," << record.english << "," << record.math << "," << record.science << "\n";
    }

    file.close();
    std::cout << "Data written to " << filename << " successfully!" << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of records: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Invalid number of records!" << std::endl;
        return 1;
    }

    std::vector<Record> records;

    for (int i = 0; i < n; ++i) {
        Record record;
        std::cout << "Enter details for record " << i + 1 << " (name english math science): ";
        std::cin >> record.name >> record.english >> record.math >> record.science;
        records.push_back(record);
    }

    std::string filename = "output.csv";

    writeToCSV(filename, records);

    return 0;
}
