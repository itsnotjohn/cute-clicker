namespace hud
{
	namespace memory
	{
		void reach( )
		{
			ImGui::BeginGroupPanel( "reach", var::reach::reach_tab, ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ), ImVec4( 1, 1, 1, 1 ), ImVec2( 1, 1 ) );
			ImGui::TextColored( ImVec4( 0.502, 0.502, 0.502, 1.00f ), "enable" );
			if ( ImGui::IsItemHovered( ) )
			{
				ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, ImVec2( 6, 6 ) );
				ImGui::SetTooltip( "enable reach" );
				ImGui::PopStyleVar( );
			}
			if ( ImGui::IsItemClicked( ) )
				var::reach::reach_tab = !var::reach::reach_tab;
			ImGui::PushItemWidth( 280.f );
			ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding, 1.7f );
			ImGui::PushStyleVar( ImGuiStyleVar_FramePadding, ImVec2( 0.1f, 0.1f ) );
			ImGui::Text( "distance: %.2f", var::reach::distance );
			ImGui::SliderFloat( "###Reach", &var::reach::distance, 3.0f, 6.0f, "" );
			ImGui::PopStyleVar( 2 );
			utils::imgui::SpacingInt( 3 );
			ImGui::Text( "bind: " ); ImGui::SameLine( );
			ImGui::TextColored( ImVec4( 0.502, 0.502, 0.502, 1.00f ), var::reach::key_reach_hide_text.c_str( ) );
			if ( ImGui::IsItemClicked( ) )
				var::keybindchoose = 1;
			ImGui::EndGroupPanel( );
		}

		void velocity( )
		{
			utils::imgui::SpacingInt( 2 );
			utils::imgui::Position( 53, 305 );
			ImGui::BeginGroupPanel( "velocity", var::velocity::velocity_tab, ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ), ImVec4( 1, 1, 1, 1 ), ImVec2( 1, 1 ) );
			ImGui::TextColored( ImVec4( 0.502, 0.502, 0.502, 1.00f ), "enable" );
			if ( ImGui::IsItemHovered( ) )
			{
				ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, ImVec2( 6, 6 ) );
				ImGui::SetTooltip( "enable velocity" );
				ImGui::PopStyleVar( );
			}
			if ( ImGui::IsItemClicked( ) )
				var::velocity::velocity_tab = !var::velocity::velocity_tab;
			ImGui::PushItemWidth( 290.f );
			ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding, 1.7f );
			ImGui::PushStyleVar( ImGuiStyleVar_FramePadding, ImVec2( 0.1f, 0.1f ) );
			ImGui::Text( "horizontal: %.2f", var::velocity::velocity );
			ImGui::SliderFloat( "###Velocity", &var::velocity::velocity, 1.00f, 100.00f, "" );
			ImGui::PopStyleVar( 2 );
			utils::imgui::SpacingInt( 3 );
			ImGui::Text( "bind: " ); ImGui::SameLine( );
			ImGui::TextColored( ImVec4( 0.502, 0.502, 0.502, 1.00f ), var::right_click::key_bind_rc_text.c_str( ) );
			if ( ImGui::IsItemClicked( ) )
				var::keybindchoose = 2;
			ImGui::EndGroupPanel( );
		}

		void timer( )
		{
			utils::imgui::SpacingInt( 2 );
			ImGui::BeginGroupPanel( "timer", var::timer::timer_tab, ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ), ImVec4( 1, 1, 1, 1 ), ImVec2( 1, 1 ) );
			ImGui::TextColored( ImVec4( 0.502, 0.502, 0.502, 1.00f ), "enable" );
			if ( ImGui::IsItemHovered( ) )
			{
				ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, ImVec2( 6, 6 ) );
				ImGui::SetTooltip( "enable timer" );
				ImGui::PopStyleVar( );
			}
			if ( ImGui::IsItemClicked( ) )
				var::timer::timer_tab = !var::timer::timer_tab;
			ImGui::PushItemWidth( 280.f );
			ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding, 1.7f );
			ImGui::PushStyleVar( ImGuiStyleVar_FramePadding, ImVec2( 0.1f, 0.1f ) );
			ImGui::Text( "speed: %.2f", var::timer::timer_speed ); ImGui::SameLine( );
			ImGui::TextColored( ImVec4( 0.502, 0.502, 0.502, 1.00f ), "[?]" );
			if ( ImGui::IsItemHovered( ) )
			{
				ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, ImVec2( 6, 6 ) );
				ImGui::SetTooltip( "to put a different value on the timer, press \"enable\" again" );
				ImGui::PopStyleVar( );
			}
			ImGui::SliderFloat( "###speedtimer", &var::timer::timer_speed, -1.0f, 1.0f, "" );
			ImGui::PopStyleVar( 2 );
			ImGui::EndGroupPanel( );
		}

		void memory_tabs( )
		{
			hud::memory::reach( );
			hud::memory::velocity( );
			hud::memory::timer( );
		}
	}
}