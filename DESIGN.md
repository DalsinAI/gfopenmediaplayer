# GFOpenPlay: design

GFOpenPlay 0.1, 6 October 2026. The mock-ups (draft 2, eight screens, every
GFOpenGadTools theme) are in the Team's design archive. The rules are GFOpen Apps Look and Feel.

## 1. What it is

A player for anything datatypes.library opens. It never decodes a format
itself: the datatypes do (openamigaimage's gfopenpicture, gfopensound, gfopenvideo,
webp and webm, and the OS's own). So the player stays small, and every new
datatype is a new format for it.

| Kind | Group | What GFOpenPlay does |
| --- | --- | --- |
| Picture | GID_PICTURE | Shows it; Play is a slideshow, six seconds a picture |
| Sound, tune, module | GID_SOUND, GID_MUSIC | Plays, pauses, stops (DTM_TRIGGER: STM_PLAY, STM_PAUSE, STM_STOP); volume (SDTA_Volume); Repeat (DTA_Repeat) |
| Film, animation | GID_ANIMATION, GID_MOVIE | The same (ADTA_Volume); seeking by a click on the bar (ADTA_Frame); the last frame moves on to the next item unless Repeat is on; Save CDXL |
| Text, document | GID_TEXT, GID_DOCUMENT | Shows it |

## 2. The window

```
[Open] | [Previous] [Play] [Stop] [Next] | [Repeat] [Full screen]   [Playlist] [Info] [Save CDXL]
+-----------------------------------------------+   Playlist        7 items
| the datatype object, as a gadget              |   Boing 2026.mp4
|                                               |   Lake at dusk.heic
+-----------------------------------------------+   [Add...] [Remove] [Save...]
1:36 =======O-------------------------- 4:12
[VIDEO] gfopenvideo.datatype - 640 x 480 - decoded by media.decode/1 through the Nursery - opened in 2.0 s
```

- **On Workbench by default.** View › Own screen (and an `OWNSCREEN` ToolType)
  opens a public screen like Workbench's for GFOpenPlay alone. Full screen is
  always a screen of its own, with the film or picture alone; Esc, F or a
  click goes back.
- **First size:** 800 x 600, centred in the screen's free area (below the
  title bar and beside GFOpenDock), and never larger than that area, so on a
  screen smaller than 800 x 600 it is the whole free area (the rule for every
  GFOpen app, 10 October 2026, as in GFOpenFiles 0.2.3). After that, the place
  and size the user gives it are kept (`ENVARC:GFOpenPlay/Window`, section 5;
  GFOpenWindows remembers it too). On its own screen it fills the screen.
- **Title:** `GFOpenPlay · <file>`.
- **The main action, Play, is in the accent**, and becomes Pause while
  playing (Slideshow for pictures).
- **Toggles** (Repeat, Playlist) draw pressed while on.
- **The status line** names the datatype and what decoded the file: what
  the datatype says through openamigaimage's `OIA_DecodedBy` attribute
  (gfopenmodule.datatype: this Amiga's CPU, a cores board core or
  media.decode/1), else the Nursery for gfopenpicture, gfopensound, gfopendoc and
  gfopenvideo, else this Amiga. Info adds the datatype's `OIA_Stats`. Over a
  toolbar button it names the button and its key, since toolbar help bubbles
  aren't in GFOpenGadTools yet (DESIGN.md 2h, gap 4).

## 3. Buttons

Icons, icons and text, or text, as in every GFOpen app; icons only when
nothing says otherwise (every GFOpen app starts with icons, not icons and
text: the Team's rule of 10 October 2026). The style comes from, first to
last: `BUTTONS=` (Shell or ToolType), View › Buttons (kept in
`ENVARC:GFOpenPlay/Buttons`), then Look prefs' `buttons` line
(`ogt_buttons_style()`). View › Buttons › As in Look prefs goes back to the
last.

The toolbar is GFOpenGadTools' (`ogt_toolbar`, from the library copied into
`third_party/opengadtools`); GFOpenPlay draws the player icons (play, pause,
stop, previous, next, repeat, full screen, playlist, info, convert,
slideshow, sound, film) on its buttons from `app/op_icons.c`, and reads Look
prefs' `buttons` line itself. Both move to GFOpenGadTools when it has player
icons, the Buttons line and a themed slider, so every GFOpen app shares them.

The datatype object is a gadget in the window (AddDTObject, ICA_TARGET
ICTARGET_IDCMP). Its IDCMPUPDATE messages are told from the playlist's
scroller by GA_ID, and DTA_Sync refreshes it (RefreshDTObjects). Play is
sent on the first DTA_Sync, once the object has laid itself out.

## 4. The look

The theme, light or dark (or by the clock), the accent and Lite come from
`ENV:GFOpenGadTools/Look` as GFOpenLook reads them; older set-ups'
`ENV:GFOpenGadTools/Theme` works too; with neither, Open light. GFOpenPlay draws
nothing in its own colours: the media area is black for pictures and films,
the theme's list colour for sound.

## 5. What it remembers

`ENVARC:GFOpenPlay/`: `Buttons`, `Playlist` (shown or not), `Repeat`, `Volume`,
`OwnScreen` and `Window` (its place and size on Workbench).

## 6. Next

1. Films: playing waits on gfopenvideo.datatype (it runs through every frame
   at once and hangs on close; reported to the datatypes work).
2. The compact window for tunes from the mock-ups: title, author, songs and
   a scope.
3. A themed slider for position and volume, dragged as well as clicked,
   when GFOpenGadTools has one.
4. Help bubbles and underlined keys on the toolbar, when GFOpenGadTools has
   them.
5. Thumbnails in the playlist, made by the same datatypes at small size.
