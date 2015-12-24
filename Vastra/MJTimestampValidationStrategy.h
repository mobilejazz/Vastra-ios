//
//  PWDTimestampValidationStrategy.h
//  PeerWell
//
//  Created by Joan Martin on 24/11/15.
//  Copyright © 2015 Manish Shah. All rights reserved.
//

#import "MJValidationStrategy.h"

@protocol MJTimestampValidationStrategyDataSource <MJValidationStrategyDataSource>

- (NSDate*)lastUpdate;
- (NSTimeInterval)expiryTimeInterval;

@end

@interface MJTimestampValidationStrategy : MJValidationStrategy

- (MJValidationStrategyResult)isObjectValid:(id <MJTimestampValidationStrategyDataSource>)object;

@end
