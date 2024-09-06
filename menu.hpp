#include "includes.h"
#include "visuals.hpp"
#include <thread>
#include <chrono>
#include <time.h>
#include "fonts.h"
#include "icon.h"
#include "colors.h"
#include <string>
#include <tchar.h>
#include <tchar.h>
#include <string>
#include <tchar.h>
#include <d3dx11.h>
#pragma comment(lib, "d3dx11.lib")
#include "imgui/imgui_freetype.h"
#include "imgui/imgui_internal.h"
#pragma comment(lib, "freetype.lib")

//op
#include "pathfinder.h"
#include "revenat.h"
#include "seer.h"
#include "maggie.h"
#include "Bangladesh.h"
#include "Bloodhound.h"
#include "Catalyst.h"
#include "Fuse.h"
#include "Gibraltar.h"
#include "newcastle.h"
#include "Wattson.h"
#include "Wraith.h"
#include "ash.h"
#include "Ballistic.h"
#include "Caustic.h"
#include "Crypto.h"
#include "Lifeline.h"
#include "Loba.h"
#include "Mirage.h"
#include "Octane.h"
#include "Valk.h"
#include "Vantage.h"
#include "Rampart.h"
#include "horizon.h"
//op
int menukey = VK_INSERT;
int menustate;

float pa, pb, pc, pd;
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool watermark = false;
Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
//MENU SHIT

int m_tab_count = 0;
int m_active_tab = 0;
float m_tab_alpha = 1.f;
float m_tab_add = 0.f;
float m_tab_checkmark = 0.f;
float color[4] = { 0.345f, 0.094f, 0.400f, 1.000f };


ImFont* ubuntu_bold_font = nullptr;
ImFont* ubuntu_medium_font = nullptr;
ImFont* ubuntu_regular_font = nullptr;
ImFont* expand_font = nullptr;

ID3D11ShaderResourceView* aimbot_texture = nullptr;
ID3D11ShaderResourceView* players_texture = nullptr;
ID3D11ShaderResourceView* world_texture = nullptr;
ID3D11ShaderResourceView* skins_texture = nullptr;
ID3D11ShaderResourceView* settings_texture = nullptr;
ID3D11ShaderResourceView* icon_texture = nullptr;

