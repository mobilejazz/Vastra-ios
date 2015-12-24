//
//  PWDTimestampValidationStrategy.m
//  PeerWell
//
//  Created by Joan Martin on 24/11/15.
//  Copyright © 2015 Manish Shah. All rights reserved.
//

#import "MJTimestampValidationStrategy.h"

@implementation MJTimestampValidationStrategy

- (MJValidationStrategyResult)isObjectValid:(id <MJTimestampValidationStrategyDataSource>)object
{
    NSDate *lastUpdate = [object lastUpdate];
    NSTimeInterval expiryTimeInterval = [object expiryTimeInterval];
    
    // If not last update available, we cannot decide
    if (!lastUpdate)
        return MJValidationStrategyResultUnknown;
    
    NSDate *date = [NSDate date];
    
    NSTimeInterval diff = [lastUpdate timeIntervalSinceDate:date];
    
    if (diff < expiryTimeInterval)
        return MJValidationStrategyResultValid;

    return MJValidationStrategyResultInvalid;
}

@end
