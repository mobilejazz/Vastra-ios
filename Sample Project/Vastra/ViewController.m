//
//  ViewController.m
//  Vastra
//
//  Created by Joan Martin on 24/12/15.
//  Copyright © 2015 Mobile Jazz. All rights reserved.
//

#import "ViewController.h"

#import "VSValidationService.h"
#import "MJUser.h"

#import "VSReachabilityValidationStrategy.h"
#import "VSTimestampValidationStrategy.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    NSString *host = @"www.google.com"; // Valid host
//    NSString *host = @"asdfasdf"; // Invalid host --> Reachability strategy will return always Valid.
    
    VSValidationStrategy *defaultStrategy = [[VSValidationStrategy alloc] init];
    VSValidationStrategy *timestampStrategy = [[VSTimestampValidationStrategy alloc] init];
    VSValidationStrategy *reachabilityStrategy = [[VSReachabilityValidationStrategy alloc] initWithHost:host];
    
    VSValidationService *validationService = [[VSValidationService alloc] initWithStrategies:@[reachabilityStrategy,
                                                                                               timestampStrategy,
                                                                                               defaultStrategy]];
    
    MJUser *user = [[MJUser alloc] init];
    user.name = @"John Doe";
    user.updatedAt = [NSDate date];
    
    if ([validationService isObjectValid:user])
    {
        NSLog(@"User did pass validation");
    }
    else
    {
        NSLog(@"User failed validation");
    }
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(6 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if ([validationService isObjectValid:user])
        {
            NSLog(@"After 6 seconds: User did pass validation");
        }
        else
        {
            NSLog(@"After 6 seconds: User failed validation");
        }
    });
}

@end
