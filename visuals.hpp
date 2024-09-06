#include "classes.hpp"
#include "imgui/imgui.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <array>
#include <typeinfo> 
#include <D3D11.h>
inline uintptr_t GameAddress;
inline bool bbox;
inline bool operatorESP = false;
inline bool bname;
inline bool bdistance;
inline bool SpeedHack;
inline bool heirloomchanger = false;
inline bool autograple;
inline bool SpectatorCount = false;
inline int autograpleKey, autograpleState;
inline bool bhealth;
inline bool fakeduck = false;
inline bool bshield;
inline bool HideName;
inline bool IncreaseDrive;
inline bool FastSkyDrive;
inline bool ChargeRifle;
inline int maxDistance = 1000;
inline bool bGlow;
inline ID3D11ShaderResourceView* PathFinder_texture = nullptr;
inline ID3D11ShaderResourceView* revenat_texture = nullptr;
inline ID3D11ShaderResourceView* seer_texture = nullptr;
inline ID3D11ShaderResourceView* Maggie_texture = nullptr;
inline ID3D11ShaderResourceView* Bangladesh_texture = nullptr;
inline ID3D11ShaderResourceView* bloodhound_texture = nullptr;
inline ID3D11ShaderResourceView* catalyst_texture = nullptr;
inline ID3D11ShaderResourceView* Fuse_texture = nullptr;
inline ID3D11ShaderResourceView* Gibraltar_texture = nullptr;
inline ID3D11ShaderResourceView* newcastle_texture = nullptr;
inline ID3D11ShaderResourceView* wattson_texture = nullptr;
inline ID3D11ShaderResourceView* wraith_texture = nullptr;
inline ID3D11ShaderResourceView* ash_texture = nullptr;
inline ID3D11ShaderResourceView* ballistic_texture = nullptr;
inline ID3D11ShaderResourceView* caustic_texture = nullptr;
inline ID3D11ShaderResourceView* crypto_texture = nullptr;
inline ID3D11ShaderResourceView* lifeline_texture = nullptr;
inline ID3D11ShaderResourceView* loba_texture = nullptr;
inline ID3D11ShaderResourceView* mirage_texture = nullptr;
inline ID3D11ShaderResourceView* octane_texture = nullptr;
inline ID3D11ShaderResourceView* rampart_texture = nullptr;
inline ID3D11ShaderResourceView* valk_texture = nullptr;
inline ID3D11ShaderResourceView* vantage_texture = nullptr;
inline ID3D11ShaderResourceView* horizon_texture = nullptr;
inline ID3D11ShaderResourceView* Empty_Texture = nullptr;
inline float rounding;
inline bool vis;
inline bool bHands;
inline bool bWeapon;
inline bool WeaponName;
inline bool airstuck;
inline bool NoSpread; inline float pitchSTR = 1;
inline float yawSTR = 1;
inline bool ItemGlow;
inline bool bIgnoreDowned;
static int cases = 0;
inline int testing_int = 7;
static int r = 1.00, g = 0.00, b = 1.00;
inline bool bThirdPerson;
inline const char* GlowMethods[] = { "Red Pulse", "Plasma", "Blueberry", "Matrix", "Hot Rod", "Citrus", "Purple" };
inline int GlowMethodInt = 0;
inline bool aimTeamCheck;
inline bool renderFov;
inline int seerFov = 10;
inline float FOVCOLOR[4] = { 255,255,255,255 };
inline bool Heirloom;
inline bool bTrigger;
inline bool Legendary;
inline bool Epic;
inline bool Rare;
inline bool Common;
inline int glowSelection = 0;
inline int weaponSelection = 0;
inline bool Freecam;
inline int freecamKey, FreeCamState;
inline int AirStuckKey, AirStuckState;
inline int thridPersonKey, thirdPersonState;
inline int triggerKey, triggerState;
inline bool Unlockall;
inline bool SilentAim;
inline int handSelection = 0;
inline int fov = 100;
inline bool bTeamCheck;
inline bool bSeer;
inline bool bCorner;
inline bool bItemEsp;
inline int aimbotDist = 1;
inline const char* playerSelectionOptions[] = { "Standard", "glass", "Pulse", "Outline", "Glitch", "Edit" };
inline const char* weaponSelectionOptions[] = { "Full", "White With Outline", "Outline", "Pulse", "Glitch", "Edit" };
inline const char* handSelectionOptions[] = { "Full", "Pulse", "Outline", "Edit" };
inline bool bVis = false;
inline int maxLootDist = 500;
inline int lootKey = 0;
inline bool bVisCheck;
inline int aimbotkey, aimbotmode;
inline bool fuckjews = false;
inline bool AimbotVis = false;
inline int secondaimbotkey, secondaimbotmode;
inline int hitbox = 0;
inline const char* hitboxes[] = { "Head", "Neck", "Pelvis", "Nearest" };
inline ImFont* esp_font = nullptr;
inline bool bSnaplines;
inline bool GrenadeEsp;
inline float GrenadeColor[4] = { 255,255,255,255 };
inline const char* snaplinePos[] = { "Bottom", "Center", "Top" };
inline int snaplineSelection = 0;
inline float snaplineCol[4] = { 255,255,255,255 };
inline float playerCol[4] = { 255,255,255,255 };
inline float playerColN[4] = { 255,255,255,255 };
inline float weaponCol[4] = { 255,255,255,255 };
inline float handCol[4] = { 255,255,255,255 };
inline float skeletonCol[4] = { 255,255,255,255 };
inline float BoxCol[4] = { 255,255,255,255 };
inline float NBoxCol[4] = { 255,255,255,255 };
inline float NameCol[4] = { 255,255,255,255 };
inline float DistCol[4] = { 255,255,255,255 };
inline int edit1;
inline int edit2;
inline int edit3;
inline int edit4;
inline bool bDrawTarget;
inline int amountofspectatprs = 0;
inline float TargetColor[4] = { 255,255,255,255 };
inline float weaponColor[4] = { 255,255,255,255 };
inline float healsColor[4] = { 255,255,255,255 };
inline float attachemtColor[4] = { 255,255,255,255 };
inline float grenadeColor[4] = { 255,255,255,255 };
inline float armorColor[4] = { 255,255,255,255 };
inline float ammoColor[4] = { 255,255,255,255 };
inline bool showInfo = false;
inline int infoX = GetSystemMetrics(0) * 0.75;
inline int infoY = GetSystemMetrics(0) * 0.3;
inline double timeCache[125];
inline bool weaponSelections[29];
inline const char* weaponList[29] =
{
	"Kraber",
	"Mastiff",
	"LStar",
	"Havoc",
	"Devotion",
	"Triple Take",
	"Flatline",
	"Hemlok",
	"G7 Scout",
	"Alternator",
	"R99",
	"Prowler",
	"Volt",
	"Longbow",
	"Charge Rifle",
	"Spitfire",
	"R301",
	"EVA-8 Auto",
	"Peacekeeper",
	"Mozambique",
	"Wingman",
	"P2020",
	"RE-45",
	"Sentinel",
	"Bocek Bow",
	"30-30 Repeater",
	"Nemesis",
	"Rampage",
	"Car"
};

inline bool lightWeapons[7];
inline const char* lightOptions[] =
{
	"G7 Scout",
	"Alternator",
	"R99",
	"Spitfire",
	"R301",
	"P2020",
	"RE-45",
};

