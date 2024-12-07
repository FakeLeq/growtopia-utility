enum Flags {
    ITEM_FLAG_FLIPPABLE = 1 << 0,
    ITEM_FLAG_EDITABLE = 1 << 1,
    ITEM_FLAG_SEEDLESS = 1 << 2,
    ITEM_FLAG_PERMANENT = 1 << 3,
    ITEM_FLAG_AUTOPICKUP = 1 << 4,
    ITEM_FLAG_DROPLESS = 1 << 5,
    ITEM_FLAG_NOSELF = 1 << 6,
    ITEM_FLAG_NOSHADOW = 1 << 7,
    ITEM_FLAG_WORLDLOCKED = 1 << 8,
    ITEM_FLAG_FOREGROUND = 1 << 9,
    ITEM_FLAG_RANDGROW = 1 << 10,
    ITEM_FLAG_PUBLIC = 1 << 11,
    ITEM_FLAG_HOLIDAY = 1 << 12,
    ITEM_FLAG_UNTRADEABLE = 1 << 13,
    ITEM_FLAG_BETA = 1 << 14,
    ITEM_FLAG_SERVER_ALTMODE = 1 << 15,
    ITEM_FLAG_NOFRAME = 1 << 16,
};

enum Flags2 {
    ITEM_FLAG2_ROBOT_DEADLY = 1 << 0,
    ITEM_FLAG2_ROBOT_SHOOT_LEFT = 1 << 1,
    ITEM_FLAG2_ROBOT_SHOOT_RIGHT = 1 << 2,
    ITEM_FLAG2_ROBOT_SHOOT_DOWN = 1 << 3,
    ITEM_FLAG2_ROBOT_SHOOT_UP = 1 << 4,
    ITEM_FLAG2_ROBOT_CAN_SHOOT = 1 << 5,
    ITEM_FLAG2_ROBOT_LAVA = 1 << 6,
    ITEM_FLAG2_ROBOT_POINTY = 1 << 7,
    ITEM_FLAG2_ROBOT_SHOOT_DEADLY = 1 << 8,
    ITEM_FLAG2_GUILD_ITEM = 1 << 9,
    ITEM_FLAG2_GUILD_FLAG = 1 << 10,
    ITEM_FLAG2_STARSHIP_HELM = 1 << 11,
    ITEM_FLAG2_STARSHIP_REACTOR = 1 << 12,
    ITEM_FLAG2_STARSHIP_VIEWSCREEN = 1 << 13,
    ITEM_FLAG2_SMOD = 1 << 14,
    ITEM_FLAG2_TILE_DEADLY_IF_ON = 1 << 15,
    ITEM_FLAG2_LONG_HAND_ITEM64x32 = 1 << 16,
    ITEM_FLAG2_GEMLESS = 1 << 17,
    ITEM_FLAG2_TRANSMUTABLE = 1 << 18,
    ITEM_FLAG2_DUNGEON_ITEM = 1 << 19,
    ITEM_FLAG2_ONE_IN_WORLD = 1 << 20,
    ITEM_FLAG2_ONLY_FOR_WORLD_OWNER = 1 << 21,
    ITEM_FLAG2_PVE_MELEE = 1 << 22,
    ITEM_FLAG2_PVE_RANGED = 1 << 23,
    ITEM_FLAG2_PVE_AUTOAIM = 1 << 24,
    ITEM_FLAG2_NO_UPGRADE = 1 << 25,
    ITEM_FLAG2_EXTINGUISH_FIRE = 1 << 26,
    ITEM_FLAG2_EXTINGUISH_FIRE_NO_DAMAGE = 1 << 27,
    ITEM_FLAG2_NEED_RECEPTION_DESK = 1 << 28,
    ITEM_FLAG2_USE_PAINT = 1 << 29
};

