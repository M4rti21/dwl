/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
/* appearance */
static const int sloppyfocus               = 0;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const unsigned int borderpx         = 2;  /* border pixel of windows */
static const int showbar                   = 1; /* 0 means no bar */
static const int topbar                    = 0; /* 0 means bottom bar */
static const char *fonts[]                 = {"IBM Plex Mono:style=Medium:size=8"};
static const float rootcolor[]             = COLOR(0x000000ff);
static const int trayspacing               = 4; /* Spacing between icons in system tray */
static const int traymargins               = 4; /* System tray inner margins */
/* This conforms to the xdg-protocol. Set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.1f, 0.1f, 0.1f, 1.0f}; /* You can also use glsl colors */
static const char *cursor_theme            = "Banana";
static const char cursor_size[]            = "42"; /* Make sure it's a valid integer, otherwise things will break */

static uint32_t colors[][3]                = {
	/*               fg          bg          border    */
	// [SchemeNorm] = { 0xbbbbbbff, 0x222222ff, 0x444444ff }, // default
	// [SchemeSel]  = { 0xeeeeeeff, 0x005577ff, 0x770000ff }, // default
	[SchemeNorm] = { 0xbbbbbbff, 0x0e0e0eff, 0x222222ff }, // custom
	[SchemeSel]  = { 0xeeeeeeff, 0x333333ff, 0x770000ff }, // custom
	// [SchemeNorm] = { 0xffffffff, 0x1e1e1eff, 0x444444ff }, // adw
	// [SchemeSel]  = { 0xffffffff, 0x303030ff, 0x78aeedff }, // adw
	[SchemeUrg]  = { 0,          0,          0x007777ff },
};

/* tagging - TAGCOUNT must be no greater than 31 */
//                                          󰸿    󰣖        󰻞    
static char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

#define T1 1 << 0
#define T2 1 << 1
#define T3 1 << 2
#define T4 1 << 3
#define T5 1 << 4
#define T6 1 << 5
#define T7 1 << 6
#define T8 1 << 7
#define T9 1 << 8

/* logging */
static int log_level = WLR_ERROR;

/* NOTE: ALWAYS keep a rule declared even if you don't use rules (e.g leave at least one example) */
static const Rule rules[] = {
	/* app_id             title         tags mask     isfloating   monitor scratchkey */

    // Entertainment
    // 1. Media
	{ "com.stremio.stremio",NULL,       T5,         0,      -1,     0 },
    // 2. Games
	{ "osu!",               NULL,       T5,         0,      -1,     0 },
	{ "osu!.exe",           NULL,       T5,         0,      -1,     0 },
	{ "wine64",             NULL,       T5,         0,      -1,     0 },
	{ "supertuxcart",       NULL,       T5,         0,      -1,     0 },
	{ "^steam_app_.*$",     NULL,       T5,         0,      -1,     0 },
	{ "sober",              NULL,       T5,         0,      -1,     0 },
	{ "factorio",           NULL,       T5,         0,      -1,     0 },
	{ "portal2_linux",      NULL,       T5,         0,      -1,     0 },
	{ "rocketleague.exe",   NULL,       T5,         0,      -1,     0 },
	{ "fall_guys_client_game.exe", NULL,T5,         0,      -1,     0 },
	{ NULL,                 "TETR.IO",  T5,         0,      -1,     0 },

    // Background
	{ "obs",                NULL,       T6,         0,      -1,     0 },
    
    // Game Launcher
	{ NULL,                 "Steam",    T7,         0,      -1,     0 },
	{ "heroic",             NULL,       T7,         0,      -1,     0 },
    
    // Communication
	{ "vesktop",            NULL,       T8,         0,      -1,     0 },
	{ "teams-for-linux",    NULL,       T8,         0,      -1,     0 },
	{ "zapzap",             NULL,       T8,         0,      -1,     0 },
	{ "thunderbird-bin",    NULL,       T9,         0,      -1,     0 },

    //--------------------------------------------------------//
    
	{ NULL,                 "pulsemixer",0,         1,      -1,     'v' },
	{ NULL,                 "Bitwarden",0,          1,      -1,     'p' },
	{ "spotube",            NULL,       0,          1,      -1,     'm' },
	{ "e_xample",           NULL,       T1,         0,      -1,     0  }
};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "[M]",      monocle },
	{ NULL,       NULL }, /* terminate */
};

