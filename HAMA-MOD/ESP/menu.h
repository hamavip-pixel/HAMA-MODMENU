// HMOOD__TG@i_8_f
 

#pragma once

#include "imgui/imgui.h"

extern bool MenDeal;
extern ImFont* cyberMenuFont;

void ApplyImGuiStyle();
void InitializeMenuFonts(ImGuiIO& io);
void RenderMenu();

void SetMenuLanguage(int language);
int GetMenuLanguage();
const char* TranslateMenuText(const char* value);

void DrawMenuHudBadge(ImDrawList* draw, ImVec2 center, float diameter);
#ifdef __OBJC__
@class UIImage;
UIImage* GetMenuBadgeImage();
#endif
