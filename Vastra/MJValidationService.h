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

#import <Foundation/Foundation.h>

#import "MJValidationStrategy.h"

/**
 * A validation service contains multiple strategies.
 * The validation service will try to validate an object with each strategy by order. The first strategy that validates or invalidates the object will define the validity of the object.
 * If any strategy succeeds to validate or invalidate the object, the validation will fail and the object will be considered as invalid.
 **/
@interface MJValidationService : NSObject

/** *************************************************** **
 * @name Initializers
 ** *************************************************** **/

/**
 * Default static initializer.
 * @param strategies    An array of strategies.
 * @return An initialized instance.
 **/
+ ( MJValidationService* _Nonnull)serviceWithStrategies:(NSArray <MJValidationStrategy*>  * _Nonnull)strategies;

/**
 * Default initializer.
 * @param strategies    An array of strategies.
 * @return The initialized instance.
 **/
- (_Nonnull id)initWithStrategies:(NSArray <MJValidationStrategy*>  * _Nonnull )strategies;

/** *************************************************** **
 * @name Strategies
 ** *************************************************** **/

/**
 * Array of validation strategies.
 **/
@property (nonatomic, strong, readonly, nonnull) NSArray <MJValidationStrategy*> *strategies;

/** *************************************************** **
 * @name Object validation
 ** *************************************************** **/

/**
 * Main validator method.
 * @param object The object to validate.
 * @return YES if valid, NO otherwise.
 * @discussion The validation process iterates over the strategies array in order. The first strategy that returns Valid or Invalid will make this method return YES or NO. If all strategies are consumed and none decided, default return value is NO.
 **/
- (BOOL)isObjectValid:(id <MJValidationStrategyDataSource> _Nonnull)object;

@end
