//
//  PWDReachabilityValidationStrategy.m
//  PeerWell
//
//  Created by Joan Martin on 24/11/15.
//  Copyright © 2015 Manish Shah. All rights reserved.
//

#import "VSReachabilityValidationStrategy.h"

#import <Reachability/Reachability.h>

@implementation VSReachabilityValidationStrategy
{
    Reachability *_reachability;
    
    BOOL _serviceAvailable;
}

- (id)initWithHost:(NSString*)host
{
    self = [super init];
    if (self)
    {
        _host = host;
        
        _reachability = [Reachability reachabilityWithHostname:host];
        [_reachability startNotifier];
        
        // is passed in the object parameter
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(vs_reachabilityChanged:)
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

- (VSValidationStrategyResult)isObjectValid:(id<VSValidationStrategyDataSource>)object
{
    if (![_reachability isReachable] && _serviceAvailable)
    {
        // If not reachable, cache is valid
        return VSValidationStrategyResultValid;
    }
    
    return VSValidationStrategyResultUnknown;
}

- (void)vs_reachabilityChanged:(NSNotification*)notification
{
    _serviceAvailable = YES;
}

@end