enum FX_Flags {
    ITEM_FX_FLAG_MULTI_ANIM_START = 1 << 0,
    ITEM_FX_FLAG_MULTI_ANIM_END = 1 << 0,
    ITEM_FX_FLAG_MULTI_ANIM2_START = 1 << 1,
    ITEM_FX_FLAG_MULTI_ANIM2_END = 1 << 1,
    ITEM_FX_FLAG_PING_PONG_ANIM = 1 << 2,
    ITEM_FX_FLAG_OVERLAY_OBJECT = 1 << 3,
    ITEM_FX_FLAG_RENDER_FX_VARIANT_VERSION = 1 << 4,
    ITEM_FX_FLAG_OFFSET_UP = 1 << 5,
    ITEM_FX_FLAG_DUAL_LAYER = 1 << 6,
    ITEM_FX_FLAG_USE_SKIN_TINT = 1 << 7,
    ITEM_FX_FLAG_SEED_TINT_LAYER1 = 1 << 8,
    ITEM_FX_FLAG_SEED_TINT_LAYER2 = 1 << 9,
    ITEM_FX_FLAG_RAINBOW_TINT_LAYER1 = 1 << 10,
    ITEM_FX_FLAG_RAINBOW_TINT_LAYER2 = 1 << 11,
    ITEM_FX_FLAG_GLOW = 1 << 12,
    ITEM_FX_FLAG_NO_ARMS = 1 << 13,
    ITEM_FX_FLAG_RENDER_OFFHAND = 1 << 14,
    ITEM_FX_FLAG_FRONT_ARM_PUNCH = 1 << 15,
    ITEM_FX_FLAG_SLOWFALL_OBJECT = 1 << 16,
    ITEM_FX_FLAG_REPLACEMENT_SPRITE = 1 << 17,
    ITEM_FX_FLAG_ORB_FLOAT = 1 << 18,
};

enum Material {
    MATERIAL_WOOD = 0,
    MATERIAL_GLASS = 1,
    MATERIAL_ROCK = 2,
    MATERIAL_METAL = 3
};

enum Storage {
    STORAGE_SINGLE_FRAME_ALONE = 0,
    STORAGE_SINGLE_FRAME = 1,
    STORAGE_SMART_EDGE = 2,
    STORAGE_SMART_EDGE_HORIZ = 3,
    STORAGE_SMART_CLING = 4,
    STORAGE_SMART_CLING2 = 5,
    STORAGE_SMART_OUTER = 6,
    STORAGE_RANDOM = 7,
    STORAGE_SMART_EDGE_VERT = 8,
    STORAGE_SMART_EDGE_HORIZ_CAVE = 9,
    STORAGE_SMART_EDGE_DIAGON = 10
};

enum Collision {
    COLLISION_NONE = 0,
    COLLISION_NORMAL = 1,
    COLLISION_JUMP_THROUGH = 2,
    COLLISION_JUMP_DOWN = 3,
    COLLISION_GATEWAY = 4,
    COLLISION_IF_OFF = 5,
    COLLISION_IF_ON = 6,
    COLLISION_ONE_WAY = 7,
    COLLISION_VIP = 8,
    COLLISION_ADVENTURE = 9,
    COLLISION_FACTION = 10,
    COLLISION_GUILD = 11,
    COLLISION_CLOUD = 12,
};