inline bool heavyWeapons[5];
inline const char* heavyOptions[] =
{
	"Flatline",
	"Hemlok",
	"30-30 Repeater",
	"Rampage",
	"Car"
};
inline bool energyWeapons[5];
inline const char* energyOptions[] =
{
	"Havoc",
	"Devotion",
	"Triple Take",
	"Volt",
	"Nemesis"
};
inline bool sniperWeapons[4];
inline const char* sniperOptions[] =
{
	"Longbow",
	"Charge Rifle",
	"Wingman",
	"Sentinel",
};
inline bool shotgunWeapons[4];
inline const char* shotgunOptions[] =
{
	"EVA-8 Auto",
	"Peacekeeper",
	"Mastiff",
	"Mozambique"
};
inline bool specialWeapons[4];
inline const char* specialOptions[] =
{
	"Kraber",
	"LStar",
	"Prowler",
	"Bocek Bow"
};
inline bool attachmentSelections[45];
inline const char* attachmentOptions[] =
{
	"1x HCOG (Classic)",
	"2x HCOG (Bruiser)",
	"1x Holo",
	"1x-2x Variable Holo",
	"1x Digital Threat",
	"3x HCOG (Ranger)",
	"2x-4x Variable AOG",
	"6x Sniper",
	"4x-8x Variable Sniper",
	"4x-10x Digital Sniper Threat",
	"Barrel Stabilizer Level 1",
	"Barrel Stabilizer Level 2",
	"Barrel Stabilizer Level 3",
	"Laser Sight Level 1",
	"Laser Sight Level 2",
	"Laser Sight Level 3",
	"Light Magazine Level 1",
	"Light Magazine Level 2",
	"Light Magazine Level 3",
	"Light Magazine Level 4",
	"Heavy Magazine Level 1",
	"Heavy Magazine Level 2",
	"Heavy Magazine Level 3",
	"Heavy Magazine Level 4",
	"Energy Magazine Level 1",
	"Energy Magazine Level 2",
	"Energy Magazine Level 3",
	"Energy Magazine Level 4",
	"Sniper Magazine Level 1",
	"Sniper Magazine Level 2",
	"Sniper Magazine Level 3",
	"Sniper Magazine Level 4",
	"Shotgun Bolt Level 1",
	"Shotgun Bolt Level 2",
	"Shotgun Bolt Level 3",
	"Shotgun Bolt Level 4",
	"Standard Stock Level 1",
	"Standard Stock Level 2",
	"Standard Stock Level 3",
	"Sniper Stock Level 1",
	"Sniper Stock Level 2",
	"Sniper Stock Level 3",
	"Turbocharger",
	"Hammerpoint Rounds",
	"Disruptor Rounds"
};
inline bool opticAttachments[10];
inline const char* opticOptions[] =
{
	"1x HCOG (Classic)",
	"2x HCOG (Bruiser)",
	"1x Holo",
	"1x-2x Variable Holo",
	"1x Digital Threat",
	"3x HCOG (Ranger)",
	"2x-4x Variable AOG",
	"6x Sniper",
	"4x-8x Variable Sniper",
	"4x-10x Digital Sniper Threat",
};
inline bool magazineAttachments[16];
inline const char* magazineOptions[] =
{
	"Light Magazine Level 1",
	"Light Magazine Level 2",
	"Light Magazine Level 3",
	"Light Magazine Level 4",
	"Heavy Magazine Level 1",
	"Heavy Magazine Level 2",
	"Heavy Magazine Level 3",
	"Heavy Magazine Level 4",
	"Energy Magazine Level 1",
	"Energy Magazine Level 2",
	"Energy Magazine Level 3",
	"Energy Magazine Level 4",
	"Sniper Magazine Level 1",
	"Sniper Magazine Level 2",
	"Sniper Magazine Level 3",
	"Sniper Magazine Level 4",
};
inline bool stabilizerAttachments[6];
inline const char* stabilizerOptions[] =
{
	"Barrel Stabilizer Level 1",
	"Barrel Stabilizer Level 2",
	"Barrel Stabilizer Level 3",
	"Laser Sight Level 1",
	"Laser Sight Level 2",
	"Laser Sight Level 3",
};
inline bool stockAttachments[10];
inline const char* stockOptions[] =
{
	"Shotgun Bolt Level 1",
	"Shotgun Bolt Level 2",
	"Shotgun Bolt Level 3",
	"Shotgun Bolt Level 4",
	"Standard Stock Level 1",
	"Standard Stock Level 2",
	"Standard Stock Level 3",
	"Sniper Stock Level 1",
	"Sniper Stock Level 2",
	"Sniper Stock Level 3",
};
inline bool hopAttachments[3];
inline const char* hopOptions[] =
{
	"Turbocharger",
	"Hammerpoint Rounds",
	"Disruptor Rounds"
};
inline bool ammoAndHealsSelections[15];
inline const char* ammoAndHealsOptions[] =
{
	"Phoenix Kit",
	"Med Kit",
	"Syringe",
	"Shield Battery",
	"Shield Cell",
	"Thermite Grenade",
	"Frag Grenade",
	"Arc Star",
	"Light Rounds",
	"Energy Ammo",
	"Shotgun Shells",
	"Heavy Rounds",
	"Sniper Rounds",
	"Ultimate Accelerant",
	"Boost Loader",
	"Treasure Pack",
	"Vault Key",
	"Heat Shield",
	"Respawn Beacon",
	"Evac Tower",
};
inline bool medsOther[5];
inline const char* medsOptions[] =
{
	"Phoenix Kit",
	"Med Kit",
	"Syringe",
	"Shield Battery",
	"Shield Cell",
};
inline bool nadeOther[3];
inline const char* nadeOptions[] =
{
	"Thermite Grenade",
	"Frag Grenade",
	"Arc Star",
};
inline bool ammoOther[5];
inline const char* ammoOptions[] =
{
	"Light Rounds",
	"Energy Ammo",
	"Shotgun Shells",
	"Heavy Rounds",
	"Sniper Rounds",
};
inline bool miscOther[6];
inline const char* miscOptions[] =
{
	"Boost Loader",
	"Treasure Pack",
	"Vault Key",
	"Heat Shield",
	"Respawn Beacon",
	"Evac Tower",
};
inline bool armorSelections[20];
inline const char* armorOptions[] =
{
	"Helmet Level 1",
	"Helmet Level 2",
	"Helmet Level 3",
	"Helmet Level 4",
	"Body Armor Level 1",
	"Body Armor Level 2",
	"Body Armor Level 3",
	"Body Armor Level 4",
	"Evo Shield 1",
	"Evo Shield 2",
	"Evo Shield 3",
	"Evo Shield 4",
	"Knockdown Shield Level 1",
	"Knockdown Shield Level 2",
	"Knockdown Shield Level 3",
	"Knockdown Shield Level 4",
	"Backpack Level 1",
	"Backpack Level 2",
	"Backpack Level 3",
	"Backpack Level 4",
};
inline bool helmetArmor[4];
inline const char* helmetOptions[] =
{
	"Helmet Level 1",
	"Helmet Level 2",
	"Helmet Level 3",
	"Helmet Level 4",
};
inline bool bodyArmor[8];
inline const char* bodyOptions[] =
{
	"Body Armor Level 1",
	"Body Armor Level 2",
	"Body Armor Level 3",
	"Body Armor Level 4",
	"Evo Shield 1",
	"Evo Shield 2",
	"Evo Shield 3",
	"Evo Shield 4",
};
inline bool knochdownArmor[4];
inline const char* knockdownOptions[] =
{
	"Knockdown Shield Level 1",
	"Knockdown Shield Level 2",
	"Knockdown Shield Level 3",
	"Knockdown Shield Level 4",
};
inline bool backpackArmor[4];
inline const char* backpackOptions[] =
{
	"Backpack Level 1",
	"Backpack Level 2",
	"Backpack Level 3",
	"Backpack Level 4",
};

inline bool isVisable(uintptr_t ent, int index)
{
	return bVis;
}
inline ImVec2 tranlateTextPos(ImVec2 targetpos, char* text)
{
	int length = strlen(text);
	return ImVec2(targetpos.x - length / 2 * 11, targetpos.y);
}
inline int AutoStrafeeKey, AutoStrafeeState;
namespace items {
	enum Rarity { Weapon, Ammo, Heals, Attachment, Armor, Grenade };

	struct c_prop {
		std::string item_name;
		Rarity m_rarity;
	};


