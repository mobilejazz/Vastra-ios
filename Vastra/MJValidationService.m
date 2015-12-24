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

#import "MJValidationService.h"

@implementation MJValidationService

+ (MJValidationService*)serviceWithStrategies:(NSArray <MJValidationStrategy*> *)strategies
{
    MJValidationService *service = [[self alloc] initWithStrategies:strategies];
    return service;
}

- (id)initWithStrategies:(NSArray <MJValidationStrategy*> *)strategies;
{
    self = [super init];
    if (self)
    {
        _strategies = strategies;
    }
    return self;
}

- (BOOL)isObjectValid:(id <MJValidationStrategyDataSource>)object
{
    if (!object)
        return NO;
    
    // Default value set to NO.
    __block BOOL isValid = NO;
    
    [_strategies enumerateObjectsUsingBlock:^(MJValidationStrategy * _Nonnull strategy, NSUInteger idx, BOOL * _Nonnull stop) {
        MJValidationStrategyResult result = [strategy isObjectValid:object];
        
        if (result == MJValidationStrategyResultValid)
        {
            isValid = YES;
            *stop = YES;
        }
        else if (result == MJValidationStrategyResultInvalid)
        {
            isValid = NO;
            *stop = YES;
        }
        else
        {
            // result is MJValidationStrategyResultUnknown
            // lets iterate to next strategy
        }
    }];
    
    return isValid;
}

@end
