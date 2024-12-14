#include <fstream>
#include "./item_info.h"
#include "../3rd_party/json.hpp"
#include "../utils/data_reader.h"
#include "../utils/data_writer.h"

#ifndef MIN_ITEMS_DAT_VERSION
    #define MIN_ITEMS_DAT_VERSION 4
#endif

#ifndef MAX_ITEMS_DAT_VERSION
    #define MAX_ITEMS_DAT_VERSION 19
#endif

ItemsDatDetails parse_items(uint8_t* data) {
    ItemsDatDetails items_dat;
    DataReader reader{data};

    items_dat.version = reader.read_int<uint16_t>();
    
    if(items_dat.version > MAX_ITEMS_DAT_VERSION || items_dat.version < MIN_ITEMS_DAT_VERSION) {
        std::cout << "You are using unsupported items.dat version!\n"
            << "Your version is " << items_dat.version << ", supported versions are "
            << MIN_ITEMS_DAT_VERSION << " to " << MAX_ITEMS_DAT_VERSION << std::endl;
        system("pause");
    }

    items_dat.item_count = reader.read_int<uint32_t>();
    items_dat.items.reserve(items_dat.item_count);

    for(size_t i = 0; i < items_dat.item_count; i++) {
        ItemInfo item{};

        item.id = reader.read_int<uint32_t>();

        if(i != item.id) {
            printf("ItemID's must be in order! %s", item.id);
            system("pause");
        }

        // see more in item_flags.h
        item.flags = reader.read_int<uint16_t>();
        item.type = reader.read_int<uint8_t>();

        /**
         * for blocks check item_flags.h
         *
         * shirts:
         * RenderBackArm() getting data from here
         * for player_sleeve
         * it checks for base then checks if SleeveHasTwoColors()
         * then it +1 to material data to get another part
         */
        item.material = reader.read_int<uint8_t>();

        if(items_dat.version < 3)
            item.name = reader.read_str();
        else
            item.name = reader.read_decoded_str(item.id);

        item.texture_file = reader.read_str();
        item.texture_hash = reader.read_int<int32_t>();
        
        // see more in item_flags.h
        item.visual_effect = reader.read_int<uint8_t>();

        // 0 to perfect in seconds
        item.cooking_time = reader.read_int<int32_t>();
        
        item.texture_x = reader.read_int<uint8_t>();
        item.texture_y = reader.read_int<uint8_t>();
        
        item.storage = reader.read_int<uint8_t>();

        // still don't know what is this
        item.layer = reader.read_int<uint8_t>();
        
        item.collision_type = reader.read_int<uint8_t>();
        item.hp = reader.read_int<uint8_t>();

        item.restore_time = reader.read_int<uint32_t>();
        
        item.clothing_type = reader.read_int<uint8_t>();
        item.rarity = reader.read_int<int16_t>();
        item.max_can_hold = reader.read_int<uint8_t>();
        
        item.alt_file = reader.read_str();
        item.alt_file_hash = reader.read_int<int32_t>();

        /**
         * it defines frames ms to next frame
         * 
         * pet's visual effects (like u can turn dragon to kite!)
         * - or u can throw a burrito like ball lol
         ** see more in item_flags.h
         * 
         * weather ids
         */
        item.anim_ms = reader.read_int<uint32_t>();
        
        /**
         * some pets doesnt have (name, prefix, suffix, ability)
         * because some of them hardcoded to client BattlePetDefList()
         */
        if(items_dat.version > 3) {
            item.pet_name = reader.read_str();
            item.pet_prefix = reader.read_str();
            item.pet_suffix = reader.read_str();
        }

        if(items_dat.version > 4)
            item.pet_ability = reader.read_str();
        
        /**
         * seed_base, seed_overlay seed's texture pos
         * client checking if its root seed
         * if its root it uses rts.rttex else seed.rttex
         * 
         * tree_base, tree_overlay tree's texture pos
         * getting from tiles_page1
         * 
         * seed_color, seed_overlay_color
         * for root seed it doesnt do anything getting the current
         * color values
         * 
         * for normal seeds it has ColorCombine()
         */
        item.seed_base = reader.read_int<uint8_t>();
        item.seed_overlay = reader.read_int<uint8_t>();
        item.tree_base = reader.read_int<uint8_t>();
        item.tree_overlay = reader.read_int<uint8_t>();
        item.seed_color = reader.read_int<uint32_t>();
        item.seed_overlay_color = reader.read_int<uint32_t>();

        // people saying it contains seeds
        item.unk_1 = reader.read_int<uint32_t>(); // removed part
        
        /**
         * this data contains seeds & providers
         * for seeds fully to grow in seconds
         * for providers ready to harvest in seconds
         * 
         * probably setup_provider linking to here
         */
        item.grow_time = reader.read_int<uint32_t>();

        if(items_dat.version > 6) {
            /**
             * set_fx_flags linking to here
             * see more in item_flags.h
             */
            item.fx_flags = reader.read_int<uint32_t>();

            item.animating_coordinates = reader.read_str();
        }

        if(items_dat.version > 7) {
            item.animating_texture_file = reader.read_str();
            item.animating_coordinates_2 = reader.read_str();
        }

        item.unk_2 = reader.read_int<uint32_t>();
        item.unk_3 = reader.read_int<uint32_t>();

        // see mroe in item_flags.h
        item.flags2 = reader.read_int<uint32_t>();

        for(auto _ = 0; _ < 60; _++) {
            item.unk_4[_] = reader.read_int<uint8_t>();
        }  
        
        /**
         * extractor dynamo tile length
         * disco fever, conquest helm, pineapple crown /omg range
         * (more like action triggers)
         * 
         * gravity well pull range
         */
        item.tile_range = reader.read_int<uint32_t>();

        /**
         * contains vualts capacity
         * safe vault, storage box, dynasty vase
         * not contains untrade box
         */
        item.pile_size = reader.read_int<uint32_t>();
        
        if (items_dat.version >= 11) {
            /**
             * so lazy to explain what those do
             * 
             * ONPUNCHSTART
             * OP_WITH_PE_GUN_FLARE
             * UPDATEPUNCH
             * UP_SPINARM2
             * RFA_HIDEITEM
             * OP_ARM1TARGET
             * OP_ARM2TARGET
             * EXTEND_FROM_EMITTER
             * 
             * op_particle2
             * op_particle1
             * op_punch_pattern
             * op_audio
             * op_params
             * up_face
             * up_arm1
             * up_arm2
             * fire_rate
             */
            item.customized_punch = reader.read_str();
        }
        
        /**
         * unk_5 and body_part_list only changes for
         * haunted jack'o lantern
         * 
         * but it doesnt effect anything (i guess)
         */
        if (items_dat.version >= 12) {
            item.unk_5 = reader.read_int<uint32_t>();

            for(auto _ = 0; _ < 9; _++) {
                item.body_part_list[_] = reader.read_int<uint8_t>();
            } 
        }
        
        if (items_dat.version >= 13) {
            /**
             * item's vision range in dark backgrounds
             * like dark cave bg, dwarven background
             * 
             * only can set 3 and 5? else returns 0 ig
             */
            item.light_source_range = reader.read_int<uint32_t>();
        }
        
        if (items_dat.version >= 14)
            item.unk_7 = reader.read_int<uint32_t>();
        
        /**
         * setup_chair linking to here
         * 
         * offsets can be negative
         */
        if (items_dat.version >= 15) {
            item.can_sit = reader.read_int<int8_t>();
            item.player_offset_x = reader.read_int<int32_t>();
            item.player_offset_y = reader.read_int<int32_t>();
            item.chair_texture_x = reader.read_int<uint32_t>();
            item.chair_texture_y = reader.read_int<uint32_t>();
            item.chair_leg_offset_x = reader.read_int<int32_t>();
            item.chair_leg_offset_y = reader.read_int<int32_t>();
        
            item.chair_texture_file = reader.read_str();
        }
        
        // item renderer files (GameData/../...(.xml))
        if (items_dat.version >= 16)
            item.item_renderer_file = reader.read_str();
        
        if (items_dat.version >= 17)
            item.unk_8 = reader.read_int<uint32_t>();
        
        // item renderer file hash
        if (items_dat.version >= 18)
            item.item_renderer_hash = reader.read_int<int32_t>();

        if (items_dat.version >= 19) {
            for(auto _ = 0; _ < 9; _++) {
                item.unk_9[_] = reader.read_int<uint8_t>();
            } 
        }
        
        items_dat.items.push_back(item);
    }

    return items_dat;
}

