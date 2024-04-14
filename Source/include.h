/* imgui Stuff */

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include "imgui_internal.h"
#include <GLFW/glfw3.h>

/* some shit includes */

#include <stdio.h>
#include <dinput.h>
#include <tchar.h>
#include <thread>
#include <windows.h>
#include <string>
#include <iostream>
#include <time.h>
#include <cctype>
#include <thread>
#include <Windows.h>
#include <iostream>
#include <tlhelp32.h>
#include <conio.h>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <fstream>
#include <strsafe.h>
#include <algorithm>
#include <WinINet.h>
#include <tlhelp32.h>
#include <ShlObj_core.h>
#include <filesystem>
#include <random>

/*  protect for win api calls  */

#include "utils/lib/lazy.hpp"
#include "utils/lib/xorstr.hpp"
#include "utils/lib/base64.hpp"
#include "utils/cpuid.h"

/*  bruuh  */

#include "utils/variables.hpp"
#include "features/keybind/keys.h"
#include "utils/utils.hpp"

/*  auth system  */

//#include "auth/auth.hpp"

/*  crazy includes  */

#include "font/fonts.hpp"

/*  modules lol  */

#include "features/clicker.hpp"
#include "features/reach.hpp"
#include "features/velocity.hpp"
#include "features/timer.hpp"
#include "features/throwpot.h"

/*  tabs he  */

#include "ui/tabs/random_tabs.hpp"
#include "ui/tabs/combat_tabs.hpp"
#include "ui/tabs/memory_tabs.hpp"
#include "ui/tabs/misc_tabs.hpp"

/*  ui stfu  */

#include "ui/ui.hpp"

/*  more some shit  */

#pragma comment(lib, "WinINet.lib")
#define GL_FALSE
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif