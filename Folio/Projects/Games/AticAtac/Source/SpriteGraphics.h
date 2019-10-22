#pragma once

// STL includes.
#include    <map>

// "Home-made" includes.
#include    <Game.h>

#pragma pack(push, 1)

namespace Folio
{

namespace Games
{

namespace AticAtac
{

// Sprite identifier enumeration.
enum SPRITE_ID
{
    SPRITE_UNDEFINED = Folio::Core::Game::DrawingElement::DRAWING_ELEMENT_ID_UNDEFINED,
    SPRITE_LEAF = 0,
    SPRITE_KEY,
    SPRITE_BOTTLE,
    SPRITE_MEDICINE_BOTTLE,
    SPRITE_BROKEN,
    SPRITE_ROPE,
    SPRITE_ARM,
    SPRITE_BOWL,
    SPRITE_APPLE,
    SPRITE_CANDY_BAR,
    SPRITE_HAM,
    SPRITE_LOLLIPOP,
    SPRITE_MONEY_BAG,
    SPRITE_GOBSTOPPER,
    SPRITE_AMULET,
    SPRITE_CAN,
    SPRITE_ICE_CREAM_CONE,
    SPRITE_CRUCIFIX,
    SPRITE_SKULL,
    SPRITE_SPANNER,
    SPRITE_ACG_KEY_LEFT,
    SPRITE_ACG_KEY_MIDDLE,
    SPRITE_ACG_KEY_RIGHT,
    SPRITE_MUSHROOM,
    SPRITE_GRAVESTONE,

    SPRITE_KNIGHT_WALKING_UP_1,
    SPRITE_KNIGHT_UP,
    SPRITE_KNIGHT_WALKING_UP_2,
    SPRITE_KNIGHT_WALKING_DOWN_1,
    SPRITE_KNIGHT_DOWN,
    SPRITE_KNIGHT_WALKING_DOWN_2,
    SPRITE_KNIGHT_WALKING_LEFT_1,
    SPRITE_KNIGHT_LEFT,
    SPRITE_KNIGHT_WALKING_LEFT_2,
    SPRITE_KNIGHT_WALKING_RIGHT_1,
    SPRITE_KNIGHT_RIGHT,
    SPRITE_KNIGHT_WALKING_RIGHT_2,

    SPRITE_WIZARD_WALKING_UP_1,
    SPRITE_WIZARD_UP,
    SPRITE_WIZARD_WALKING_UP_2,
    SPRITE_WIZARD_WALKING_DOWN_1,
    SPRITE_WIZARD_DOWN,
    SPRITE_WIZARD_WALKING_DOWN_2,
    SPRITE_WIZARD_WALKING_LEFT_1,
    SPRITE_WIZARD_LEFT,
    SPRITE_WIZARD_WALKING_LEFT_2,
    SPRITE_WIZARD_WALKING_RIGHT_1,
    SPRITE_WIZARD_RIGHT,
    SPRITE_WIZARD_WALKING_RIGHT_2,

    SPRITE_SERF_WALKING_UP_1,
    SPRITE_SERF_UP,
    SPRITE_SERF_WALKING_UP_2,
    SPRITE_SERF_WALKING_DOWN_1,
    SPRITE_SERF_DOWN,
    SPRITE_SERF_WALKING_DOWN_2,
    SPRITE_SERF_WALKING_LEFT_1,
    SPRITE_SERF_LEFT,
    SPRITE_SERF_WALKING_LEFT_2,
    SPRITE_SERF_WALKING_RIGHT_1,
    SPRITE_SERF_RIGHT,
    SPRITE_SERF_WALKING_RIGHT_2,

    SPRITE_NASTY_ALIVE_1,
    SPRITE_NASTY_ALIVE_2,
    SPRITE_NASTY_ALIVE_3,
    SPRITE_NASTY_ALIVE_4,

    SPRITE_NASTY_DEAD_1,
    SPRITE_NASTY_DEAD_2,
    SPRITE_NASTY_DEAD_3,
    SPRITE_NASTY_DEAD_4,

