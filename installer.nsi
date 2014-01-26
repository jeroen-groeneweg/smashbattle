; Script generated by the HM NIS Edit Script Wizard.

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "Tweak Battle"
!define PRODUCT_VERSION "0.1-alpha"
!define PRODUCT_PUBLISHER "Tweakers.net"
!define PRODUCT_WEB_SITE "https://github.com/DemonTPx/smashbattle"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\Battle.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!insertmacro MUI_PAGE_LICENSE "gpl-2.0.txt"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!define MUI_FINISHPAGE_RUN "$INSTDIR\Battle.exe"
!define MUI_FINISHPAGE_RUN_PARAMETERS "-f"
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "tweakbattle-setup.exe"
InstallDir "$PROGRAMFILES\Tweak Battle"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite try
  File "vcredist_x86.exe"
  ExecWait "$INSTDIR\vcredist_x86.exe /q"
  File "Release\Battle.exe"
  CreateDirectory "$SMPROGRAMS\Tweak Battle"
  CreateShortCut "$SMPROGRAMS\Tweak Battle\Tweak Battle.lnk" "$INSTDIR\Battle.exe" "-f"
  CreateShortCut "$SMPROGRAMS\Tweak Battle\Tweak Battle (Windowed mode).lnk" "$INSTDIR\Battle.exe"
  CreateShortCut "$DESKTOP\Tweak Battle.lnk" "$INSTDIR\Battle.exe"
  File "Release\libcurl.dll"
  File "Release\libFLAC-8.dll"
  File "Release\libmikmod-2.dll"
  File "Release\libogg-0.dll"
  File "Release\libvorbis-0.dll"
  File "Release\libvorbisfile-3.dll"
  File "Release\SDL.dll"
  File "Release\SDL_mixer.dll"
  File "Release\SDL_net.dll"
  File "Release\smpeg.dll"
  File "Release\zlib1.dll"
  SetOutPath "$INSTDIR\gfx"
  SetOverwrite try
  File "Battle\gfx\arjen.bmp"
  File "Battle\gfx\arnoud.bmp"
  File "Battle\gfx\bert.bmp"
  File "Battle\gfx\bg_black.bmp"
  File "Battle\gfx\bg_blue.bmp"
  File "Battle\gfx\bg_grey.bmp"
  File "Battle\gfx\bg_orange.bmp"
  File "Battle\gfx\bg_white.bmp"
  File "Battle\gfx\bomb.bmp"
  File "Battle\gfx\bryan.bmp"
  File "Battle\gfx\cannon.bmp"
  File "Battle\gfx\chick.bmp"
  File "Battle\gfx\common.bmp"
  File "Battle\gfx\cups.bmp"
  File "Battle\gfx\femme.bmp"
  File "Battle\gfx\font_l.bmp"
  File "Battle\gfx\font_m.bmp"
  File "Battle\gfx\font_s.bmp"
  File "Battle\gfx\frederik.bmp"
  File "Battle\gfx\gatling.bmp"
  File "Battle\gfx\jeroen.bmp"
  File "Battle\gfx\joost.bmp"
  File "Battle\gfx\jur.bmp"
  File "Battle\gfx\kees.bmp"
  File "Battle\gfx\kim.bmp"
  File "Battle\gfx\maite.bmp"
  File "Battle\gfx\mark.bmp"
  File "Battle\gfx\misha.bmp"
  File "Battle\gfx\paul.bmp"
  File "Battle\gfx\player1hp.bmp"
  File "Battle\gfx\player2hp.bmp"
  File "Battle\gfx\pmarkers.bmp"
  File "Battle\gfx\powerups.bmp"
  File "Battle\gfx\props.bmp"
  File "Battle\gfx\ray.bmp"
  File "Battle\gfx\robert.bmp"
  File "Battle\gfx\SB.bmp"
  File "Battle\gfx\SB.ico"
  File "Battle\gfx\SB.png"
  File "Battle\gfx\shield.bmp"
  File "Battle\gfx\sim.bmp"
  File "Battle\gfx\tiles.bmp"
  File "Battle\gfx\tino.bmp"
  File "Battle\gfx\weapons.bmp"
  File "Battle\gfx\wilbert.bmp"
  File "Battle\gfx\wout.bmp"
  SetOutPath "$INSTDIR\music"
  File "Battle\music\a_hero_rises.ogg"
  File "Battle\music\graveyard.ogg"
  File "Battle\music\hydro_dreams.ogg"
  File "Battle\music\space_farer.ogg"
  File "Battle\music\victory.ogg"
  SetOutPath "$INSTDIR\sfx"
  File "Battle\sfx\airstrike.wav"
  File "Battle\sfx\blip.wav"
  File "Battle\sfx\bounce.wav"
  File "Battle\sfx\countdown.wav"
  File "Battle\sfx\explode.wav"
  File "Battle\sfx\go.wav"
  File "Battle\sfx\hit.wav"
  File "Battle\sfx\item.wav"
  File "Battle\sfx\jump.wav"
  File "Battle\sfx\laser.wav"
  File "Battle\sfx\pause.wav"
  File "Battle\sfx\select.wav"
  File "Battle\sfx\select_character.wav"
  File "Battle\sfx\shield.wav"
  File "Battle\sfx\shoot.wav"
  File "Battle\sfx\youlose.wav"
  SetOutPath "$INSTDIR\stage"
  File "Battle\stage\blastbowl.lvl"
  File "Battle\stage\boulderdash.lvl"
  File "Battle\stage\chicken_run.lvl"
  File "Battle\stage\chick_invasion.lvl"
  File "Battle\stage\chick_invasion_ii.lvl"
  File "Battle\stage\commongrounds.lvl"
  File "Battle\stage\ducknhunt.lvl"
  File "Battle\stage\easy_does_it.lvl"
  File "Battle\stage\lamoustache.lvl"
  File "Battle\stage\piepit.lvl"
  File "Battle\stage\pitfall.lvl"
  File "Battle\stage\pitofdeath.lvl"
  File "Battle\stage\platformalley.lvl"
  File "Battle\stage\pogostick.lvl"
  File "Battle\stage\rabbithole.lvl"
  File "Battle\stage\slipnslide.lvl"
  File "Battle\stage\snowfight.lvl"
  File "Battle\stage\stayhigh.lvl"
  File "Battle\stage\thefunnel.lvl"
  File "Battle\stage\titlescreen.lvl"
  File "Battle\stage\trainingdojo.lvl"
  File "Battle\stage\tryout.lvl"
