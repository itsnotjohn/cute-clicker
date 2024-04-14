namespace ui
{
	namespace render
	{
		void styles( ImGuiIO &io )
		{
			ImGuiStyle *style = &ImGui::GetStyle( );

			//style->Alpha = 1.0f;
			//style->WindowPadding = ImVec2( 0, 0 );
			//style->WindowRounding = 0.0f;
			//style->FramePadding = ImVec2( 5, 5 );
			//style->FrameRounding = 2.0f;
			//style->ItemSpacing = ImVec2( 5, 5 );
			//style->ItemInnerSpacing = ImVec2( 5, 5 );
			//style->IndentSpacing = 10.0f;
			//style->TouchExtraPadding = ImVec2( 5, 5 );
			//style->ScrollbarSize = 13.0f;
			//style->ScrollbarRounding = 15.0f;
			//style->GrabMinSize = 10.0f;
			//style->GrabRounding = 2.0f;
			//style->ColumnsMinSpacing = 10.0f;
			//style->WindowBorderSize = 0;

			/*style->FramePadding = ImVec2( 5, 5 );
			style->ItemSpacing = ImVec2( 5, 3 );
			style->WindowBorderSize = 0;
			style->IndentSpacing = 15.0f;

			style->WindowPadding = ImVec2( 7, 15 );
			style->WindowRounding = 0.0f;
			style->ScrollbarSize = 15.0f;
			style->ScrollbarRounding = 9.0f;

			style->Colors[ ImGuiCol_Text ] = ImVec4( 1.f, 1.f, 1.f, 1.f );
			style->Colors[ ImGuiCol_TextDisabled ] = ImVec4( 1.00f, 1.00f, 1.00f, 0.57f );

			style->Colors[ ImGuiCol_WindowBg ] = ImVec4( 0.02f, 0.02f, 0.02f, 1.00f ); //begin color

			style->Colors[ ImGuiCol_ChildWindowBg ] = ImVec4( 0.02f, 0.02f, 0.02f, 1.f ); //child begin color

			style->Colors[ ImGuiCol_PopupBg ] = ImVec4( 0.02f, 0.02f, 0.02f, 0.90f );

			style->Colors[ ImGuiCol_Border ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			style->Colors[ ImGuiCol_BorderShadow ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );

			style->Colors[ ImGuiCol_FrameBg ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ); //Background
			style->Colors[ ImGuiCol_FrameBgHovered ] = ImVec4(var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ); //Background
			style->Colors[ ImGuiCol_FrameBgActive ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ); //Background

			style->Colors[ ImGuiCol_TitleBg ] = ImVec4( 0.008f, 0.008f, 0.008f, 1.00f );
			style->Colors[ ImGuiCol_TitleBgCollapsed ] = ImVec4( 0.008f, 0.008f, 0.008f, 1.00f );
			style->Colors[ ImGuiCol_TitleBgActive ] = ImVec4( 0.008f, 0.008f, 0.008f, 1.00f );

			style->Colors[ ImGuiCol_MenuBarBg ] = ImVec4( 0.14f, 0.28f, 0.34f, 0.57f );

			style->Colors[ ImGuiCol_ScrollbarBg ] = ImVec4( 0.20f, 0.34f, 0.39f, 1.00f );
			style->Colors[ ImGuiCol_ScrollbarGrab ] = ImVec4( 0.19f, 0.50f, 0.63f, 0.31f );
			style->Colors[ ImGuiCol_ScrollbarGrabHovered ] = ImVec4( 0.19f, 0.50f, 0.63f, 0.78f );
			style->Colors[ ImGuiCol_ScrollbarGrabActive ] = ImVec4( 0.19f, 0.50f, 0.63f, 1.00f );

			style->Colors[ ImGuiCol_CheckMark ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );

			style->Colors[ ImGuiCol_SliderGrab ] = ImVec4( 0.204f, 0.596f, 0.859f, 1.00f );
			style->Colors[ ImGuiCol_SliderGrabActive ] = ImVec4( 0.906f, 0.298f, 0.235f, 0.2f );

			style->Colors[ ImGuiCol_Button ] = ImVec4( 0.341f, 0.f, 0.624f, 1.0f );
			style->Colors[ ImGuiCol_ButtonHovered ] = ImVec4( 0.341f, 0.f, 0.624f, 0.9f );
			style->Colors[ ImGuiCol_ButtonActive ] = ImVec4( 0.341f, 0.f, 0.624f, 0.8f );

			style->Colors[ ImGuiCol_Header ] = ImVec4( 0.33f, 0.63f, 0.74f, 0.76f );
			style->Colors[ ImGuiCol_HeaderHovered ] = ImVec4( 0.20f, 0.48f, 0.61f, 0.86f );
			style->Colors[ ImGuiCol_HeaderActive ] = ImVec4( 0.19f, 0.50f, 0.63f, 1.00f );

			style->Colors[ ImGuiCol_Separator ] = ImVec4( 1.00f, 1.00f, 1.00f, 1.f );
			style->Colors[ ImGuiCol_SeparatorHovered ] = ImVec4( 1.00f, 1.00f, 1.00f, 0.78f );
			style->Colors[ ImGuiCol_SeparatorActive ] = ImVec4( 1.00f, 1.00f, 1.00f, 1.00f );

			style->Colors[ ImGuiCol_ResizeGrip ] = ImVec4( 0.19f, 0.50f, 0.63f, 0.20f );
			style->Colors[ ImGuiCol_ResizeGripHovered ] = ImVec4( 0.19f, 0.50f, 0.63f, 0.78f );
			style->Colors[ ImGuiCol_ResizeGripActive ] = ImVec4( 0.19f, 0.50f, 0.63f, 1.00f );

			style->Colors[ ImGuiCol_PlotLines ] = ImVec4( 0.85f, 0.90f, 0.92f, 0.63f );
			style->Colors[ ImGuiCol_PlotLinesHovered ] = ImVec4( 0.19f, 0.50f, 0.63f, 1.00f );
			style->Colors[ ImGuiCol_PlotHistogram ] = ImVec4( 0.85f, 0.90f, 0.92f, 0.63f );
			style->Colors[ ImGuiCol_PlotHistogramHovered ] = ImVec4( 0.19f, 0.50f, 0.63f, 1.00f );

			style->Colors[ ImGuiCol_TextSelectedBg ] = ImVec4( 0.19f, 0.50f, 0.63f, 0.43f );

			style->Colors[ ImGuiCol_ModalWindowDarkening ] = ImVec4( 0.20f, 0.20f, 0.20f, 0.35f );*/

			style->FramePadding = ImVec2( 5, 5 );
			style->ItemSpacing = ImVec2( 5, 3 );
			style->WindowBorderSize = 0;
			style->IndentSpacing = 15.0f;

			style->WindowPadding = ImVec2( 7, 15 );
			style->WindowRounding = 0.0f;
			style->ScrollbarSize = 15.0f;
			style->ScrollbarRounding = 9.0f;

			ImVec4 *colors = style->Colors;

			colors[ ImGuiCol_MenuBarBg ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_ChildBg ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_Border ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_CheckMark ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_SliderGrab ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_SliderGrabActive ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_FrameBg ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_FrameBgActive ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_FrameBgHovered ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_Button ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_ButtonHovered ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_ButtonActive ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
			colors[ ImGuiCol_TextSelectedBg ] = ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] );
		}
	}
