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
 * A `MJValidationStrategyResult` specifies the validity of an object.
 **/
typedef NS_ENUM(NSUInteger, MJValidationStrategyResult)
{
    /** Strategy cannot decide if valid or invalid. **/
    MJValidationStrategyResultUnknown,
    
    /** Strategy decides the object is valid. **/
    MJValidationStrategyResultValid,
    
    /** Strategy decides the object is invalid. **/
    MJValidationStrategyResultInvalid,
};

/**
 * `MJValidationStrategy` subclasses will have to declare its own data sources protocols which will heritate from this protocol.
 **/
@protocol MJValidationStrategyDataSource <NSObject>

@end

/**
 * A validation strategy. Create subclasses to implement customized strategies.
 **/
@interface MJValidationStrategy : NSObject

/** *************************************************** **
 * @name Object validation
 ** *************************************************** **/

/**
 * Strategy validation method.
 * @param object The object to test.
 * @return The validation strategy result.
 * @discussion Subclasses must override this method and implement custom validation.
 **/
- (MJValidationStrategyResult)isObjectValid:(id <MJValidationStrategyDataSource> __nonnull)object;

@end
