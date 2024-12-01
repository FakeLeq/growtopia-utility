#include <string>

class DataReader {
public:
    DataReader(uint8_t* data) : m_data(data), pos(0) {};

public:
    template <typename T>
    T read_int() {
        T value{};
        std::memcpy(&value, m_data + this->pos, sizeof(T));
        this->pos += sizeof(T);
        return value;
    }

    std::string read_decoded_str(uint32_t item_id) {
        const uint16_t str_lenght = this->read_int<int16_t>();
        std::string out_str{ "" };

        for (uint16_t i = 0; i < str_lenght; i++)
            out_str += static_cast<char>(this->read_int<int8_t>() ^ (this->SECRET_KEY[(i + item_id) % this->SECRET_KEY.length()]));

        return out_str;
    }

    std::string read_str() {
        const uint16_t str_length = this->read_int<uint16_t>();
        std::string out_str{ "" };

        for (uint16_t i = 0; i < str_length; i++)
            out_str += this->read_int<uint8_t>();

        return out_str;
    }

    void move(size_t m_pos) { this->pos += m_pos; }

    uint8_t* get_data() { return m_data; };
    size_t get_pos() { return pos; }

private:
    size_t pos;
    uint8_t* m_data;
    std::string SECRET_KEY = "PBG892FXX982ABC*";
};
