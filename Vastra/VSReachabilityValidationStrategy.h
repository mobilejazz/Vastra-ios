//
//  PWDReachabilityValidationStrategy.h
//  PeerWell
//
//  Created by Joan Martin on 24/11/15.
//  Copyright © 2015 Manish Shah. All rights reserved.
//

#import "VSValidationStrategy.h"

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
- (nonnull id)initWithHost:(NSString * __nonnull)host;

/** *************************************************** **
 * @name Properties
 ** *************************************************** **/

/**
 * The host to use to check if reachable.
 **/
@property (nonatomic, strong, readonly, nonnull) NSString *host;

@end