enum Visual_Effect {
    VISUAL_EFFECT_NORMAL = 0,
    VISUAL_EFFECT_FLAME_LICK = 1,
    VISUAL_EFFECT_SMOKING = 2,
    VISUAL_EFFECT_GLOW_TINT1 = 3,
    VISUAL_EFFECT_ANIM = 4,
    VISUAL_EFFECT_BUBBLES = 5,
    VISUAL_EFFECT_PET = 6,
    VISUAL_EFFECT_PET_ANIM = 7,
    VISUAL_EFFECT_NO_ARMS = 8,
    VISUAL_EFFECT_WAVEY = 9,
    VISUAL_EFFECT_WAVEY_ANIM = 10,
    VISUAL_EFFECT_BOTHARMS = 11,
    VISUAL_EFFECT_LOWHAIR = 12,
    VISUAL_EFFECT_UNDERFACE = 13,
    VISUAL_EFFECT_SKINTINT = 14,
    VISUAL_EFFECT_MASK = 15,
    VISUAL_EFFECT_ANIM_MASK = 16,
    VISUAL_EFFECT_LOWHAIR_MASK = 17,
    VISUAL_EFFECT_GHOST = 18,
    VISUAL_EFFECT_PULSE = 19,
    VISUAL_EFFECT_COLORIZE = 20,
    VISUAL_EFFECT_COLORIZE_TO_SHIRT = 21,
    VISUAL_EFFECT_COLORIZE_ANIM = 22,
    VISUAL_EFFECT_HIGHFACE = 23,
    VISUAL_EFFECT_HIGHFACE_ANIM = 24,
    VISUAL_EFFECT_RAINBOW_SHIFT = 25,
    VISUAL_EFFECT_BACKFORE = 26,
    VISUAL_EFFECT_COLORIZE_WITH_SKIN = 27,
    VISUAL_EFFECT_NO_RENDER = 28,
    VISUAL_EFFECT_SPIN = 29,
    VISUAL_EFFECT_OFFHAND = 30,
    VISUAL_EFFECT_WINGED = 31,
    VISUAL_EFFECT_SINK = 32,
    VISUAL_EFFECT_DARKNESS = 33,
    VISUAL_EFFECT_LIGHTSOURCE = 34,
    VISUAL_EFFECT_LIGHT_IF_ON = 35,
    VISUAL_EFFECT_DISCOLOR = 36,
    VISUAL_EFFECT_STEP_SPIN = 37,
    VISUAL_EFFECT_PETCOLORED = 38,
    VISUAL_EFFECT_SILKFOOT = 39,
    VISUAL_EFFECT_TILTY = 40,
    VISUAL_EFFECT_TILTY_DARK = 41,
    VISUAL_EFFECT_NEXT_FRAME_IF_ON = 42,
    VISUAL_EFFECT_WOBBLE = 43,
    VISUAL_EFFECT_SCROLL = 44,
    VISUAL_EFFECT_LIGHTSOURCE_PULSE = 45,
    VISUAL_EFFECT_BUBBLE_MACHINE = 46,
    VISUAL_EFFECT_VERYLOWHAIR = 47,
    VISUAL_EFFECT_VERYLOWHAIR_MASK = 48,
};

/**
 * this part can be found in RenderAPet()
 * those names aren't official names
 */
enum Pet_Render {
    PET_RENDER_NORMAL = 0, // just walking like ice calf
    PET_RENDER_FLYING = 1, // dragons (fiesta, ice, diamond...)
    PET_RENDER_TUMBLEWEED_ATTRACTOR = 2,
    PET_RENDER_FLYING2 = 3, // evil space helmet, spiritfire mask
    PET_RENDER_KITE = 4, // summer kite, rainbow kite
    PET_RENDER_FLY_AND_SLEEP_ON_HEAD = 5, // mid-pacific owl, chamelon
    PET_RENDER_RAND_SPAWN_ON_AVATAR = 6, // cuddly piranha
    PET_RENDER_JUMPING_WALKING = 7, // pet bunny
    PET_RENDER_UNK1 = 8,
    PET_RENDER_DRAGON_OF_LEGEND = 9, // this drag hardcoded, only getting actual dragon's texture
    PET_RENDER_FLY_AND_SLEEP_ON_BEARD = 10, // owlbeard
    PET_RENDER_GLIDE_FOLLOW = 11, // death scarf, and fish leashs
    PET_RENDER_DOUBLE_AVATAR = 12, // gemini ring
    PET_RENDER_SPIN_WALK = 13, // winter flu vaccine
    PET_RENDER_MINI_DOUBLE_AVATAR = 14, // mini-you
    PET_RENDER_SHADOW_EFFECT_BEHIND = 15, // shadow wolf leash
    PET_RENDER_MARSHMALLOW_BASKET = 16,
    PET_RENDER_PHOENIX_PACIFIER = 17,
    PET_RENDER_BOUNCE = 18, // footballs (fc cleats, man u cleats)
    PET_RENDER_MAGICAL_CARROT = 19,
    PET_RENDER_BIRD = 20, // part fowl, mini mallard, love bird
    PET_RENDER_SILKWORM = 21,
    PET_RENDER_UNK2 = 22, // phologiston, toy lock-bot
    PET_RENDER_LIKE_GHOST = 23, // only can see with googles (haunted pants)
    /**
     * 
     * have more very lazy
     * 
     */
    PET_RENDER_PLAYFUL_FIRE_SPRITE = 29,
    PET_RENDER_BALLOON = 30 // like kite but it can turn around (red floaty balloon)
    /**
     * have more to 38
     */
    /**
     * have extra 100, 200 400
     */
};