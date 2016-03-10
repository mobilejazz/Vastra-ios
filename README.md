[![Version](https://cocoapod-badges.herokuapp.com/v/Vastra/badge.png)](http://cocoadocs.org/docsets/Vastra) 
[![Platform](https://cocoapod-badges.herokuapp.com/p/Vastra/badge.png)](http://cocoadocs.org/docsets/Vastra) 
[![CocoaDocs](https://img.shields.io/badge/docs-%E2%9C%93-blue.svg)](http://cocoadocs.org/docsets/Vastra) 

![Mobile Jazz Vastra](https://raw.githubusercontent.com/mobilejazz/metadata/master/images/banners/mobile-jazz-vastra-banner.png)

#Vastra

**Vastra** is a library that helps to validate objects applying different strategy validations.

## How To Get Vastra

The easiest way to add **Vastra** to your project is using CocoaPods. Add the following line to your Podfile:
```
  pod 'Vastra', '~> 1.0'
```
## Using Vastra

### Creating strategies
Create the strategy instances that you want to validate your objects:

```objective-c
// Default validation strategy (always return validity)
VSValidationStrategy *defaultStrategy = [[VSValidationStrategy alloc] init];
 
// Timestamp based validation strategy
VSValidationStrategy *timestampStrategy = [[VSTimestampValidationStrategy alloc] init];

// Reachability validation strategy
VSValidationStrategy *reachabilityStrategy = [[VSReachabilityValidationStrategy alloc] initWithHost:@"www.google.com"];
```

Custom strategies can also be created. To do it:

1. Subclass the `VSValidationStrategy` class
2. Override the `isObjectValid:` method and implement your custom logic. The method must return:
  - `VSValidationStrategyResultValid` if the object is valid.
  - `VSValidationStrategyResultInvalid` if the object is invalid.
  - `VSValidationStrategyResultUnknown` if the strategy cannot decide.
3. If your strategy needs any particular data to implement the validation strategy, create a subprotocol of `VSValidationStrategyDataSource` and make your objects implement it. Checkout the implementation of `VSTimestampValidationStrategy` for a better example

### Creating the validation service
Create a `VSValidationService` instance including the strategies created above.

```objective-c
NSArray *strategies =  @[reachabilityStrategy, 
                         timestampStrategy,
                         defaultStrategy];
                       
VSValidationService *validationService = [[VSValidationService alloc] initWithStrategies:strategies];
```

The order of the strategies in the array will define the order of the validation phases. Objects will attempt to validate first to the first strategy, then the second, and so on.

If none strategy validates or invalidates the object, the validation service will consider the object as invalid.

In the example above we are using the showed order because we want our validation service to work as:

1. If no internet connection available, we want our objects to be considered valid. Otherwise, lets move to the second validation strategy.
2. If the object to be validated has a `lastUpdate` date smaller than `now+expiryTimeInterval`, then lets consider the object valid. Otherwise invalid.
3. In case the object doesn't have a `lastUpdate` date, lets consider the object valid.

### Using the validation service

Lets say we have a `MJUser` class:

```objective-c
@interface MJUser : NSObject <VSTimestampValidationStrategyDataSource>
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSDate *updatedAt;
@end

@implementation MJUser
- (NSDate*)lastUpdate {
    return _updatedAt;
}
- (NSTimeInterval)expiryTimeInterval {
    return 5; // 5 seconds
}
@end
```
To validate a user instance we would do:

```objective-c
// Create user instance
MJUser *user = [[MJUser alloc] init];
user.name = @"John Doe";
user.updatedAt = [NSDate date];

// Executing the validation service
if ([validationService isObjectValid:user]) 
  NSLog(@"User did pass validation");
else
  NSLog(@"User failed validation");
```

Assuming we have a valid internet connection, this user would pass the validation test. However, if we run this code 5 seconds later, this same user would fail validation as the timestamp strategy would invalidate it.

## Project Maintainer

This open source project is maintained by [Joan Martin](https://github.com/vilanovi).

## License

    Copyright 2016 MobileJazz

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
