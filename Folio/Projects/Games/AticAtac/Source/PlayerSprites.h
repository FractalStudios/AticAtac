#pragma once

// STL includes.
#include    <map>
#include    <memory>
#include    <vector>

// "Home-made" includes.
#include    <Applet.h>
#include    <Game.h>
#include    "SpriteGraphics.h"
#include    "ZxSpectrum.h"

#pragma pack(push, 1)

namespace Folio
{

namespace Games
{

namespace AticAtac
{

// Player sprite identifier enumeration.
enum PLAYER_SPRITE_ID
{
    PLAYER_SPRITE_UNDEFINED = Folio::Core::Game::DrawingElement::DRAWING_ELEMENT_ID_UNDEFINED,
    PLAYER_SPRITE_KNIGHT = 0,
    PLAYER_SPRITE_WIZARD,
    PLAYER_SPRITE_SERF,
    MAX_PLAYER_SPRITE = PLAYER_SPRITE_SERF, 
}; // Endenum.


// Player sprite.
class PlayerSprite : public Folio::Core::Game::APlayerSprite
{
public:
    static  const   UInt32  MAIN_PLAYER_SPEED = 6;  // Main player speed.

    // Player sprite flags.
    static  const   UInt32  FLAGS_NONE                  = 0x00000000;
    static  const   UInt32  FLAGS_INITIALISED_BOTTOM_UP = 0x00000001;
    static  const   UInt32  FLAGS_INITIALISED_TOP_DOWN  = 0x00000002;
    static  const   UInt32  FLAGS_TERMINATED_BOTTOM_UP  = 0x00000010;
    static  const   UInt32  FLAGS_TERMINATED_TOP_DOWN   = 0x00000020;
    
    PlayerSprite ();
    ~PlayerSprite ();

    FolioStatus Create (FolioHandle             dcHandle, 
                        PLAYER_SPRITE_ID        playerSpriteId,
                        const SpriteGraphicsMap &spriteGraphicsMap,
                        Int32                   initialScreenXLeft,
                        Int32                   initialScreenYTop,
                        ZxSpectrum::COLOUR      playerSpriteColour,
                        Direction               initialDirection = E,
                        UInt32                  playerSpriteFlags = FLAGS_NONE);
    FolioStatus Restart ();

    PLAYER_SPRITE_ID    GetPlayerSpriteId () const;
    ZxSpectrum::COLOUR  GetPlayerSpriteColour () const;
    UInt32              GetPlayerSpriteFlags () const;

    static  bool    IsInitialisedBottomUp (UInt32 playerSpriteFlags);
    static  bool    IsInitialisedTopDown (UInt32 playerSpriteFlags);
    static  bool    IsTerminatedBottomUp (UInt32 playerSpriteFlags);
    static  bool    IsTerminatedTopDown (UInt32 playerSpriteFlags);

private:
    PLAYER_SPRITE_ID    m_playerSpriteId;       // The identifier of the player sprite.
    Int32               m_initialScreenXLeft;   // The initial screen X left (in pixels) of the player sprite.
    Int32               m_initialScreenYTop;    // The initial screen Y top (in pixels) of the player sprite.
    ZxSpectrum::COLOUR  m_playerSpriteColour;   // The colour of the player sprite.
    Direction           m_initialDirection;     // The initial direction of the player sprite.
    UInt32              m_playerSpriteFlags;    // The flags of the player sprite.

    FolioStatus SetInitialisingMode (UInt32 playerSpriteFlags);
    FolioStatus SetTerminatingMode (UInt32 playerSpriteFlags);

    // Private copy constructor to prevent copying.
    PlayerSprite (const PlayerSprite& rhs);

    // Private assignment operator to prevent copying.
    PlayerSprite& operator= (const PlayerSprite& rhs);
}; // Endclass.                         

// Player sprite pointer.
typedef std::shared_ptr<PlayerSprite>   PlayerSpritePtr;

// Player sprites map.
typedef std::map<PLAYER_SPRITE_ID, PlayerSpritePtr> PlayerSpritesMap;
     
// Player sprite drawing element.
typedef Folio::Core::Game::SpriteDrawingElement<PlayerSpritePtr> PlayerSpriteDrawingElement;

// Player sprite drawing elements list.
typedef std::vector<PlayerSpriteDrawingElement> PlayerSpriteDrawingElementsList;


// Routines.

extern  FolioStatus BuildPlayerSprites (FolioHandle             dcHandle,
                                        const SpriteGraphicsMap &spriteGraphicsMap,
                                        PlayerSpritesMap        &playerSpritesMap);

} // Endnamespace.

} // Endnamespace.

} // Endnamespace.

#pragma pack(pop)

/******************************* End of File *******************************/
