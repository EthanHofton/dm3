// * map keys to common numbers. for simplcity, the DM£ key codes will be an alias for GLFW key codes.
// * all other key codes will need to be mapped to MGL key codes in its corrispindoig window driver
//
// * FROM GLFW3.h
#define DM3_KEY_SPACE              32
#define DM3_KEY_APOSTROPHE         39  /* ' */
#define DM3_KEY_COMMA              44  /* , */
#define DM3_KEY_MINUS              45  /* - */
#define DM3_KEY_PERIOD             46  /* . */
#define DM3_KEY_SLASH              47  /* / */
#define DM3_KEY_0                  48
#define DM3_KEY_1                  49
#define DM3_KEY_2                  50
#define DM3_KEY_3                  51
#define DM3_KEY_4                  52
#define DM3_KEY_5                  53
#define DM3_KEY_6                  54
#define DM3_KEY_7                  55
#define DM3_KEY_8                  56
#define DM3_KEY_9                  57
#define DM3_KEY_SEMICOLON          59  /* ; */
#define DM3_KEY_EQUAL              61  /* = */
#define DM3_KEY_A                  65
#define DM3_KEY_B                  66
#define DM3_KEY_C                  67
#define DM3_KEY_D                  68
#define DM3_KEY_E                  69
#define DM3_KEY_F                  70
#define DM3_KEY_G                  71
#define DM3_KEY_H                  72
#define DM3_KEY_I                  73
#define DM3_KEY_J                  74
#define DM3_KEY_K                  75
#define DM3_KEY_L                  76
#define DM3_KEY_M                  77
#define DM3_KEY_N                  78
#define DM3_KEY_O                  79
#define DM3_KEY_P                  80
#define DM3_KEY_Q                  81
#define DM3_KEY_R                  82
#define DM3_KEY_S                  83
#define DM3_KEY_T                  84
#define DM3_KEY_U                  85
#define DM3_KEY_V                  86
#define DM3_KEY_W                  87
#define DM3_KEY_X                  88
#define DM3_KEY_Y                  89
#define DM3_KEY_Z                  90
#define DM3_KEY_LEFT_BRACKET       91  /* [ */
#define DM3_KEY_BACKSLASH          92  /* \ */
#define DM3_KEY_RIGHT_BRACKET      93  /* ] */
#define DM3_KEY_GRAVE_ACCENT       96  /* ` */
#define DM3_KEY_WORLD_1            161 /* non-US #1 */
#define DM3_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define DM3_KEY_ESCAPE             256
#define DM3_KEY_ENTER              257
#define DM3_KEY_TAB                258
#define DM3_KEY_BACKSPACE          259
#define DM3_KEY_INSERT             260
#define DM3_KEY_DELETE             261
#define DM3_KEY_RIGHT              262
#define DM3_KEY_LEFT               263
#define DM3_KEY_DOWN               264
#define DM3_KEY_UP                 265
#define DM3_KEY_PAGE_UP            266
#define DM3_KEY_PAGE_DOWN          267
#define DM3_KEY_HOME               268
#define DM3_KEY_END                269
#define DM3_KEY_CAPS_LOCK          280
#define DM3_KEY_SCROLL_LOCK        281
#define DM3_KEY_NUM_LOCK           282
#define DM3_KEY_PRINT_SCREEN       283
#define DM3_KEY_PAUSE              284
#define DM3_KEY_F1                 290
#define DM3_KEY_F2                 291
#define DM3_KEY_F3                 292
#define DM3_KEY_F4                 293
#define DM3_KEY_F5                 294
#define DM3_KEY_F6                 295
#define DM3_KEY_F7                 296
#define DM3_KEY_F8                 297
#define DM3_KEY_F9                 298
#define DM3_KEY_F10                299
#define DM3_KEY_F11                300
#define DM3_KEY_F12                301
#define DM3_KEY_F13                302
#define DM3_KEY_F14                303
#define DM3_KEY_F15                304
#define DM3_KEY_F16                305
#define DM3_KEY_F17                306
#define DM3_KEY_F18                307
#define DM3_KEY_F19                308
#define DM3_KEY_F20                309
#define DM3_KEY_F21                310
#define DM3_KEY_F22                311
#define DM3_KEY_F23                312
#define DM3_KEY_F24                313
#define DM3_KEY_F25                314
#define DM3_KEY_KP_0               320
#define DM3_KEY_KP_1               321
#define DM3_KEY_KP_2               322
#define DM3_KEY_KP_3               323
#define DM3_KEY_KP_4               324
#define DM3_KEY_KP_5               325
#define DM3_KEY_KP_6               326
#define DM3_KEY_KP_7               327
#define DM3_KEY_KP_8               328
#define DM3_KEY_KP_9               329
#define DM3_KEY_KP_DECIMAL         330
#define DM3_KEY_KP_DIVIDE          331
#define DM3_KEY_KP_MULTIPLY        332
#define DM3_KEY_KP_SUBTRACT        333
#define DM3_KEY_KP_ADD             334
#define DM3_KEY_KP_ENTER           335
#define DM3_KEY_KP_EQUAL           336
#define DM3_KEY_LEFT_SHIFT         340
#define DM3_KEY_LEFT_CONTROL       341
#define DM3_KEY_LEFT_ALT           342
#define DM3_KEY_LEFT_SUPER         343
#define DM3_KEY_RIGHT_SHIFT        344
#define DM3_KEY_RIGHT_CONTROL      345
#define DM3_KEY_RIGHT_ALT          346
#define DM3_KEY_RIGHT_SUPER        347
#define DM3_KEY_MENU               348
