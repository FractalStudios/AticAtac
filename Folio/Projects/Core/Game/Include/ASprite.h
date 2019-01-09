#pragma once

// STL includes.
#include    <map>
#include    <memory>
#include    <vector>

// "Home-made" includes.
#include    <Graphic.h>
#include    "CollisionGrid.h"
#include    "DrawingElement.h"
#include    "ResourceGraphic.h"

#pragma pack(push, 1)

namespace Folio
{

namespace Core
{

namespace Game
{

class ASprite : public Folio::Core::Graphic::AGdiGraphicElement
{
public:
    static  const   UInt32  STATIC_SPEED = 0;   // Speed when static.

    // Direction.
    typedef UInt32  Direction;

    // Sprite directions.
    static  const   Direction   NO_DIRECTION        = 0x00000000;
    static  const   Direction   N                   = 0x00000001;   // North.
    static  const   Direction   S                   = 0x00000002;   // South.
    static  const   Direction   E                   = 0x00000004;   // East.
    static  const   Direction   W                   = 0x00000008;   // West.
    static  const   Direction   NE                  = N | E;        // North-East.
    static  const   Direction   NW                  = N | W;        // North-West.
    static  const   Direction   SE                  = S | E;        // South-East.
    static  const   Direction   SW                  = S | W;        // South-West.
    static  const   Direction   ALL_DIRECTIONS      = N | S | E | W;
    static  const   Direction   DEFAULT_DIRECTION   = E;

    // Sprite control.
    struct SpriteControl
    {
        static  const   UInt32  CONTROL_TYPE_UNDEFINED = FOLIO_UNDEFINED;

        SpriteControl ()
        :   m_controlType(CONTROL_TYPE_UNDEFINED),
            m_direction(NO_DIRECTION)
        {} // Endproc.

        SpriteControl (UInt32       controlType,
                       Direction    direction)
        :   m_controlType(controlType),
            m_direction(direction)
        {} // Endproc.

        UInt32      m_controlType;  // The type of the sprite control.
        Direction   m_direction;    // The direction(s) of the sprite control.
    }; // Endstruct.

    // Sprite controls map.
    typedef std::map<UInt32, SpriteControl> SpriteControlsMap;

    // Sprite graphic.
    typedef std::shared_ptr<ResourceGraphic>    SpriteGraphic;

    // Sprite bitmaps list.
    typedef std::vector<SpriteGraphic>  SpriteGraphicsList;

    // Sprite graphic attributes.
    struct SpriteGraphicAttributes
    {
        SpriteGraphicAttributes ()
        :   m_direction(NO_DIRECTION)
        {} // Endproc.

        SpriteGraphicAttributes (Direction                  direction,
                                 const SpriteGraphicsList   &spriteGraphics)
        :   m_direction(direction),
            m_spriteGraphics(spriteGraphics)
        {} // Endproc.

        Direction           m_direction;        // The direction(s) of the sprite.
        SpriteGraphicsList  m_spriteGraphics;   // The sprite graphics representing the direction(s).
    }; // Endstruct.

    // Sprite graphic attributes list.
    typedef std::vector<SpriteGraphicAttributes>    SpriteGraphicAttributesList;

    virtual ~ASprite ();

    FolioStatus Create (FolioHandle                         dcHandle,
                        const SpriteGraphicAttributesList&  spriteGraphicAttributesList,
                        Int32                               initialScreenXLeft,
                        Int32                               initialScreenYTop,
                        UInt32                              screenScale,
                        Gdiplus::ARGB                       spriteInkColour,
                        Direction                           initialDirection = DEFAULT_DIRECTION,
                        UInt32                              maxNumAutoMoves = 0,
                        UInt32                              initialSpriteBitmapIndex = 0);

    FolioStatus ChangeSpriteInkColour (Gdiplus::ARGB spriteInkColour);

    CollisionGrid::CellValue    GetCollisionGridCellValue () const;

    UInt32  GetMaxNumAutoMoves () const;
    UInt32  GetRemainingNumAutoMoves () const;

    // Sprite state enumeration.
    enum STATE
    {
        STATE_UNKNOWN = 0,
        STATE_CREATED,
        STATE_INITIALISE_RQD,
        STATE_INITIALISING,
        STATE_INITIALISED,
        STATE_TERMINATE_RQD,
        STATE_TERMINATING,
        STATE_TERMINATED,
        STATE_STATIC,
        STATE_MOVING,
        STATE_FALLING,
    }; // Endenum.

    void    SetState (STATE state);
    STATE   GetState () const;
    
    void    SetAlive ();
    bool    IsAlive () const;

    void    SetDead ();
    bool    IsDying () const;
    bool    IsDead () const;

    bool    IsReady () const;

    bool    IsInitialiseRqd () const;
    bool    IsInitialising () const;
    bool    IsInitialised () const;
    bool    IsTerminateRqd () const;
    bool    IsTerminating () const;
    bool    IsTerminated () const;
    bool    IsStatic () const;
    bool    IsMoving () const;
    bool    IsFalling () const;

    FolioStatus SetGraphicInitialisingMode (FolioHandle                 dcHandle,
                                            const SpriteGraphicsList&   initialisingSpriteGraphics,
                                            UInt32                      initialisingMaxSequenceCount);
    FolioStatus SetGraphicTerminatingMode (FolioHandle                  dcHandle,
                                           const SpriteGraphicsList&    terminatingSpriteGraphics,
                                           UInt32                       terminatingMaxSequenceCount);

    Direction   UpdateDirection (Direction direction);
    void        SetDirection (Direction direction);
    Direction   GetDirection () const;

    bool    IsAtLockedScreenExit () const;

    bool    IsInScreenExit () const;
    bool    IsInScreenExit (const Gdiplus::Rect& screenRect) const;
    bool    IsExitedScreen () const;

    void    SetScreenEntrance (CollisionGrid::ScreenEntrance& screenEntrance);
    void    ResetScreenEntrance (); 
    bool    IsEnteringScreen () const;

    CollisionGrid::ScreenExit       GetScreenExit () const;
    CollisionGrid::ScreenEntrance   GetScreenEntrance () const;

    Direction   GetDirectionToScreenTopLeft (Int32                  initialScreenXLeft,
                                             Int32                  initialScreenYTop,
                                             const CollisionGrid&   collisionGrid,
                                             bool                   toScreenTopLeft = true) const;
    bool    IsAtScreenTopLeft (Int32    initialScreenXLeft,
                               Int32    initialScreenYTop) const;

    Direction   GetDirectionToScreenRect (const Gdiplus::Rect&  screenRect,
                                          const CollisionGrid&  collisionGrid,
                                          bool                  toScreenRect = true) const;
    bool    IsAtScreenRect (const Gdiplus::Rect& screenRect) const;
    
    Direction  GetDirectionToNearestCorner (const Folio::Core::Game::CollisionGrid &collisionGrid) const;

    Direction   GetFloorBoundDirection (CollisionGrid::DIRECTION collisionGridDirection) const;

    FolioStatus StoreUnderlyingBackground (Gdiplus::Graphics&   graphics,
                                           Gdiplus::Rect*       rect = 0);
    FolioStatus RestoreUnderlyingBackground (Gdiplus::Graphics& graphics,
                                             RectList*          rects = 0);
    FolioStatus Move (Gdiplus::Graphics&    graphics,
                      UInt32                speed, 
                      const CollisionGrid&  collisionGrid);
    FolioStatus Static (Gdiplus::Graphics&      graphics,
                        const CollisionGrid&    collisionGrid);

    // AGdiGraphicElement method(s).
    virtual FolioStatus SetScreenTopLeft (Int32 screenXLeft,
                                          Int32 screenYTop);
    virtual FolioStatus Draw (Gdiplus::Graphics&    graphics,
                              RectList*             rects = 0);

protected:
    STATE   m_state;    // The state of the sprite.

    Int32           m_spriteWidth;      // The width of the sprite.
    Int32           m_spriteHeight;     // The height of the sprite. 
    Gdiplus::ARGB   m_spriteInkColour;  // The ink colour of the sprite.
    Direction       m_direction;        // The direction of the sprite.

