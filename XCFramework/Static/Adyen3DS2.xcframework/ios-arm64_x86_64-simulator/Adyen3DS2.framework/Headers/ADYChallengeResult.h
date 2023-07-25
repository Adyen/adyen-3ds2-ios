//
//  ADYChallengeResult.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Contains the result of a successfully completed challenge.
 
 @note This class corresponds to the `CompletionEvent` class in the specification.
 */
@interface ADYChallengeResult : NSObject

/**
 A unique string identifying the transaction within the scope of the SDK.
 - Warning: SDKTransactionIdentifier is deprecated and will be removed in future release. If you need this [reach out to us](https://github.com/Adyen/adyen-3ds2-ios/issues). 
 */
@property (nonatomic, copy, readonly) NSString *SDKTransactionIdentifier __attribute__((deprecated("Will be removed in a future release.")));

/**
 The final transaction status.
 */
@property (nonatomic, copy, readonly) NSString *transactionStatus;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
