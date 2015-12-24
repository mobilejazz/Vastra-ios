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

/**
 * A `VSValidationStrategyResult` specifies the validity of an object.
 **/
typedef NS_ENUM(NSUInteger, VSValidationStrategyResult)
{
    /** Strategy cannot decide if valid or invalid. **/
    VSValidationStrategyResultUnknown,
    
    /** Strategy decides the object is valid. **/
    VSValidationStrategyResultValid,
    
    /** Strategy decides the object is invalid. **/
    VSValidationStrategyResultInvalid,
};

/**
 * `VSValidationStrategy` subclasses will have to declare its own data sources protocols which will heritate from this protocol.
 **/
@protocol VSValidationStrategyDataSource <NSObject>

@end

/**
 * A validation strategy. Create subclasses to implement customized strategies.
 **/
@interface VSValidationStrategy : NSObject

/** *************************************************** **
 * @name Object validation
 ** *************************************************** **/

/**
 * Strategy validation method.
 * @param object The object to test.
 * @return The validation strategy result.
 * @discussion Subclasses must override this method and implement custom validation.
 **/
- (VSValidationStrategyResult)isObjectValid:(id <VSValidationStrategyDataSource> __nonnull)object;

@end
