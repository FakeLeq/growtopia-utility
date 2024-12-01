#include <string>

class DataWriter {
    public:
        DataWriter(size_t size) : data_size(size), pos(0)  {};
        ~DataWriter() {
            free(data);
        }

    public:
        
        template <typename T>
        T write_int(T value) {
            std::memcpy(data + pos, &value, sizeof(T));
            pos += sizeof(T);
        }

        void write_str(const std::string& value) {
            this->write_int<uint16_t>(value.length());

            std::memcpy(data + pos, value.c_str(), value.length());
            pos += value.length();
        }

        void write_encoded_str(const std::string& value, const uint32_t& item_id) {
            this->write_int<uint16_t>(value.length());

            for(uint16_t i = 0; i < value.length(); i++) {
                std::memcpy(data + pos, (char*)(value[i] ^ (this->SECRET_KEY[(i + item_id) % SECRET_KEY.length()])), 1);
                pos += 1;
            }
        }

        void move(size_t m_pos) { pos += m_pos; }

        uint8_t* get_data() { return data; }
        size_t get_pos() { return pos; }

    private:
        uint8_t* data;
        size_t pos;
        size_t data_size;  
        std::string SECRET_KEY = "PBG892FXX982ABC*";
};