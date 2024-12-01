#include <fstream>

namespace Utils {
    uint8_t* get_file_data(const std::string& file_name) {
        std::ifstream inFile(file_name, std::ios::in | std::ios_base::binary);
        
        inFile.seekg(0, std::ios_base::end);
        size_t length = inFile.tellg();
        inFile.seekg(0, std::ios_base::beg);
        
        uint8_t* data = static_cast<uint8_t*>(std::malloc(length));
        
        inFile.read(reinterpret_cast<char*>(data), length);
        inFile.close();
    
        return data;
    }
}