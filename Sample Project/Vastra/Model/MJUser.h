//
//  MJUser.h
//  Vastra
//
//  Created by Joan Martin on 24/12/15.
//  Copyright © 2015 Mobile Jazz. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "VSTimestampValidationStrategy.h"

@interface MJUser : NSObject <VSTimestampValidationStrategyDataSource>

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSDate *updatedAt;

@end
