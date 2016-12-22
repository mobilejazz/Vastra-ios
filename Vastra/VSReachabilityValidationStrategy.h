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
#import "VSReachabilityProtocol.h"

/**
 * Reachability validation strategy.
 *
 * The strategy implements the following approach:
 *
 *    - If internet is NOT available: the strategy considers all objects valid (`VSValidationStrategyResultValid`).
 *    - If internet is available: the strategy doesn't decide if the object is valid (`VSValidationStrategyResultUnknown`).
 **/
@interface VSReachabilityValidationStrategy : VSValidationStrategy

/** *************************************************** **
 * @name Initializers
 ** *************************************************** **/

/**
 * Default initializer.
 * @param host The host to use to check if reachable.
 * @return The initialized instance.
 **/
- (nonnull id)initWithRechabilityProvider:(nonnull id<VSReachabilityProtocol>)reachabilityProvider;

@end