/* monitors */
/* (x=-1, y=-1) is reserved as an "autoconfigure" monitor position indicator
 * WARNING: negative values other than (-1, -1) cause problems with Xwayland clients
 * https://gitlab.freedesktop.org/xorg/xserver/-/issues/899
*/
/* NOTE: ALWAYS add a fallback rule, even if you are completely sure it won't be used */
static const MonitorRule monrules[] = {
	/* name       mfact  nmaster scale layout       rotate/reflect                x    y */
	/* example of a HiDPI laptop monitor:
	{ "eDP-1",    0.5f,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	*/
	/* defaults */
	{ NULL,         0.5f, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
};

/* keyboard */
static const struct xkb_rule_names xkb_rules[] = {
	{
		/* can specify fields: rules, model, layout, variant, options */
		.layout = "us",
		.options = NULL,
	},
	{
		.layout = "es",
		.options = NULL,
	},
};

static const int repeat_rate = 25;
static const int repeat_delay = 300;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 1;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT;
static const double accel_speed = 0.0;

/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

#define MODKEY WLR_MODIFIER_LOGO
#define CTRLKEY WLR_MODIFIER_CTRL
#define ALTKEY WLR_MODIFIER_ALT
#define SHIFTKEY WLR_MODIFIER_SHIFT

#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,                   KEY,    view,       {.ui = 1 << TAG} }, \
	{ MODKEY|CTRLKEY,           KEY,    toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|SHIFTKEY,          SKEY,   tag,        {.ui = 1 << TAG} }, \
	{ MODKEY|CTRLKEY|SHIFTKEY,  SKEY,   toggletag,  {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// APPS
#define TERMINAL "foot"
#define BROWSER "librewolf"
#define BCTL "busctl", "--user", "set-property", "rs.wl-gammarelay", "/", "rs.wl.gammarelay"

/* commands */
static const char *termcmd[]     = { TERMINAL, NULL };
static const char *menucmd[]     = { "tofi-drun", "--drun-launch=true", NULL };
static const char *rssreader[]   = { TERMINAL, "-e", "newsboat", NULL };
static const char *filemanager[] = { TERMINAL, "-e", "lf", NULL };
static const char *taskmgr[]     = { TERMINAL, "-e", "btop", NULL };

static const char *browser_p[]   = { BROWSER, "-p", "Personal", NULL };
static const char *browser_w[]   = { BROWSER, "-p", "Work", NULL };
static const char *browser_s[]   = { BROWSER, "-p", "Study", NULL };

static const char *light_top[] = { BCTL, "Brightness", "d", "1", NULL };
static const char *light_mid[] = { BCTL, "Brightness", "d", "0.6", NULL };
static const char *light_low[] = { BCTL, "Brightness", "d", "0.2", NULL };

static const char *night_top[] = { BCTL, "Temperature", "q", "6000", NULL };
static const char *night_mid[] = { BCTL, "Temperature", "q", "4000", NULL };
static const char *night_low[] = { BCTL, "Temperature", "q", "2500", NULL };

static const char *clipboard[] = { "clipboard", NULL };

static const char *book_p[]    = { "book", "personal", NULL };
static const char *book_w[]    = { "book", "work", NULL };
static const char *book_s[]    = { "book", "study", NULL };

static const char *ss_region[] = { "screenshot", NULL };
static const char *ss_screen[] = { "screenshot", "-f", NULL };

#define toggle_sp focusortogglematchingscratch

/* named scratchpads - First arg only serves to match against key in rules*/
static const char *volume[]     = { "v", TERMINAL, "-T", "pulsemixer", "-e", "pulsemixer", NULL };
static const char *password[]   = { "p", "flatpak", "run", "com.bitwarden.desktop", NULL };
static const char *music[]      = { "m", "flatpak", "run", "com.github.KRTirtho.Spotube", NULL };

static const Key keys[] = {
	// Note that Shift changes certain key codes: c -> C, 2 -> at, etc.
    //modifier          key                 function            argument
    
    // Programs
	{ MODKEY,           XKB_KEY_r,          spawn,              {.v = menucmd} },
	{ MODKEY,           XKB_KEY_Return,     spawn,              {.v = termcmd} },
	{ MODKEY,           XKB_KEY_e,          spawn,              {.v = filemanager} },
	{ MODKEY,           XKB_KEY_u,          spawn,              {.v = rssreader} },

	{ MODKEY,           XKB_KEY_i,          spawn,              {.v = browser_p} },
	{ MODKEY|SHIFTKEY,  XKB_KEY_I,          spawn,              {.v = browser_w} },
	{ MODKEY|CTRLKEY,   XKB_KEY_i,          spawn,              {.v = browser_s} },

	{ MODKEY,           XKB_KEY_space,      switchxkbrule,      {0} },
    
    // Scratchpads
	{ MODKEY,           XKB_KEY_v,          toggle_sp,          {.v = volume } },
	{ MODKEY,           XKB_KEY_p,          toggle_sp,          {.v = password} },
	{ MODKEY,           XKB_KEY_m,          toggle_sp,          {.v = music} },

    // Actions
	{ MODKEY,           XKB_KEY_d,          spawn,              {.v = book_p} },
	{ MODKEY|SHIFTKEY,  XKB_KEY_D,          spawn,              {.v = book_w} },
	{ MODKEY|CTRLKEY,   XKB_KEY_d,          spawn,              {.v = book_s} },

    { MODKEY|SHIFTKEY,  XKB_KEY_B,          spawn,              {.v = light_top} },
    { MODKEY,           XKB_KEY_b,          spawn,              {.v = light_mid} },
    { MODKEY|CTRLKEY,   XKB_KEY_b,          spawn,              {.v = light_low} },

    { MODKEY|SHIFTKEY,  XKB_KEY_N,          spawn,              {.v = night_top} },
    { MODKEY,           XKB_KEY_n,          spawn,              {.v = night_mid} },
    { MODKEY|CTRLKEY,   XKB_KEY_n,          spawn,              {.v = night_low} },

    { CTRLKEY|SHIFTKEY, XKB_KEY_Escape,     spawn,              {.v = taskmgr} },

    { MODKEY,           XKB_KEY_c,          spawn,              {.v = clipboard} },

    { MODKEY|SHIFTKEY,  XKB_KEY_S,          spawn,              {.v = ss_region} },
    { MODKEY|CTRLKEY,   XKB_KEY_s,          spawn,              {.v = ss_screen} },

	// { MODKEY,           XKB_KEY_m,          focusmaster,        {0} },
	{ MODKEY|SHIFTKEY,  XKB_KEY_M,          zoom,               {0} },  // make master

	{ MODKEY,           XKB_KEY_j,          focusstack,         {.i = +1} },
	{ MODKEY,           XKB_KEY_k,          focusstack,         {.i = -1} },
	{ MODKEY|SHIFTKEY,  XKB_KEY_J,          movestack,          {.i = +1} },
	{ MODKEY|SHIFTKEY,  XKB_KEY_K,          movestack,          {.i = -1} },

	{ MODKEY,           XKB_KEY_h,          focusmon,           {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY,           XKB_KEY_l,          focusmon,           {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|SHIFTKEY,  XKB_KEY_H,          tagmon,             {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY|SHIFTKEY,  XKB_KEY_L,          tagmon,             {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|CTRLKEY,   XKB_KEY_h,          setmfact,           {.f = -0.05f} },
	{ MODKEY|CTRLKEY,   XKB_KEY_l,          setmfact,           {.f = +0.05f} },

	{ MODKEY,           XKB_KEY_a,          incnmaster,         {.i = +1} },
	{ MODKEY,           XKB_KEY_x,          incnmaster,         {.i = -1} },
    
    // Views
	{ MODKEY,           XKB_KEY_0,          view,               {.ui = ~0} },
	{ MODKEY,           XKB_KEY_Tab,        nextlayout,         {0} },
	// { MODKEY,           XKB_KEY_Tab,        setlayout,          {.v = &layouts[0]} },
	// { MODKEY,           XKB_KEY_Tab,        setlayout,          {.v = &layouts[1]} },
	{ MODKEY,           XKB_KEY_w,          killclient,         {0} },
	{ MODKEY,           XKB_KEY_t,          togglefloating,     {0} },
	{ MODKEY,           XKB_KEY_f,          togglefullscreen,   {0} },
	{ MODKEY,           XKB_KEY_y,          togglebar,          {0} },

	TAGKEYS(XKB_KEY_1,  XKB_KEY_exclam,         0),
	TAGKEYS(XKB_KEY_2,  XKB_KEY_at,             1),
	TAGKEYS(XKB_KEY_3,  XKB_KEY_numbersign,     2),
	TAGKEYS(XKB_KEY_4,  XKB_KEY_dollar,         3),
	TAGKEYS(XKB_KEY_5,  XKB_KEY_percent,        4),
	TAGKEYS(XKB_KEY_6,  XKB_KEY_asciicircum,    5),
	TAGKEYS(XKB_KEY_7,  XKB_KEY_ampersand,      6),
	TAGKEYS(XKB_KEY_8,  XKB_KEY_asterisk,       7),
	TAGKEYS(XKB_KEY_9,  XKB_KEY_parenleft,      8),

	{ MODKEY|SHIFTKEY,  XKB_KEY_Q,          quit,           {0} },

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ CTRLKEY|ALTKEY,   XKB_KEY_Terminate_Server, quit,     {0} },
	/* Ctrl-Alt-Fx is used to switch to another VT, if you don't know what a VT is
	 * do not remove them.
	 */
#define CHVT(n) { CTRLKEY|ALTKEY,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ ClkClient,   MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ ClkClient,   MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ ClkClient,   MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
	{ ClkTagBar,   0,      BTN_LEFT,   view,           {0} },
	{ ClkTagBar,   0,      BTN_RIGHT,  toggleview,     {0} },
};
