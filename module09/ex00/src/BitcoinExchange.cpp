#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_data = other._data;
    }
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    std::string line, date;
    float rate;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            date = line.substr(0, commaPos);
            std::stringstream ss(line.substr(commaPos + 1));

            ss >> rate;
            _data[date] = rate;
        }
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }

    int y, m, d;
    std::stringstream ssY(date.substr(0, 4));
    std::stringstream ssM(date.substr(5, 2));
    std::stringstream ssD(date.substr(8, 2));

    if (!(ssY >> y) || !(ssM >> m) || !(ssD >> d))
        return false;

    if (y < 2008 || y > 2026) return false;
    if (m < 1 || m > 12) return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m == 2) {
        bool isLeap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        if (isLeap) daysInMonth[1] = 29;
    }

    if (d < 1 || d > daysInMonth[m - 1])
        return false;

    return true;
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, sep);
        std::string valStr = line.substr(sep + 3);
        float value;
        std::stringstream ss(valStr);
        ss >> value;

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
        } else if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
        } else if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
        } else {
            std::map<std::string, float>::iterator it = _data.upper_bound(date);
            if (it != _data.begin()) {
                --it;
                std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
            } else {
                std::cerr << "Error: no data for this date or earlier." << std::endl;
            }
        }
    }
}
