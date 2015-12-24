//
//  MJUser.m
//  Vastra
//
//  Created by Joan Martin on 24/12/15.
//  Copyright © 2015 Mobile Jazz. All rights reserved.
//

#import "MJUser.h"

@implementation MJUser

#pragma mark - Protocols
#pragma mark VSTimestampValidationStrategyDataSource

- (NSDate*)lastUpdate
{
    return _updatedAt;
}

- (NSTimeInterval)expiryTimeInterval
{
    return 5; // 5 seconds
}

@end
