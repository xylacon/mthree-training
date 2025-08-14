#pragma once

#include <string>

namespace utils {
	int generate_id(int&);
	std::string generate_date();
	bool file_exists(const std::string&);
}