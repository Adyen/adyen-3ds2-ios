//
//  ADYSecurityWarningsDelegate.h
//  Adyen3DS2
//
//  Copyright © 2021 Adyen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Adyen3DS2/ADYWarning.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A delegate to receive real time security warnings.
 */
@protocol ADYSecurityWarningsDelegate <NSObject>

/**
 Notify the delegate about security warnings.
 Will be called only in case the list of warnings has changed since the last update.

 @param warnings The list of warnings found.
 */
- (void)securityWarningsFound:(NSArray<ADYWarning *>*)warnings;

@end

NS_ASSUME_NONNULL_END
