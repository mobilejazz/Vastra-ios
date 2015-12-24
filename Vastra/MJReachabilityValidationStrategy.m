//
//  PWDReachabilityValidationStrategy.m
//  PeerWell
//
//  Created by Joan Martin on 24/11/15.
//  Copyright © 2015 Manish Shah. All rights reserved.
//

#import "MJReachabilityValidationStrategy.h"

#import <Reachability/Reachability.h>

@implementation MJReachabilityValidationStrategy
{
    Reachability *_reachability;
    
    BOOL _serviceAvailable;
}

- (id)initWithHost:(NSString*)host
{
    self = [super init];
    if (self)
    {
        _reachability = [Reachability reachabilityWithHostname:host];
        [_reachability startNotifier];
        
        // is passed in the object parameter
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(pw_reachabilityChanged:)
                                                     name:kReachabilityChangedNotification
                                                   object:nil];

    }
    return self;
}

- (void)dealloc
{
    [_reachability stopNotifier];
    [[NSNotificationCenter defaultCenter] removeObserver:self
                                                    name:kReachabilityChangedNotification
                                                  object:_reachability];
}

- (MJValidationStrategyResult)isObjectValid:(id<MJValidationStrategyDataSource>)object
{
    if (![_reachability isReachable] && _serviceAvailable)
    {
        // If not reachable, cache is valid
        return MJValidationStrategyResultValid;
    }
    
    return MJValidationStrategyResultUnknown;
}

- (void)pw_reachabilityChanged:(NSNotification*)notification
{
    _serviceAvailable = YES;
}

@end
