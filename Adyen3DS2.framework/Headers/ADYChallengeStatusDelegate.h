//
//  ADYChallengeStatusDelegate.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <Adyen3DS2/ADYChallengeCompletion.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Defines methods which a delegate can implement to be informed when a challenge is completed.
 
 @note This protocol corresponds to the `ChallengeStatusReceiver` interface in the specification.
 */
@protocol ADYChallengeStatusDelegate <NSObject>

/**
 Invoked when a challenge is completed successfully.

 @param completion The completion event of the challenge.
 */
- (void)challengeDidFinishWithCompletion:(ADYChallengeCompletion *)completion;

/**
 Invokes when a challenge has failed.

 @param error The error that occurred.
 */
- (void)challengeDidFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
