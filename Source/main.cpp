#include "include.h"

auto _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) -> int
{
	std::atexit(utils::cute::self::cute_selfdestruct_function);

	_beginthreadex(nullptr, 0, (_beginthreadex_proc_type)&utils::cute::hook::hooking, nullptr, 0, nullptr);
	_beginthreadex(nullptr, 0, (_beginthreadex_proc_type)modules::clicker::leftclick_thread, nullptr, 0, nullptr);
	_beginthreadex(nullptr, 0, (_beginthreadex_proc_type)modules::clicker::rightclick_thread, nullptr, 0, nullptr);
	_beginthreadex(nullptr, 0, (_beginthreadex_proc_type)modules::clicker::throwpot_thread, nullptr, 0, nullptr);
	_beginthreadex(nullptr, 0, (_beginthreadex_proc_type)modules::clicker::throwpearl_thread, nullptr, 0, nullptr);

	var::reach::handle_reach = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)combat::thread::thread_reach, nullptr, 0, 0);
	var::velocity::handle_velocity = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)combat::thread::thread_velocity, nullptr, 0, 0);
	var::timer::handle_timer = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)thread_speed, nullptr, 0, 0);

	if (!glfwInit())
		return EXIT_FAILURE;
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	GLFWwindow* window = glfwCreateWindow(611, 511, xorstr(""), NULL, NULL);
	if (window == NULL)
		return EXIT_FAILURE;

	glfwMakeContextCurrent(window);
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL2_Init();

	utils::imgui::glfwSetWindowCenter(window);

	ImGuiIO& io = ImGui::GetIO(); (void)io; io.IniFilename = nullptr;

	fonts fonte;

	ImFont* cute_default_font = io.Fonts->AddFontFromMemoryCompressedTTF(fonte.getFontBytes(), fonte.getFontSize(), 15.0f);
	ImFont* cute_default_font_big = io.Fonts->AddFontFromMemoryCompressedTTF(fonte.getFontBytes(), fonte.getFontSize(), 17.0f);
	ImFont* cute_default_font_small = io.Fonts->AddFontFromMemoryCompressedTTF(fonte.getFontBytes(), fonte.getFontSize(), 10.0f);

	font_icon icon;

	ImFont* cute_icon_font = io.Fonts->AddFontFromMemoryCompressedTTF(icon.getFontBytes(), icon.getFontSize(), 15.0f);
	ImFont* cute_icon_font_big = io.Fonts->AddFontFromMemoryCompressedTTF(icon.getFontBytes(), icon.getFontSize(), 35.0f);

	while (!glfwWindowShouldClose(window))
	{
		ui::render::styles(io);
		utils::random::fixf();
		utils::cute::keybindsystem();

		glfwPollEvents();
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::SetNextWindowPos(ImVec2(-3, -15));
		ImGui::SetNextWindowSize(ImVec2(919, 600));
		ImGui::Begin(xorstr("###background"), NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);

		bool authentication = true;
		if (!authentication)
		{
			glfwSetWindowSize(window, 280, 50);
			ImGui::PushFont(cute_default_font_big);
			ImGui::TextColored(ImVec4(1.00f, 0.331f, 0.331f, 1.00f), xorstr("Authentication Failure")); ImGui::SameLine(150);
			ImGui::Text(xorstr(", try again.\n"));
			ImGui::Text("Your HWID has been copied to Clipboard.");
			ImGui::PopFont();
		}

		hud::initial(cute_default_font_big, cute_default_font);

		switch (var::tabs::switchtabs)
		{
		case 1:
			hud::combat::combat_tabs();

			utils::imgui::Position(505, 552);
			hud::tabs();
			break;
		case 2:
			hud::memory::memory_tabs();

			utils::imgui::Position(505, 552);
			hud::tabs();
			break;
		case 3:
			hud::misc::misc_tabs();

			utils::imgui::Position(505, 552);
			hud::tabs();
			break;
		}

		utils::cute::cute_rainbow_mode();

		ImGui::End();
		ImGui::Render();

		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
		glfwMakeContextCurrent(window);
		glfwSwapBuffers(window);

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(window);
	glfwTerminate();
}
