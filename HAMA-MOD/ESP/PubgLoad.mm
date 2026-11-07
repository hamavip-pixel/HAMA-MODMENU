// HMOOD__TG@i_8_f
#import "PubgLoad.h"
#import "Engine.h"
#import "menu.h"
#import "HeeeNoScreenShotView.h"
#import <QuartzCore/QuartzCore.h>
#include <math.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <unistd.h>

bool aPVQRIF = false;
bool zQkX8A = false;
bool MxVsd = false;
bool MXValQy = false;
extern bool MenDeal;
float menuIconAlpha = .92f;

// HMOOD__TG@i_8_f
@interface HMOODFloatingWindow : UIWindow
@property(nonatomic, weak) UIView* interactiveView;
@end

@implementation HMOODFloatingWindow
- (BOOL)canBecomeKeyWindow { return NO; }
- (UIView*)hitTest:(CGPoint)point withEvent:(UIEvent*)event {
    UIView* target = [super hitTest:point withEvent:event];
    return target && (target == self.interactiveView || [target isDescendantOfView:self.interactiveView]) ? target : nil;
}
@end

// HMOOD__TG@i_8_f
@interface ImGuiLoad ()
@property(nonatomic, strong) metalbiew* vna;
@property(nonatomic, strong) HMOODFloatingWindow* floatingWindow;
@property(nonatomic, strong) UIButton* menuIconView;
@property(nonatomic, strong) NSTimer* iconTimer;
@property(nonatomic, assign) CGPoint dragOrigin;
@property(nonatomic, assign) BOOL dragging;
@property(nonatomic, assign) CGSize previousWindowSize;
- (UIWindow*)getKeyWindow;
- (void)attachRenderer;
- (void)refreshMenuIcon;
- (void)dragMenuIcon:(UIPanGestureRecognizer*)gesture;
@end

@implementation ImGuiLoad
+ (void)load { [self load1]; }

+ (void)load1 {
    struct kinfo_proc info;
    int query[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()};
    size_t size = sizeof(info);
    if (sysctl(query, 4, &info, &size, NULL, 0) == 0 && (info.kp_proc.p_flag & P_TRACED)) {
        abort();
    }
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 3 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        [[self share] initTapGes];
    });
}

+ (instancetype)share {
    static ImGuiLoad* instance = nil;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ instance = [[ImGuiLoad alloc] init]; });
    return instance;
}

- (UIWindow*)getKeyWindow {
    UIWindow* fallback = nil;
    for (UIScene* scene in UIApplication.sharedApplication.connectedScenes) {
        if (![scene isKindOfClass:UIWindowScene.class] || scene.activationState != UISceneActivationStateForegroundActive)
            continue;
        for (UIWindow* window in ((UIWindowScene*)scene).windows) {
            if (window == self.floatingWindow || [window isKindOfClass:HMOODFloatingWindow.class] ||
                window.hidden || window.windowLevel != UIWindowLevelNormal) continue;
            if (window.isKeyWindow) return window;
            if (!fallback && window.rootViewController) fallback = window;
        }
    }
    return fallback;
}

- (void)attachRenderer {
    UIWindow* window = [self getKeyWindow];
    if (!window || !window.rootViewController) return;
    if (!self.vna) self.vna = [[metalbiew alloc] init];
    UIView* view = self.vna.view;
    view.frame = window.bounds;
    view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    if (!view.superview) [window.rootViewController.view addSubview:view];
    view.userInteractionEnabled = MenDeal;
}

- (void)initTapGes {
    if (![NSThread isMainThread]) {
        dispatch_async(dispatch_get_main_queue(), ^{ [self initTapGes]; });
        return;
    }
    [self attachRenderer];
    [self refreshMenuIcon];
    if (!self.iconTimer) {
        __weak ImGuiLoad* weakSelf = self;
        self.iconTimer = [NSTimer timerWithTimeInterval:.25 repeats:YES block:^(NSTimer* timer) {
            (void)timer;
            [weakSelf refreshMenuIcon];
        }];
        [NSRunLoop.mainRunLoop addTimer:self.iconTimer forMode:NSRunLoopCommonModes];
    }
}