/*		void render( GLFWwindow *window )
		{
			ImGuiIO &io = ImGui::GetIO( ); ( void ) io;
			io.IniFilename = nullptr;

			fonts fonte;

			ImFont *cute_default_font = io.Fonts->AddFontFromMemoryCompressedTTF( fonte.getFontBytes( ), fonte.getFontSize( ), 15.0f );
			ImFont *cute_default_font_big = io.Fonts->AddFontFromMemoryCompressedTTF( fonte.getFontBytes( ), fonte.getFontSize( ), 17.0f );

			font_icon icon;

			ImFont *cute_icon_font = io.Fonts->AddFontFromMemoryCompressedTTF( icon.getFontBytes( ), icon.getFontSize( ), 15.0f );
			ImFont *cute_icon_font_big = io.Fonts->AddFontFromMemoryCompressedTTF( icon.getFontBytes( ), icon.getFontSize( ), 35.0f );

			while ( !glfwWindowShouldClose( window ) )
			{
				ui::render::styles( io );
				glfwPollEvents( );
				ImGui_ImplOpenGL2_NewFrame( );
				ImGui_ImplGlfw_NewFrame( );
				ImGui::NewFrame( );

				ImGui::SetNextWindowPos( ImVec2( -3, -15 ) );
				ImGui::SetNextWindowSize( ImVec2( 906, 600 ) );
				ImGui::Begin( xorstr( "###background" ), NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar );

				if ( var::auth::cute_logged = true )
				{
					utils::color::text( cute_icon_font_big );
					switch ( var::tabs::switchtabs )
					{
						case 1:
							hud::combat( );
							break;
						case 2:
							hud::movement( );
							break;
						case 3:
							hud::misc( );
							break;
						case 4:
							hud::destruct( );
							break;
					}
				}
				else
				{
					ImGui::PushFont( cute_default_font_big );
					ImGui::TextColored( ImVec4( 1.00f, 0.331f, 0.331f, 1.00f ), xorstr( "Not Authenticated") ); ImGui::SameLine( 125 );
					ImGui::Text( xorstr( ", try again.\n" ) );
					ImGui::Text( "Your HWID has been copied to Clipboard." );
					ImGui::PopFont( );
				}
				ImGui::End( );
				ImGui::Render( );

				ImGui_ImplOpenGL2_RenderDrawData( ImGui::GetDrawData( ) );
				glfwMakeContextCurrent( window );
				glfwSwapBuffers( window );
			}
			ImGui_ImplOpenGL2_Shutdown( );
			ImGui_ImplGlfw_Shutdown( );
			ImGui::DestroyContext( );
			glfwDestroyWindow( window );
			glfwTerminate( );
		}
	}

	namespace device
	{
		void content( GLFWwindow *window )
		{
			glfwMakeContextCurrent( window );
			ImGui::CreateContext( );

			ImGui_ImplGlfw_InitForOpenGL( window, true );
			ImGui_ImplOpenGL2_Init( );
		}

		bool create( )
		{
			if ( !glfwInit( ) )
				return EXIT_FAILURE;
			glfwWindowHint( GLFW_RESIZABLE, GLFW_FALSE );
			GLFWwindow *window = glfwCreateWindow( 900, 500, xorstr( "" ), NULL, NULL );
			if ( window == NULL )
				return EXIT_FAILURE;

			utils::imgui::glfwSetWindowCenter( window );

			device::content( window );

			render::render( window );
		}
	}*/
}