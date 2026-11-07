# GFOpenPlay

The Open media player for AmigaOS 3.2: pictures, sounds, tunes and films,
anything a datatype opens, in one window drawn with GFOpenGadTools in the
user's GFOpenLook theme. A new datatype is a new format for GFOpenPlay, with
nothing else to install.

We, 6 October 2026: "we will need a cool media player for this, that shows
off the datatypes and the new gfopengadtools interface and open rtg".

- **One window:** a toolbar, the picture or film, the position, a playlist
  and a status line that says which datatype opened the file and what decoded
  it (this Amiga, a cores board core, or the Nursery: the services card or a
  paired Cradle), as the datatype tells it where it can.
- **Buttons as icons (the default), icons and text, or text,** from
  GFOpenPrefs Look, View › Buttons, or a `BUTTONS=` ToolType (GFOpen Apps Look
  and Feel).
- **Pictures play as a slideshow;** sounds and films play, pause and stop
  (DTM_TRIGGER), with a volume bar (SDTA_Volume), seeking in films
  (ADTA_Frame) and Repeat (DTA_Repeat).
- **About this file** shows the datatype, the decoder, the screen and the
  time it took to open, and copies it to the clipboard.
- **Full screen** on a screen of its own (GFOpenRTG scales it on the board),
  and **View › Own screen** for the whole player.
- **Save CDXL** turns a film into a CDXL the chipset plays by itself, with
  ToCDXL (gfopenservice), for an AGA Amiga.
- **Drag and drop:** files and drawers dropped on the window join the
  playlist. Playlists save as `.opl` and open `.m3u`.

![GFOpenPlay 0.1 in the Open theme](docs/window.png)

Status, 6 October 2026: 0.1, built and tested on AmiCradle with OS 3.2.3.
Pictures, sound and tunes play. Films open, but playing them waits on a fix in
gfopenvideo.datatype (gfopenimage).

## Building

    ./build.sh      # build/os3/GFOpenPlay

It needs the os32 stove (m68k-amigaos-gcc, NDK 3.2). GFOpenGadTools' library is
copied into `third_party/opengadtools` (`FROM` says which commit); GFOpenPlay
draws its own player icons (`app/op_icons.c`) until GFOpenGadTools has them.
Built for the 68040, integer maths only. GFOpenUp installs it as a part
(SYS:Utilities/GFOpenPlay).

## Using it

    GFOpenPlay [FILES ...] [BUTTONS=ICONS|TEXT|BOTH] [OWNSCREEN]

From Workbench: double-click it, shift-click files with it, or drop files on
its window. Keys: O open, P or Space play/pause, T or Esc stop, V and N (or
the cursor keys) previous and next, R repeat, F full screen, L playlist,
I about this file, C save CDXL, A add, M remove, + and - volume.

`OPENPLAY_DEBUG` set to a file's name writes a line for each step there.

## ARexx

GFOpenPlay has an ARexx port, `GFOPENPLAY.1`, on arexx.class (GFOpenSDK's `arexx/apphost.h`, copied into `third_party/gfopensdk`).

| Command | Does |
| --- | --- |
| `OPEN FILE/A` | a new playlist of FILE (a drawer: what is in it), shown and played |
| `ADD FILE/A` | FILE, or a drawer's files, at the end of the playlist |
| `PLAY`, `PAUSE`, `STOP` | as the buttons |
| `NEXT`, `PREV` | the next or the previous item |
| `CLEAR` | an empty playlist |
| `VOLUME LEVEL/N/A` | 0 to 64 |
| `GETFILE` | RESULT: the item being shown |
| `STATUS` | RESULT: `PLAYING` or `STOPPED`, the item's number, the number of items (`PLAYING 2 5`) |
| `QUIT`, `ACTIVATE`, `VERSION`, `HELP`, `FAULT` | the standard commands (`DEACTIVATE` answers RC 5: no icon yet) |

The package's `Rexx/` drawer has `PlayDrawer.rexx`: `rx Rexx/PlayDrawer.rexx Work:Music 40`.

```
/* GFOpenPlay: play a drawer of music quietly */
OPTIONS RESULTS
ADDRESS 'GFOPENPLAY.1'
'OPEN Work:Music'
'VOLUME 32'
'STATUS'
SAY result
```

## Licence

MIT, Copyright (c) 2026 AmiCradle Team (`LICENSE`). If you use or build on
this work, we ask (we do not require) that you credit the AmiCradle Team and
AmiCradle.

## Contributors

GFOpenPlay is created and maintained by [SacredTrees](https://github.com/SacredTrees) with The AmiCradle Team, copyright AmiCradle Team. Everyone whose work it includes is credited in [`CONTRIBUTORS.md`](CONTRIBUTORS.md).
