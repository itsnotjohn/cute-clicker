namespace hud
{
	namespace misc
	{
		void self_destruct_tab()
		{
			ImGui::BeginGroupPanel("misc", NULL, ImVec4(var::misc::color[0], var::misc::color[1], var::misc::color[2], var::misc::color[3]), ImVec4(1, 1, 1, 1), ImVec2(1, 1));
			ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 1.3f);
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.1f, 0.1f));

			ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
			ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.15f, 0.15f, 0.15f, 0.90));
			ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.15f, 0.15f, 0.15f, 0.85));

			ImGui::Checkbox("Self Delete", &var::misc::selfdelete); ImGui::SameLine();
			ImGui::TextColored(ImVec4(0.502, 0.502, 0.502, 1.00f), "[?]");
			if (ImGui::IsItemHovered())
			{
				ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(6, 6));
				ImGui::SetTooltip("delete this executable");
				ImGui::PopStyleVar();
			}
			utils::imgui::SpacingInt(2);
			ImGui::PushItemWidth(290);
			ImGui::Text("change gui color");

			ImGui::Spacing();
			ImGui::Checkbox("rainbow", &var::misc::rainbow);
			if (ImGui::IsItemHovered())
			{
				ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(6, 6));
				ImGui::SetTooltip("enable rainbow mode");
				ImGui::PopStyleVar();
			}

			ImGui::TextColored(ImVec4(0.502, 0.502, 0.502, 1.00f), "[reset color]");
			if (ImGui::IsItemHovered())
			{
				ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(6, 6));
				ImGui::SetTooltip("press to reset color");
				ImGui::PopStyleVar();

				if (ImGui::IsItemClicked())
				{
					var::misc::color[0] = 1.00f,
						var::misc::color[1] = 0.451,
						var::misc::color[2] = 0.451,
						var::misc::color[3] = 1.00f;
				}
			}
			ImGui::PushItemWidth(240.f);
			ImGui::ColorPicker3("###color", var::misc::color, COLOR_FLAGS);

			utils::imgui::SpacingInt(3);
			ImGui::Text("hide: "); ImGui::SameLine();
			ImGui::TextColored(ImVec4(0.502, 0.502, 0.502, 1.00f), var::misc::key_bind_hide_text.c_str());
			if (ImGui::IsItemClicked())
				var::keybindchoose = 3;

			ImGui::PopStyleVar(2); ImGui::PopStyleColor(3);
			ImGui::EndGroupPanel();
		}

		void misc_tabs()
		{
			hud::misc::self_destruct_tab();
		}
	}
}