SectionEnd

Section -AdditionalIcons
  SetOutPath $INSTDIR
  CreateShortCut "$SMPROGRAMS\Tweak Battle\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\Battle.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\Battle.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd


Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name) was successfully removed from your computer."
FunctionEnd

Function un.onInit
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "Are you sure you want to completely remove $(^Name) and all of its components?" IDYES +2
  Abort
FunctionEnd

Section Uninstall
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\stage\tryout.lvl"
  Delete "$INSTDIR\stage\trainingdojo.lvl"
  Delete "$INSTDIR\stage\titlescreen.lvl"
  Delete "$INSTDIR\stage\thefunnel.lvl"
  Delete "$INSTDIR\stage\stayhigh.lvl"
  Delete "$INSTDIR\stage\snowfight.lvl"
  Delete "$INSTDIR\stage\slipnslide.lvl"
  Delete "$INSTDIR\stage\rabbithole.lvl"
  Delete "$INSTDIR\stage\pogostick.lvl"
  Delete "$INSTDIR\stage\platformalley.lvl"
  Delete "$INSTDIR\stage\pitofdeath.lvl"
  Delete "$INSTDIR\stage\pitfall.lvl"
  Delete "$INSTDIR\stage\piepit.lvl"
  Delete "$INSTDIR\stage\lamoustache.lvl"
  Delete "$INSTDIR\stage\easy_does_it.lvl"
  Delete "$INSTDIR\stage\ducknhunt.lvl"
  Delete "$INSTDIR\stage\commongrounds.lvl"
  Delete "$INSTDIR\stage\chick_invasion_ii.lvl"
  Delete "$INSTDIR\stage\chick_invasion.lvl"
  Delete "$INSTDIR\stage\chicken_run.lvl"
  Delete "$INSTDIR\stage\boulderdash.lvl"
  Delete "$INSTDIR\stage\blastbowl.lvl"
  Delete "$INSTDIR\sfx\youlose.wav"
  Delete "$INSTDIR\sfx\shoot.wav"
  Delete "$INSTDIR\sfx\shield.wav"
  Delete "$INSTDIR\sfx\select_character.wav"
  Delete "$INSTDIR\sfx\select.wav"
  Delete "$INSTDIR\sfx\pause.wav"
  Delete "$INSTDIR\sfx\laser.wav"
  Delete "$INSTDIR\sfx\jump.wav"
  Delete "$INSTDIR\sfx\item.wav"
  Delete "$INSTDIR\sfx\hit.wav"
  Delete "$INSTDIR\sfx\go.wav"
  Delete "$INSTDIR\sfx\explode.wav"
  Delete "$INSTDIR\sfx\countdown.wav"
  Delete "$INSTDIR\sfx\bounce.wav"
  Delete "$INSTDIR\sfx\blip.wav"
  Delete "$INSTDIR\sfx\airstrike.wav"
  Delete "$INSTDIR\music\victory.ogg"
  Delete "$INSTDIR\music\space_farer.ogg"
  Delete "$INSTDIR\music\hydro_dreams.ogg"
  Delete "$INSTDIR\music\graveyard.ogg"
  Delete "$INSTDIR\music\a_hero_rises.ogg"
  Delete "$INSTDIR\gfx\wout.bmp"
  Delete "$INSTDIR\gfx\wilbert.bmp"
  Delete "$INSTDIR\gfx\weapons.bmp"
  Delete "$INSTDIR\gfx\tino.bmp"
  Delete "$INSTDIR\gfx\tiles.bmp"
  Delete "$INSTDIR\gfx\sim.bmp"
  Delete "$INSTDIR\gfx\shield.bmp"
  Delete "$INSTDIR\gfx\SB.png"
  Delete "$INSTDIR\gfx\SB.ico"
  Delete "$INSTDIR\gfx\SB.bmp"
  Delete "$INSTDIR\gfx\robert.bmp"
  Delete "$INSTDIR\gfx\ray.bmp"
  Delete "$INSTDIR\gfx\props.bmp"
  Delete "$INSTDIR\gfx\powerups.bmp"
  Delete "$INSTDIR\gfx\pmarkers.bmp"
  Delete "$INSTDIR\gfx\player2hp.bmp"
  Delete "$INSTDIR\gfx\player1hp.bmp"
  Delete "$INSTDIR\gfx\paul.bmp"
  Delete "$INSTDIR\gfx\misha.bmp"
  Delete "$INSTDIR\gfx\mark.bmp"
  Delete "$INSTDIR\gfx\maite.bmp"
  Delete "$INSTDIR\gfx\kim.bmp"
  Delete "$INSTDIR\gfx\kees.bmp"
  Delete "$INSTDIR\gfx\jur.bmp"
  Delete "$INSTDIR\gfx\joost.bmp"
  Delete "$INSTDIR\gfx\jeroen.bmp"
  Delete "$INSTDIR\gfx\gatling.bmp"
  Delete "$INSTDIR\gfx\frederik.bmp"
  Delete "$INSTDIR\gfx\font_s.bmp"
  Delete "$INSTDIR\gfx\font_m.bmp"
  Delete "$INSTDIR\gfx\font_l.bmp"
  Delete "$INSTDIR\gfx\femme.bmp"
  Delete "$INSTDIR\gfx\cups.bmp"
  Delete "$INSTDIR\gfx\common.bmp"
  Delete "$INSTDIR\gfx\chick.bmp"
  Delete "$INSTDIR\gfx\cannon.bmp"
  Delete "$INSTDIR\gfx\bryan.bmp"
  Delete "$INSTDIR\gfx\bomb.bmp"
  Delete "$INSTDIR\gfx\bg_white.bmp"
  Delete "$INSTDIR\gfx\bg_orange.bmp"
  Delete "$INSTDIR\gfx\bg_grey.bmp"
  Delete "$INSTDIR\gfx\bg_blue.bmp"
  Delete "$INSTDIR\gfx\bg_black.bmp"
  Delete "$INSTDIR\gfx\bert.bmp"
  Delete "$INSTDIR\gfx\arnoud.bmp"
  Delete "$INSTDIR\gfx\arjen.bmp"
  Delete "$INSTDIR\gfx\anne_willemijn.bmp"
  Delete "$INSTDIR\smpeg.dll"
  Delete "$INSTDIR\zlib1.dll"
  Delete "$INSTDIR\SDL_net.dll"
  Delete "$INSTDIR\SDL_mixer.dll"
  Delete "$INSTDIR\SDL.dll"
  Delete "$INSTDIR\libvorbisfile-3.dll"
  Delete "$INSTDIR\libvorbis-0.dll"
  Delete "$INSTDIR\libogg-0.dll"
  Delete "$INSTDIR\libmikmod-2.dll"
  Delete "$INSTDIR\libFLAC-8.dll"
  Delete "$INSTDIR\libcurl.dll"
  Delete "$INSTDIR\Battle.exe"
  Delete "$INSTDIR\vcredist_x86.exe"

  Delete "$SMPROGRAMS\Tweak Battle\Uninstall.lnk"
  Delete "$DESKTOP\Tweak Battle.lnk"
  Delete "$SMPROGRAMS\Tweak Battle\Tweak Battle.lnk"

  RMDir "$SMPROGRAMS\Tweak Battle"
  RMDir "$INSTDIR\stage"
  RMDir "$INSTDIR\sfx"
  RMDir "$INSTDIR\music"
  RMDir "$INSTDIR\gfx"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd