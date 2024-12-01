#include <vector>

struct ItemInfo
{
    uint32_t id;
    uint16_t flags;
    uint8_t type;
    uint8_t material;

    std::string name;
    std::string texture_file;
    int32_t texture_hash;
    uint8_t visual_effect;
    int32_t cooking_time;
    uint8_t texture_x;
    uint8_t texture_y;
    uint8_t storage;

    uint8_t layer;
    uint8_t collision_type;
    uint8_t hp;
    uint32_t restore_time;
    uint8_t clothing_type;
    int16_t rarity;
    uint8_t max_can_hold;
    std::string alt_file;
    int32_t alt_file_hash;
    uint32_t anim_ms;
    
    std::string pet_name;
    std::string pet_prefix;
    std::string pet_suffix;
    std::string pet_ability;

    uint8_t seed_base;
    uint8_t seed_overlay;
    uint8_t tree_base;
    uint8_t tree_overlay;
    uint32_t seed_color;
    uint32_t seed_overlay_color;

    uint32_t unk_1;

    uint32_t grow_time;

    uint32_t fx_flags;
    std::string animating_coordinates;
    std::string animating_texture_file;
    std::string animating_coordinates_2;

    uint32_t unk_2;
    uint32_t unk_3;

    uint32_t flags2;

    uint8_t unk_4[60] = { 0 };

    uint32_t tile_range;
    uint32_t pile_size;
    std::string customized_punch;

    uint32_t unk_5;

    int8_t body_part_list[9] = { 0 };

    uint32_t light_source_range;
    uint32_t unk_7;

    int8_t can_sit;
    int32_t player_offset_x;
    int32_t player_offset_y;
    uint32_t chair_texture_x;
    uint32_t chair_texture_y;
    int32_t chair_leg_offset_x;
    int32_t chair_leg_offset_y;

    std::string chair_texture_file;
    std::string item_renderer_file;

    uint32_t unk_8;

    int32_t item_renderer_hash;

    uint8_t unk_9[9] = { 0 };
};

struct ItemsDatDetails
{
    uint16_t version;
    uint32_t item_count;
    std::vector<ItemInfo> items;
};