    UInt32  m_maxNumAutoMoves;          // The maximum number of sprite auto-moves.
    UInt32  m_remainingNumAutoMoves;    // The remaining number of sprite auto-moves.

    Folio::Core::Graphic::GdiBufferedBitmap   m_underlyingBackground;   // The underlying background of the sprite.

    Int32   m_initialisingDrawingMode;  // The initialising drawing mode of the player sprite.
    Int32   m_terminatingDrawingMode;   // The terminating drawing mode of the player sprite.
    
    CollisionGrid::ScreenExit    m_screenExit;  // The screen exit of the sprite.
    bool    m_isAtLockedScreenExit; // Indicates if the sprite is at a locked screen exit.
    bool    m_isInScreenExit;       // Indicates if the sprite is in a screen exit.
    bool    m_isExitedScreen;       // Indicates if the sprite has exited the screen.
    bool    m_isEnteringScreen;     // Indicates if the sprite is entering the screen.

    ASprite ();

    virtual FolioStatus HandleInitialiseSprite (Gdiplus::Graphics&  graphics,
                                                RectList*           rects = 0);
    virtual FolioStatus HandleTerminateSprite (Gdiplus::Graphics&   graphics,
                                               RectList*            rects = 0);

    virtual FolioStatus HandleMoveSprite (Gdiplus::Graphics&    graphics,
                                          UInt32                speed, 
                                          const CollisionGrid&  collisionGrid);
    virtual FolioStatus HandleStaticSprite (Gdiplus::Graphics&      graphics,
                                            const CollisionGrid&    collisionGrid);

    // Sprite drawing bitmap.
    typedef std::shared_ptr<Folio::Core::Graphic::GdiBitmap>    SpriteDrawingBitmap;

    // Sprite drawing bitmap list.
    typedef std::vector<SpriteDrawingBitmap>    SpriteDrawingBitmapsList;

    FolioStatus SetInitialSpriteBitmaps (Direction  initialDirection,
                                         UInt32     initialSpriteBitmapIndex);
    FolioStatus QueryCurrentSpriteBitmaps (SpriteDrawingBitmap& spriteDrawingBitmap,
                                           SpriteDrawingBitmap& spriteMaskedDrawingBitmap);

    FolioStatus UpdateSpriteDrawingAttributes (Direction direction);

private:
    DrawingElement::Id          m_drawingElementId;         // The drawing element identifier of the sprite.
    CollisionGrid::CellValue    m_collisionGridCellValue;   // The collision grid cell value of the sprite.

    // Drawing mode enumeration.
    enum DRAWING_MODE
    {
        DM_NONE = 0,
        DM_GRAPHIC = 10,
    }; // Endenum.

    UInt32  m_initialisingMaxSequenceCount;     // Initialising sprite maximum sequence count.
    UInt32  m_initialisingCurrentSequenceCount; // Initialising sprite current sequence count.
    
    UInt32  m_terminatingMaxSequenceCount;      // Terminating sprite maximum sequence count.
    UInt32  m_terminatingCurrentSequenceCount;  // Terminating sprite current sequence count.
    
    // Sprite drawing attributes.
    struct SpriteDrawingAttributes
    {
        SpriteDrawingAttributes ()
        :   m_direction(NO_DIRECTION),
            m_maxNumSpriteBitmaps(0),
            m_currentSpriteBitmapIndex(0)
        {} // Endproc.

        SpriteDrawingAttributes (Direction                  direction,               
                                 const SpriteDrawingBitmap& spriteDrawingBitmap,           
                                 const SpriteDrawingBitmap& spriteMaskedDrawingBitmap)
        :   m_direction(direction),
            m_maxNumSpriteBitmaps(1),
            m_currentSpriteBitmapIndex(0),
            m_spriteDrawingBitmaps{spriteDrawingBitmap},
            m_spriteMaskedDrawingBitmaps{spriteMaskedDrawingBitmap}
        {} // Endproc.

