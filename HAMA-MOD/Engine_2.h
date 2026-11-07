// HMOOD__TG@i_8_f
#pragma once

#include <atomic>

#ifndef HMOOD_METALBIEW_IMPLEMENTATION
#error "metalbiew_private.h must only be included by metalbiew.mm"
#endif

float Z = 0.5f;
static std::atomic<float> aimDisplayWidth{0.f}, aimDisplayHeight{0.f};

@interface metalbiew () <MTKViewDelegate>
@property(nonatomic, strong) IBOutlet MTKView* mtkView;
@property(nonatomic, strong) id<MTLDevice> device;
@property(nonatomic, strong) id<MTLCommandQueue> commandQueue;
@property(nonatomic, weak) NSTimer* timer;
@property(nonatomic, assign) NSInteger aimcir;
@property(nonatomic, assign) NSInteger rpr;

@end

// HMOOD__TG@i_8_f
static uintptr_t Get_module_base() {
    uint32_t count = _dyld_image_count();
    for (int i = 0; i < count; i++) {
        std::string path = (const char*)_dyld_get_image_name(i);
        if (path.find("ShadowTrackerExtra.app/ShadowTrackerExtra") != path.npos) {
            return (uintptr_t)_dyld_get_image_vmaddr_slide(i);
        }
    }
    return 0;
}
// HMOOD__TG@i_8_f
bool IsValidAddress(kaddr addr) {
    return addr > 0x100000000 && addr < 0x2000000000;
}

extern bool aPVQRIF;
extern bool zQkX8A;
extern bool MxVsd;
extern bool MXValQy;

extern UIView* menuIconView;
extern float menuIconAlpha;

bool hideNameKillMsg = false;

float strokeIntensity = 1.0f;

ASTExtraPlayerController* g_LocalController = 0;

ASTExtraPlayerController* localPlayerController = 0;

ASTExtraPlayerCharacter* localPlayer = 0;

ImFont* mainFont = nullptr;

float globalHpAlphaF = 1.00f;

ImU32 COLOR_Distance = IM_COL32(255, 255, 255, 255);

ImColor borderColor = ImColor(0, 255, 0, 255);
ImColor bgColor = ImColor(0, 0, 0, 80);

bool ifismembotenable = false;

namespace Settings {

    bool isVisibilityCheck = true;
    bool ifismembotenable = false;
    bool BypassMode = false;

    namespace SettingsTab {
        bool BypassMode = false;
    }

    namespace Aimbot {

        bool Enable = false;
        bool Tick = false;
        int AimMethod = 0;
        std::atomic<int> TriggerMode{3};
        float FOV = 200.f;

        bool MemoryAimbot = false;
        bool SilentAim = false;

        namespace SilentAimSettings {

            bool Enable = true;
            bool AimKnocked = false;
            bool Highprecisiontracking = false;

            int Aimpositon = 0;
            bool Prediction = true;

            bool EnableFov = true;

            bool BypassFOVLimit = false;

            bool AimingLine = false;
            float MaxStepDeg = 2.0f;

            int LegitTrackSwitchrate = 6;
        }
    }
}

float ESPMaxDistance = 300.f;
float AlertRadius = 50.0f;
float SilentAimMaxDistance = 355.f;
int IsStyle = 1;

namespace imgui {
    bool ESP = false;
    bool Boxes = false;
    bool HideBot = false;
    bool Health = false;
    bool Line = false;
    bool Name = false;
    bool TeamID = false;
    bool Distance = false;
    bool EnemyCount = false;
    bool Weapon = false;
    bool Bone = false;
    bool GameInfo = false;
    bool Alert360 = false;
    bool EnemyAiming = false;
    bool Items = false;
    bool Lootbox = false;
    bool Vehicle = false;

    bool Grenade = false;
}

namespace itemesp {
    inline bool Enable = false;

    inline bool Vehicles = true;

    inline float MaxDistance = 200.0f;
}

bool IsEnglish;
bool ShowFov = false;

int 玩家, 人机;

bool 坐标追;

bool 自动开火;