// from json file
size_t get_size_items_dat(const std::string& file_name) {
    size_t size = 0;

    std::ifstream inFile(file_name);
    nlohmann::json j;
    inFile >> j;

    size += sizeof(uint16_t); // version
    size += sizeof(uint32_t); // item_count

    for(uint32_t i = 0; i < j["item_count"]; i++) {
        size += 4*26 + 2*2 + 1*16; // int types
        size += 13*2; // string name len

        size += (j["items"][i]["name"]).size();
        size += (j["items"][i]["texture_file"]).size();
        size += (j["items"][i]["alt_file"]).size();
        size += (j["items"][i]["pet_name"]).size();
        size += (j["items"][i]["pet_prefix"]).size();
        size += (j["items"][i]["pet_suffix"]).size();
        size += (j["items"][i]["pet_ability"]).size();
        size += (j["items"][i]["animating_coordinates"]).size();
        size += (j["items"][i]["animating_texture_file"]).size();
        size += (j["items"][i]["animating_texture_coordinates_2"]).size();
        size += (j["items"][i]["customized_punch"]).size();
        size += (j["items"][i]["chair_texture_file"]).size();
        size += (j["items"][i]["item_renderer_file"]).size();

        size += 9; // body part

        // extras
        size += 9;
        size += 60;
    }

    return size;
}

