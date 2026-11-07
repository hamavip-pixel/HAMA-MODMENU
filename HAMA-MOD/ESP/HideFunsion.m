// HMOOD__TG@i_8_f
 

#import "HideFunsion.h"
#import "HeeeNoScreenShotView.h"

@implementation HideFunsion {
    HeeeNoScreenShotView *_hideesp;
}

+ (instancetype)sharedManager {
    static HideFunsion *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[HideFunsion alloc] initPrivate];
    });
    return sharedInstance;
}

 
- (instancetype)initPrivate {
    self = [super init];
    if (self) {
        _hideesp = [[HeeeNoScreenShotView alloc] initWithFrame:[UIScreen mainScreen].bounds];
        [[UIApplication sharedApplication].windows[0].rootViewController.view addSubview:_hideesp];
        _hideesp.userInteractionEnabled = YES;  
        _hideesp.hidden = YES;  
    }
    return self;
}

 
- (instancetype)init {
    @throw [NSException exceptionWithName:@"Singleton"
                                   reason:@"Use +[HideFunsion sharedManager]"
                                 userInfo:nil];
    return nil;
}

 
- (void)addView:(UIView *)view
     isStreaming:(BOOL)streaming
  MenDeal:(BOOL)MenDeal {

    if (streaming) {
        [_hideesp addSubview:view];
    } else {
        [[UIApplication sharedApplication].keyWindow addSubview:view];
    }

    _hideesp.hidden = !(streaming || MenDeal);

    _hideesp.userInteractionEnabled = MenDeal;
}

@end
