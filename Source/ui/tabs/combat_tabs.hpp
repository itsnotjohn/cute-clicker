namespace hud
{
	namespace combat
	{
		void left_click( )
		{
			ImGui::BeginGroupPanel( "left click", var::left_click::left_click_tab, ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ), ImVec4( 1, 1, 1, 1 ), ImVec2( 1, 1 ) );
			ImGui::PushItemWidth( 280.f );
			ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding, 1.7f );
			ImGui::PushStyleVar( ImGuiStyleVar_FramePadding, ImVec2( 0.1f, 0.1f ) );
			ImGui::Text( "minimum: %.1f", var::left_click::lmincps );
			utils::random::blatantchange( );
			ImGui::SliderFloat( "###LMin CPS", &var::left_click::lmincps, 1.f, var::left_click::maxclicks, "" );
			ImGui::Text( "maximum: %.1f", var::left_click::lmaxcps );
			ImGui::SliderFloat( "###LMax CPS", &var::left_click::lmaxcps, 1.f, var::left_click::maxclicks, "" );
			ImGui::PopStyleVar( 2 );
			utils::imgui::SpacingInt( 3 );
			ImGui::Text( "bind: " ); ImGui::SameLine( );
			ImGui::TextColored( ImVec4( 0.502, 0.502, 0.502, 1.00f ), var::left_click::key_bind_lc_text.c_str( ) );
			if ( ImGui::IsItemClicked( ) )
				var::keybindchoose = 1;
			ImGui::EndGroupPanel( );
		}

		void right_click( )
		{
			utils::imgui::SpacingInt( 2 );
			utils::imgui::Position( 53, 305 );
			ImGui::BeginGroupPanel( "right click", var::right_click::right_click_tab, ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ), ImVec4( 1, 1, 1, 1 ), ImVec2( 1, 1 ) );
			ImGui::PushItemWidth( 290.f );
			ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding, 1.7f );
			ImGui::PushStyleVar( ImGuiStyleVar_FramePadding, ImVec2( 0.1f, 0.1f ) );
			ImGui::Text( "minimum: %.1f", var::right_click::rmincps );
			ImGui::SliderFloat( "###RMin CPS", &var::right_click::rmincps, 1.f, var::right_click::maxclicks, "" );
			ImGui::Text( "maximum: %.1f", var::right_click::rmaxcps );
			ImGui::SliderFloat( "###RMax CPS", &var::right_click::rmaxcps, 1.f, var::right_click::maxclicks, "" );
			ImGui::PopStyleVar( 2 );
			utils::imgui::SpacingInt( 3 );
			ImGui::Text( "bind: " ); ImGui::SameLine( );
			ImGui::TextColored( ImVec4( 0.502, 0.502, 0.502, 1.00f ), var::right_click::key_bind_rc_text.c_str( ) );
			if ( ImGui::IsItemClicked( ) )
				var::keybindchoose = 2;
			ImGui::EndGroupPanel( );
		}

		void jitter( )
		{
			utils::imgui::SpacingInt( 2 );
			ImGui::BeginGroupPanel( "jitter", var::jitter::jitter_tab, ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ), ImVec4( 1, 1, 1, 1 ), ImVec2( 1, 1 ) );
			ImGui::TextColored( ImVec4( 0.502, 0.502, 0.502, 1.00f ), "enable" );
			if ( ImGui::IsItemHovered( ) )
			{
				ImGui::PushStyleVar( ImGuiStyleVar_WindowPadding, ImVec2( 6, 6 ) );
				ImGui::SetTooltip( "enable jitter click" );
				ImGui::PopStyleVar( );
			}
			if ( ImGui::IsItemClicked( ) )
				var::jitter::jitter_tab = !var::jitter::jitter_tab;
			ImGui::PushItemWidth( 280.f );
			ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding, 1.7f );
			ImGui::PushStyleVar( ImGuiStyleVar_FramePadding, ImVec2( 0.1f, 0.1f ) );
			ImGui::Text( "density x: %d",var::jitter::densityx );
			ImGui::SliderInt( "###density x", &var::jitter::densityx, 1, 10, "" );
			ImGui::Text( "density y: %d", var::jitter::densityy );
			ImGui::SliderInt( "###density y", &var::jitter::densityy, 1, 10, "" );
			ImGui::PopStyleVar( 2 );
			ImGui::EndGroupPanel( );
		}

		void settings( )
		{
			utils::imgui::SpacingInt( 2 );
			utils::imgui::Position( 180, 305 );
			ImGui::BeginGroupPanel( "settings", NULL, ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ), ImVec4( 1, 1, 1, 1 ), ImVec2( 1, 1 ) );
			ImGui::PushItemWidth( 200 );
			ImGui::PushStyleColor( ImGuiCol_FrameBg, ImVec4( 0.09f, 0.09f, 0.09f, 1.0f ) );
			ImGui::PushStyleColor( ImGuiCol_FrameBgHovered, ImVec4( 0.09f, 0.09f, 0.09f, 0.90 ) );
			ImGui::PushStyleColor( ImGuiCol_FrameBgActive, ImVec4( 0.09f, 0.09f, 0.09f, 0.85 ) );

			ImGui::InputTextWithHint( "###windowtitle", "null", var::settings::minecraft_title, 256 ); ImGui::SameLine( );
			if ( ImGui::Button( "Find Window" ) )
				utils::cute::getwindowname( );

			utils::imgui::SpacingInt( 1 );
			ImGui::PushItemWidth( 290 );
			ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding, 1.3f );
			ImGui::PushStyleVar( ImGuiStyleVar_FramePadding, ImVec2( 0.999995f, 0.999995f ) );

			ImGui::PushStyleColor( ImGuiCol_FrameBg, ImVec4( 0.15f, 0.15f, 0.15f, 1.0f ) );
			ImGui::PushStyleColor( ImGuiCol_FrameBgHovered, ImVec4( 0.15f, 0.15f, 0.15f, 0.90 ) );
			ImGui::PushStyleColor( ImGuiCol_FrameBgActive, ImVec4( 0.15f, 0.15f, 0.15f, 0.85 ) );

			ImGui::Checkbox( "Inventory", &var::settings::inventory );
			ImGui::Checkbox( "BlockBlock", &var::settings::humanized );
			ImGui::Checkbox( "Blatant", &var::settings::coming_soon );
			if (ImGui::IsItemHovered())
				utils::imgui::CustomTooltip("coming soon...");

			ImGui::PopStyleColor( 6 );	ImGui::PopStyleVar( 2 );
			ImGui::EndGroupPanel( );
		}

		void throwpot( )
		{
			utils::imgui::SpacingInt( 2 );
			ImGui::BeginGroupPanel( "throwpot", NULL, ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ), ImVec4( 1, 1, 1, 1 ), ImVec2( 1, 1 ) );

			ImGui::Text("select potion slots");

			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 1.3f);
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.999995f, 0.999995f));

			ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
			ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.15f, 0.15f, 0.15f, 0.90));
			ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.15f, 0.15f, 0.15f, 0.85));

			for (int i = 0; i < 9; i++)
			{
				ImGui::Checkbox(std::string("##slot" + std::to_string(i)).c_str(), &var::throwp::slot[i]);
				ImGui::SameLine();
			}

			ImGui::PopStyleVar(2); ImGui::PopStyleColor(3);

			ImGui::Spacing();

			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 1.3f);
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.999995f, 0.999995f));

			ImGui::Text("delay: %.0f ms", var::throwp::delaypot);
			ImGui::PushItemWidth(280.f);
			ImGui::SliderFloat("###delay throwpot", &var::throwp::delaypot, 30.f, 150.f, "");
			
			ImGui::Spacing();

			ImGui::Text("return slot: %.0f", var::throwp::return_pos);
			ImGui::SliderFloat(("###returnslot"), &var::throwp::return_pos, 1.f, 9.f, "");

			ImGui::Spacing();

			ImGui::Checkbox(("Drop item"), &var::throwp::throw_item);

			utils::imgui::SpacingInt(3);

			ImGui::Text("bind: "); ImGui::SameLine();

			ImGui::TextColored(ImVec4(0.502, 0.502, 0.502, 1.00f), var::throwp::key_bind_throwpot_text.c_str());
			if (ImGui::IsItemClicked())
				var::keybindchoose = 4;

			ImGui::PopStyleVar(2);

			ImGui::EndGroupPanel( );
		}

		void throwpearl( )
		{
			utils::imgui::Position( 297, 305 );
			ImGui::BeginGroupPanel( "throwpearl", NULL, ImVec4( var::misc::color[ 0 ], var::misc::color[ 1 ], var::misc::color[ 2 ], var::misc::color[ 3 ] ), ImVec4( 1, 1, 1, 1 ), ImVec2( 1, 1 ) );

			ImGui::PushStyleColor( ImGuiCol_FrameBg, ImVec4( 0.08f, 0.08f, 0.08f, 1.0f ) );
			ImGui::PushStyleColor( ImGuiCol_FrameBgHovered, ImVec4( 0.08f, 0.08f, 0.08f, 0.90 ) );
			ImGui::PushStyleColor( ImGuiCol_FrameBgActive, ImVec4( 0.08f, 0.08f, 0.08f, 0.85 ) );
			ImGui::Text( "sword slot" );
			//ImGui::InputInt( "###sword slott", &var::throwpl::swordslot );

			ImGui::Text( "perl slot" );
			ImGui::InputInt( "###perl slot", &var::throwpl::perlslot );
			ImGui::PopStyleColor( 3 );

			ImGui::PushItemWidth( 290.f );
			ImGui::PushStyleVar( ImGuiStyleVar_FrameRounding, 1.7f );
			ImGui::PushStyleVar( ImGuiStyleVar_FramePadding, ImVec2( 0.1f, 0.1f ) );
			ImGui::Text( "delay: %.0f ms", var::throwpl::delaypearl );
			ImGui::SliderFloat( "###delay throwpearl", &var::throwpl::delaypearl, 30.f, 150.f, "" );
			ImGui::PopStyleVar( 2 );

			utils::imgui::SpacingInt( 3 );
			ImGui::Text( "bind: " ); ImGui::SameLine( );
			ImGui::TextColored( ImVec4( 0.502, 0.502, 0.502, 1.00f ), var::throwp::key_bind_throwpearl_text.c_str( ) );
			if ( ImGui::IsItemClicked( ) )
				var::keybindchoose = 5;
			ImGui::EndGroupPanel( );
		}

		void combat_tabs( )
		{
			hud::combat::left_click( );
			hud::combat::right_click( );
			hud::combat::jitter( );
			hud::combat::settings( );
			hud::combat::throwpot( );
			hud::combat::throwpearl( );
		}
	}
}