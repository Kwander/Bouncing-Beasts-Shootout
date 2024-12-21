#pragma once

#define QUAD_GLFW


#ifdef QUAD_GLFW
	#define QUAD_KEY_SPACE              32
	#define QUAD_KEY_APOSTROPHE         39  /* ' */
	#define QUAD_KEY_COMMA              44  /* , */
	#define QUAD_KEY_MINUS              45  /* - */
	#define QUAD_KEY_PERIOD             46  /* . */
	#define QUAD_KEY_SLASH              47  /* / */
	#define QUAD_KEY_0                  48
	#define QUAD_KEY_1                  49
	#define QUAD_KEY_2                  50
	#define QUAD_KEY_3                  51
	#define QUAD_KEY_4                  52
	#define QUAD_KEY_5                  53
	#define QUAD_KEY_6                  54
	#define QUAD_KEY_7                  55
	#define QUAD_KEY_8                  56
	#define QUAD_KEY_9                  57
	#define QUAD_KEY_SEMICOLON          59  /* ; */
	#define QUAD_KEY_EQUAL              61  /* = */
	#define QUAD_KEY_A                  65
	#define QUAD_KEY_B                  66
	#define QUAD_KEY_C                  67
	#define QUAD_KEY_D                  68
	#define QUAD_KEY_E                  69
	#define QUAD_KEY_F                  70
	#define QUAD_KEY_G                  71
	#define QUAD_KEY_H                  72
	#define QUAD_KEY_I                  73
	#define QUAD_KEY_J                  74
	#define QUAD_KEY_K                  75
	#define QUAD_KEY_L                  76
	#define QUAD_KEY_M                  77
	#define QUAD_KEY_N                  78
	#define QUAD_KEY_O                  79
	#define QUAD_KEY_P                  80
	#define QUAD_KEY_Q                  81
	#define QUAD_KEY_R                  82
	#define QUAD_KEY_S                  83
	#define QUAD_KEY_T                  84
	#define QUAD_KEY_U                  85
	#define QUAD_KEY_V                  86
	#define QUAD_KEY_W                  87
	#define QUAD_KEY_X                  88
	#define QUAD_KEY_Y                  89
	#define QUAD_KEY_Z                  90
	#define QUAD_KEY_LEFT_BRACKET       91  /* [ */
	#define QUAD_KEY_BACKSLASH          92  /* \ */
	#define QUAD_KEY_RIGHT_BRACKET      93  /* ] */
	#define QUAD_KEY_GRAVE_ACCENT       96  /* ` */
	#define QUAD_KEY_WORLD_1            161 /* non-US #1 */
	#define QUAD_KEY_WORLD_2            162 /* non-US #2 */

	/* Function keys */
	#define QUAD_KEY_ESCAPE             256
	#define QUAD_KEY_ENTER              257
	#define QUAD_KEY_TAB                258
	#define QUAD_KEY_BACKSPACE          259
	#define QUAD_KEY_INSERT             260
	#define QUAD_KEY_DELETE             261
	#define QUAD_KEY_RIGHT              262
	#define QUAD_KEY_LEFT               263
	#define QUAD_KEY_DOWN               264
	#define QUAD_KEY_UP                 265
	#define QUAD_KEY_PAGE_UP            266
	#define QUAD_KEY_PAGE_DOWN          267
	#define QUAD_KEY_HOME               268
	#define QUAD_KEY_END                269
	#define QUAD_KEY_CAPS_LOCK          280
	#define QUAD_KEY_SCROLL_LOCK        281
	#define QUAD_KEY_NUM_LOCK           282
	#define QUAD_KEY_PRINT_SCREEN       283
	#define QUAD_KEY_PAUSE              284
	#define QUAD_KEY_F1                 290
	#define QUAD_KEY_F2                 291
	#define QUAD_KEY_F3                 292
	#define QUAD_KEY_F4                 293
	#define QUAD_KEY_F5                 294
	#define QUAD_KEY_F6                 295
	#define QUAD_KEY_F7                 296
	#define QUAD_KEY_F8                 297
	#define QUAD_KEY_F9                 298
	#define QUAD_KEY_F10                299
	#define QUAD_KEY_F11                300
	#define QUAD_KEY_F12                301
	#define QUAD_KEY_F13                302
	#define QUAD_KEY_F14                303
	#define QUAD_KEY_F15                304
	#define QUAD_KEY_F16                305
	#define QUAD_KEY_F17                306
	#define QUAD_KEY_F18                307
	#define QUAD_KEY_F19                308
	#define QUAD_KEY_F20                309
	#define QUAD_KEY_F21                310
	#define QUAD_KEY_F22                311
	#define QUAD_KEY_F23                312
	#define QUAD_KEY_F24                313
	#define QUAD_KEY_F25                314
	#define QUAD_KEY_KP_0               320
	#define QUAD_KEY_KP_1               321
	#define QUAD_KEY_KP_2               322
	#define QUAD_KEY_KP_3               323
	#define QUAD_KEY_KP_4               324
	#define QUAD_KEY_KP_5               325
	#define QUAD_KEY_KP_6               326
	#define QUAD_KEY_KP_7               327
	#define QUAD_KEY_KP_8               328
	#define QUAD_KEY_KP_9               329
	#define QUAD_KEY_KP_DECIMAL         330
	#define QUAD_KEY_KP_DIVIDE          331
	#define QUAD_KEY_KP_MULTIPLY        332
	#define QUAD_KEY_KP_SUBTRACT        333
	#define QUAD_KEY_KP_ADD             334
	#define QUAD_KEY_KP_ENTER           335
	#define QUAD_KEY_KP_EQUAL           336
	#define QUAD_KEY_LEFT_SHIFT         340
	#define QUAD_KEY_LEFT_CONTROL       341
	#define QUAD_KEY_LEFT_ALT           342
	#define QUAD_KEY_LEFT_SUPER         343
	#define QUAD_KEY_RIGHT_SHIFT        344
	#define QUAD_KEY_RIGHT_CONTROL      345
	#define QUAD_KEY_RIGHT_ALT          346
	#define QUAD_KEY_RIGHT_SUPER        347
	#define QUAD_KEY_MENU               348

#else
	//#only_GLFW_is_supported_for_now
#endif