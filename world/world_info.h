#include <string>
#include <vector>
#include "tile_extra_data.h"

struct WorldInfo {
    uint16_t version;
    std::string name;

    uint32_t width;
    uint32_t height;
    uint32_t tile_count;

    std::vector<TileInfo> tiles;
};

struct TileInfo {
    uint16_t fg;
    uint16_t bg;
    uint16_t parent;
    uint16_t flags;

    uint16_t parent_lock_index;
    uint8_t tile_extra_type;

    
};