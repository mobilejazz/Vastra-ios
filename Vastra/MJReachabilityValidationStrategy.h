//
//  PWDReachabilityValidationStrategy.h
//  PeerWell
//
//  Created by Joan Martin on 24/11/15.
//  Copyright © 2015 Manish Shah. All rights reserved.
//

#import "MJValidationStrategy.h"

@interface MJReachabilityValidationStrategy : MJValidationStrategy

/**
 * The host to use to check if reachable.
 **/
- (id)initWithHost:(NSString*)host;

@end
