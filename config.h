/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */

static const int barlineheight      = 7;
static const int draw_clname        = 0;

static unsigned int baralpha        = 0xc0;
static unsigned int borderalpha     = OPAQUE;

static const char *fonts[]          = { "SF Mono:size=12" };
static const char dmenufont[]       = "SF Mono:size=13";


static const char normbordercolor[] = "black";
static const char normbgcolor[]     = "black";
static const char normfgcolor[]     = "gray90";
static const char selbordercolor[]  = "#eeeeee";
static const char selbgcolor[]      = "white";
static const char selfgcolor[]      = "black";
static const char dselbgcolor[]     = "gray90";
static const char dselfgcolor[]     = "black";


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {{}};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */


static const char *upvol[]   = { "amixer", "set", "Master", "3%+",     NULL };
static const char *downvol[] = { "amixer", "set", "Master", "3%-",     NULL };
static const char *mutevol[] = { "amixer", "set", "Master", "toggle", NULL };


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz }, };

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_Down,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_Up,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m",dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", dselbgcolor, "-sf", dselfgcolor, "-b",NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
        { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
        { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
        { MODKEY,                       XK_c,      spawn,          SHCMD("clipmenue")} ,
        { MODKEY,                       XK_w,      spawn,          SHCMD("clip")} ,
        { MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
        { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,                       XK_Left,   focusmon,     {.i = -1 } },
	{ MODKEY|ShiftMask,                       XK_Right,     focusmon,     {.i = +1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_agrave,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_ampersand,                      0)
	TAGKEYS(                        XK_eacute,                         1)
	TAGKEYS(                        XK_quotedbl,                       2)
	TAGKEYS(                        XK_apostrophe,                     3)
	TAGKEYS(                        XK_parenleft,                      4)
	TAGKEYS(                        XK_minus,                          5)
	TAGKEYS(                        XK_egrave,                         6)
	TAGKEYS(                        XK_underscore,                     7)
	TAGKEYS(                        XK_ccedilla,                       8)
        STACKKEYS(MODKEY,                          focus)
        STACKKEYS(MODKEY|ShiftMask,                push)
  	{ MODKEY|ShiftMask,             XK_BackSpace,      quit,           {1} },
        { MODKEY,                       XK_F12,    spawn,          {.v = upvol   } },
	{ MODKEY,                       XK_F11,    spawn,          {.v = downvol } },
	{ MODKEY,                       XK_F10,     spawn,          {.v = mutevol } },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
