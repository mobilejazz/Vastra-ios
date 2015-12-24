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

#import "VSValidationService.h"

@implementation VSValidationService

+ (VSValidationService *)serviceWithStrategies:(NSArray<__kindof VSValidationStrategy *> *)strategies
{
    VSValidationService *service = [[self alloc] initWithStrategies:strategies];
    return service;
}

- (id)initWithStrategies:(NSArray <VSValidationStrategy*> *)strategies;
{
    self = [super init];
    if (self)
    {
        _strategies = strategies;
    }
    return self;
}

- (BOOL)isObjectValid:(id <VSValidationStrategyDataSource>)object
{
    if (!object)
        return NO;
    
    __block BOOL isValid = NO;
    
    [_strategies enumerateObjectsUsingBlock:^(VSValidationStrategy * _Nonnull strategy, NSUInteger idx, BOOL * _Nonnull stop) {
        VSValidationStrategyResult result = [strategy isObjectValid:object];
        
        if (result == VSValidationStrategyResultValid)
        {
            isValid = YES;
            *stop = YES;
        }
        else if (result == VSValidationStrategyResultInvalid)
        {
            isValid = NO;
            *stop = YES;
        }
        else
        {
            // result is VSValidationStrategyResultUnknown
            // lets iterate to next strategy
        }
    }];
    
    return isValid;
}

@end
