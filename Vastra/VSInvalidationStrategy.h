//
// Copyright 2016 Mobile Jazz SL
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
 * Object invalidation strategy data source.
 **/
@protocol VSInvalidationStrategyDataSource <VSValidationStrategyDataSource>

@required

/** *************************************************** **
 * @name invalidation strategy data source
 ** *************************************************** **/

/**
 * Must return YES if object is invalid. Otherwise return NO.
 * @return YES if invalid, otherwise NO.
 **/
- (BOOL)isObjectInvalid;

@end

/**
 * Object invalidation strategy
 *
 * The strategy implements the following approach:
 *
 *    - If the object is invalid, returns `VSValidationStrategyResultInvalid`.
 *    - Otherwise returns `VSValidationStrategyResultUnknown`.
 **/
@interface VSInvalidationStrategy : VSValidationStrategy

/** *************************************************** **
 * @name Object validation
 ** *************************************************** **/

/**
 * Strategy validation method for object invalidation strategy.
 * @param object The object to test.
 * @return The validation strategy result.
 **/
- (VSValidationStrategyResult)isObjectValid:(id <VSInvalidationStrategyDataSource> __nonnull)object;

@end
