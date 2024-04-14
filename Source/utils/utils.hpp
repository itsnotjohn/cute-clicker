namespace utils
{
	namespace imgui
	{
		void SpacingInt(int num)
		{
			for (int i = 0; i < num; i++)
				ImGui::Spacing();
		}

		void CustomTooltip(char* text)
		{
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(6, 6));
			ImGui::SetTooltip(text);
			ImGui::PopStyleVar();
		}

		void CenteredText(const char* text, int width)
		{
			ImVec2 s = ImGui::CalcTextSize(text);

			ImGui::SetCursorPosX((width - s.x) / 2);
			ImGui::Text(text);
		}

		void Position(int y, int x)
		{
			ImGui::SetCursorPosY(y);
			ImGui::SetCursorPosX(x);
		}

		void glfwSetWindowCenter(GLFWwindow* window)
		{
			int window_x, window_y;
			glfwGetWindowPos(window, &window_x, &window_y);
			int window_width, window_height;
			glfwGetWindowSize(window, &window_width, &window_height);
			window_width *= 0.5;
			window_height *= 0.5;
			window_x += window_width;
			window_y += window_height;
			int monitors_length;
			GLFWmonitor** monitors = glfwGetMonitors(&monitors_length);
			if (monitors == NULL)
				return;
			GLFWmonitor* owner = NULL;
			int owner_x, owner_y, owner_width, owner_height;
			for (int i = 0; i < monitors_length; i++)
			{
				int monitor_x, monitor_y;
				glfwGetMonitorPos(monitors[i], &monitor_x, &monitor_y);
				int monitor_width, monitor_height;
				GLFWvidmode* monitor_vidmode = (GLFWvidmode*)glfwGetVideoMode(monitors[i]);
				if (monitor_vidmode == NULL)
				{
					continue;
				}
				else
				{
					monitor_width = monitor_vidmode->width;
					monitor_height = monitor_vidmode->height;
				}
				if ((window_x > monitor_x && window_x < (monitor_x + monitor_width)) && (window_y > monitor_y && window_y < (monitor_y + monitor_height)))
				{
					owner = monitors[i];
					owner_x = monitor_x;
					owner_y = monitor_y;
					owner_width = monitor_width;
					owner_height = monitor_height;
				}
			}
			if (owner != NULL)
				glfwSetWindowPos(window, owner_x + (owner_width * 0.5) - window_width, owner_y + (owner_height * 0.5) - window_height);
		}

		void TextColoredInt(const char* text, int width, ImVec4 color)
		{
			ImVec2 s = ImGui::CalcTextSize(text);

			ImGui::SetCursorPosX((width - s.x) / 2);
			ImGui::TextColored(color, text);
		}
	}

	namespace random
	{
		void fixf()
		{
			if (var::settings::blatant)
			{
				if (var::left_click::lmincps < 1)
					var::left_click::lmincps = 1;

				if (var::left_click::lmincps > 50)
					var::left_click::lmincps = 50;

				if (var::left_click::lmaxcps < 1)
					var::left_click::lmaxcps = 1;

				if (var::left_click::lmaxcps > 50)
					var::left_click::lmaxcps = 50;

				if (var::left_click::lmincps > var::left_click::lmaxcps)
					var::left_click::lmaxcps++;
			}
			else
			{
				if (var::left_click::lmincps < 1)
					var::left_click::lmincps = 1;

				if (var::left_click::lmaxcps < 1)
					var::left_click::lmaxcps = 1;

				if (var::left_click::lmincps > 20)
					var::left_click::lmincps = 20;

				if (var::left_click::lmaxcps > 20)
					var::left_click::lmaxcps = 20;

				if (var::left_click::lmincps > var::left_click::lmaxcps)
					var::left_click::lmaxcps++;
			}

			//--------------------//

			if (var::settings::blatant)
			{
				if (var::right_click::rmincps < 1)
					var::right_click::rmincps = 1;

				if (var::right_click::rmincps > 50)
					var::right_click::rmincps = 50;

				if (var::right_click::rmaxcps < 1)
					var::right_click::rmaxcps = 1;

				if (var::right_click::rmaxcps > 50)
					var::right_click::rmaxcps = 50;

				if (var::right_click::rmincps > var::right_click::rmaxcps)
					var::right_click::rmaxcps++;
			}
			else
			{
				if (var::right_click::rmincps < 1)
					var::right_click::rmincps = 1;

				if (var::right_click::rmincps > 20)
					var::right_click::rmincps = 20;

				if (var::right_click::rmaxcps < 1)
					var::right_click::rmaxcps = 1;

				if (var::right_click::rmaxcps > 20)
					var::right_click::rmaxcps = 20;

				if (var::right_click::rmincps > var::right_click::rmaxcps)
					var::right_click::rmaxcps++;
			}

			//--------------------//

			if (var::throwp::delaypot > 150)
				var::throwp::delaypot = 150;

			if (var::throwp::delaypot < 30)
				var::throwp::delaypot = 30;

			//--------------------//

			if (var::throwpl::delaypearl > 150)
				var::throwpl::delaypearl = 150;

			if (var::throwpl::delaypearl < 30)
				var::throwpl::delaypearl = 30;

			//--------------------//

			if (var::jitter::densityx > 10)
				var::jitter::densityx = 10;

			if (var::jitter::densityx < 1)
				var::jitter::densityx = 1;

			//--------------------//

			if (var::jitter::densityy > 10)
				var::jitter::densityy = 10;

			if (var::jitter::densityy < 1)
				var::jitter::densityy = 1;
		}

		void blatantchange()
		{
			if (var::settings::blatant)
			{
				var::left_click::maxclicks = 50;
				var::right_click::maxclicks = 50;
			}
			else
			{
				var::left_click::maxclicks = 20;
				var::right_click::maxclicks = 20;
			}
		}

		std::string get_exe_name()
		{
			std::string strAppName;
			std::string strinpathloool;
			char szAppPath[MAX_PATH];
			::GetModuleFileName(0, szAppPath, MAX_PATH);
			strinpathloool = szAppPath;
			strAppName = szAppPath;
			strAppName = strAppName.substr(strAppName.rfind("\\") + 1);
			return strAppName;
		}

		std::string get_exe_path()
		{
			std::string strAppName;
			std::string strinpathloool;
			char szAppPath[MAX_PATH];
			::GetModuleFileName(0, szAppPath, MAX_PATH);
			std::string returnme = szAppPath;
			return returnme;
		}

		DWORD get_service_processid(const char* serviceName)
		{
			const auto hScm = OpenSCManager(nullptr, nullptr, NULL);
			const auto hSc = OpenService(hScm, serviceName, SERVICE_QUERY_STATUS);
			SERVICE_STATUS_PROCESS ssp = {};
			DWORD bytesNeeded = 0;
			QueryServiceStatusEx(hSc, SC_STATUS_PROCESS_INFO, reinterpret_cast<LPBYTE>(&ssp), sizeof(ssp), &bytesNeeded);
			CloseServiceHandle(hSc);
			CloseServiceHandle(hScm);
			return ssp.dwProcessId;
		}

		int random_int(int min, int max)
		{
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
			return dist6(rng);
		}

		WCHAR random_wchar(int min, int max)
		{
			int choose = utils::random::random_int(min, max);
			WCHAR returnme;
			if (choose == 0)
			{
				returnme = '0';
			}
			if (choose == 1)
			{
				returnme = '1';
			}
			if (choose == 2)
			{
				returnme = '2';
			}
			if (choose == 3)
			{
				returnme = '3';
			}
			if (choose == 4)
			{
				returnme = '4';
			}
			if (choose == 5)
			{
				returnme = '5';
			}
			if (choose == 6)
			{
				returnme = '6';
			}
			if (choose == 7)
			{
				returnme = '7';
			}
			if (choose == 8)
			{
				returnme = '8';
			}
			if (choose == 9)
			{
				returnme = '9';
			}
			if (choose == 10)
			{
				returnme = 'a';
			}
			if (choose == 11)
			{
				returnme = 'b';
			}
			if (choose == 12)
			{
				returnme = 'c';
			}
			if (choose == 13)
			{
				returnme = 'd';
			}
			if (choose == 14)
			{
				returnme = 'e';
			}
			if (choose == 15)
			{
				returnme = 'f';
			}
			if (choose == 16)
			{
				returnme = 'g';
			}
			if (choose == 17)
			{
				returnme = 'h';
			}
			if (choose == 18)
			{
				returnme = 'i';
			}
			if (choose == 19)
			{
				returnme = 'j';
			}
			if (choose == 20)
			{
				returnme = 'k';
			}
			if (choose == 21)
			{
				returnme = 'l';
			}
			if (choose == 22)
			{
				returnme = 'm';
			}
			if (choose == 23)
			{
				returnme = 'n';
			}
			if (choose == 24)
			{
				returnme = 'o';
			}
			if (choose == 25)
			{
				returnme = 'p';
			}
			if (choose == 26)
			{
				returnme = 'q';
			}
			if (choose == 27)
			{
				returnme = 'r';
			}
			if (choose == 28)
			{
				returnme = 's';
			}
			if (choose == 29)
			{
				returnme = 't';
			}
			if (choose == 30)
			{
				returnme = 'u';
			}
			if (choose == 31)
			{
				returnme = 'v';
			}
			if (choose == 32)
			{
				returnme = 'w';
			}
			if (choose == 33)
			{
				returnme = 'x';
			}
			if (choose == 34)
			{
				returnme = 'y';
			}
			if (choose == 35)
			{
				returnme = 'z';
			}

			return returnme;
		}
	}

	namespace cute
	{
		int randint(int MinCPS, int MaxCPS)
		{
			srand(time(0));

			return std::rand() % (MaxCPS + 1 - MinCPS) + MinCPS;
		}

		void keybindsystem()
		{
			switch (var::keybindchoose)
			{
			case 1:
				var::left_click::keybindleftclick = 0;
				while (var::left_click::keybindleftclick == 0)
				{
					for (int i = 3; i < 256; i++)
					{
						if (i != 13)
						{
							if (GetAsyncKeyState((i)&SHRT_MAX) && var::left_click::keybindleftclick == 0)
							{
								var::left_click::keybindleftclick = i;
								var::left_click::key_bind_lc_text = checkkeybind(i);
							}
						}
					}
				}
				var::keybindchoose = 0;
				break;
			case 2:
				var::right_click::keybindrightclick = 0;
				while (var::right_click::keybindrightclick == 0)
				{
					for (int i = 3; i < 256; i++)
					{
						if (i != 13)
						{
							if (GetAsyncKeyState((i)&SHRT_MAX) && var::right_click::keybindrightclick == 0)
							{
								var::right_click::keybindrightclick = i;
								var::right_click::key_bind_rc_text = checkkeybind(i);
							}
						}
					}
				}
				var::keybindchoose = 0;
				break;
			case 3:
				var::misc::keybindhide = 0;
				while (var::misc::keybindhide == 0)
				{
					for (int i = 3; i < 256; i++)
					{
						if (i != 13)
						{
							if (GetAsyncKeyState((i)&SHRT_MAX) && var::misc::keybindhide == 0)
							{
								var::misc::keybindhide = i;
								var::misc::key_bind_hide_text = checkkeybind(i);
							}
						}
					}
				}
				var::keybindchoose = 0;
				break;
			case 4:
				var::throwp::keybindthrowpot = 0;
				while (var::throwp::keybindthrowpot == 0)
				{
					for (int i = 3; i < 256; i++)
					{
						if (i != 13)
						{
							if (GetAsyncKeyState((i)&SHRT_MAX) && var::throwp::keybindthrowpot == 0)
							{
								var::throwp::keybindthrowpot = i;
								var::throwp::key_bind_throwpot_text = checkkeybind(i);
							}
						}
					}
				}
				var::keybindchoose = 0;
				break;
			case 5:
				var::throwpl::keybindthrowpearl = 0;
				while (var::throwpl::keybindthrowpearl == 0)
				{
					for (int i = 3; i < 256; i++)
					{
						if (i != 13)
						{
							if (GetAsyncKeyState((i)&SHRT_MAX) && var::throwpl::keybindthrowpearl == 0)
							{
								var::throwpl::keybindthrowpearl = i;
								var::throwp::key_bind_throwpearl_text = checkkeybind(i);
							}
						}
					}
				}
				var::keybindchoose = 0;
				break;
			}
		}

		DWORD get_processid(std::string processname)
		{
			PROCESSENTRY32 processinfo;
			processinfo.dwSize = sizeof(processinfo);
			HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
			if (processesSnapshot == INVALID_HANDLE_VALUE)
			{
				return (DWORD)0;
			}
			Process32First(processesSnapshot, &processinfo);
			if (!processname.compare(processinfo.szExeFile))
			{
				CloseHandle(processesSnapshot);
				return processinfo.th32ProcessID;
			}
			while (Process32Next(processesSnapshot, &processinfo))
			{
				if (!processname.compare(processinfo.szExeFile))
				{
					CloseHandle(processesSnapshot);
					return processinfo.th32ProcessID;
				}
			}
			CloseHandle(processesSnapshot);
			return (DWORD)0;
		}

		void getwindowname()
		{
			HWND lwjgl = FindWindowA("LWJGL", NULL);
			if (!lwjgl)
			{
				strcpy(var::settings::minecraft_title, "Minecraft not found...");
				return;
			}

			char title[256];
			GetWindowTextA(lwjgl, title, sizeof(title));
			strcpy(var::settings::minecraft_title, title);

			return;
		}

		int cute_random_int(int min, int max)
		{
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);

			return dist6(rng);
		}

		void cute_rainbow_mode()
		{
			if (var::misc::rainbow) {
				float add = 0.03f;

				static size_t turn = 0;

				if (turn == 0)
				{
					var::misc::color[0] += add;

					if (var::misc::color[0] >= 1.00f)
					{
						var::misc::color[0] = 1.00f;
						turn++;
					}
				}

				if (turn == 1)
				{
					var::misc::color[1] += add;

					if (var::misc::color[1] >= 1.00f)
					{
						var::misc::color[1] = 1.00f;
						turn++;
					}
				}

				if (turn == 2)
				{
					var::misc::color[0] -= add;

					if (var::misc::color[0] <= 0.00f)
					{
						var::misc::color[0] = 0.00f;
						turn++;
					}
				}

				if (turn == 3)
				{
					var::misc::color[2] += add;

					if (var::misc::color[2] >= 1.00f)
					{
						var::misc::color[2] = 1.00f;
						turn++;
					}
				}

				if (turn == 4)
				{
					var::misc::color[1] -= add;

					if (var::misc::color[1] <= 0.00f)
					{
						var::misc::color[1] = 0.00f;
						turn++;
					}
				}

				if (turn == 5)
				{
					var::misc::color[0] += add;

					if (var::misc::color[0] >= 1.00f)
					{
						var::misc::color[0] = 1.00f;
						turn++;
					}
				}

				if (turn == 6)
				{
					var::misc::color[2] -= add;

					if (var::misc::color[2] <= 0.00f)
					{
						var::misc::color[2] = 0.00f;
						turn = 0;
					}
				}
			}
		}

		namespace hook
		{
			LRESULT __stdcall mouse_callback(int nCode, WPARAM wParam, LPARAM lParam)
			{
				auto* hook = reinterpret_cast<MSLLHOOKSTRUCT*> (lParam);

				if ((hook->flags == LLMHF_INJECTED))
				{
					hook->flags &= ~LLMHF_INJECTED;
					hook->flags &= ~LLMHF_LOWER_IL_INJECTED;
					return false;
				}

				if (wParam != WM_MOUSEMOVE)
				{
					switch (wParam)
					{
					case WM_LBUTTONDOWN:
						var::left_click::LBUTTONDOWN = true;
						break;
					case WM_LBUTTONUP:
						var::left_click::LBUTTONDOWN = false;
						break;
					case WM_RBUTTONDOWN:
						var::right_click::RBUTTONDOWN = true;
						break;
					case WM_RBUTTONUP:
						var::right_click::RBUTTONDOWN = false;
						break;
					}
				}

				return CallNextHookEx(var::hookdoMouse, nCode, wParam, lParam);
			}

			DWORD __stdcall hooking()
			{
				var::hookdoMouse = SetWindowsHookExA(WH_MOUSE_LL, &mouse_callback, nullptr, 0);

				MSG lpMsg;
				while (GetMessageA(&lpMsg, nullptr, 0, 0))
				{
					TranslateMessage(&lpMsg);
					DispatchMessageA(&lpMsg);
				}

				UnhookWindowsHookEx(var::hookdoMouse);

				return EXIT_SUCCESS;
			}
		}

		namespace input
		{
			namespace left
			{
				void left_down()
				{
					INPUT input = { 0 };
					input.type = INPUT_MOUSE;
					input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
					SendInput(1, &input, sizeof(INPUT));
				}

				void left_up()
				{
					INPUT input = { 0 };
					input.type = INPUT_MOUSE;
					input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
					SendInput(1, &input, sizeof(INPUT));
				}
			}

			namespace right
			{
				void right_down()
				{
					INPUT input = { 0 };
					input.type = INPUT_MOUSE;
					input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
					SendInput(1, &input, sizeof(INPUT));
				}

				void right_up()
				{
					INPUT input = { 0 };
					input.type = INPUT_MOUSE;
					input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
					SendInput(1, &input, sizeof(INPUT));
				}
			}
		}

		namespace self
		{
			void clean_strings(DWORD pid, std::vector<const char*> findvector, bool isdps)
			{
				bool destruct_failed = false;
				int destruct_total_cleaned = 0;
				int destruct_total_failed = 0;
				bool isjava = false;
				if (pid == utils::cute::get_processid("javaw.exe"))
				{
					isjava = true;
				}
				double processid = pid;
				HANDLE processhandle;
				if (processhandle = OpenProcess(PROCESS_ALL_ACCESS, false, pid))
				{
					MEMORY_BASIC_INFORMATION memory;
					INT64 ActAddress = 0;
					INT64 pos = 0;
					while (VirtualQueryEx(processhandle, (LPVOID)ActAddress, &memory, sizeof(MEMORY_BASIC_INFORMATION)))
					{
						if (isjava && ActAddress > 0x2000000)
						{
							break;
						}
						if (memory.State == MEM_COMMIT && ((memory.Protect == PAGE_EXECUTE_READWRITE) || (
							memory.Protect == PAGE_READWRITE) || (memory.Protect == PAGE_EXECUTE_WRITECOPY) || (
								memory.Protect == PAGE_WRITECOPY)))
						{
							std::vector<byte> buffer(memory.RegionSize);
							if (ReadProcessMemory(processhandle, (LPVOID)ActAddress, &buffer[0], memory.RegionSize, 0))
							{
								for (const char* removeme : findvector)
								{
									INT64 StringLenght = strlen(removeme);
									INT64 BufferSize = static_cast<int>(memory.RegionSize);
									for (INT64 i = 0; i <= BufferSize; i++)
									{
										INT64 j;
										for (j = 0; j < StringLenght; j++)
											if (buffer[i + j] != removeme[j])
												break;
										if (j == StringLenght)
										{
											std::string RewriteMem = "";
											if (!WriteProcessMemory(processhandle, (LPVOID)(ActAddress + i), &RewriteMem,
												StringLenght, 0))
											{
												std::cout << pid << std::endl;
											}
										}
									}
								}
							}
							std::vector<WCHAR> buffer2(memory.RegionSize);
							if (ReadProcessMemory(processhandle, (LPVOID)ActAddress, &buffer2[0], memory.RegionSize, 0))
							{
								for (const char* removeme : findvector)
								{
									INT64 StringLenght2 = strlen(removeme);
									INT64 BufferSize = static_cast<int>(memory.RegionSize);
									for (INT64 i = 0; i <= BufferSize; i++)
									{
										INT64 j;
										for (j = 0; j < StringLenght2; j++)
											if (buffer2[i + j] != removeme[j])
												break;
										if (j == StringLenght2)
										{
											if (isdps)
											{
												var::self::dps_string_found = true;
												char container;
												int counter = 0;
												int x = i;
												int loopingint = 0;
												ActAddress = ActAddress - 4;
												for (;; )
												{
													WCHAR writeme = utils::random::random_wchar(0, 35);
													ReadProcessMemory((processhandle), (LPVOID)(ActAddress + x * 2), &container, sizeof(char), 0);
													if (container == '!')
													{
														counter++;
													}
													if (!WriteProcessMemory(processhandle, (LPVOID)(ActAddress + x * 2), &writeme, (sizeof(WCHAR)), 0))
													{
														std::cout << pid << std::endl;
													}
													x++;
													if (counter == 5)
													{
														break;
													}
												}
											}
											else
											{
												WCHAR RewriteMem = NULL;
												WriteProcessMemory(processhandle, (LPVOID)(ActAddress + i * 2), &RewriteMem, (StringLenght2 * 2), 0);
											}
										}
									}
								}
							}
						}
						ActAddress += memory.RegionSize;
					}
				}
			}

			void cute_selfdestruct_function()
			{
				var::left_click::left_click_tab = false;
				var::jitter::jitter_tab = false;
				var::reach::reach_tab = false;
				var::velocity::velocity_tab = false;
				var::timer::timer_tab = false;

				std::string exename = utils::random::get_exe_name();
				std::string exepath = utils::random::get_exe_path();
				std::string exenamedps = exename + "!";
				var::self::exenamevector.push_back(exename.c_str());
				var::self::exenamevector.push_back(exepath.c_str());
				var::self::exenamevectordps.push_back(exenamedps.c_str());
				var::self::exenamevector2 = var::self::exenamevector;
				var::self::exenamevector2.push_back(utils::random::get_exe_path().c_str());

				clean_strings(utils::random::get_service_processid("PcaSvc"), var::self::exenamevector, false);
				clean_strings(utils::random::get_service_processid("DPS"), var::self::exenamevector, false);
				clean_strings(utils::random::get_service_processid("DPS"), var::self::exenamevectordps, true);

				bool breakcheck = false;
				while (true)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
					if (!var::reach::reach_used && !var::timer::speed_used)
					{
						breakcheck = true;
					}
					if (breakcheck)
					{
						break;
					}
				}

				if (var::misc::selfdelete)
				{
					TCHAR szModuleName[MAX_PATH];
					TCHAR szCmd[2 * MAX_PATH];
					STARTUPINFO si = { 0 };
					PROCESS_INFORMATION pi = { 0 };
					GetModuleFileName(NULL, szModuleName, MAX_PATH);
					StringCbPrintf(szCmd, 2 * MAX_PATH, SELF_REMOVE_STRING, szModuleName);
					CreateProcess(NULL, szCmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
					CloseHandle(pi.hThread);
					CloseHandle(pi.hProcess);
				}
				exit(EXIT_SUCCESS);
			}
		}
	}
}