- (void)refreshMenuIcon {
    UIWindow* window = [self getKeyWindow];
    if (!window) { self.floatingWindow.hidden = YES; return; }
    if (!self.floatingWindow || self.floatingWindow.windowScene != window.windowScene) {
        self.floatingWindow.hidden = YES;
        HMOODFloatingWindow* floating = [[HMOODFloatingWindow alloc] initWithWindowScene:window.windowScene];
        floating.frame = window.bounds;
        floating.backgroundColor = UIColor.clearColor;
        floating.windowLevel = UIWindowLevelAlert + 1.f;
        UIViewController* controller = [UIViewController new];
        controller.view = [[HeeeNoScreenShotView alloc] initWithFrame:floating.bounds];
        controller.view.backgroundColor = UIColor.clearColor;
        floating.rootViewController = controller;
        UIButton* icon = [UIButton buttonWithType:UIButtonTypeCustom];
        icon.frame = CGRectMake(0, 0, 52, 52);
        icon.adjustsImageWhenHighlighted = NO;
        UIImage* image = GetMenuBadgeImage();
        if (image) [icon setImage:image forState:UIControlStateNormal];
        else {
            [icon setTitle:@"H" forState:UIControlStateNormal];
            [icon setTitleColor:UIColor.whiteColor forState:UIControlStateNormal];
            icon.backgroundColor = [UIColor colorWithRed:.35f green:.02f blue:.08f alpha:1.f];
        }
        icon.imageView.contentMode = UIViewContentModeScaleAspectFit;
        icon.accessibilityLabel = @"HMOOD VIP";
        icon.layer.cornerRadius = 26.f;
        icon.layer.shadowColor = UIColor.blackColor.CGColor;
        icon.layer.shadowOpacity = .5f;
        icon.layer.shadowRadius = 4.f;
        icon.layer.shadowOffset = CGSizeMake(0, 2);
        [icon addTarget:self action:@selector(show) forControlEvents:UIControlEventTouchUpInside];
        UIPanGestureRecognizer* pan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(dragMenuIcon:)];
        pan.cancelsTouchesInView = YES;
        [icon addGestureRecognizer:pan];
        [controller.view addSubview:icon];
        floating.interactiveView = icon;
        self.floatingWindow = floating;
        self.menuIconView = icon;
        self.previousWindowSize = floating.bounds.size;
        NSUserDefaults* defaults = NSUserDefaults.standardUserDefaults;
        const CGFloat x = [defaults objectForKey:@"HMOODIconX"] ? [defaults doubleForKey:@"HMOODIconX"] : .94;
        const CGFloat y = [defaults objectForKey:@"HMOODIconY"] ? [defaults doubleForKey:@"HMOODIconY"] : .32;
        icon.center = CGPointMake(x * floating.bounds.size.width, y * floating.bounds.size.height);
    }
    [self attachRenderer];
    self.floatingWindow.frame = window.bounds;
    const CGSize previous = self.previousWindowSize, current = self.floatingWindow.bounds.size;
    if (!self.dragging && previous.width > 0 && previous.height > 0 && !CGSizeEqualToSize(previous, current))
        self.menuIconView.center = CGPointMake(self.menuIconView.center.x * current.width / previous.width,
                                               self.menuIconView.center.y * current.height / previous.height);
    self.previousWindowSize = current;
    if (!self.dragging) {
        CGPoint center = self.menuIconView.center;
        const UIEdgeInsets safe = window.safeAreaInsets;
        center.x = fmax(safe.left + 29.f, fmin(self.floatingWindow.bounds.size.width - safe.right - 29.f, center.x));
        center.y = fmax(safe.top + 29.f, fmin(self.floatingWindow.bounds.size.height - safe.bottom - 29.f, center.y));
        self.menuIconView.center = center;
    }
    self.menuIconView.alpha = MenDeal ? 1.f : menuIconAlpha;
    self.floatingWindow.hidden = NO;
}

- (void)dragMenuIcon:(UIPanGestureRecognizer*)gesture {
    if (gesture.state == UIGestureRecognizerStateBegan) {
        self.dragging = YES;
        self.dragOrigin = self.menuIconView.center;
    }
    const CGPoint shift = [gesture translationInView:self.floatingWindow.rootViewController.view];
    if (gesture.state == UIGestureRecognizerStateChanged)
        self.menuIconView.center = CGPointMake(self.dragOrigin.x + shift.x, self.dragOrigin.y + shift.y);
    if (gesture.state == UIGestureRecognizerStateEnded || gesture.state == UIGestureRecognizerStateCancelled) {
        self.dragging = NO;
        [self refreshMenuIcon];
        const CGSize size = self.floatingWindow.bounds.size;
        if (size.width > 0 && size.height > 0) {
            [NSUserDefaults.standardUserDefaults setDouble:self.menuIconView.center.x / size.width forKey:@"HMOODIconX"];
            [NSUserDefaults.standardUserDefaults setDouble:self.menuIconView.center.y / size.height forKey:@"HMOODIconY"];
        }
    }
}

- (void)updateMenuIconAlpha:(float)alpha {
    if (![NSThread isMainThread]) {
        dispatch_async(dispatch_get_main_queue(), ^{ [self updateMenuIconAlpha:alpha]; });
        return;
    }
    menuIconAlpha = fmaxf(.35f, fminf(1.f, alpha));
    [self refreshMenuIcon];
}

- (void)show {
    if (![NSThread isMainThread]) {
        dispatch_async(dispatch_get_main_queue(), ^{ [self show]; });
        return;
    }
    [self attachRenderer];
    if (!self.vna.view.superview) return;
    MenDeal = !MenDeal;
    self.vna.view.userInteractionEnabled = MenDeal;
    [self refreshMenuIcon];
}
@end
