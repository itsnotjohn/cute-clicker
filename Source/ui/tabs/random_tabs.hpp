namespace hud
{
	void initial( ImFont* bigfont, ImFont* smallfont )
	{
		utils::imgui::SpacingInt( 3 );
		ImGui::PushFont( bigfont );
		ImGui::PushFont( smallfont );
		ImGui::Text( "%d clicks", var::left_click::counter );
		if ( ImGui::IsItemHovered( ) )
		{
			ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, ImVec2( 6, 6 ) );
			ImGui::SetTooltip( "press to reset counter clicks" );
			ImGui::PopStyleVar( );
		}
		if ( ImGui::IsItemClicked( ) )
			var::left_click::counter = 0;
		ImGui::PopFont( );
		ImGui::SameLine( );
		utils::imgui::TextColoredInt( "cute.surf", 585, ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ) ); 
		if ( ImGui::IsItemHovered( ) )
		{
			ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, ImVec2( 6, 6 ) );
			ImGui::SetTooltip( "by tenebroso" );
			ImGui::PopStyleVar( );
		}
		utils::imgui::SpacingInt( 2 );
		ImGui::Separator( );
		ImGui::PopFont( );
	}

	void tabs( )
	{
		ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding, 1.3f );
		ImGui::PushStyleVar( ImGuiStyleVar_FramePadding, ImVec2( 0.1f, 0.1f ) );

		ImGui::PushStyleColor( ImGuiCol_FrameBg, ImVec4( 0.251, 0.251, 0.251, 0.5f ) ); //Background
		ImGui::PushStyleColor( ImGuiCol_FrameBgHovered, ImVec4( 0.251, 0.251, 0.251, 1.0f ) ); //Background
		ImGui::PushStyleColor( ImGuiCol_FrameBgActive, ImVec4( 0.251, 0.251, 0.251, 0.5f ) ); //Background

		//combat
		if ( ImGui::Checkbox( xorstr( "###combat" ), &var::tabs::combat_tab ) )
		{
			var::tabs::switchtabs = 1;
			var::tabs::combat_tab = true;
			var::tabs::memory_tab = false;
			var::tabs::misc_tab = false;
		}
		ImGui::SameLine( );

		//memory
		if ( ImGui::Checkbox( xorstr( "###memory" ), &var::tabs::memory_tab ) )
		{
			var::tabs::switchtabs = 2;
			var::tabs::combat_tab = false;
			var::tabs::memory_tab = true;
			var::tabs::misc_tab = false;
		}
		ImGui::SameLine( );

		//misc
		if ( ImGui::Checkbox( xorstr( "###misc" ), &var::tabs::misc_tab ) )
		{
			var::tabs::switchtabs = 3;
			var::tabs::combat_tab = false;
			var::tabs::memory_tab = false;
			var::tabs::misc_tab = true;

		}
		ImGui::PopStyleColor( 3 );
		ImGui::PopStyleVar( 2 );
	}
}