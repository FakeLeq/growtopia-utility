#include "world_info.h"
#include "../utils/data_reader.h"
#include "world_flags.h"
#include <iostream>

namespace World {
    WorldInfo parse_world(uint8_t* data) {
        DataReader reader(data);
        WorldInfo world;

        world.version = reader.read_int<uint16_t>();
        reader.move(sizeof(uint32_t));
        world.name = reader.read_str();
        world.width = reader.read_int<uint32_t>();
        world.height = reader.read_int<uint32_t>();
        world.tile_count = reader.read_int<uint32_t>();

        if(world.width <= 0 || world.height <= 0 || world.tile_count <= 0) {
            std::cout << "Weird world sizes" << std::endl;
            system("pause");
        }

        for(uint32_t i = 0; i < world.tile_count; i++) {
            TileInfo tile;

            tile.fg = reader.read_int<uint16_t>();
            tile.bg = reader.read_int<uint16_t>();            
            tile.parent = reader.read_int<uint16_t>();            
            tile.flags = reader.read_int<uint16_t>();            

            if(tile.flags & Tile_Flags::TILE_FLAG_HAS_PARENT) {
                tile.parent_lock_index = reader.read_int<uint16_t>();
            } else {
                tile.parent_lock_index = 0;
            }

            if(tile.flags & Tile_Flags::TILE_FLAG_HAS_EXTRA_DATA) {
                tile.tile_extra_type = reader.read_int<uint8_t>();
            } else {
                tile.tile_extra_type = 0;
            }

            
        }

        return world;
    }
}