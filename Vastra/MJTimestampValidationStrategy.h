//
//  PWDTimestampValidationStrategy.h
//  PeerWell
//
//  Created by Joan Martin on 24/11/15.
//  Copyright © 2015 Manish Shah. All rights reserved.
//

#import "MJValidationStrategy.h"

/**
 * Objects that will be validated using the `MJTimestampValidationStrategy` must implement this protocol.
 **/
@protocol MJTimestampValidationStrategyDataSource <MJValidationStrategyDataSource>

@required

/** *************************************************** **
 * @name Timestamp data source
 ** *************************************************** **/

/**
 * The last update date.
 **/
- (nullable NSDate*)lastUpdate;

/**
 * The expiry time interval.
 **/
- (NSTimeInterval)expiryTimeInterval;

@end

/**
 * Timestamp validation strategy.
 *
 * The strategy will measure the elapsed timeinterval from the `lastUpdate` to the current time.
 *    - If the elapsed timeinterval is smaller than `expiryTimeInterval`: The object will be considered valid.
 *    - If the elapsed timeinterval is greater than or equal to `expiryTimeInterval`: The object will be considered invalid.
 *    - If there is no a `lastUpdate` date, the strategy won't decide object validity (`MJValidationStrategyResultUnknown`).
 **/
@interface MJTimestampValidationStrategy : MJValidationStrategy

/** *************************************************** **
 * @name Object validation
 ** *************************************************** **/

/**
 * Strategy validation method for timestamp validation.
 * @param object The object to test.
 * @return The validation strategy result.
 **/
- (MJValidationStrategyResult)isObjectValid:(id <MJTimestampValidationStrategyDataSource> __nonnull)object;

@end