	static inline std::map<uint32_t, c_prop> itemList = {
	{ 1, { "Kraber", Rarity::Weapon }},
	{ 2, { "Mastiff", Rarity::Weapon }},
	{ 8, { "LStar", Rarity::Weapon }},
	{ 13, { "Havoc", Rarity::Weapon }},
	{ 18, { "Devotion", Rarity::Weapon }},
	{ 23, { "Triple Take", Rarity::Weapon }},
	{ 28, { "Flatline", Rarity::Weapon }},
	{ 33, { "Hemlok", Rarity::Weapon }},
	{ 39, { "G7 Scout", Rarity::Weapon }},
	{ 44, { "Alternator", Rarity::Weapon }},
	{ 49, { "R99", Rarity::Weapon }},
	{ 55, { "Prowler", Rarity::Weapon }},
	{ 60, { "Volt", Rarity::Weapon }},
	{ 65, { "Longbow", Rarity::Weapon }},
	{ 69, { "Charge Rifle", Rarity::Weapon }},
	{ 75, { "Spitfire", Rarity::Weapon }},
	{ 80, { "R301", Rarity::Weapon }},
	{ 85, { "EVA-8 Auto", Rarity::Weapon }},
	{ 90, { "Peacekeeper", Rarity::Weapon }},
	{ 95, { "Mozambique", Rarity::Weapon }},
	{ 105, { "Wingman", Rarity::Weapon }},
	{ 110, { "P2020", Rarity::Weapon }},
	{ 115, { "RE-45", Rarity::Weapon }},
	{ 121, { "Sentinel", Rarity::Weapon }},
	{ 126, { "Bocek Bow", Rarity::Weapon }},
	{ 128, { "30-30 Repeater", Rarity::Weapon }},
	{ 134, { "Nemesis", Rarity::Weapon }},
	{ 145, { "Rampage", Rarity::Weapon }},
	{ 150, { "Car", Rarity::Weapon }},

	{ 139, { "Light Rounds", Rarity::Ammo }},
	{ 140, { "Energy Ammo", Rarity::Ammo }},
	{ 141, { "Shotgun Shells", Rarity::Ammo }},
	{ 142, { "Heavy Rounds", Rarity::Ammo }},
	{ 143, { "Sniper Rounds", Rarity::Ammo }},

	{ 181, { "Ultimate Accelerant", Rarity::Heals }},
	{ 182, { "Phoenix Kit", Rarity::Heals }},
	{ 183, { "Med Kit", Rarity::Heals }},
	{ 184, { "Syringe", Rarity::Heals }},
	{ 185, { "Shield Battery", Rarity::Heals }},
	{ 186, { "Shield Cell", Rarity::Heals }},

	{ 187, { "Helmet Level 1", Rarity::Armor }},
	{ 188, { "Helmet Level 2", Rarity::Armor }},
	{ 189, { "Helmet Level 3", Rarity::Armor }},
	{ 190, { "Helmet Level 4", Rarity::Armor }},

	{ 192, { "Body Armor Level 1", Rarity::Armor }},
	{ 193, { "Body Armor Level 2", Rarity::Armor }},
	{ 194, { "Body Armor Level 3", Rarity::Armor }},
	{ 195, { "Body Armor Level 4", Rarity::Armor }},

	{ 197, { "Evo Shield 1", Rarity::Armor }},
	{ 198, { "Evo Shield 2", Rarity::Armor }},
	{ 199, { "Evo Shield 3", Rarity::Armor }},
	{ 200, { "Evo Shield 4", Rarity::Armor }},

	{ 202, { "Knockdown Shield Level 1", Rarity::Armor }},
	{ 203, { "Knockdown Shield Level 2", Rarity::Armor }},
	{ 204, { "Knockdown Shield Level 3", Rarity::Armor }},
	{ 205, { "Knockdown Shield Level 4", Rarity::Armor }},

	{ 206, { "Backpack Level 1", Rarity::Armor }},
	{ 207, { "Backpack Level 2", Rarity::Armor }},
	{ 208, { "Backpack Level 3", Rarity::Armor }},
	{ 209, { "Backpack Level 4", Rarity::Armor }},

	{ 211, { "Thermite Grenade", Rarity::Grenade }},
	{ 212, { "Frag Grenade", Rarity::Grenade }},
	{ 213, { "Arc Star", Rarity::Grenade }},

	{ 214, { "1x HCOG (Classic)", Rarity::Attachment }},
	{ 215, { "2x HCOG (Bruiser)", Rarity::Attachment }},
	{ 216, { "1x Holo", Rarity::Attachment }},
	{ 217, { "1x-2x Variable Holo", Rarity::Attachment }},
	{ 218, { "1x Digital Threat", Rarity::Attachment }},
	{ 219, { "3x HCOG (Ranger)", Rarity::Attachment }},
	{ 220, { "2x-4x Variable AOG", Rarity::Attachment }},
	{ 221, { "6x Sniper", Rarity::Attachment }},
	{ 222, { "4x-8x Variable Sniper", Rarity::Attachment }},
	{ 223, { "4x-10x Digital Sniper Threat", Rarity::Attachment }},

	{ 224, { "Barrel Stabilizer Level 1", Rarity::Attachment }},
	{ 225, { "Barrel Stabilizer Level 2", Rarity::Attachment }},
	{ 226, { "Barrel Stabilizer Level 3", Rarity::Attachment }},

	{ 228, { "Laser Sight Level 1", Rarity::Attachment }},
	{ 229, { "Laser Sight Level 2", Rarity::Attachment }},
	{ 230, { "Laser Sight Level 3", Rarity::Attachment }},

	{ 231, { "Light Magazine Level 1", Rarity::Attachment }},
	{ 232, { "Light Magazine Level 2", Rarity::Attachment }},
	{ 233, { "Light Magazine Level 3", Rarity::Attachment }},
	{ 234, { "Light Magazine Level 4", Rarity::Attachment }},

	{ 235, { "Heavy Magazine Level 1", Rarity::Attachment }},
	{ 236, { "Heavy Magazine Level 2", Rarity::Attachment }},
	{ 237, { "Heavy Magazine Level 3", Rarity::Attachment }},
	{ 238, { "Heavy Magazine Level 4", Rarity::Attachment }},

	{ 239, { "Energy Magazine Level 1", Rarity::Attachment }},
	{ 240, { "Energy Magazine Level 2", Rarity::Attachment }},
	{ 241, { "Energy Magazine Level 3", Rarity::Attachment }},
	{ 242, { "Energy Magazine Level 4", Rarity::Attachment }},

	{ 243, { "Sniper Magazine Level 1", Rarity::Attachment }},
	{ 244, { "Sniper Magazine Level 2", Rarity::Attachment }},
	{ 245, { "Sniper Magazine Level 3", Rarity::Attachment }},
	{ 246, { "Sniper Magazine Level 4", Rarity::Attachment }},

	{ 247, { "Shotgun Bolt Level 1", Rarity::Attachment }},
	{ 248, { "Shotgun Bolt Level 2", Rarity::Attachment }},
	{ 249, { "Shotgun Bolt Level 3", Rarity::Attachment }},
	{ 250, { "Shotgun Bolt Level 4", Rarity::Attachment }},

	{ 251, { "Standard Stock Level 1", Rarity::Attachment }},
	{ 252, { "Standard Stock Level 2", Rarity::Attachment }},
	{ 253, { "Standard Stock Level 3", Rarity::Attachment }},

	{ 254, { "Sniper Stock Level 1", Rarity::Attachment }},
	{ 255, { "Sniper Stock Level 2", Rarity::Attachment }},
	{ 256, { "Sniper Stock Level 3", Rarity::Attachment }},

	{ 1, { "Turbocharger", Rarity::Attachment }},
	{ 5, { "Hammerpoint Rounds", Rarity::Attachment }},
	{ 4, { "Disruptor Rounds", Rarity::Attachment }},
	{ 15, { "Boost Loader", Rarity::Heals }},
	{ 273, { "Treasure Pack", Rarity::Heals }},
	{ 25, { "Vault Key", Rarity::Heals }},
	{ 22, { "Heat Shield", Rarity::Heals }},
	{ 23, { "Respawn Beacon", Rarity::Heals }},
	{ 26, { "Evac Tower", Rarity::Heals }}
	};
}
inline bool isSelected(uint32_t id)
{
	auto item = items::itemList[id];
	if (item.m_rarity == items::Rarity::Weapon)
	{
		for (int i = 0; i < IM_ARRAYSIZE(lightOptions); i++)
		{
			if (item.item_name == lightOptions[i])
				if (lightWeapons[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(heavyOptions); i++)
		{
			if (item.item_name == heavyOptions[i])
				if (heavyWeapons[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(sniperOptions); i++)
		{
			if (item.item_name == sniperOptions[i])
				if (sniperWeapons[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(shotgunOptions); i++)
		{
			if (item.item_name == shotgunOptions[i])
				if (shotgunWeapons[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(energyOptions); i++)
		{
			if (item.item_name == energyOptions[i])
				if (energyWeapons[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(specialOptions); i++)
		{
			if (item.item_name == specialOptions[i])
				if (specialWeapons[i])
					return true;
		}
	}


	else if (item.m_rarity == items::Rarity::Attachment)
	{
		for (int i = 0; i < IM_ARRAYSIZE(opticOptions); i++)
		{
			if (item.item_name == opticOptions[i])
				if (opticAttachments[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(magazineOptions); i++)
		{
			if (item.item_name == magazineOptions[i])
				if (magazineAttachments[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(stabilizerOptions); i++)
		{
			if (item.item_name == stabilizerOptions[i])
				if (stabilizerAttachments[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(stockOptions); i++)
		{
			if (item.item_name == stockOptions[i])
				if (stockAttachments[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(hopOptions); i++)
		{
			if (item.item_name == hopOptions[i])
				if (hopAttachments[i])
					return true;
		}
	}


	else if (item.m_rarity == items::Rarity::Armor)
	{
		for (int i = 0; i < IM_ARRAYSIZE(helmetOptions); i++)
		{
			if (item.item_name == helmetOptions[i])
				if (helmetArmor[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(bodyOptions); i++)
		{
			if (item.item_name == bodyOptions[i])
				if (bodyArmor[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(knockdownOptions); i++)
		{
			if (item.item_name == knockdownOptions[i])
				if (knochdownArmor[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(backpackOptions); i++)
		{
			if (item.item_name == backpackOptions[i])
				if (backpackArmor[i])
					return true;
		}
	}


	else if (item.m_rarity == items::Rarity::Grenade || item.m_rarity == items::Rarity::Ammo || items::Rarity::Heals)
	{
		for (int i = 0; i < IM_ARRAYSIZE(medsOptions); i++)
		{
			if (item.item_name == medsOptions[i])
				if (medsOther[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(nadeOptions); i++)
		{
			if (item.item_name == nadeOptions[i])
				if (nadeOther[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(ammoOptions); i++)
		{
			if (item.item_name == ammoOptions[i])
				if (ammoOther[i])
					return true;
		}
		for (int i = 0; i < IM_ARRAYSIZE(miscOptions); i++)
		{
			if (item.item_name == miscOptions[i])
				if (miscOther[i])
					return true;
		}
	}
	return false;
}
inline void draw_text_outline_font(float x, float y, ImColor color, const char* string, ImFont* Font) {
	char buf[512];
	va_list arg_list;

	ImGui::PushFont(Font);
	ImVec2 len = ImGui::CalcTextSize(string);
	ImGui::PopFont();

	ImGui::GetBackgroundDrawList()->AddText(Font, 12, ImVec2(x - .3 - len.x / 2, y - len.y / 2), ImColor(0.0f, 0.0f, 0.0f, 1.0f), string);
	ImGui::GetBackgroundDrawList()->AddText(Font, 12, ImVec2(x + .3 - len.x / 2, y - len.y / 2), ImColor(0.0f, 0.0f, 0.0f, 1.0f), string);
	ImGui::GetBackgroundDrawList()->AddText(Font, 12, ImVec2(x - len.x / 2, y - .3 - len.y / 2), ImColor(0.0f, 0.0f, 0.0f, 1.0f), string);
	ImGui::GetBackgroundDrawList()->AddText(Font, 12, ImVec2(x - len.x / 2, y + .3 - len.y / 2), ImColor(0.0f, 0.0f, 0.0f, 1.0f), string);

	ImGui::GetBackgroundDrawList()->AddText(Font, 12, ImVec2(x - len.x / 2, y - len.y / 2), color, string);
	return;
}
inline void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness)
{
	float lineW = (W / 3);
	float lineH = (H / 3);

	////black outlines
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);

	//corners
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}
inline void AddHexagon(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col, float thickness)
{
	if ((col & IM_COL32_A_MASK) == 0)
		return;

	ImGui::GetBackgroundDrawList()->PathLineTo(p1);
	ImGui::GetBackgroundDrawList()->PathLineTo(p2);
	ImGui::GetBackgroundDrawList()->PathLineTo(p3);
	ImGui::GetBackgroundDrawList()->PathLineTo(p4);
	ImGui::GetBackgroundDrawList()->PathLineTo(p5);
	ImGui::GetBackgroundDrawList()->PathLineTo(p6);

	ImGui::GetBackgroundDrawList()->PathStroke(col, true, thickness);
}
inline void AddHexagonFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col)
{
	if ((col & IM_COL32_A_MASK) == 0)
		return;

	ImGui::GetBackgroundDrawList()->PathLineTo(p1);
	ImGui::GetBackgroundDrawList()->PathLineTo(p2);
	ImGui::GetBackgroundDrawList()->PathLineTo(p3);
	ImGui::GetBackgroundDrawList()->PathLineTo(p4);
	ImGui::GetBackgroundDrawList()->PathLineTo(p5);
	ImGui::GetBackgroundDrawList()->PathLineTo(p6);
	ImGui::GetBackgroundDrawList()->PathFillConvex(col);
}
inline void DrawQuadFilled(ImVec2 p1, ImVec2 p2, ImVec2 p3, ImVec2 p4, ImColor color) {
	ImGui::GetBackgroundDrawList()->AddQuadFilled(p1, p2, p3, p4, color);
}
inline void DrawHexagon(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col, float thickness)
{
	AddHexagon(p1, p2, p3, p4, p5, p6, col, thickness);
}
inline void DrawHexagonFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col)
{
	AddHexagonFilled(p1, p2, p3, p4, p5, p6, col);
}
inline int atest, btest;
inline void SeerHealth(float x, float y, int shield, int max_shield, int armorType, int health) {

	int bg_offset = 3;
	int bar_width = 158;
	// 4steps...2*3=6
	// 38*4=152 152+6 = 158
	// 5steps...2*4=8
	// 30*5=150 150+8 = 158
	float max_health = 100.0f;
	float shield_step = 25.0f;

	int shield_25 = 30;
	int steps = 5;

	ImVec2 bg1(x - bar_width / 2 - bg_offset, y);
	ImVec2 bg2(bg1.x - 10, bg1.y - 16);
	ImVec2 bg3(bg2.x + 5, bg2.y - 7);
	ImVec2 bg4(bg3.x + bar_width + bg_offset, bg3.y);
	ImVec2 bg5(bg4.x + 11, bg4.y + 18);
	ImVec2 bg6(x + bar_width / 2 + bg_offset, y);
	DrawHexagonFilled(bg1, bg2, bg3, bg4, bg5, bg6, ImColor(0, 0, 0, 140));

	ImVec2 h1(bg1.x + 3, bg1.y - 4);
	ImVec2 h2(h1.x - 5, h1.y - 8);
	ImVec2 h3(h2.x + (float)health / max_health * bar_width, h2.y);
	ImVec2 h4(h1.x + (float)health / max_health * bar_width, h1.y);
	ImVec2 h3m(h2.x + bar_width, h2.y);
	ImVec2 h4m(h1.x + bar_width, h1.y);
	DrawQuadFilled(h1, h2, h3m, h4m, ImColor(10, 10, 30, 60));
	DrawQuadFilled(h1, h2, h3, h4, ImColor(255, 255, 255, 255));


	ImColor shieldCracked(97, 97, 97);
	ImColor shieldCrackedDark(67, 67, 67);

	ImColor shieldCol;
	ImColor shieldColDark; //not used, but the real seer q has shadow inside
	if (armorType == 1) { //white
		shieldCol = ImColor(247, 247, 247);
		shieldColDark = ImColor(164, 164, 164);
	}
	else if (armorType == 2) { //blue
		shieldCol = ImColor(39, 178, 255);
		shieldColDark = ImColor(27, 120, 210);
	}
	else if (armorType == 3) { //purple
		shieldCol = ImColor(206, 59, 255);
		shieldColDark = ImColor(136, 36, 220);
	}
	else if (armorType == 4) { //gold
		shieldCol = ImColor(255, 255, 79);
		shieldColDark = ImColor(218, 175, 49);
	}
	else if (armorType == 5) { //red
		shieldCol = ImColor(219, 2, 2);
		shieldColDark = ImColor(219, 2, 2);
	}
	else {
		shieldCol = ImColor(247, 247, 247);
		shieldColDark = ImColor(164, 164, 164);
	}
	int shield_tmp = shield;
	int shield1 = 0;
	int shield2 = 0;
	int shield3 = 0;
	int shield4 = 0;
	int shield5 = 0;
	if (shield_tmp > 25) {
		shield1 = 25;
		shield_tmp -= 25;
		if (shield_tmp > 25) {
			shield2 = 25;
			shield_tmp -= 25;
			if (shield_tmp > 25) {
				shield3 = 25;
				shield_tmp -= 25;
				if (shield_tmp > 25) {
					shield4 = 25;
					shield_tmp -= 25;
					shield5 = shield_tmp;
				}
				else {
					shield4 = shield_tmp;
				}
			}
			else {
				shield3 = shield_tmp;
			}
		}
		else {
			shield2 = shield_tmp;
		}
	}
	else {
		shield1 = shield_tmp;
	}
	ImVec2 s1(h2.x - 1, h2.y - 2);
	ImVec2 s2(s1.x - 3, s1.y - 5);
	ImVec2 s3(s2.x + shield1 / shield_step * shield_25, s2.y);
	ImVec2 s4(s1.x + shield1 / shield_step * shield_25, s1.y);
	ImVec2 s3m(s2.x + shield_25, s2.y);
	ImVec2 s4m(s1.x + shield_25, s1.y);

	ImVec2 ss1(s4m.x + 2, s1.y);
	ImVec2 ss2(s3m.x + 2, s2.y);
	ImVec2 ss3(ss2.x + shield2 / shield_step * shield_25, s2.y);
	ImVec2 ss4(ss1.x + shield2 / shield_step * shield_25, s1.y);
	ImVec2 ss3m(ss2.x + shield_25, s2.y);
	ImVec2 ss4m(ss1.x + shield_25, s1.y);

	ImVec2 sss1(ss4m.x + 2, s1.y);
	ImVec2 sss2(ss3m.x + 2, s2.y);
	ImVec2 sss3(sss2.x + shield3 / shield_step * shield_25, s2.y);
	ImVec2 sss4(sss1.x + shield3 / shield_step * shield_25, s1.y);
	ImVec2 sss3m(sss2.x + shield_25, s2.y);
	ImVec2 sss4m(sss1.x + shield_25, s1.y);

	ImVec2 ssss1(sss4m.x + 2, s1.y);
	ImVec2 ssss2(sss3m.x + 2, s2.y);
	ImVec2 ssss3(ssss2.x + shield4 / shield_step * shield_25, s2.y);
	ImVec2 ssss4(ssss1.x + shield4 / shield_step * shield_25, s1.y);
	ImVec2 ssss3m(ssss2.x + shield_25, s2.y);
	ImVec2 ssss4m(ssss1.x + shield_25, s1.y);

	ImVec2 sssss1(ssss4m.x + 2, s1.y);
	ImVec2 sssss2(ssss3m.x + 2, s2.y);
	ImVec2 sssss3(sssss2.x + shield5 / shield_step * shield_25, s2.y);
	ImVec2 sssss4(sssss1.x + shield5 / shield_step * shield_25, s1.y);
	ImVec2 sssss3m(sssss2.x + shield_25, s2.y);
	ImVec2 sssss4m(sssss1.x + shield_25, s1.y);
	if (max_shield == 50) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield != 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
	}
	else if (max_shield == 75) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield < 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
		else if (shield <= 75) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			if (shield < 75) {
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
		}
	}
	else if (max_shield == 100) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield < 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
		else if (shield <= 75) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			if (shield < 75) {
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
		}
		else if (shield <= 100) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
			if (shield < 100) {
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ssss1, ssss2, ssss3, ssss4, shieldCol);
		}
	}
	else if (max_shield == 125) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield < 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
		else if (shield <= 75) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			if (shield < 75) {
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
		}
		else if (shield <= 100) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
			if (shield < 100) {
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ssss1, ssss2, ssss3, ssss4, shieldCol);
		}
		else if (shield <= 125) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
			DrawQuadFilled(ssss1, ssss2, ssss3, ssss4, shieldCol);
			if (shield < 125) {
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sssss1, sssss2, sssss3, sssss4, shieldCol);
		}
	}
}
inline bool SkinChange;
inline int skinId;
inline uintptr_t GetEntityById(int Ent)
{
	uintptr_t EntityList = GameAddress + offsets::EntityList;
	uintptr_t BaseEntity = read<DWORD64>(EntityList);
	if (!BaseEntity)
		return NULL;
	return read<uintptr_t>(EntityList + (Ent << 5));

}
inline void DrawBox(ImVec2 headPos, ImVec2 pos, const ImU32 color, int thickness) {
	int dist = pos.y - headPos.y;
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(headPos.x - dist / 4, headPos.y), ImVec2(headPos.x + dist / 4, headPos.y), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(headPos.x + dist / 4, headPos.y), ImVec2(pos.x + dist / 4, pos.y), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pos.x + dist / 4, pos.y), ImVec2(pos.x - dist / 4, pos.y), color, thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(pos.x - dist / 4, pos.y), ImVec2(headPos.x - dist / 4, headPos.y), color, thickness);
}
inline void enableGlow()
{
	for (auto idx{ 0 }; idx <= 150; idx++)
	{
		auto Ent = GetEntityById(idx);
		if (read<int>(Ent + offsets::m_bleedoutState) > 0 && bIgnoreDowned) continue;

		if (!Ent) return;
		static DWORD Glow_Type = 0x29c;
		static DWORD Glow_Enabled = 0x28C;
		static DWORD Glow_Through_Walls = 0x26c;
		static DWORD GLOW_COLOR_R = 0x1D0 + 0x30;
		static DWORD GLOW_COLOR_G = 0x1D4 + 0x30;
		static DWORD GLOW_COLOR_B = 0x1D8 + 0x30;
		uint8_t Method = 50;
		if (GlowMethodInt == 0)
			Method = 50;
		else if (GlowMethodInt == 1)
			Method = 46;
		else if (GlowMethodInt == 2)
			Method = 44;
		else if (GlowMethodInt == 3)
			Method = 15;
		else if (GlowMethodInt == 4)
			Method = 64;
		else if (GlowMethodInt == 5)
			Method = 25;
		else if (GlowMethodInt == 6)
			Method = 29;

		DWORD_PTR MyLocalplayer = read<DWORD_PTR>(GameAddress + offsets::LocalPlayer);

		DWORD64 ViewModelHandle = read<DWORD64>(MyLocalplayer + offsets::m_hViewModels) & 0xFFFF; //m_hViewModels
		DWORD64 ViewModelPtr = read<DWORD64>(GameAddress + offsets::EntityList + ViewModelHandle * 0x20);
		auto LP = read<uintptr_t>(GameAddress + offsets::LocalPlayer);
		if (Ent != ViewModelPtr && Ent != LP)
		{

			write<uint8_t>(Ent + 0x28C, 0); // 0x294 turn glow on 
			write<uint8_t>(Ent + 0x298, 15); // Hilight id 0x298
			write<int>(Ent + 0x278, 1); // glfix
			write<int>(Ent + 0x26c, 1); // glow through walls 
		}


	}


}
inline bool autostraf = false;
inline void draw_text_outline(float x, float y, ImColor color, const char* string, ...) {
	char buf[512];
	va_list arg_list;

	ZeroMemory(buf, sizeof(buf));

	va_start(arg_list, string);
	vsnprintf(buf, sizeof(buf), string, arg_list);
	va_end(arg_list);

	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(x - 1, y), ImColor(0.0f, 0.0f, 0.0f, 1.0f), buf, 0, 0, 0);
	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(x + 1, y), ImColor(0.0f, 0.0f, 0.0f, 1.0f), buf, 0, 0, 0);
	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(x, y - 1), ImColor(0.0f, 0.0f, 0.0f, 1.0f), buf, 0, 0, 0);
	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(x, y + 1), ImColor(0.0f, 0.0f, 0.0f, 1.0f), buf, 0, 0, 0);

	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), ImVec2(x, y), color, buf, 0, 0, 0);
	return;
}
inline Vector3 ProjectWorldToScreen(const struct Vector3 pos) {

	uintptr_t render = read<uintptr_t>(GameAddress + offsets::ViewRender);
	uintptr_t Matrixa = read<uintptr_t>(offsets::ViewMatrix + render);

	BaseMatrix M = read<BaseMatrix>(Matrixa);
	struct Vector3 out;
	float _x = M.at[0] * pos.x + M.at[1] * pos.y + M.at[2] * pos.z + M.at[3];
	float _y = M.at[4] * pos.x + M.at[5] * pos.y + M.at[6] * pos.z + M.at[7];
	out.z = M.at[12] * pos.x + M.at[13] * pos.y + M.at[14] * pos.z + M.at[15];

	if (out.z < 0.1f)
		return { 0, 0,0 };

	_x *= 1.f / out.z;
	_y *= 1.f / out.z;

	out.x = ImGui::GetIO().DisplaySize.x * .5f;
	out.y = ImGui::GetIO().DisplaySize.y * .5f;

	out.x += 0.5f * _x * ImGui::GetIO().DisplaySize.x + 0.5f;
	out.y -= 0.5f * _y * ImGui::GetIO().DisplaySize.y + 0.5f;

	return out;

}
inline Vector3 GetBonePos(uintptr_t ent, int id)
{
	Vector3 pos = read<Vector3>(ent + offsets::VecAbs); //PoopSets::M_VecAbsOrigin
	uintptr_t bones = read<uintptr_t>(ent + 0x0db0 + 0x48); //PoopSets::demfuckingBone
	Vector3 bone = {};
	UINT32 boneloc = (id * 0x30);
	bone_t bo = {};
	bo = read<bone_t>(bones + boneloc);

	bone.x = bo.x + pos.x;
	bone.y = bo.y + pos.y;
	bone.z = bo.z + pos.z;
	return bone;
}
#define Assert( _exp ) ((void)0)
struct matrix3x4_t
{
	matrix3x4_t() {}
	matrix3x4_t(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23)
	{
		m_flMatVal[0][0] = m00;	m_flMatVal[0][1] = m01; m_flMatVal[0][2] = m02; m_flMatVal[0][3] = m03;
		m_flMatVal[1][0] = m10;	m_flMatVal[1][1] = m11; m_flMatVal[1][2] = m12; m_flMatVal[1][3] = m13;
		m_flMatVal[2][0] = m20;	m_flMatVal[2][1] = m21; m_flMatVal[2][2] = m22; m_flMatVal[2][3] = m23;
	}

	float* operator[](int i) { Assert((i >= 0) && (i < 3)); return m_flMatVal[i]; }
	const float* operator[](int i) const { Assert((i >= 0) && (i < 3)); return m_flMatVal[i]; }
	float* Base() { return &m_flMatVal[0][0]; }
	const float* Base() const { return &m_flMatVal[0][0]; }

	float m_flMatVal[3][4];
};
inline Vector3 getBonePositionByHitbox(uintptr_t entity, int id)
{
	Vector3 origin = read<Vector3>(entity + offsets::VecAbs);

	//BoneByHitBox
	uint64_t Model = *(uint64_t*)(entity + offsets::m_pStudioHdr);

	//get studio hdr
	uint64_t StudioHdr = read<uint64_t>(Model + 0x8);

	//get hitbox array
	uint16_t HitboxCache = read<uint16_t>(StudioHdr + 0x34);
	uint64_t HitBoxsArray = StudioHdr + ((uint16_t)(HitboxCache & 0xFFFE) << (4 * (HitboxCache & 1)));

	uint16_t IndexCache = read<uint16_t>(HitBoxsArray + 0x4);
	int HitboxIndex = ((uint16_t)(IndexCache & 0xFFFE) << (4 * (IndexCache & 1)));

	uint16_t Bone = read<uint16_t>(HitBoxsArray + HitboxIndex + (id * 0x20));

	if (Bone < 0 || Bone > 255)
		return Vector3();

	//hitpos
	uint64_t BoneArray = *(uint64_t*)(entity + 0x0db0 + 0x48);

	matrix3x4_t Matrix = read<matrix3x4_t>(BoneArray + Bone * sizeof(matrix3x4_t));

	return Vector3(Matrix.m_flMatVal[0][3] + origin.x, Matrix.m_flMatVal[1][3] + origin.y, Matrix.m_flMatVal[2][3] + origin.z);
}
inline int bloodhoundBones[] = { 0, 1, 2, 4, -5, 1, 6, 7, 19, -5, 1, 8, 9, 10, -5, 4, 11, 12, 13, 14, -5, 4, 15, 16, 17, 18 };
inline int regualrBones[] = { 0, 1, 3, 4, -5, 1, 6, 7, 8, -5, 1, 9, 10, 11, -5, 4, 12, 13, 14, 15, -5, 4, 16, 17, 18, 19 };
inline void boneEsp(uintptr_t entity)
{
	for (int i = 1; i < 26; i++)
	{
		uintptr_t pMode_Name = read<uintptr_t>(entity + offsets::m_ModelName);
		char* modelName = reinterpret_cast<char*>(pMode_Name);
		std::string s(modelName);

		if (s.find("bloodhound") != -1)
		{
			if (bloodhoundBones[i] == -5)
			{
				i++;
				continue;
			}

			Vector3 first = getBonePositionByHitbox(entity, bloodhoundBones[i - 1]);
			first = ProjectWorldToScreen(first);
			if (first.Empty()) continue;

			Vector3 last = getBonePositionByHitbox(entity, bloodhoundBones[i]);
			last = ProjectWorldToScreen(last);
			if (last.Empty()) continue;

			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x, first.y), ImVec2(last.x, last.y), ImColor(skeletonCol[0], skeletonCol[1], skeletonCol[2]), 1);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x - 1, first.y), ImVec2(last.x - 1, last.y), ImColor(0, 0, 0), 1);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x + 1, first.y), ImVec2(last.x + 1, last.y), ImColor(0, 0, 0), 1);
		}
		else
		{
			if (regualrBones[i] == -5)
			{
				i++;
				continue;
			}
			Vector3 first = getBonePositionByHitbox(entity, regualrBones[i - 1]);
			first = ProjectWorldToScreen(first);
			if (first.Empty()) continue;

			Vector3 last = getBonePositionByHitbox(entity, regualrBones[i]);
			last = ProjectWorldToScreen(last);
			if (first.Empty()) continue;
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x, first.y), ImVec2(last.x, last.y), ImColor(skeletonCol[0], skeletonCol[1], skeletonCol[2]), 1);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x - 1, first.y), ImVec2(last.x - 1, last.y), ImColor(0, 0, 0), 1);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(first.x + 1, first.y), ImVec2(last.x + 1, last.y), ImColor(0, 0, 0), 1);
		}
	}

}
inline void DrawBones(uintptr_t Entity, BoneList BoneOne, BoneList BoneTwo, ImColor Color)
{
	Vector3 Screen1, Screen2;
	Screen1 = ProjectWorldToScreen(GetBonePos(Entity, BoneOne));
	if (Screen1.Empty()) return;
	Screen2 = ProjectWorldToScreen(GetBonePos(Entity, BoneTwo));
	if (Screen2.Empty()) return;
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(Screen1.x, Screen1.y), ImVec2(Screen2.x, Screen2.y), Color);

}
inline bool Skeleton = false;
inline uintptr_t GetBestOp(uintptr_t local, float fovs) {
	float closest = INT_MAX;
	uintptr_t bestEnt = 0;
	for (int i = 0; i < 125; i++) {
		uintptr_t Entity = GetEntityById(i);
		if (Entity == local) continue;
		if (!Entity) continue;
		if (read<int>(Entity + offsets::m_iHealth <= 0)) continue;
		if (read<int>(Entity + offsets::m_iTeamNum) == read<int>(local + offsets::m_iTeamNum) && aimTeamCheck) continue;
		if (read<int>(Entity + offsets::m_bleedoutState) > 0) continue;

		//if (bVisCheck && !isVisable(Entity, i)) continue;
		float distance = calcDist(read<Vector3>(Entity + offsets::VecAbs), read<Vector3>(local + offsets::VecAbs));
		if ((distance / 15) > maxDistance) continue;
		if ((distance / 15) > aimbotDist) continue;
		Vector3 Head2d = ProjectWorldToScreen(GetBonePos(Entity, BoneList::Head));
		if (Head2d.Empty()) continue;
		float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - Head2d.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - Head2d.y, 2));

		if (length < closest && length <= (fovs * 3)) {
			closest = length;
			//printf("Ent Found\n");
			bestEnt = Entity;
		}
	}
	return bestEnt;
}
inline uintptr_t getBestEnt(uintptr_t local) {
	float closest = INT_MAX;
	uintptr_t bestEnt = 0;
	for (int i = 0; i < 125; i++) {
		uintptr_t Entity = GetEntityById(i);
		if (Entity == local) continue;
		if (!Entity) continue;
		uintptr_t nameptr = read<uintptr_t>(GameAddress + offsets::NameList + (i - 1) * 0x10);
		if (!nameptr) continue;
		char* name = reinterpret_cast<char*>(nameptr);
		if (name == "")
			continue;
		if (read<int>(Entity + offsets::m_iHealth <= 0)) continue;
		if (read<int>(Entity + offsets::m_iTeamNum) == read<int>(local + offsets::m_iTeamNum) && aimTeamCheck) continue;
		if (read<int>(Entity + offsets::m_bleedoutState) > 0) continue;

		//if (bVisCheck && !isVisable(Entity, i)) continue;
		float distance = calcDist(read<Vector3>(Entity + offsets::VecAbs), read<Vector3>(local + offsets::VecAbs));
		if ((distance / 15) > maxDistance) continue;
		if ((distance / 15) > aimbotDist) continue;
		Vector3 Head2d = ProjectWorldToScreen(GetBonePos(Entity, BoneList::Head));
		if (Head2d.Empty()) continue;
		float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - Head2d.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - Head2d.y, 2));

		if (length < closest && length <= (fov * 3)) {
			closest = length;
			bestEnt = Entity;
		}
	}
	return bestEnt;
}
inline Vector3 getCamPos(uintptr_t local) {
	return read<Vector3>(local + offsets::camera_origin);
}
inline Vector2 getAngles(uintptr_t local) {
	Vector2 angles;
	angles.x = read<float>(local + offsets::viewAngles + sizeof(float));
	angles.y = read<float>(local + offsets::viewAngles);
	return angles;
}
inline int smothing = 1;
inline float previousPitch = 0;
inline float previousYaw = 0;
inline uintptr_t TriggerEnt(uintptr_t local, float size, float& bonedistane) {
	float closest = INT_MAX;
	uintptr_t bestEnt = 0;
	for (int i = 0; i < 125; i++) {
		uintptr_t Entity = GetEntityById(i);
		if (Entity == local) continue;
		if (!Entity) continue;
		if (read<int>(Entity + offsets::m_iHealth <= 0)) continue;
		if (read<int>(Entity + offsets::m_iTeamNum) == read<int>(local + offsets::m_iTeamNum) && aimTeamCheck) continue;
		if (read<int>(Entity + offsets::m_bleedoutState) > 0) continue;
		Vector3 HitBoxTarget;
		float distance = calcDist(read<Vector3>(Entity + offsets::VecAbs), read<Vector3>(local + offsets::VecAbs));
		if ((distance / 15) > maxDistance) continue;
		if ((distance / 15) > aimbotDist) continue;
		bonedistane = distance;
		Vector3 w2s;
		int targetBone;
		if (hitbox == 0)
		{
			targetBone = BoneList::Head;
		}
		else if (hitbox == 1) {
			targetBone = BoneList::Neck;
		}
		else {
			targetBone = BoneList::Pelivs;
		}
		Vector3 tPos = GetBonePos(Entity, targetBone);
		auto v1 = ProjectWorldToScreen(tPos);
		if (v1.Empty()) continue ;
		float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - v1.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - v1.y, 2));

		if (length < closest&& length <= (size)) {
			closest = length;
			ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(v1.x, v1.y), 5, ImColor(255, 0, 0, 255));

			bestEnt = Entity;
		}
	}
	return bestEnt;
}
inline bool IsInCrossHair(DWORD64 Address) {
	auto tmp_lastCrosshairTargetTime = read<float>(Address + offsets::OFFSET_CROSSHAIR_LAST);
	float LastCrossHair = read<float>(Address + offsets::OFFSET_CROSSHAIR_LAST);
	auto iter = LastCrossHair;
	if (!iter)return false;
	if (iter == -1.f) {
		iter = tmp_lastCrosshairTargetTime;
		return false;
	}
	auto isCrosshair = tmp_lastCrosshairTargetTime > iter;
	iter = tmp_lastCrosshairTargetTime;
	return isCrosshair;
}
inline void triggerbot()
{
	{
		if (bTrigger)
		{
			uintptr_t localPlayer = read<uintptr_t>(GameAddress + offsets::LocalPlayer);
			if (GetAsyncKeyState(triggerKey))
			{
				float increments = 10.0f;
				float distance;

				float closest = INT_MAX;
				uintptr_t bestEnt = 0;
				for (int i = 0; i < 125; i++) {
					uintptr_t Entity = GetEntityById(i);
					if (Entity == localPlayer) continue;
					if (!Entity) continue;
					if (read<int>(Entity + offsets::m_iHealth <= 0)) continue;
					if (read<int>(Entity + offsets::m_iTeamNum) == read<int>(localPlayer + offsets::m_iTeamNum) && aimTeamCheck) continue;
					if (read<int>(Entity + offsets::m_bleedoutState) > 0) continue;
					Vector3 HitBoxTarget;
					float distancea = calcDist(read<Vector3>(Entity + offsets::VecAbs), read<Vector3>(localPlayer + offsets::VecAbs));
					distance = (distancea / 15);
					if ((distance / 15) > maxDistance) continue;
					if ((distance / 15) > aimbotDist) continue;
					if (distance < 50.0f)
					{
						increments = 22.0f;
					}
					if (distance > 50.0f && distance < 100.0f)
					{
						increments = 18.0f;
					}
					if (distance > 100.0f && distance < 500.0f)
					{
						increments = 12.0f;
					}

					Vector3 w2s;
					int targetBone;
					if (hitbox == 0)
					{
						targetBone = BoneList::Head;
					}
					else if (hitbox == 1) {
						targetBone = BoneList::Neck;
					}
					else {
						targetBone = BoneList::Pelivs;
					}
					Vector3 tPos = GetBonePos(Entity, targetBone);
					auto v1 = ProjectWorldToScreen(tPos);
					if (v1.Empty()) return;

					float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - v1.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - v1.y, 2));
					if (length < closest && length <= (increments)) {
						closest = length;
						ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(v1.x, v1.y), 5, ImColor(255, 0, 0, 255));
						if (!GetAsyncKeyState(0x01))
						{
							draw_text_outline_font(GetSystemMetrics(0) / 2, (GetSystemMetrics(1) / 2) + 15, ImColor(255, 0, 0, 255), "[ F i r i n g ]", esp_font);
							if (GetAsyncKeyState(triggerKey))
							{
								draw_text_outline_font(GetSystemMetrics(0) / 2, (GetSystemMetrics(1) / 2) + 15, ImColor(255, 0, 0, 255), "[ F i r i n g ]", esp_font);
								float randa = rand() % 100;

								keybd_event(0x01, MapVirtualKey(0x01, 0), 0, 0);
								Sleep(1);
								keybd_event(0x01, MapVirtualKey(0x01, 0), KEYEVENTF_KEYUP, 0);
								Sleep(1);
							}
							else {
								keybd_event(0x01, MapVirtualKey(0x01, 0), KEYEVENTF_KEYUP, 0);
								Sleep(1);
							}
						}
					}
				}
			}
		}
	}

}
inline void noRecoil() {
	uintptr_t localPlayer = read<DWORD64>(GameAddress + offsets::LocalPlayer);
	if (localPlayer != NULL) {
		Vector2 angles;
		angles.y = read<float>(localPlayer + offsets::viewAngles); //works
		angles.x = read<float>(localPlayer + offsets::viewAngles + sizeof(float)); // works
		Vector2 punch = read<Vector2>(localPlayer + offsets::punchAngle);
		if (punch.y < 0 || punch.x < 0) {
			angles.x -= (punch.y - previousYaw) * yawSTR;
			angles.y -= (punch.x - previousPitch) * pitchSTR;
			//NormalizeAngles(angles);
			write<float>(localPlayer + offsets::viewAngles, angles.y);
			write<float>(localPlayer + offsets::viewAngles + sizeof(float), angles.x);
			previousPitch = punch.x;
			previousYaw = punch.y;
		}
	}
}
inline float GetWeaponBulletSpeeds(uintptr_t local) {

	uint64_t entitylist = read<uint64_t>(GameAddress + offsets::EntityList);
	uint64_t wephandle = read<uint64_t>(local + offsets::m_latestPrimaryWeapons  /*active weapon*/);

	wephandle &= 0xffff;

	uint64_t wep_entity = read<uint64_t>(entitylist + (wephandle << 5));

	auto projectileSpeed = read<float>(wep_entity + (0x19a0 + offsets::projectile_inherit_base_velocity_scale));

	return projectileSpeed;
}
inline void SetSkin(uintptr_t pLocal, int SkinIndex)
{
	DWORD64 LastWeapon = read<DWORD64>(pLocal + offsets::m_latestPrimaryWeapons) & 0xFFFF; // current weapon
	DWORD64 Weapon = read<DWORD64>(GameAddress + offsets::EntityList + (LastWeapon << 5));
	write<int>(Weapon + 0x0d88, SkinIndex);
}
inline Vector3 CalcAnglePredictives(Vector3 src, Vector3 dst, uintptr_t targetEntity, uintptr_t local)
{
	Vector3 Velocity = read<Vector3>(targetEntity + offsets::m_vecAbsVelocity);
	float bullet_vel = GetWeaponBulletSpeeds(local);
	float dist = VAR_deltaDistances(src, dst);
	if (bullet_vel < 5000 || dist < 700) { // Not using gun or Super closeup
		return Var_CalcAngless(src, dst);
	}

	float travel_time = dist / bullet_vel;
	float bullet_drop = (358.f * travel_time * travel_time);

	Vector3 predictedDst = dst;
	predictedDst.x += Velocity.x * travel_time;
	predictedDst.y += Velocity.y * travel_time;
	predictedDst.z += (Velocity.z * travel_time) + bullet_drop;

	return Var_CalcAngless(src, predictedDst);
}
inline Vector3 calculateAnglesForEntss(uintptr_t targetEntity, uintptr_t local, int targetBone) {

	Vector3 CameraPos = read<Vector3>(local + offsets::camera_origin);
	if (CameraPos.x == 0.0f && CameraPos.y == 0.0f) return { 0,0,0 };
	int AimBones = 0;



	Vector3 target_head = GetBonePos(targetEntity, targetBone);
	if (target_head.x == 0.0f && target_head.y == 0.0f) return { 0,0,0 };

	//Vector3 target_head = D.RPM<Vector3>(targetEntity + OFFSET_ORIGIN);

	Vector3 newAngles = CalcAnglePredictives(CameraPos, target_head, targetEntity, local);
	if (newAngles.x == 0.0f && newAngles.y == 0.0f) return { 0,0,0 };



	return newAngles;
}
inline int getClosestBone(uintptr_t ent)
{
	uintptr_t pMode_Name = read<uintptr_t>(ent + offsets::m_ModelName);
	char* modelName = reinterpret_cast<char*>(pMode_Name);
	std::string s(modelName);

	float closest = 9999;
	int boneId = -1000;

	if (s.find("bloodhound") != -1)
	{
		for (int i : bloodhoundBones)
		{
			Vector3 pos = getBonePositionByHitbox(ent, i);
			pos = ProjectWorldToScreen(pos);

			float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - pos.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - pos.y, 2));

			if (length < closest && length <= (fov * 3)) {
				closest = length;
				boneId = boneId;
			}
		}
	}
	else
	{
		for (int i : regualrBones)
		{
			Vector3 pos = getBonePositionByHitbox(ent, i);
			pos = ProjectWorldToScreen(pos);

			float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - pos.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - pos.y, 2));

			if (length < closest && length <= (fov * 3)) {
				closest = length;
				boneId = boneId;
			}
		}
	}

	return boneId;
}
inline void aimbot() {
	if (GetAsyncKeyState(aimbotkey) || GetAsyncKeyState(secondaimbotkey))
	{
		uintptr_t localPlayer = read<DWORD64>(GameAddress + offsets::LocalPlayer);
		if (localPlayer != NULL) {
			uintptr_t ent = getBestEnt(localPlayer);
			if (ent != NULL) {
				int targetBone;
				if (hitbox == 0)
				{
					targetBone = 0;
				}
				else if (hitbox == 1) {
					targetBone = 1;
				}
				else if (hitbox == 3)
				{
					targetBone = getClosestBone(ent);
				}
				else {
					targetBone = 4;
				}

				Vector3 newAngle = CalcAngle(getBonePositionByHitbox(localPlayer, 0), getBonePositionByHitbox(ent, targetBone)); //calculateAnglesForEntss(ent, localPlayer, targetBone);
				Vector3 tPos = getBonePositionByHitbox(ent, targetBone);
				tPos = ProjectWorldToScreen(tPos);
				if (tPos.Empty()) return;

				if (newAngle.x != 0 && newAngle.y != 0)
				{
					Vector3 ViewAngle = read<Vector3>(localPlayer + offsets::viewAngles);
					Vector2 punch = read<Vector2>(localPlayer + offsets::punchAngle);
					newAngle.x -= (punch.x - previousPitch) * 0.8f;
					newAngle.y -= (punch.y - previousYaw) * 0.8f;

					Vector3 delta = newAngle - ViewAngle;

					delta.Normalize();
					float newSmoothing = smothing;
					if (smothing == 1)
					{
						newSmoothing = 1.0f;
					}
					else {
						newSmoothing *= 18;
					}

					delta.y /= newSmoothing;
					delta.x /= newSmoothing;
					if (AimbotVis)
						if (vis)
							write<Vector2>(localPlayer + offsets::viewAngles, Vector2(ViewAngle.x + delta.x, ViewAngle.y + delta.y));

					if (!AimbotVis)
						write<Vector2>(localPlayer + offsets::viewAngles, Vector2(ViewAngle.x + delta.x, ViewAngle.y + delta.y));

				}
			}
		}
	}
}
inline int getTeamNumber(uintptr_t entity)
{
	return read<int>(entity + offsets::m_iTeamNum);
}
inline bool IsDist;
inline float Speed;
inline int helmid = 912;
inline bool DoAimbot = false;
inline bool removeRecoil = false;
inline std::vector<int> RareID;
inline std::vector<std::string> RareName;
inline int PlayerHealth(uintptr_t ent)
{
	return read<int>(ent + offsets::m_iHealth);
}
inline int PlayerSheild(uintptr_t ent)
{
	return read<int>(ent + offsets::m_shieldHealth);

}
inline bool InstantBullet = false;
inline bool TesFet = false;
inline bool SpeedHackV2 = false;
inline bool ShowFps = false;
inline bool SkinIntroVideo = false;
inline bool Gravity = false;
inline bool TwitchDrops = false;
inline bool Brightness = false;
inline bool DisableFog = false;
inline bool ForceCrossPlayer = false;
inline bool FastSwap = false;
inline bool NoWeaponDelay = false;
inline float Brightnessch = 25.0f;
inline float opfov = 10.0f;
inline bool Fovchanger = false;
inline float LPFOV = 25.0f;
inline bool bhop = false;
inline int bhopkey, bhopstate;
inline bool visCheck = false;
inline bool fastrate;
inline bool instantswap;
inline bool fullshoot;
inline float VisColor[4] = { 255,255,255,255 };
inline void DoBhop()
{
	while (true) {
		if (bhop)
			if (GetAsyncKeyState(bhopkey)) {
				write<int>(GameAddress + offsets::IN_JUMP + 0x08, 5);
				Sleep(5);
				write<int>(GameAddress + offsets::IN_JUMP + 0x08, 4);
				Sleep(5);
			}

	}

}
inline void doMisc(uintptr_t LocalPlayer, uintptr_t Entity)
{

	if (ShowFps) //// works
		write<bool>(GameAddress + offsets::showfps_enabled, true);
	else write<bool>(GameAddress + offsets::showfps_enabled, false);

	if (autograple)
	{
		if (GetAsyncKeyState(autograpleKey))
		{
			write<int>(GameAddress + offsets::IN_JUMP + 0x8, 4);

			auto Gn = read<int>(LocalPlayer + offsets::m_grapple + 0x0048);
			if (Gn == 1) {
				write<int>(GameAddress + offsets::IN_JUMP + 0x8, 5);
			}
		}
	}
	
	
	if (autostraf)
	{
		uintptr_t m_grapple = offsets::m_grapple;
		uintptr_t timeBase = offsets::TimeBase;
		uintptr_t OFFSET_m_traversalStartTime = offsets::m_traversalStartTime;
		uintptr_t OFFSET_m_traversalProgress = offsets::m_traversalProgress;
		static float startjumpTime = 0;
		static bool startSg = false;

		float	WorldTime = read<float>(LocalPlayer + timeBase);
		float m_traversalStartTime = read<float>(LocalPlayer + OFFSET_m_traversalStartTime);
		float m_traversalProgress = read<float>(LocalPlayer + OFFSET_m_traversalProgress);
		auto HangOnWall = -(m_traversalStartTime - WorldTime);

		if (GetAsyncKeyState(AutoStrafeeKey))
		{
			if (m_traversalProgress > 0.87f && !startSg && HangOnWall > 0.05f && HangOnWall < 1.5f) {
				//start SG
				startjumpTime = WorldTime;
				startSg = true;
			}

			if (startSg) {
				//press button
				write<int>(GameAddress + offsets::IN_JUMP + 0x8, 7);
				if ((WorldTime - startjumpTime) > 0.007) {
					write<int>(GameAddress + offsets::IN_CROUCH + 0x8, 6);
				}
			}

			if ((WorldTime - startjumpTime) > 1.5f && startSg) {
				//need to release button
				write<int>(GameAddress + offsets::IN_JUMP + 0x8, 4);
				write<int>(GameAddress + offsets::IN_CROUCH + 0x8, 4);
				startSg = false;
			}

		}


	}

	if (removeRecoil)
	{
		noRecoil();
	}

	if (Freecam)
	{
		if (GetAsyncKeyState(freecamKey))
		{
			write<int>(LocalPlayer + offsets::m_iObserverMode, 7);
			//draw_text_outline(GetSystemMetrics(0) / 2 - (ImGui::CalcTextSize("Free Cam [Enable]").x / 2), GetSystemMetrics(1) / 2 - (ImGui::CalcTextSize("Free Cam [Enable]").y / 2), ImColor(255, 0, 0, 255), "Free Cam [Enable]");
		}
		else {
			write<int>(LocalPlayer + offsets::m_iObserverMode, 0);
		}

	}
	if (ForceCrossPlayer)
	{
		write<bool>(GameAddress + offsets::crossPlay_Enabled + 0x68, true);
		write<bool>(GameAddress + offsets::crossPlay_Enabled + 0x8, true);
	}


	if (SkinChange)
	{
		SetSkin(LocalPlayer, skinId);
	}

	if (airstuck) {

		if (GetAsyncKeyState(AirStuckKey)) {
			write<float>(GameAddress + offsets::host_timescale + 0x68, 0.00000001);

		}
		else {
			write<float>(GameAddress + offsets::host_timescale + 0x68, 1.0f);
		}

	}
}
inline bool fullmapradar = false;
inline float TabSize = 10.0f;
inline auto RenderVisualsTest() -> void
{
	std::cout << "renderVisualTest\n";
	GameAddress = (uintptr_t)(GetModuleHandle("r5apex.exe"));
	if (!GameAddress)
	{
		std::cout << "Failed to get base\n";
		return;
	}
	for (int i = 0; i < 15000; i++) {
		DWORD64 Entity = GetEntityById(i);
		if (Entity == 0)
			continue;
		uintptr_t sigAddr = read<uintptr_t>(Entity + offsets::m_iSignifierName);
		if (sigAddr == 0)
			continue;
		uintptr_t localPlayer = read<uintptr_t>(GameAddress + offsets::LocalPlayer);

		char* sig = reinterpret_cast<char*>(sigAddr);
		std::string s = std::string(sig);
		if (GrenadeEsp)
		{
			uintptr_t sigAddr = read<uintptr_t>(Entity + offsets::m_iSignifierName);

			char* sig = reinterpret_cast<char*>(sigAddr);
			std::string s = std::string(sig);
			Vector3 Position = read<Vector3>(Entity + offsets::VecAbs);
			Position = ProjectWorldToScreen(Position);

		}

		if (s == "prop_survival" || s == "prop_death_box")
		{
			int id = read<int>(Entity + offsets::m_customScriptInt);
			if (isSelected(id))
			{
				Vector3 pos = read<Vector3>(Entity + offsets::VecAbs);

				float distance = calcDist(pos, read<Vector3>(localPlayer + offsets::VecAbs));
				if ((distance / 15) > maxLootDist) goto loop;
				pos = ProjectWorldToScreen(pos);

				std::string s = items::itemList[id].item_name;
				ImColor color;

				switch (items::itemList[id].m_rarity)
				{
				case items::Rarity::Weapon:
					color = ImColor(weaponColor[0], weaponColor[1], weaponColor[2]);
					break;
				case items::Rarity::Attachment:
					color = ImColor(attachemtColor[0], attachemtColor[1], attachemtColor[2]);
					break;
				case items::Rarity::Armor:
					color = ImColor(armorColor[0], armorColor[1], armorColor[2]);
					break;
				case items::Rarity::Heals:
					color = ImColor(healsColor[0], healsColor[1], healsColor[2]);
					break;
				case items::Rarity::Ammo:
					color = ImColor(ammoColor[0], ammoColor[1], ammoColor[2]);
					break;
				case items::Rarity::Grenade:
					color = ImColor(grenadeColor[0], grenadeColor[1], grenadeColor[2]);
					break;
				default:
					break;
				}

				draw_text_outline_font(pos.x, pos.y + 2, color, s.c_str(), esp_font);
			}
		}
	}

	loop:
	for (int i{ 0 }; i <= 150; i++)
	{
		uintptr_t LocalPlayer = read<uintptr_t>(GameAddress + offsets::LocalPlayer);
		uintptr_t Entity = GetEntityById(i);
		if (!Entity) continue;
		doMisc(LocalPlayer, Entity);
		if (Entity == LocalPlayer) continue;
		Vector3 Position = read<Vector3>(Entity + offsets::VecAbs);
		Vector3 headPos3D = Position;
		headPos3D.z += 70;
		int MaxHealth = read<int>(Entity + offsets::m_iMaxHealth);
		int Health = read<int>(Entity + offsets::m_iHealth);
		float distance = calcDist(headPos3D, read<Vector3>(LocalPlayer + offsets::VecAbs));
		Vector3 headPos2D = ProjectWorldToScreen(headPos3D);
		Vector3 pos2D = ProjectWorldToScreen(Position);
		
		int dist = pos2D.y - headPos2D.y;
		if (read<int>(Entity + offsets::m_bleedoutState) > 0 && bIgnoreDowned) continue;
		if (getTeamNumber(Entity) == getTeamNumber(LocalPlayer) && bTeamCheck) continue;
		if (read<Vector3>(LocalPlayer + offsets::VecAbs).Empty()) continue;
		if (bGlow)
			enableGlow();
		if (Health < 1.0f) continue;
		if (distance <= 1) continue;
		if ((distance / 15) > maxDistance) continue;
		if (headPos2D.Empty()) continue;
		if (headPos2D.Empty()) continue;
		if (pos2D.Empty()) continue;

		
			if (SpectatorCount)
			{

				float targetangle = read<float>(LocalPlayer + offsets::YAW);
				float targetyaw = -targetangle; // yaw is inverted
				if (targetyaw < 0)
					targetyaw += 360;
				targetyaw += 90; // yaw is off by 90
				if (targetyaw > 360)
					targetyaw -= 360;
				float localangle = read<float>(Entity + offsets::YAW);
				float localyaw = -localangle; // yaw is inverted
				if (localyaw < 0)
					localyaw += 360;
				localyaw += 90; // yaw is off by 90
				if (localyaw > 360)
					localyaw -= 360;

				if (targetyaw == localyaw && read<int>(Entity + offsets::m_iHealth) == 0)
					amountofspectatprs++;

				std::string Textx = "Spectator : " + std::to_string(int(amountofspectatprs));

				if (amountofspectatprs > 0 && read<int>(Entity + offsets::m_iHealth) > 0)
				{
					draw_text_outline_font(263, 15, ImColor(255, 255, 255, 255), Textx.c_str(), esp_font);

				}
				else
					draw_text_outline_font(75, 15, ImColor(255, 255, 255, 255), Textx.c_str(), esp_font);

			}
			if (bSnaplines)
			{
				ImVec2 start;
				if (snaplineSelection == 0)
					start = ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1));
				else if (snaplineSelection == 1)
					start = ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1) / 2);
				else if (snaplineSelection == 2)
					start = ImVec2(GetSystemMetrics(0) / 2, 0);

				if (pos2D.y < 5) continue;

				ImGui::GetForegroundDrawList()->AddLine(start, ImVec2(pos2D.x, pos2D.y), ImColor(snaplineCol[0], snaplineCol[1], snaplineCol[2]));
				ImGui::GetForegroundDrawList()->AddLine(ImVec2(start.x + 1, start.y), ImVec2(pos2D.x + 1, pos2D.y), ImColor(0, 0, 0));
				ImGui::GetForegroundDrawList()->AddLine(ImVec2(start.x - 1, start.y), ImVec2(pos2D.x - 1, pos2D.y), ImColor(0, 0, 0));
			}
			if (Skeleton)
			{
				boneEsp(Entity);
			}
			if (bTrigger)
			{
				triggerbot();
			}
			if (DoAimbot)
			{
				if (renderFov)
					ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2), fov * 3, ImColor(FOVCOLOR[0], FOVCOLOR[1], FOVCOLOR[2], FOVCOLOR[3]));
				if (bDrawTarget)
				{
					uintptr_t ent = getBestEnt(LocalPlayer);
					if (ent != NULL)
					{
						int targetBone;
						if (hitbox == 0)
						{
							targetBone = BoneList::Head;
						}
						else if (hitbox == 1) {
							targetBone = BoneList::Neck;
						}
						else {
							targetBone = BoneList::Pelivs;
						}

						Vector3 tPos = GetBonePos(ent, targetBone);
						tPos = ProjectWorldToScreen(tPos);
						if (tPos.Empty()) return;
						ImGui::GetForegroundDrawList()->AddLine(ImVec2(tPos.x, tPos.y), ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1) / 2), ImColor(TargetColor[0], TargetColor[1], TargetColor[2], TargetColor[3]));
					}
				}
				aimbot();
			}
			if (operatorESP)
			{

				Vector3 Head = ProjectWorldToScreen(GetBonePos(Entity, BoneList::Head));
				if (Head.Empty()) return;
				float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - Head.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - Head.y, 2));

				if (length <= (TabSize * 3))
				{
					uintptr_t pMode_Name = read<uintptr_t>(Entity + offsets::m_ModelName);
					char* modelName = reinterpret_cast<char*>(pMode_Name);
					std::string s(modelName);


					ImGui::SetNextWindowSize(ImVec2(300.000f, 150.000f), ImGuiCond_Once);
					ImGui::Begin("rename me 0", NULL, 139);

					ImVec2 P1, P2;
					ImDrawList* pDrawList;
					const auto& CurrentWindowPos = ImGui::GetWindowPos();
					const auto& pWindowDrawList = ImGui::GetWindowDrawList();
					const auto& pBackgroundDrawList = ImGui::GetBackgroundDrawList();
					const auto& pForegroundDrawList = ImGui::GetForegroundDrawList();

					P1 = ImVec2(100.000f, 100.000f);
					P1.x += CurrentWindowPos.x;
					P1.y += CurrentWindowPos.y;
					P2 = ImVec2(400.000f, 100.000f);
					P2.x += CurrentWindowPos.x;
					P2.y += CurrentWindowPos.y;
					pDrawList = pWindowDrawList;
					pDrawList->AddRectFilledMultiColor(P1, P2,
						ImColor(1.000f, 1.000f, 1.000f, 1.000f),
						ImColor(1.000f, 1.000f, 1.000f, 1.000f),
						ImColor(1.000f, 1.000f, 1.000f, 1.000f),
						ImColor(1.000f, 1.000f, 1.000f, 1.000f));
					ImGui::SetCursorPos(ImVec2(10.5, 18));
					ImGui::Image(Empty_Texture, ImVec2(109, 101.4));
					ImGui::End();

					if (s.find("pathfinder") != -1)
					{
						Empty_Texture = PathFinder_texture;
					}
					else if (s.find("revenant") != -1)
					{
						Empty_Texture = revenat_texture;

					}
					else if (s.find("seer") != -1)
					{
						Empty_Texture = seer_texture;

					}
					else if (s.find("maggie") != -1)
					{
						Empty_Texture = Maggie_texture;

					}
					else if (s.find("wattson") != -1)
					{
						Empty_Texture = wattson_texture;
					}
					else if (s.find("fuse") != -1)
					{
						Empty_Texture = Fuse_texture;
					}
					else if (s.find("catalyst") != -1)
					{
						Empty_Texture = catalyst_texture;
					}
					else if (s.find("gibraltar") != -1)
					{
						Empty_Texture = Gibraltar_texture;
					}
					else if (s.find("newcastle") != -1)
					{
						Empty_Texture = newcastle_texture;
					}
					else if (s.find("wraith") != -1)
					{
						Empty_Texture = wraith_texture;
					}
					else if (s.find("bloodhound") != -1)
					{
						Empty_Texture = bloodhound_texture;

					}
					else if (s.find("bangalore") != -1)
					{
						Empty_Texture = Bangladesh_texture;
					}
					else if (s.find("ash") != -1)
					{
						Empty_Texture = ash_texture;
					}
					else if (s.find("ballistic") != -1)
					{
						Empty_Texture = ballistic_texture;
					}
					else if (s.find("caustic") != -1)
					{
						Empty_Texture = caustic_texture;
					}
					else if (s.find("crypto") != -1)
					{
						Empty_Texture = crypto_texture;
					}
					else if (s.find("lifeline") != -1)
					{
						Empty_Texture = lifeline_texture;
					}
					else if (s.find("loba") != -1)
					{
						Empty_Texture = loba_texture;
					}
					else if (s.find("mirage") != -1)
					{
						Empty_Texture = mirage_texture;
					}
					else if (s.find("octane") != -1)
					{
						Empty_Texture = octane_texture;
					}
					else if (s.find("rampart") != -1)
					{
						Empty_Texture = rampart_texture;
					}
					else if (s.find("valk") != -1)
					{
						Empty_Texture = valk_texture;
					}
					else if (s.find("vantage") != -1)
					{
						Empty_Texture = vantage_texture;
					}
					else if (s.find("horizon") != -1)
					{
						Empty_Texture = vantage_texture;
					}
					else {
						Empty_Texture = nullptr;
					}
				}
			}
			if (bbox)
			{
				ImColor col;
				if (isVisable(Entity, i))
					col = ImColor(BoxCol[0], BoxCol[1], BoxCol[2]);
				else
					col = ImColor(NBoxCol[0], NBoxCol[1], NBoxCol[2]);

				if (visCheck)
					vis ? DrawBox(ImVec2(headPos2D.x, headPos2D.y), ImVec2(pos2D.x, pos2D.y), col, 0.7f) : DrawBox(ImVec2(headPos2D.x, headPos2D.y), ImVec2(pos2D.x, pos2D.y), ImColor(VisColor[0], VisColor[1], VisColor[2], VisColor[3]), 0.7f);
				else
					DrawBox(ImVec2(headPos2D.x, headPos2D.y), ImVec2(pos2D.x, pos2D.y), col, 0.7f);

			}
			if (bCorner)
			{
				ImColor col;
				if (isVisable(Entity, i))
					col = ImColor(BoxCol[0], BoxCol[1], BoxCol[2]);
				else
					col = ImColor(NBoxCol[0], NBoxCol[1], NBoxCol[2]);

				DrawCorneredBox(pos2D.x - (dist / 4), headPos2D.y, dist / 2, dist, col, 0.7f);
			}
			if (bdistance)
			{

				Vector3 newPos = Position;
				newPos.z -= 3;
				Vector3 newpos2d = ProjectWorldToScreen(newPos);
				if (newpos2d.Empty()) return;
				std::string Distance = std::to_string(int(distance / 15)) + "m";

				/*ImGui::PushFont(esp_font);
				ImVec2 displacment = ImGui::CalcTextSize(Distance.c_str());
				ImGui::PopFont();*/

				if (!bhealth && !bshield)
					draw_text_outline_font(newpos2d.x, newpos2d.y + 15, ImColor(DistCol[0], DistCol[1], DistCol[2]), Distance.c_str(), esp_font);
				else
					draw_text_outline_font(newpos2d.x, newpos2d.y + 29, ImColor(DistCol[0], DistCol[1], DistCol[2]), Distance.c_str(), esp_font);
			}
			if (bhealth)
			{

				float width = (float(dist) / 2) * (float(Health) / 100);
				ImColor HealthCol;

				if (Health > 75)
				{
					HealthCol = { 0,255,0,255 };
				}
				else if (Health > 45)
				{
					HealthCol = { 255, 99,0,255 };
				}
				else {
					HealthCol = { 255,0,0,255 };

				}
				/*std::string sHealth = std::to_string(int(Health));
				std::string m_sHealth = std::to_string(int(MaxHealth));
				ImGui::GetForegroundDrawList()->AddText(ImVec2(headPos2D.x - 5, headPos2D.y - 5), ImColor(255, 0, 155, 255), sHealth.c_str());
				ImGui::GetForegroundDrawList()->AddText(ImVec2(headPos2D.x - 5, headPos2D.y - 15), ImColor(255, 0, 155, 255), m_sHealth.c_str());*/

				ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4 - 1, pos2D.y + 3 - 1), ImVec2(pos2D.x + dist / 4 + 1, pos2D.y + 9 + 1), ImColor(0, 0, 0)); // black outline
				ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 3), ImVec2(pos2D.x + dist / 4, pos2D.y + 9), ImColor(28, 28, 28)); // grey background
				ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 3), ImVec2((pos2D.x - dist / 4) + width, pos2D.y + 9), HealthCol); // green health bar
			}
			if (bSeer)
			{
				int shield = read<int>(Entity + offsets::m_shieldHealth);

				int shieldType = read<int>(Entity + offsets::m_armorType);
				Vector3 Head = ProjectWorldToScreen(GetBonePos(Entity, BoneList::Head));
				if (Head.Empty()) return;
				float length = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - Head.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - Head.y, 2));

				if (length <= (seerFov * 3))
					SeerHealth(Head.x, Head.y - 15, PlayerSheild(Entity), 125, shieldType, PlayerHealth(Entity));
			}
			if (bshield)
			{
				int shield = read<int>(Entity + offsets::m_shieldHealth);
				float width = (float(dist) / 2) * (float(shield) / 125);
				bool draw = true;
				int shieldType = read<int>(Entity + offsets::m_armorType);
				ImColor color;
				if (shieldType == 5)
				{
					color = ImColor(200, 15, 50);
				}
				else if (shieldType == 4)
				{
					color = ImColor(205, 195, 50);
				}
				else if (shieldType == 3)
				{
					color = ImColor(150, 65, 245);
				}
				else if (shieldType == 2)
				{
					color = ImColor(25, 115, 175);
				}
				else if (shieldType == 1)
				{
					color = ImColor(215, 215, 215);
				}
				else
				{
					draw = false;
				}

				if (draw)
				{
					if (bhealth)
					{
						ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 12), ImVec2(pos2D.x + dist / 4, pos2D.y + 18), ImColor(28, 28, 28)); // grey background
						ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 12), ImVec2((pos2D.x - dist / 4) + width, pos2D.y + 18), color); // shield bar
						ImGui::GetBackgroundDrawList()->AddRect(ImVec2(pos2D.x - dist / 4 - 1, pos2D.y + 12 - 1), ImVec2(pos2D.x + dist / 4 + 1, pos2D.y + 18 + 1), ImColor(0, 0, 0)); // black outline
					}
					else
					{
						ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 3), ImVec2(pos2D.x + dist / 4, pos2D.y + 9), ImColor(28, 28, 28)); // grey background
						ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos2D.x - dist / 4, pos2D.y + 3), ImVec2((pos2D.x - dist / 4) + width, pos2D.y + 9), color); // shield bar
						ImGui::GetBackgroundDrawList()->AddRect(ImVec2(pos2D.x - dist / 4 - 1, pos2D.y + 12 - 1), ImVec2(pos2D.x + dist / 4 + 1, pos2D.y + 18 + 1), ImColor(0, 0, 0)); // black outline
					}
				}

			}
			if (bname)
			{

				Vector3 newPos = Position;
				newPos.z -= 3;
				Vector3 newpos2d = ProjectWorldToScreen(newPos);

				uintptr_t nameptr = read<uintptr_t>(GameAddress + offsets::NameList + (i - 1) * 0x10);
				if (!nameptr) continue;

				char* name = reinterpret_cast<char*>(nameptr);

				ImGui::PushFont(esp_font);
				if (!bhealth && !bshield)
					draw_text_outline_font(newpos2d.x, newpos2d.y, ImColor(NameCol[0], NameCol[1], NameCol[2]), name, esp_font);
				else
					draw_text_outline_font(newpos2d.x, newpos2d.y + 21, ImColor(NameCol[0], NameCol[1], NameCol[2]), name, esp_font);
				ImGui::PopFont();
			}

		

	}

	
}



// hand 150 169 200 165
// gun 200 186 0 16
// player 1, 108, 100, 96