// broken rn
bool encode_from_json(const std::string& file_name) {
    std::ifstream inFile(file_name);
    nlohmann::json j;
    inFile >> j;

    DataWriter writer(get_size_items_dat(file_name));

    std::ofstream outFile("items_encoded.dat", std::ios::binary);

    writer.write_int<uint16_t>(j["version"]);
    writer.write_int<uint32_t>(j["item_count"]);

    for(uint32_t i = 0; i < j["item_count"]; i++) {
        writer.write_int<uint32_t>(j["items"][i]["id"]);
        writer.write_int<uint16_t>(j["items"][i]["flags"]);
        writer.write_int<uint8_t>(j["items"][i]["type"]);
        writer.write_int<uint8_t>(j["items"][i]["material"]);

        writer.write_encoded_str(j["items"][i]["name"], j["items"][i]["id"]);
        writer.write_str(j["items"][i]["texture_file"]);

        writer.write_int<int32_t>(j["items"][i]["texture_hash"]);
        writer.write_int<uint8_t>(j["items"][i]["visual_effect"]);
        writer.write_int<int32_t>(j["items"][i]["cooking_time"]);

        writer.write_int<uint8_t>(j["items"][i]["texture_x"]);
        writer.write_int<uint8_t>(j["items"][i]["texture_y"]);
        writer.write_int<uint8_t>(j["items"][i]["storage"]);
        writer.write_int<uint8_t>(j["items"][i]["layer"]);

        writer.write_int<uint8_t>(j["items"][i]["collision_type"]);
        writer.write_int<uint8_t>(j["items"][i]["hp"]);
        writer.write_int<uint32_t>(j["items"][i]["restore_time"]);
        writer.write_int<uint8_t>(j["items"][i]["clothing_type"]);
        writer.write_int<int16_t>(j["items"][i]["rarity"]);
        writer.write_int<uint8_t>(j["items"][i]["max_can_hold"]);

        writer.write_int<uint32_t>(j["items"][i]["anim_ms"]);

        writer.write_str(j["items"][i]["pet_name"]);
        writer.write_str(j["items"][i]["pet_prefix"]);
        writer.write_str(j["items"][i]["pet_suffix"]);
        writer.write_str(j["items"][i]["pet_ability"]);

        writer.write_int<uint8_t>(j["items"[i]["seed_base"]]);
        writer.write_int<uint8_t>(j["items"[i]["seed_overlay"]]);
        writer.write_int<uint8_t>(j["items"[i]["tree_base"]]);
        writer.write_int<uint8_t>(j["items"[i]["tree_overlay"]]);

        writer.write_int<uint32_t>(j["items"[i]["seed_color"]]);
        writer.write_int<uint32_t>(j["items"[i]["seed_overlay_color"]]);
        writer.write_int<uint32_t>(j["items"[i]["unk_1"]]);
        writer.write_int<uint32_t>(j["items"[i]["grow_time"]]);
        writer.write_int<uint32_t>(j["items"[i]["fx_flags"]]);

        writer.write_str(j["items"][i]["animating_coordinates"]);
        writer.write_str(j["items"][i]["animating_texture_file"]);
        writer.write_str(j["items"][i]["animating_coordinates_2"]);
        
        writer.write_int<uint32_t>(j["items"[i]["unk_2"]]);
        writer.write_int<uint32_t>(j["items"[i]["unk_3"]]);
        writer.write_int<uint32_t>(j["items"[i]["flags2"]]);

        std::memcpy(writer.get_data() + writer.get_pos(), &j["items"[i]["unk_4"]], 60);
        writer.move(60);

        writer.write_int<uint32_t>(j["items"[i]["tile_range"]]);
        writer.write_int<uint32_t>(j["items"[i]["pile_size"]]);
        
        writer.write_str(j["items"[i]["customized_punch"]]);
        writer.write_int<uint32_t>(j["items"[i]["unk_5"]]);

        std::memcpy(writer.get_data() + writer.get_pos(), &j["items"[i]["body_part_list"]], 9);
        writer.move(9);

        writer.write_int<uint32_t>(j["items"[i]["light_source_range"]]);
        writer.write_int<uint32_t>(j["items"[i]["unk_7"]]);

        writer.write_int<int8_t>(j["items"[i]["can_sit"]]);
        writer.write_int<int32_t>(j["items"[i]["player_offset_x"]]);
        writer.write_int<int32_t>(j["items"[i]["player_offset_y"]]);
        writer.write_int<uint32_t>(j["items"[i]["chair_texture_x"]]);
        writer.write_int<uint32_t>(j["items"[i]["chair_texture_y"]]);
        writer.write_int<int32_t>(j["items"[i]["chair_leg_offset_x"]]);
        writer.write_int<int32_t>(j["items"[i]["chair_leg_offset_y"]]);

        writer.write_str(j["items"[i]["chair_texture_file"]]);
        writer.write_str(j["items"[i]["item_renderer_file"]]);

        writer.write_int<uint32_t>(j["items"[i]["unk_8"]]);
        writer.write_int<int32_t>(j["items"[i]["item_renderer_hash"]]);

        std::memcpy(writer.get_data() + writer.get_pos(), &j["items"[i]["unk_9"]], 9);
        writer.move(9);
    }

    outFile.write(reinterpret_cast<char*>(writer.get_data()), writer.get_pos());
    outFile.close();
    
    writer.~DataWriter();

    return true;
}