const float offset = 21.0f;

bool 下雨;

float 巨人;

bool 人物变大;
bool 重置游客;

int 打击圈 = 0;
int CL = 1;

bool 瞄准线;
bool AimBot = false;
int AimF = 3;
int value = 120;

int Aim = 0;

float 追踪概率 = 100;

bool FixShoot;
float Cross = 150.f;
float g_disstance = 150.0f;

bool IgnoreKnocked = false;

bool VisCheck = false;
bool IgnoreBot = false;

float RadarX = 30;
float RadarY = 10;
bool 对局信息 = true;
bool IsLogin = true;
bool Enable = false;

float crosshairSizeSlider = 0.0f;
bool IsCrossHair = false;

bool IsNocamerashake = false;

bool IsFastshoot = false;
bool IsFastSwitch = false;
bool IsNorecoil2 = false;

bool IsFastDrop = false;

bool IsHitXPL = false;
bool InstantHit = false;

float carx;
float cary;
float carz;
bool CarFly = false;

bool tudongnhay = false;
bool chaynhanhv2 = false;
float tocdoquay;
bool isSpinning = false;

float DanceValue;

float DancerValue;

float rainbowSpeed = 0.02f;

bool MaxStep = false;

bool good = false;

bool Blacksky = false;

bool 枪械变大 = false;
bool HitX = false;

bool ReCo = false;

float magicX = 23.f + 150.f;
float magicY = 25.f + 150.f;
float magicZ = 30.5f + 150.f;
bool MagicSDK = false;

static bool Magic = false;

bool textBorder = true;

static bool IsLaunch = false;

bool ResetGuest;
int SX = 0;

float Gun_Size = 2.5;

bool 人物自杀;
bool 据点 = false;

static int currentLanguage = 0;

bool WideView = false;
bool MemoryFastScope = false;
bool MemoryZoom = false;
bool MemoryDamage = false;
bool MemoryRainbow = false;
bool MemoryCrossSpin = false;
float MemoryZoomFov = 40.f;
float MemoryRainbowSpeed = 1.6f;
float MemoryCrossSpinSpeed = 180.f;
int WideValue = 100;

bool initialized = false;
// HMOOD__TG@i_8_f
void InitializeMemoryProtection() {
    if (!initialized) {

        initialized = true;
    }
}

#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

bool hideHacker = true;
HeeeNoScreenShotView* hideesp = nullptr;

kaddr module = (unsigned long)Get_module_base();
namespace YN {
    int boxtype = 1;
    int healthbartype = 0;
    int Nationtype = 2;
    int DirectionLineSize = 70;
    int VehicleDirectionLineSize = 100;
    int offscreen_range = 40;
    int max_distance_offscreen = 400;
    int playersdistancessize = 600;
    bool esp_Outline = true;
    int distance_Radar = 150;
}

long l2 = 0xFFFFF;

using namespace std;
using namespace SDK;
using namespace ImGui;

static int Radar = 0;

bool 下雪特效 = false;

struct sConfig {
    struct sESPMenu {
        bool Health;

        bool Name;
        bool Distance;
        bool TeamID;
        bool 对局信息;
        bool Weapon;

        bool Vehicle;
        bool IgnoreBot;
    };
    sESPMenu ESPMenu{false};
};
sConfig Config{false};

UISlider* Auto1;

int Interval = 1;
int counter;

float AimSmooth = 5.0f;

int boxtype = 1;
int healthbartype = 0;
int Nationtype = 2;
int DirectionLineSize = 70;
int VehicleDirectionLineSize = 100;
int offscreen_range = 40;
int max_distance_offscreen = 400;
int playersdistancessize = 600;
bool esp_Outline = true;
int distance_Radar = 150;

#define SLEEP_TIME 1000LL / 120LL
#define TORAD(x) ((x) * (M_PI / 180.f))
#define DefineHook(RET, NAME, ARGS) \          \
    ARGS;                           


int screenWidth ;
int screenHeight ;


char extra[30];
float density = -1;


#define PI 3.14159265358979323846
#define __fastcall


