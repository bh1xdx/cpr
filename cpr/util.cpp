#include "cpr/util.h"

#include <cctype>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

CPR_NS_BEGIN

namespace util {

Header parseHeader(const std::string& headers) {
    Header header;
    std::vector<std::string> lines;
    std::istringstream stream(headers);
    {
        std::string line;
        while (std::getline(stream, line, '\n')) {
            lines.push_back(line);
        }
    }

    for (auto& line : lines) {
        if (line.substr(0, 5) == "HTTP/") {
            header.clear();
        }

        if (line.length() > 0) {
            auto found = line.find(":");
            if (found != std::string::npos) {
                auto value = line.substr(found + 2, line.length() - 1);
                if (value.back() == '\r') {
                    value = value.substr(0, value.length() - 1);
                }
                header[line.substr(0, found)] = value;
            }
        }
    }

    return header;
}

std::vector<std::string> split(const std::string& to_split, char delimiter) {
    std::vector<std::string> tokens;

    std::stringstream stream(to_split);
    std::string item;
    while (std::getline(stream, item, delimiter)) {
        tokens.push_back(item);
    }

    return tokens;
}

size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

std::string urlEncode(const std::string& value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (auto i = value.cbegin(), n = value.cend(); i != n; ++i) {
        std::string::value_type c = (*i);
        // Keep alphanumeric and other accepted characters intact
        if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }
        // Any other characters are percent-encoded
        escaped << '%' << std::setw(2) << std::int32_t((unsigned char) c);
    }

    return escaped.str();
}

} // namespace util

CPR_NS_END