    SPRITE_PUMPKIN_1,            
    SPRITE_PUMPKIN_2,            

    SPRITE_SPIDER_1,             
    SPRITE_SPIDER_2,             

    SPRITE_GHOST_1,              
    SPRITE_GHOST_2,              

    SPRITE_BOUNCY_1,             
    SPRITE_BOUNCY_2,             

    SPRITE_SMORPH_1,             
    SPRITE_SMORPH_2,             

    SPRITE_JELLY_GHOUL_1,        
    SPRITE_JELLY_GHOUL_2,        

    SPRITE_BAT_1,                
    SPRITE_BAT_2,                

    SPRITE_GHOUL_1,              
    SPRITE_GHOUL_2,

    SPRITE_WITCH_FLYING_LEFT_1,  
    SPRITE_WITCH_FLYING_LEFT_2,  
    SPRITE_WITCH_FLYING_RIGHT_1, 
    SPRITE_WITCH_FLYING_RIGHT_2, 

    SPRITE_GHOUL_FLYING_LEFT_1,  
    SPRITE_GHOUL_FLYING_LEFT_2,  
    SPRITE_GHOUL_FLYING_RIGHT_1, 
    SPRITE_GHOUL_FLYING_RIGHT_2, 

    SPRITE_BAT_FLYING_LEFT_1,    
    SPRITE_BAT_FLYING_LEFT_2,    
    SPRITE_BAT_FLYING_RIGHT_1,   
    SPRITE_BAT_FLYING_RIGHT_2,

    SPRITE_KNIGHT_AXE_1,
    SPRITE_KNIGHT_AXE_2,
    SPRITE_KNIGHT_AXE_3,
    SPRITE_KNIGHT_AXE_4,
    SPRITE_KNIGHT_AXE_5,
    SPRITE_KNIGHT_AXE_6,
    SPRITE_KNIGHT_AXE_7,
    SPRITE_KNIGHT_AXE_8,
    
    SPRITE_WIZARD_POTION_1,
    SPRITE_WIZARD_POTION_2,
    SPRITE_WIZARD_POTION_3,
    
    SPRITE_SERF_SWORD_1,    
    SPRITE_SERF_SWORD_2,    
    SPRITE_SERF_SWORD_3,    
    SPRITE_SERF_SWORD_4,    
    SPRITE_SERF_SWORD_5,    
    SPRITE_SERF_SWORD_6,    
    SPRITE_SERF_SWORD_7,    
    SPRITE_SERF_SWORD_8,    
    
    SPRITE_MUMMY_1,    
    SPRITE_MUMMY_2,    
    SPRITE_MUMMY_3,    
    
    SPRITE_DRACULA_1,    
    SPRITE_DRACULA_2,    
    SPRITE_DRACULA_3,    
    
    SPRITE_FRANKENSTEIN_1,    
    SPRITE_FRANKENSTEIN_2,    
    SPRITE_FRANKENSTEIN_3,    
    
    SPRITE_HUNCHBACK_1,    
    SPRITE_HUNCHBACK_2,    
    SPRITE_HUNCHBACK_3,    
    
    SPRITE_DEVIL_1,    
    SPRITE_DEVIL_2,    
    SPRITE_DEVIL_3,    
}; // Endenum.

// Sprite graphic.
typedef Folio::Core::Game::ResourceGraphicPtr   SpriteGraphic;

// Sprite graphics map.
typedef std::map<SPRITE_ID, SpriteGraphic>      SpriteGraphicsMap;
             

// Routines.

extern  FolioStatus BuildSpriteGraphics (FolioHandle        dcHandle, 
                                         FolioHandle        instanceHandle,
                                         SpriteGraphicsMap  &spriteGraphicsMap);

} // Endnamespace.

} // Endnamespace.

} // Endnamespace.

#pragma pack(pop)

/******************************* End of File *******************************/
