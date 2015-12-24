//
//  PWDTimestampValidationStrategy.m
//  PeerWell
//
//  Created by Joan Martin on 24/11/15.
//  Copyright © 2015 Manish Shah. All rights reserved.
//

#import "VSTimestampValidationStrategy.h"

@implementation VSTimestampValidationStrategy

- (VSValidationStrategyResult)isObjectValid:(id <VSTimestampValidationStrategyDataSource>)object
{
    NSDate *lastUpdate = [object lastUpdate];
    NSTimeInterval expiryTimeInterval = [object expiryTimeInterval];
    
    // If not last update available, we cannot decide
    if (!lastUpdate)
        return VSValidationStrategyResultUnknown;
    
    NSDate *date = [NSDate date];
    
    NSTimeInterval diff = [date timeIntervalSinceDate:lastUpdate];
    
    if (diff < expiryTimeInterval)
        return VSValidationStrategyResultValid;

    return VSValidationStrategyResultInvalid;
}

@end
