
#import <UIKit/UIKit.h>

@interface HAMAViewController : UIViewController
@end

@implementation HAMAViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor colorWithRed:7.0/255.0
                                                green:11.0/255.0
                                                 blue:16.0/255.0
                                                alpha:1.0];

    UILabel *logo = [[UILabel alloc] init];
    logo.text = @"HAMA⚡VIP";
    logo.textColor = UIColor.whiteColor;
    logo.font = [UIFont boldSystemFontOfSize:32];
    logo.textAlignment = NSTextAlignmentCenter;
    logo.frame = CGRectMake(20, 100, self.view.bounds.size.width-40, 45);
    [self.view addSubview:logo];

    UILabel *telegram = [[UILabel alloc] init];
    telegram.text = @"HAMA⚡VIP TELEGRAM CHNELL👇";
    telegram.textColor = UIColor.whiteColor;
    telegram.font = [UIFont boldSystemFontOfSize:16];
    telegram.textAlignment = NSTextAlignmentCenter;
    telegram.frame = CGRectMake(20, 180, self.view.bounds.size.width-40, 35);
    [self.view addSubview:telegram];

    UIButton *join = [UIButton buttonWithType:UIButtonTypeSystem];
    join.frame = CGRectMake(30, 235, self.view.bounds.size.width-60, 48);
    [join setTitle:@"Join Channel" forState:UIControlStateNormal];
    [join setTitleColor:UIColor.whiteColor forState:UIControlStateNormal];
    join.backgroundColor = [UIColor colorWithRed:0 green:0.65 blue:0.4 alpha:1];
    join.layer.cornerRadius = 10;
    [join addTarget:self action:@selector(openTelegram)
   forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:join];

    UIButton *continueButton = [UIButton buttonWithType:UIButtonTypeSystem];
    continueButton.frame = CGRectMake(30, 300, self.view.bounds.size.width-60, 48);
    [continueButton setTitle:@"Continue" forState:UIControlStateNormal];
    [continueButton setTitleColor:UIColor.whiteColor forState:UIControlStateNormal];
    continueButton.layer.borderColor = [UIColor greenColor].CGColor;
    continueButton.layer.borderWidth = 1;
    continueButton.layer.cornerRadius = 10;
    [continueButton addTarget:self action:@selector(showStatus)
             forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:continueButton];

    self.view.tag = 100;
}

- (void)openTelegram {
    NSURL *url = [NSURL URLWithString:@"https://t.me/hama_vip1"];
    [[UIApplication sharedApplication] openURL:url
        options:@{}
        completionHandler:nil];
}

- (void)showStatus {
    for (UIView *view in self.view.subviews) {
        [view removeFromSuperview];
    }

    UILabel *status = [[UILabel alloc] init];
    status.text = @"ANTI BAN STATUS: ONLINE!...";
    status.textColor = [UIColor colorWithRed:112.0/255.0
                                       green:215.0/255.0
                                        blue:92.0/255.0
                                       alpha:1.0];
    status.font = [UIFont boldSystemFontOfSize:13];
    status.textAlignment = NSTextAlignmentCenter;
    status.frame = CGRectMake(0, 100, self.view.bounds.size.width, 30);
    [self.view addSubview:status];
}

@end