        Direction                   m_direction;                    // The direction(s) of the sprite.
        UInt32                      m_maxNumSpriteBitmaps;          // The sprite's maximum number of bitmaps (in this direction).
        UInt32                      m_currentSpriteBitmapIndex;     // The sprite's current bitmap index (in this direction).
        SpriteDrawingBitmapsList    m_spriteDrawingBitmaps;         // The sprite's drawing bitmaps representing the direction(s).
        SpriteDrawingBitmapsList    m_spriteMaskedDrawingBitmaps;   // The sprite's masked drawing bitmaps representing the direction(s).
    }; // Endstruct.

    // Sprite drawing attributes list.
    typedef std::vector<SpriteDrawingAttributes>    SpriteDrawingAttributesList;

    SpriteDrawingAttributes m_initialisingSpriteDrawingAttributes;  // The initialising sprite's drawing attributes.
    SpriteDrawingAttributes m_terminatingSpriteDrawingAttributes;   // The terminating sprite's drawing attributes.

    SpriteDrawingAttributesList m_spriteDrawingAttributesList;      // The sprite's drawing attributes.
    SpriteDrawingAttributes*    m_currentSpriteDrawingAttributes;   // The current sprite's drawing attributes.

    FolioStatus InitialiseSprite (Gdiplus::Graphics&    graphics,
                                  RectList*             rects);
    FolioStatus TerminateSprite (Gdiplus::Graphics& graphics,
                                 RectList*          rects);
    FolioStatus DrawSprite (Gdiplus::Graphics&  graphics,
                            RectList*           rects);

    FolioStatus CreateSpriteDrawingAttributes (FolioHandle                  dcHandle,
                                               const SpriteGraphicsList&    spriteGraphics,
                                               SpriteDrawingAttributes&     spriteDrawingAttributes);
    FolioStatus CreateSpriteDrawingAttributes (FolioHandle                          dcHandle,
                                               const SpriteGraphicAttributesList&   spriteGraphicAttributesList,
                                               Int32                                initialScreenXLeft,
                                               Int32                                initialScreenYTop,
                                               UInt32                               screenScale,
                                               Direction                            initialDirection,
                                               UInt32                               initialSpriteBitmapIndex);

    void    AddSpriteDrawingAttributes (Direction                   direction,
                                        const SpriteDrawingBitmap&  spriteDrawingBitmap,
                                        const SpriteDrawingBitmap&  spriteMaskedDrawingBitmap);

    FolioStatus PerformGraphicInitialising (Gdiplus::Graphics&  graphics,
                                            RectList*           rects = 0);
    FolioStatus PerformGraphicTerminating (Gdiplus::Graphics&   graphics,
                                           RectList*            rects = 0);

    Int32   GetSpriteWidth () const;
    Int32   GetSpriteHeight () const;

    void    CalculateScreenRect (UInt32                 speed,
                                 const CollisionGrid&   collisionGrid);

    void    MoveUp (UInt32                  speed,
                    const CollisionGrid&    collisionGrid,
                    Direction&              direction,
                    Gdiplus::Rect&          spriteScreenRect);
    void    MoveDown (UInt32                speed,
                      const CollisionGrid&  collisionGrid,
                      Direction&            direction,
                      Gdiplus::Rect&        spriteScreenRect);
    void    MoveLeft (UInt32                speed,
                      const CollisionGrid&  collisionGrid,
                      Direction&            direction,
                      Gdiplus::Rect&        spriteScreenRect);
    void    MoveRight (UInt32               speed,
                       const CollisionGrid& collisionGrid,
                       Direction&           direction,
                       Gdiplus::Rect&       spriteScreenRect);
    void    CheckFloorBound (const CollisionGrid&       collisionGrid,
                             CollisionGrid::DIRECTION   collisionGridDirection,
                             Direction&                 direction,
                             Gdiplus::Rect&             spriteScreenRect);

    bool    IsCreated () const;
}; // Endclass.

// Sprite pointer.
typedef std::shared_ptr<ASprite>    ASpritePtr;

// Sprites list.
typedef std::vector<ASpritePtr>     ASpritesList;

} // Endnamespace.

} // Endnamespace.

} // Endnamespace.

#pragma pack(pop)

/******************************* End of File *******************************/