bool write_to_json(const std::string& out_file_name, ItemsDatDetails items_dat) {
    nlohmann::json json;

    json["version"] = items_dat.version;
    json["item_count"] = items_dat.item_count;

    for(ItemInfo item : items_dat.items) {
        nlohmann::json j_item;

        j_item["id"] = item.id;
        j_item["flags"] = item.flags;
        j_item["type"] = item.type;
        j_item["material"] = item.material;

        j_item["name"] = item.name;
        j_item["texture_file"] = item.texture_file;
        j_item["texture_hash"] = item.texture_hash;

        j_item["visual_effect"] = item.visual_effect;
        j_item["cooking_time"] = item.cooking_time;

        j_item["texture_x"] = item.texture_x;
        j_item["texture_y"] = item.texture_y;

        j_item["storage"] = item.storage;  
        j_item["layer"] = item.layer;  
        j_item["collision_type"] = item.collision_type; 

        j_item["hp"] = item.hp;  
        j_item["restore_time"] = item.restore_time;  
        j_item["clothing_type"] = item.clothing_type;  
        j_item["max_can_hold"] = item.max_can_hold;  
        j_item["alt_file"] = item.alt_file;  
        j_item["alt_file_hash"] = item.alt_file_hash;  

        j_item["pet_name"] = item.pet_name;  
        j_item["pet_preffix"] = item.pet_prefix;  
        j_item["pet_suffix"] = item.pet_suffix;  
        j_item["pet_ability"] = item.pet_ability;  

        j_item["seed_base"] = item.seed_base;
        j_item["seed_overlay"] = item.seed_overlay;  
        j_item["tree_base"] = item.tree_base;  
        j_item["tree_overlay"] = item.tree_overlay;    
        j_item["seed_color"] = item.seed_color;  
        j_item["seed_overlay_color"] = item.seed_overlay_color;

        j_item["unk_1"] = item.unk_1;  

        j_item["grow_time"] = item.grow_time;  
        j_item["fx_flags"] = item.fx_flags;  
        j_item["animating_coordinates_2"] = item.animating_coordinates_2; 

        j_item["unk_2"] = item.unk_2;
        j_item["unk_3"] = item.unk_3;

        j_item["flags2"] = item.flags2;

        j_item["unk_4"] = item.unk_4;  

        j_item["tile_range"] = item.tile_range;  
        j_item["pile_size"] = item.pile_size;  

        j_item["customized_punch"] = item.customized_punch;

        j_item["unk_5"] = item.unk_5;  

        j_item["body_part_list"] = item.body_part_list;  

        j_item["light_source_range"] = item.light_source_range;  
        j_item["unk_4"] = item.unk_7;  

        j_item["can_sit"] = item.can_sit;  
        j_item["player_offset_x"] = item.player_offset_x;  
        j_item["player_offset_y"] = item.player_offset_y;  
        j_item["chair_texture_x"] = item.chair_texture_x;  
        j_item["chair_texture_y"] = item.chair_texture_y;  
        j_item["chair_leg_offset_x"] = item.chair_leg_offset_x;  
        j_item["chair_leg_offset_y"] = item.chair_leg_offset_y;  
        j_item["chair_texture_file"] = item.chair_texture_file; 

        j_item["item_renderer_file"] = item.item_renderer_file;

        j_item["unk_8"] = item.unk_8;  

        j_item["item_renderer_hash"] = item.item_renderer_hash;  

        j_item["unk_9"] = item.unk_9;  

        json["items"].push_back(j_item);
    }

    std::ofstream oFile(out_file_name);
    oFile << json.dump(4) << std::endl;

    return true;
}
