TARGET = engine
TEMPLATE = lib
CONFIG += staticlib c++11

win32:CONFIG(release, debug|release): LIBS += -lOpengl32

QT       += opengl multimedia

DEFINES += "_CRT_SECURE_NO_WARNINGS=1"

DEFINES += "BACKEND_QT=1"

HEADERS += Engine.h \
    SceneController.h \
    Scene.h \
    SceneEntity.h \
    Drawable.h \
    ViewportProperties.h \
    Point.h \
    Size.h \
    Viewport.h \
    ViewportSurface.h \
    QTWindow.h \
    Logger.h \
    DisplayWindow.h \
    QTEngine.h \
    Renderer.h \
    QTRenderer.h \
    Color.h \
    Asset.h \
    Sprite.h \
    AssetManager.h \
    QTAssetManager.h \
    VirtualFile.h \
    QTVirtualFile.h \
    TexturePageManager.h \
    TexturePage.h \
    QTTexturePage.h \
    Sprite_Subimage.h \
    QTTexturePageManager.h \
    unused.h \
    tremor/asm_arm.h \
    tremor/backends.h \
    tremor/block.h \
    tremor/codebook.h \
    tremor/codec_internal.h \
    tremor/config_types.h \
    tremor/ivorbiscodec.h \
    tremor/ivorbisfile.h \
    tremor/lsp_lookup.h \
    tremor/mdct.h \
    tremor/mdct_lookup.h \
    tremor/misc.h \
    tremor/os.h \
    tremor/registry.h \
    tremor/window.h \
    tremor/window_lookup.h \
    ogg/ogg.h \
    ogg/os_types.h \
    AudioVoice.h \
    AudioStream.h \
    AudioStreamOggVorbis.h \
    QTAudioVoice.h \
    QTIODeviceAudioStreamAdapter.h \
    RingBuffer.h \
    InputEvent.h \
    InputKeyEvent.h \
    InputMouseEvent.h \
    InputTouchEvent.h \
    InputEventDispatcher.h \
    KeyCodes.h \
    QTKeyMap.h \
    InputEventHandler.h \
    InputState.h
SOURCES += Engine.cpp \
    SceneController.cpp \
    Scene.cpp \
    SceneEntity.cpp \
    ViewportProperties.cpp \
    Viewport.cpp \
    QTWindow.cpp \
    Logger.cpp \
    QTEngine.cpp \
    QTRenderer.cpp \
    Color.cpp \
    Sprite.cpp \
    QTAssetManager.cpp \
    QTVirtualFile.cpp \
    AssetManager.cpp \
    TexturePageManager.cpp \
    QTTexturePage.cpp \
    Sprite_Subimage.cpp \
    QTTexturePageManager.cpp \
    tremor/block.c \
    tremor/codebook.c \
    tremor/floor0.c \
    tremor/floor1.c \
    tremor/info.c \
    tremor/mapping0.c \
    tremor/mdct.c \
    tremor/registry.c \
    tremor/res012.c \
    tremor/sharedbook.c \
    tremor/synthesis.c \
    tremor/vorbisfile.c \
    tremor/window.c \
    ogg/bitwise.c \
    ogg/framing.c \
    AudioVoice.cpp \
    AudioStream.cpp \
    AudioStreamOggVorbis.cpp \
    QTAudioVoice.cpp \
    QTIODeviceAudioStreamAdapter.cpp \
    InputEvent.cpp \
    InputKeyEvent.cpp \
    InputMouseEvent.cpp \
    InputTouchEvent.cpp \
    InputEventDispatcher.cpp \
    QTKeyMap.cpp \
    InputEventHandler.cpp \
    InputState.cpp


QMAKE_CXXFLAGS_RELEASE -= -O
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2

QMAKE_CXXFLAGS_RELEASE *= -O2
