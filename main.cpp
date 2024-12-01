#include <iostream>
#include "items_dat/items_dat.h"
#include "utils/utils.h"

int main() {
    // parse_item(Utils::get_file_data("items.dat"));
    write_to_json("test.json", parse_items(Utils::get_file_data("items.dat")));
    
    return EXIT_SUCCESS;
}