///////////////////////////////////////////////
float fps;
void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;   // fix mouse issue?

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);

	ImFontConfig cfg;

	cfg.FontBuilderFlags = ImGuiFreeTypeBuilderFlags_ForceAutoHint | ImGuiFreeTypeBuilderFlags_Bitmap;
	ubuntu_bold_font = io.Fonts->AddFontFromMemoryTTF(ubuntu_bold, sizeof ubuntu_bold, 16.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	ubuntu_medium_font = io.Fonts->AddFontFromMemoryTTF(ubuntu_medium, sizeof ubuntu_medium, 14.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	ubuntu_regular_font = io.Fonts->AddFontFromMemoryTTF(ubuntu_regular, sizeof ubuntu_regular, 14.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	expand_font = io.Fonts->AddFontFromMemoryTTF(expand_binary, sizeof expand_binary, 10.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	esp_font = io.Fonts->AddFontFromMemoryTTF(espfontptr, sizeof espfontptr, 12.f);
	io.MouseDrawCursor = false;
}
void HelpMarker(const char* desc) {
	ImGui::TextDisabled(("[?]"));
	if (ImGui::IsItemHovered()) {
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();

	}
}

bool drawmenu = true;

bool showMouse = false;

bool weaponScreen = false;
bool attachmentsScreen = false;
bool armorScreen = false;
bool otherScreen = false;

bool IsKeyDown(int vk)
{
	return (GetAsyncKeyState(vk) & 0x8000) != 0;
}

void Keybind(const char* label, int* key, int* mode)
{
	ImGui::Text(label);
	ImGui::SameLine();

	// Display the current key
	ImGui::Text("[Key: %d]", *key);

	// Display the current mode
	ImGui::Text("[Mode: %d]", *mode);

	// Check if this control is active (clicked on)
	if (ImGui::IsItemHovered())
	{
		ImGui::SetTooltip("Click to change key binding");
	}

	// Capture the key press event
	if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
	{
		// Set a flag to capture next key press
		*mode = 1;
	}

	// Capture the key event and set the key value
	if (*mode == 1)
	{
		for (int i = 0; i < IM_ARRAYSIZE(ImGui::GetIO().KeysDown); i++)
		{
			if (IsKeyDown(i))
			{
				*key = i;
				*mode = 0;
				break;
			}
		}
	}
}

bool Tab(const char* label, bool isSelected, int& tabSelected)
{
	if (ImGui::Button(label))
	{
		tabSelected = isSelected ? tabSelected : (tabSelected + 1);
		return true;
	}
	return false;
}

bool MultiCombo(const char* label, bool* selected, const char* const* items, int items_count, int& active_tab)
{
	bool changed = false;
	if (ImGui::CollapsingHeader(label))
	{
		ImGui::Indent();

		for (int i = 0; i < items_count; ++i)
		{
			if (ImGui::Selectable(items[i], selected[i]))
			{
				selected[i] = !selected[i];
				changed = true;
			}
		}

		ImGui::Unindent();
	}

	return changed;
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
void DrawCross(float x, float y, float width, float height, ImColor col) {
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x - width, y), ImVec2(x + width, y), col, 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(y - height, x), ImVec2(y + height, x), col, 3);
}
inline float dax = 0.0f, day = 3.0f;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}
	
	if (GetAsyncKeyState(menukey) & 0x1)
	{
		drawmenu = !drawmenu;
	}
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (GetAsyncKeyState(VK_NUMPAD1) & 0x1 || GetAsyncKeyState(0x05) & 0x1)
	{
		showMouse = !showMouse;
	}

	/*if (!showMouse)
		ImGui::SetMouseCursor(ImGuiMouseCursor_None);*/

	D3DX11_IMAGE_LOAD_INFO info; ID3DX11ThreadPump* pump{ nullptr };

	if (aimbot_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, aimbot_binary, sizeof(aimbot_binary), &info, pump, &aimbot_texture, 0);
	if (players_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, players_binary, sizeof(players_binary), &info, pump, &players_texture, 0);
	if (skins_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, skins_binary, sizeof(skins_binary), &info, pump, &skins_texture, 0);
	if (skins_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, skins_binary, sizeof(skins_binary), &info, pump, &skins_texture, 0);
	if (settings_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, settings_binary, sizeof(settings_binary), &info, pump, &settings_texture, 0);
	if (icon_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, ICONBYTE, sizeof(ICONBYTE), &info, pump, &icon_texture, 0);

	//oprevenat_texture
	if (PathFinder_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, PathFinder, sizeof(PathFinder), &info, pump, &PathFinder_texture, 0);

	if (revenat_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, RevenantData, sizeof(RevenantData), &info, pump, &revenat_texture, 0);

	if (seer_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, SeerData, sizeof(SeerData), &info, pump, &revenat_texture, 0);

	if (Maggie_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, MaggieData, sizeof(MaggieData), &info, pump, &revenat_texture, 0);

	if (Bangladesh_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, BangladeshData, sizeof(BangladeshData), &info, pump, &Bangladesh_texture, 0);

	if (bloodhound_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, BloodhoundData, sizeof(BloodhoundData), &info, pump, &bloodhound_texture, 0);

	if (catalyst_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, CatalystData, sizeof(CatalystData), &info, pump, &catalyst_texture, 0);

	if (Fuse_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, FuseData, sizeof(FuseData), &info, pump, &Fuse_texture, 0);

	if (Gibraltar_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, GibraltarData, sizeof(GibraltarData), &info, pump, &Gibraltar_texture, 0);

	if (newcastle_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, newcastleData, sizeof(newcastleData), &info, pump, &newcastle_texture, 0);

	if (wattson_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, WattsonData, sizeof(WattsonData), &info, pump, &wattson_texture, 0);

	if (wraith_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, WraithData, sizeof(WraithData), &info, pump, &wraith_texture, 0);

	if (ash_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, ashData, sizeof(ashData), &info, pump, &ash_texture, 0);

	if (ballistic_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, BallisticData, sizeof(BallisticData), &info, pump, &ballistic_texture, 0);

	if (caustic_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, CausticData, sizeof(CausticData), &info, pump, &caustic_texture, 0);

	if (crypto_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, CryptoData, sizeof(CryptoData), &info, pump, &crypto_texture, 0);

	if (lifeline_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, LifeLineData, sizeof(LifeLineData), &info, pump, &lifeline_texture, 0);

	if (loba_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, LobaData, sizeof(LobaData), &info, pump, &loba_texture, 0);

	if (mirage_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, MirageData, sizeof(MirageData), &info, pump, &mirage_texture, 0);

	if (octane_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, OctaneData, sizeof(OctaneData), &info, pump, &octane_texture, 0);

	if (rampart_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, RampartData, sizeof(RampartData), &info, pump, &rampart_texture, 0);

	if (valk_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, ValkData, sizeof(ValkData), &info, pump, &valk_texture, 0);

	if (vantage_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, VantageData, sizeof(VantageData), &info, pump, &vantage_texture, 0);

	if (horizon_texture == nullptr)
		D3DX11CreateShaderResourceViewFromMemory(pDevice, HorizonData, sizeof(HorizonData), &info, pump, &horizon_texture, 0);

	


	
	if (drawmenu)
	{
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
		ImGui::SetNextWindowSize(ImVec2(700, 500));
		ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBringToFrontOnFocus);
		{
			const ImVec2 pos = ImGui::GetWindowPos();
			ImDrawList* draw = ImGui::GetWindowDrawList();
			ImGuiStyle* style = &ImGui::GetStyle();

			{
				style->WindowPadding = ImVec2(0, 0);
				style->WindowBorderSize = 0.f;
				style->ItemSpacing = ImVec2(15, 15);
				style->WindowRounding = 4.f;
				style->ScrollbarSize = 4.f;
				style->Colors[ImGuiCol_WindowBg] = colors::window_background;
			}

			{

				ImVec2 FUCK1 = { pos.x + 700, pos.y + 500 };
				ImVec2 FUCK2 = { pos.x + 0, pos.y + 45 };
				ImVec2 FUCK3 = { pos.x + 700, pos.y + 47 };
				ImVec2 FUCK4 = { pos.x + 15, pos.y + 62 + m_tab_checkmark };
				ImVec2 FUCK5 = { pos.x + 145, pos.y + 98 + m_tab_checkmark };
				ImVec2 FUCK6 = { pos.x + 700, pos.y + 45 };

				m_tab_checkmark = ImLerp(m_tab_checkmark, 51.f * m_tab_count, ImGui::GetIO().DeltaTime * 12.f);
				//ImGui::GetBackgroundDrawList()->AddShadowRect(pos, FUCK1, ImGui::GetColorU32(colors::window_shadow), 60.f, ImVec2(0, 0), 0, style->WindowRounding);
				draw->AddRectFilled(FUCK4, FUCK5, ImGui::GetColorU32(colors::tab_checkmark), style->WindowRounding);
				draw->AddRectFilledMultiColor(FUCK2, FUCK3, ImGui::GetColorU32(colors::accent_one), ImGui::GetColorU32(colors::accent_two), ImGui::GetColorU32(colors::accent_two), ImGui::GetColorU32(colors::accent_one));
				ImGui::PushFont(ubuntu_bold_font);
				ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetColorU32(colors::window_label));
				ImGui::RenderTextClipped(pos, FUCK6, "Apex Legends", NULL, NULL, ImVec2(0.5f, 0.5f));
				ImGui::PopStyleColor();
				ImGui::PopFont();
			}

			{

				ImGui::SetCursorPos(ImVec2(15, 62));
				ImGui::BeginGroup();
				if (Tab("Player", m_tab_count == 0, m_tab_count))
				{
					m_tab_count = 0;
				}

				ImGui::SameLine();

				if (Tab("Combat", m_tab_count == 1, m_tab_count))
				{
					m_tab_count = 1;
				}

				ImGui::SameLine();

				if (Tab("Misc", m_tab_count == 2, m_tab_count))
				{
					m_tab_count = 2;
				}

				ImGui::SameLine();

				if (Tab("Loot", m_tab_count == 3, m_tab_count))
				{
					m_tab_count = 3;
				}
				ImGui::EndGroup();
			}

			{
				m_tab_alpha = ImClamp(m_tab_alpha + (6.f * ImGui::GetIO().DeltaTime * (m_tab_count == m_active_tab ? 1.f : -1.f)), 0.f, 1.f);
				m_tab_add = ImClamp(m_tab_add + (120.f * ImGui::GetIO().DeltaTime * (m_tab_count == m_active_tab ? 1.f : -1.f)), 0.f, 20.f);

				if (m_tab_alpha == 0.f)
					m_active_tab = m_tab_count;

				ImGui::PushStyleVar(ImGuiStyleVar_Alpha, m_tab_alpha);
				ImGui::SetCursorPos(ImVec2(160, 82 - m_tab_add));
				ImGui::BeginChild("content", ImVec2(525, 423), false, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
				{
					if (m_active_tab == 0)
					{
						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Visuals");
							{
								ImGui::Checkbox("Box", &bbox);
								ImGui::Checkbox("Corner Box", &bCorner);
								ImGui::Checkbox("Name", &bname);
								ImGui::Checkbox("Operator", &operatorESP);
								ImGui::Checkbox("Distance", &bdistance);
								ImGui::Checkbox("Health", &bhealth);
								ImGui::Checkbox("Shield", &bshield);
								ImGui::Checkbox("Seer Health", &bSeer);
								ImGui::Checkbox("Skeleton", &Skeleton);
								ImGui::Checkbox("SnapLines", &bSnaplines);
								ImGui::Checkbox("Spectator Count", &SpectatorCount);
								ImGui::Checkbox("Glow", &bGlow);
								ImGui::Checkbox("Item Esp", &bItemEsp);
							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();

						ImGui::SameLine();

						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Settings", ImVec2(0, 204));
							{
								
								ImGui::SliderInt("Max Distance", &maxDistance, 0, 2500);
								ImGui::SliderInt("Seer Fov", &seerFov, 0, 100);
								ImGui::SliderFloat("Operator Fov", &TabSize, 0, 50);
								ImGui::Combo("Snapline Position", &snaplineSelection, snaplinePos, IM_ARRAYSIZE(snaplinePos));
								//ImGui::Combo("Glow Type", &GlowMethodInt, GlowMethods, IM_ARRAYSIZE(GlowMethods));
								ImGui::Checkbox("Ignore Downed", &bIgnoreDowned);
								ImGui::Checkbox("Ignore Team", &bTeamCheck);
								

							
								
								/*inline float opx, opy, opw, oph, opv, opz, opk, opi;
				inline float rounding;*/
				//PathFinder_texture


							}
							ImGui::EndChild();

							ImGui::BeginChild("Colors", ImVec2(0, 204));
							{
								ImGui::ColorEdit3("Box Color", NBoxCol);
								ImGui::ColorEdit3("Distance Color", DistCol);
								ImGui::ColorEdit3("Name Color", NameCol);
								ImGui::ColorEdit3("Skeleton Color", skeletonCol);
								ImGui::ColorEdit3("Snapline Color", snaplineCol);
								//ImGui::ColorEdit3("Grenade Color", GrenadeColor);

							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();
					}
					else if (m_active_tab == 1)
					{
						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Combat");
							{
								ImGui::Checkbox("Aimbot", &DoAimbot);
								ImGui::Checkbox("Render Fov", &renderFov);
								ImGui::Checkbox("Draw To Target", &bDrawTarget);
								ImGui::Checkbox("No Recoil", &removeRecoil);
								//ImGui::Checkbox("No Spread", &NoSpread);
								ImGui::Checkbox("Trigger Bot", &bTrigger);
							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();

						ImGui::SameLine();

						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Settings", ImVec2(0, 204));
							{
								ImGui::Text("Aimbot");
								ImGui::SliderInt("Max Distance", &aimbotDist, 1, 500);
								ImGui::SliderInt("Aimbot Fov", &fov, 1, 100);
								ImGui::SliderInt("Aimbot Smoothing", &smothing, 1.0f, 10.0f);

								Keybind("Aimbot Key", &aimbotkey, &aimbotmode);
								Keybind("Second Aimbot Key", &secondaimbotkey, &secondaimbotmode);

								Keybind("Trigger Key", &triggerKey, &triggerState);

								ImGui::Combo("Hit Box Selection", &hitbox, hitboxes, IM_ARRAYSIZE(hitboxes));
								ImGui::Checkbox("Ignore Team", &aimTeamCheck);

								ImGui::Text("Recoil");
								ImGui::SliderFloat("Pitch Strength", &pitchSTR, 0.f, 1.f);
								ImGui::SliderFloat("Yaw Strength", &yawSTR, 0.f, 1.f);
							}
							ImGui::EndChild();

							ImGui::BeginChild("Colors", ImVec2(0, 204));
							{							
								ImGui::ColorEdit3("Fov Color", FOVCOLOR);
								ImGui::ColorEdit3("Target Line Color", TargetColor);

							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();
					}
					else if (m_active_tab == 2)
					{
						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Misc");
							{
						//		ImGui::Checkbox("Air Stuck", &airstuck);
								//ImGui::Checkbox("Unlock All", &Unlockall);
						//		ImGui::Checkbox("ThirdPerson", &bThirdPerson);
								ImGui::Checkbox("Free Cam", &Freecam);
								ImGui::Checkbox("Speed Hack", &SpeedHack);
								ImGui::Checkbox("Skin Changer", &SkinChange);
								ImGui::Checkbox("Super Glide", &autostraf);
						//		ImGui::Checkbox("Show Fps", &ShowFps);
								ImGui::Checkbox("Bhop", &bhop);
								ImGui::Checkbox("Super Grapple", &autograple);
							//	ImGui::Checkbox("Heirloom Changer", &heirloomchanger);
								ImGui::Checkbox("Force Crossplay Access", &ForceCrossPlayer);

								
								

								
							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();

						ImGui::SameLine();

						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Settings", ImVec2(0, 204));
							{
								ImGui::SliderInt("Skin ID", &skinId, 0, 13);
							//ImGui::SliderFloat("Brightness", &LPFOV, -180, 360);

								
							}
							ImGui::EndChild();

							ImGui::BeginChild("KeyBinds", ImVec2(0, 204));
							{
							//	ImGui::Keybind("Air Stuck Key", &AirStuckKey, &AirStuckState);	
							//	ImGui::Keybind("ThirdPerson Key", &thridPersonKey, &thirdPersonState);
								Keybind("Free Cam Key", &freecamKey, &FreeCamState);
								Keybind("Super Glide Key", &AutoStrafeeKey, &AutoStrafeeState);
								Keybind("Auto Grapple", &autograpleKey, &autograpleKey);
								Keybind("Bhop Key", &bhopkey, &bhopstate);
								Keybind("Menu Key", &menukey, &menustate);



							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();
					}
					else if (m_active_tab == 3)
					{
						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Item Settings");
							{
								if (ImGui::Button("Weapons"))
								{
									weaponScreen = !weaponScreen;
									attachmentsScreen = false;
									armorScreen = false;
									otherScreen = false;
								}
								if (ImGui::Button("Attachments"))
								{
									attachmentsScreen = !attachmentsScreen;
									weaponScreen = false;
									armorScreen = false;
									otherScreen = false;
								}
								if (ImGui::Button("Armor"))
								{
									armorScreen = !armorScreen;
									attachmentsScreen = false;
									weaponScreen = false;
									otherScreen = false;
								}
								if (ImGui::Button("Other"))
								{
									otherScreen = !otherScreen;
									armorScreen = false;
									attachmentsScreen = false;
									weaponScreen = false;
								}
								if (weaponScreen && m_active_tab == 3)
								{
									//MultiCombo("Light", lightWeapons, lightOptions, 7)
									//MultiCombo("Light", lightWeapons, lightOptions, 7);
									//ImGui::MultiCombo("Heavy", heavyWeapons, heavyOptions, 5);
									//ImGui::MultiCombo("Sniper", sniperWeapons, sniperOptions, 4);
									//ImGui::MultiCombo("Shotgun", shotgunWeapons, shotgunOptions, 4);
									//ImGui::MultiCombo("Energy", energyWeapons, energyOptions, 5);
									//ImGui::MultiCombo("Specaial", specialWeapons, specialOptions, 4);
								}
								else if (attachmentsScreen && m_active_tab == 3)
								{
									//ImGui::MultiCombo("Optics", opticAttachments, opticOptions, 10);
									//ImGui::MultiCombo("Magazines", magazineAttachments, magazineOptions, 16);
									//ImGui::MultiCombo("Stabilizers and Lazers", stabilizerAttachments, stabilizerOptions, 6);
									//ImGui::MultiCombo("Stocks and Bolts", stockAttachments, stockOptions, 10);
									//ImGui::MultiCombo("Hop-Ups", hopAttachments, hopOptions, 3);
								}
								else if (armorScreen && m_active_tab == 3)
								{
									//ImGui::MultiCombo("Helmet", helmetArmor, helmetOptions, 4);
									//ImGui::MultiCombo("Body", bodyArmor, bodyOptions, 8);
									//ImGui::MultiCombo("Knockdown", knochdownArmor, knockdownOptions, 4);
									//ImGui::MultiCombo("Backpack", backpackArmor, backpackOptions, 4);
								}
								else if (otherScreen && m_active_tab == 3)
								{
									//ImGui::MultiCombo("Meds", medsOther, medsOptions, 5);
									//ImGui::MultiCombo("Grenades", nadeOther, nadeOptions, 3);
									//ImGui::MultiCombo("Ammo", ammoOther, ammoOptions, 5);
									//ImGui::MultiCombo("Misc", miscOther, miscOptions, 6);
								}
								/*ImGui::MultiCombo("Weapons", weaponSelections, weaponList, IM_ARRAYSIZE(weaponList));
								ImGui::MultiCombo("Attachments", attachmentSelections, attachmentOptions, IM_ARRAYSIZE(attachmentOptions));
								ImGui::MultiCombo("Armor", armorSelections, armorOptions, IM_ARRAYSIZE(armorOptions));
								ImGui::MultiCombo("Other", ammoAndHealsSelections, ammoAndHealsOptions, IM_ARRAYSIZE(ammoAndHealsOptions));*/
							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();

						ImGui::SameLine();

						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Colors", ImVec2(0, 204));
							{
								ImGui::ColorEdit3("Weapon Color", weaponColor);
								ImGui::ColorEdit3("Attachments Color", attachemtColor);
								ImGui::ColorEdit3("Armor Color", armorColor);
								ImGui::ColorEdit3("Heals Color", healsColor);
								ImGui::ColorEdit3("Ammo Color", ammoColor);
								ImGui::ColorEdit3("Grenade Color", grenadeColor);
							}
							ImGui::EndChild();

							ImGui::BeginChild("KeyBinds", ImVec2(0, 204));
							{


							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();
					}
				}
				ImGui::EndChild();
				ImGui::PopStyleVar();
			}
		}
		ImGui::End();

	}

	RenderVisualsTest();
	std::cout << "Y r u cracking us?? what did i do to u???\n";

	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}
