//
//  PWDReachabilityValidationStrategy.h
//  PeerWell
//
//  Created by Joan Martin on 24/11/15.
//  Copyright © 2015 Manish Shah. All rights reserved.
//

#import "MJValidationStrategy.h"

/**
 * Reachability validation strategy.
 *
 * The strategy implements the following approach:
 *
 *    - If internet is NOT available: the strategy considers all objects valid (`MJValidationStrategyResultValid`).
 *    - If internet is available: the strategy doesn't decide if the object is valid (`MJValidationStrategyResultUnknown`).
 **/
@interface MJReachabilityValidationStrategy : MJValidationStrategy

/** *************************************************** **
 * @name Initializers
 ** *************************************************** **/

/**
 * Default initializer.
 * @param host The host to use to check if reachable.
 * @return The initialized instance.
 **/
- (id)initWithHost:(NSString*)host;

/** *************************************************** **
 * @name Properties
 ** *************************************************** **/

/**
 * The host to use to check if reachable.
 **/
@property (nonatomic, strong, readonly) NSString *host;

@end
