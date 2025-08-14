#include "utility.h"

#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace utils {
	int generate_id(int& counter) {
		return ++counter;
	}

	std::string generate_date() {
		std::time_t t = std::time({});
		std::ostringstream ss;
		ss << std::put_time(std::localtime(&t), "%m/%d/%Y %H:%M:%S");

		return ss.str();
	}

	bool file_exists(const std::string& filename) {
		std::ifstream file(filename);
		return file.good();
	}
}