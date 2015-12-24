//
// Copyright 2015 Mobile Jazz SL
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
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
