// STL includes
#include    <memory>

// "Home-made" includes.
#include    <Applet.h>
#include    <Graphic.h>
#include    "BackgroundItemGraphics.h"
#include    "BackgroundItem.h"
#include    "DrawingElement.h"
#include    "FallingSimulationScreen.h"
#include    "GameOverScreen.h"
#include    "InformationPanel.h"
#include    "LoadingScreen.h"
#include    "PlayerSprite.h"
#include    "SpriteGraphics.h"
#include    "StaticSprite.h"
#include    "RoomGraphics.h"
#include    "Screen.h"
#include    "SelectionScreen.h"

#pragma pack(push, 1)

namespace Folio
{

namespace Games
{

namespace AticAtac
{

class MainCanvasMsgHandler : public Folio::Core::Applet::ACanvasMsgHandler
{
public:
    MainCanvasMsgHandler (Int32     maxScreenXPixels,
                          Int32     maxScreenYPixels,
                          UInt32    screenScale);
    ~MainCanvasMsgHandler ();

    virtual FolioStatus HandleCreateCanvasMsg (FolioHandle  wndHandle,
                                               UInt32       wParam,
                                               UInt32       lParam);
    virtual FolioStatus HandleProcessFrame (FolioHandle wndHandle,
                                            UInt32      &frameRateIncrement);

private:
    // State enumeration.
    enum STATE
    {
        STATE_UNKNOWN = 0,
        STATE_LOADING,
        STATE_SELECTING,
        STATE_STARTING,
        STATE_PLAYING,
        STATE_MAIN_PLAYER_FALLING,
        STATE_PAUSED,
        STATE_GAME_OVER,
    }; // Endenum.

    STATE   m_state;                // Our current state.
    UInt32  m_currentScreenNumber;  // The current screen number.
    Screen* m_currentScreen;        // The current screen.

    LoadingScreen               m_loadingScreen;                // The loading screen.
    SelectionScreen             m_selectionScreen;              // The selection screen.
    FallingSimulationScreen     m_fallingSimulationScreen;      // The falling simulation screen.
    RoomGraphicsMap             m_roomGraphicsMap;              // The room graphics.
    BackgroundItemGraphicsMap   m_backgroundItemGraphicsMap;    // The background item graphics.
    BackgroundItemsList         m_backgroundItemsList;          // The background items.
    SpriteGraphicsMap           m_spriteGraphicsMap;            // The sprite graphics.
    StaticSpritesList           m_staticSpritesList;            // The static sprites.
    InformationPanel            m_informationPanel;             // The information panel.
    ScreensList                 m_screensList;                  // The screens.
    PlayerSpritesMap            m_playerSpritesMap;             // The player sprites.

    std::unique_ptr<GameOverScreen> m_gameOverScreen;   // The game over screen.

    PlayerSpritePtr m_mainPlayer;    // The main player.

    FolioStatus HandleProcessLoadingStateFrame (FolioHandle wndHandle,
                                                UInt32      *frameRateIncrement = 0);
    FolioStatus HandleProcessSelectingStateFrame (FolioHandle   wndHandle,
                                                  UInt32        *frameRateIncrement = 0);
    FolioStatus HandleProcessStartingStateFrame (FolioHandle    wndHandle,
                                                 UInt32         *frameRateIncrement = 0);
    FolioStatus HandleProcessPlayingStateFrame (FolioHandle wndHandle,
                                                UInt32      *frameRateIncrement = 0);
    FolioStatus HandleProcessMainPlayerFallingStateFrame (FolioHandle   wndHandle,
                                                          UInt32        *frameRateIncrement = 0);
    FolioStatus HandleProcessPausedStateFrame (FolioHandle  wndHandle,
                                               UInt32       *frameRateIncrement = 0);
    FolioStatus HandleProcessGameOverStateFrame (FolioHandle    wndHandle,
                                                 UInt32         *frameRateIncrement = 0);

    FolioStatus CheckPlayingStateInput ();

    FolioStatus StartPlaying ();
    FolioStatus DisplayInitialScreen (UInt32 screenNumber);
    FolioStatus DisplayScreen (UInt32 screenNumber);
    FolioStatus DisplayGameOverScreen (bool mainPlayerCompletedGame);

    FolioStatus SetCanvasBackground (const Gdiplus::Region *clippingRegion = 0);
    FolioStatus Initialise ();

    void    DisplayFrameRate () const;

    // Private copy constructor to prevent copying.
    MainCanvasMsgHandler (const MainCanvasMsgHandler& rhs);

    // Private assignment operator to prevent copying.
    MainCanvasMsgHandler& operator= (const MainCanvasMsgHandler& rhs);
}; // Endclass.

} // Endnamespace.

} // Endnamespace.

} // Endnamespace.

#pragma pack(pop)

/******************************* End of File *******************************/