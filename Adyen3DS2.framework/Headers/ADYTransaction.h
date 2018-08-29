//
//  ADYTransaction.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Adyen3DS2/ADYAuthenticationRequestParameters.h>
#import <Adyen3DS2/ADYChallengeParameters.h>
#import <Adyen3DS2/ADYChallengeStatusDelegate.h>
#import <Adyen3DS2/ADYProgressView.h>

/**
 The default timeout value for the challenge process.
 */
extern const NSTimeInterval ADYTransactionDefaultTimeout;

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a transaction that is to be authenticated using 3D-Secure 2.0.
 
 @note This class corresponds to the `Transaction` interface in the specification.
 */
@interface ADYTransaction : NSObject

/**
 The parameters provided by the SDK that should be sent with an authentication request.
 */
@property (nonatomic, strong, readonly) ADYAuthenticationRequestParameters *authenticationRequestParameters;

/**
 A progress view that can optionally be shown to indicate a loading state.
 */
@property (nonatomic, strong, readonly) ADYProgressView *progressView;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 Starts the challenge flow for the transaction.

 @param challengeParameters The challenge parameters received from the 3DS Server.
 @param delegate The delegate to inform of the result of the challenge.
 @param timeout The timeout interval in seconds in which the challenge process should be completed. Should be at least 300 seconds.
 */
- (void)performChallengeWithParameters:(ADYChallengeParameters *)challengeParameters delegate:(id<ADYChallengeStatusDelegate>)delegate timeout:(NSTimeInterval)timeout;

/**
 Cancels the current challenge flow.
 */
- (void)cancelChallenge;

@end

NS_ASSUME_NONNULL_END
