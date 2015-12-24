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

#import "VSValidationStrategy.h"

/**
 * Objects that will be validated using the `MJTimestampValidationStrategy` must implement this protocol.
 **/
@protocol VSTimestampValidationStrategyDataSource <VSValidationStrategyDataSource>

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
 *    - If there is no a `lastUpdate` date, the strategy won't decide object validity (`VSValidationStrategyResultUnknown`).
 **/
@interface VSTimestampValidationStrategy : VSValidationStrategy

/** *************************************************** **
 * @name Object validation
 ** *************************************************** **/

/**
 * Strategy validation method for timestamp validation.
 * @param object The object to test.
 * @return The validation strategy result.
 **/
- (VSValidationStrategyResult)isObjectValid:(id <VSTimestampValidationStrategyDataSource> __nonnull)object;

@end
